#include "MainWindow/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->hide();
    ui->statusBar->hide();

    this->constructFromPanel();
    this->constructToPanel();
    this->setWindowTitle(SysInfo::sys_name()+" - "+SysInfo::sys_version());

    if(SerialhandlerFrom->isConfigLoaded() && SerialhandlerFrom->isConfigLoaded()){
        ui->pbConnect->click();
    }
    loadSounds();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::constructFromPanel()
{
    SerialhandlerFrom=new serialhandler();
    ui->verticalLayout_3->addWidget(SerialhandlerFrom->getPanel());
    SerialhandlerFrom->setType("from");
    SerialhandlerFrom->loadconfiguration();
}

void MainWindow::constructToPanel()
{
    SerialhandlerTo=new serialhandler();
    ui->verticalLayout_2->addWidget(SerialhandlerTo->getPanel());
    SerialhandlerTo->setType("to");
    SerialhandlerTo->loadconfiguration();
}

void MainWindow::readData()
{
    //Verifica se existe dados pendentes para serem lidos
    if(SerialhandlerFrom->getserialport()->bytesAvailable()<=0)
    {
        return;
    }

    bool beep=false;
    QByteArray write;
    QByteArray read=SerialhandlerFrom->getserialport()->readAll();

    if(read.contains("A"))
    {
        write.append("A\r\n");
    }

    if(read.contains("B"))
    {
        write.append("B\r\n");
        beep=true;
    }

    if(beep)
    {
        spass->stop();
        spass->play();
    }

    //Redireciona os dados para a outra porta
    SerialhandlerTo->getserialport()->clear();
    SerialhandlerTo->getserialport()->write(write);
}

void MainWindow::on_pbConnect_clicked()
{
    //Salva as configurações
    this->SerialhandlerFrom->start();
    this->SerialhandlerTo->start();

    //Abre a conexão
    SerialhandlerFrom->getserialport()->open(QIODevice::ReadWrite);
    SerialhandlerTo->getserialport()->open(QIODevice::ReadWrite);

    //Ouve a primeira porta
    connect(SerialhandlerFrom->getserialport(), &QSerialPort::readyRead,
            this, &MainWindow::readData);

    this->setButtonsEnabled();
}

void MainWindow::setButtonsEnabled()
{
    if(SerialhandlerFrom->getserialport()->isOpen() &&
            SerialhandlerTo->getserialport()->isOpen())
    {
        ui->pbConnect->setEnabled(false);
        ui->pbDisconnect->setEnabled(true);
    }
    else
    {
        ui->pbConnect->setEnabled(true);
        ui->pbDisconnect->setEnabled(false);
        SerialhandlerFrom->getserialport()->close();
        SerialhandlerTo->getserialport()->close();
    }
}

void MainWindow::on_pbDisconnect_clicked()
{
    SerialhandlerFrom->getserialport()->close();
    SerialhandlerTo->getserialport()->close();
    this->setButtonsEnabled();
}

void MainWindow::onSysTrayActivated()
{
    this->show();
}


void MainWindow::createSysTray()
{
    QPixmap oPixmap(":icon_128.png");
    QIcon oIcon(oPixmap);

    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(oIcon);
    QMenu *menu = new QMenu();
    menu->addAction(tr("Configurar"), [this](){
        this->show();
    });
    menu->addAction(tr("Sair"), [this](){
        emit exited();
    });

    trayIcon->setContextMenu(menu);
    trayIcon->setVisible(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->hide();
}

void MainWindow::setAutoRun(bool autorun)
{
    QSettings bootUpSettings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    if (autorun) {
        bootUpSettings.setValue(SysInfo::sys_name(), QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
        bootUpSettings.sync();
    } else {
        bootUpSettings.remove(SysInfo::sys_name());
        bootUpSettings.sync();
    }
}

void MainWindow::loadSounds()
{
    spass=new QSound("sound/beep.wav");
}
