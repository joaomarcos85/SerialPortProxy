#ifndef serialhandler_H
#define serialhandler_H

#include <QDebug>
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QHBoxLayout>
#include <system/sysprop.h>


//classe com o objetivo de configurar e o comunicar via s serial com equipamento
namespace Ui {
class serialhandler;
}

class serialhandler : public QDialog
{
    Q_OBJECT

public:
    Ui::serialhandler *ui;
    struct Configuration{
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    explicit serialhandler(QWidget *parent = 0);
    QSerialPort* getserialport();
    ~serialhandler();

    QWidget *getPanel();

    void start();

    void setType(QString type);

    //carrega a configuração da porta serial
    void loadconfiguration();

    bool isConfigLoaded();


private slots:
    //preenche a combo box do as portas seriais disponiveis
    void fillports();

private:
    //preenche a combo box do baudrate
    void fillbaudrate();
    //preenche as informações do dispositivo serial conforme a opção de porta serial escolhida
    void showportdetails(int);
    //seta configuração da porta serial
    void setconfiguration();
    //abre a porta serial conforme a configuração setada
    void openSerialPort();
    //salva a configuração da porta serial
    void saveconfiguration();
    //Timer que fica verificando se foi encontrada uma nova porta serial
    QTimer *timer;
    QString type="";
    bool configLoaded=false;



private:
    Configuration currentconfiguration;
    QSerialPort *serial;
};

#endif // serialhandler_H
