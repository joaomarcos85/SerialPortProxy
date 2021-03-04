#include "MainWindow/mainwindow.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QException>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    //Define o caminho atual para a pasta onde está o arquivo
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    MainWindow w;
    w.createSysTray();
    QObject::connect(&w, &MainWindow::exited, &a, &QApplication::quit);

    //Registra o Software para sempre iniciar com o windows
    w.setAutoRun(true);

    return a.exec();
}
