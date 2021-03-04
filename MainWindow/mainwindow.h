#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Serial/serialhandler.h>
#include <QSound>
#include <QSystemTrayIcon>
#include <system/sysinfo.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createSysTray();

    void setAutoRun(bool autorun);

public slots:
    void onSysTrayActivated();

private slots:
    void readData();

    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

signals:
    void exited();

    void messageHandler(QString message);

private:
    Ui::MainWindow *ui;
    serialhandler *SerialhandlerFrom;
    serialhandler *SerialhandlerTo;
    QSound *spass;

    void constructFromPanel();

    void constructToPanel();

    void setButtonsEnabled();

    void closeEvent(QCloseEvent *event);

    void loadSounds();
};





#endif // MAINWINDOW_H
