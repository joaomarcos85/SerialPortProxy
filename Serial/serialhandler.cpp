#include "serialhandler.h"
#include "ui_serialhandler.h"


static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

serialhandler::serialhandler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serialhandler)
{
    ui->setupUi(this);
    connect(ui->serialPortInfoListBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &serialhandler::showportdetails);

    setWindowTitle("Configurar Serial");
    fillbaudrate();
    fillports();

    //Cria o Timer responsável por atualizar a lista de portas
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(fillports()));
    timer->start(400);
}

serialhandler::~serialhandler()
{
    delete ui;
}

void serialhandler::fillbaudrate()
{
    ui->baudRateBox->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->setCurrentIndex(1);
}


void serialhandler::fillports()
{
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    /*Verifica se o número de portas encontradas está igual
     ao número de portas do select*/
    if(ui->serialPortInfoListBox->count() == availablePorts.size()){
        return;
    }

    ui->serialPortInfoListBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    foreach (const QSerialPortInfo &info, availablePorts) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortInfoListBox->addItem(list.first(), list);
    }

    //Atualiza o tamanho da lista de combobox
    if(ui->serialPortInfoListBox->view()->isVisible())
    {
        ui->serialPortInfoListBox->showPopup();
    }

}

void serialhandler::showportdetails(int idx)
{
    if (idx == -1)
        return;

    QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();
    ui->descriptionLabel->setText(tr("Descrição: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->manufacturerLabel->setText(tr("Fabricante: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    ui->serialNumberLabel->setText(tr("Número de série: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    ui->locationLabel->setText(tr("Porta: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    ui->vidLabel->setText(tr("ID do fornecedor: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    ui->pidLabel->setText(tr("ID do produto: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));

    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

}

void serialhandler::start()
{
    setconfiguration();
    openSerialPort();
}

void serialhandler::loadconfiguration()
{
    QString port=SysProp::instance()->customProp()->value("serial.port."+type).toString();
    QString baudRate=SysProp::instance()->customProp()->value("serial.baudRate."+type).toString();
    QString dataBits=SysProp::instance()->customProp()->value("serial.dataBits."+type).toString();
    QString parity=SysProp::instance()->customProp()->value("serial.parity."+type).toString();
    QString stopBits=SysProp::instance()->customProp()->value("serial.stopBits."+type).toString();
    QString flowControl=SysProp::instance()->customProp()->value("serial.flowControl."+type).toString();

    if(port==NULL || port.size()==0)
    {
        return;
    }

    ui->serialPortInfoListBox->setCurrentText(port);
    ui->baudRateBox->setCurrentText(baudRate);
    ui->dataBitsBox->setCurrentText(dataBits);
    ui->parityBox->setCurrentText(parity);
    ui->stopBitsBox->setCurrentText(stopBits);
    ui->flowControlBox->setCurrentText(flowControl);

    currentconfiguration.name = port;
    currentconfiguration.baudRate = static_cast<QSerialPort::BaudRate>(baudRate.toInt());
    currentconfiguration.dataBits = static_cast<QSerialPort::DataBits>(dataBits.toInt());
    currentconfiguration.parity = static_cast<QSerialPort::Parity>(parity.toInt());
    currentconfiguration.stopBits = static_cast<QSerialPort::StopBits>(stopBits.toInt());
    currentconfiguration.flowControl = static_cast<QSerialPort::FlowControl>(flowControl.toInt());
    this->configLoaded=true;
}

void serialhandler::saveconfiguration()
{
    QDir dir;
    dir.mkpath("conf/");

    QString port=ui->serialPortInfoListBox->currentText();
    QString baudRate=ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toString();
    QString dataBits=ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toString();
    QString parity=ui->parityBox->itemData(ui->parityBox->currentIndex()).toString();
    QString stopBits=ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toString();
    QString flowControl=ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toString();

    SysProp::instance()->customProp()->setValue("serial.port."+type,port);
    SysProp::instance()->customProp()->setValue("serial.baudRate."+type,baudRate);
    SysProp::instance()->customProp()->setValue("serial.dataBits."+type,dataBits);
    SysProp::instance()->customProp()->setValue("serial.parity."+type,parity);
    SysProp::instance()->customProp()->setValue("serial.stopBits."+type,stopBits);
    SysProp::instance()->customProp()->setValue("serial.flowControl."+type,flowControl);
}

void serialhandler::setconfiguration()
{

    currentconfiguration.name = ui->serialPortInfoListBox->currentText();
    currentconfiguration.baudRate = static_cast<QSerialPort::BaudRate>(ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
    currentconfiguration.stringBaudRate = QString::number(currentconfiguration.baudRate);
    currentconfiguration.dataBits = static_cast<QSerialPort::DataBits>(ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
    currentconfiguration.stringDataBits = ui->dataBitsBox->currentText();
    currentconfiguration.parity = static_cast<QSerialPort::Parity>(ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
    currentconfiguration.stringParity = ui->parityBox->currentText();
    currentconfiguration.stopBits = static_cast<QSerialPort::StopBits>(ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
    currentconfiguration.stringStopBits = ui->stopBitsBox->currentText();
    currentconfiguration.flowControl = static_cast<QSerialPort::FlowControl>(ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt());
    currentconfiguration.stringFlowControl = ui->flowControlBox->currentText();
}

void serialhandler::openSerialPort()
{
    serial=new QSerialPort(this);
    serial->setPortName(currentconfiguration.name);
    serial->setBaudRate(currentconfiguration.baudRate);
    serial->setDataBits(currentconfiguration.dataBits);
    serial->setParity(currentconfiguration.parity);
    serial->setStopBits(currentconfiguration.stopBits);
    serial->setFlowControl(currentconfiguration.flowControl);
    serial->close();
    if (serial->open(QIODevice::ReadWrite))
    {
        //QMessageBox::information(this,"","Porta serial configurada");
        saveconfiguration();
    }
    else
    {
        QMessageBox::critical(this, tr("Erro"), serial->errorString());
    }
}

QSerialPort* serialhandler::getserialport()
{
    return serial;
}

QWidget *serialhandler::getPanel()
{
    return ui->gridWidget;
}

void serialhandler::setType(QString type)
{
    this->type=type;
}

bool serialhandler::isConfigLoaded()
{
    return this->configLoaded;
}
