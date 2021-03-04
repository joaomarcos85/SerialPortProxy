/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupArduino;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupPPS;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(589, 259);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupArduino = new QGroupBox(centralWidget);
        groupArduino->setObjectName(QStringLiteral("groupArduino"));
        groupArduino->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(groupArduino);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(groupArduino);

        groupPPS = new QGroupBox(centralWidget);
        groupPPS->setObjectName(QStringLiteral("groupPPS"));
        groupPPS->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(groupPPS);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(groupPPS);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMinimumSize(QSize(0, 0));
        horizontalWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbConnect = new QPushButton(horizontalWidget);
        pbConnect->setObjectName(QStringLiteral("pbConnect"));

        horizontalLayout_2->addWidget(pbConnect);

        pbDisconnect = new QPushButton(horizontalWidget);
        pbDisconnect->setObjectName(QStringLiteral("pbDisconnect"));

        horizontalLayout_2->addWidget(pbDisconnect);


        verticalLayout_4->addWidget(horizontalWidget);


        gridLayout->addLayout(verticalLayout_4, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 589, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupArduino->setTitle(QApplication::translate("MainWindow", "Arduino", 0));
        groupPPS->setTitle(QApplication::translate("MainWindow", "PPS", 0));
        pbConnect->setText(QApplication::translate("MainWindow", "Conectar", 0));
        pbDisconnect->setText(QApplication::translate("MainWindow", "Desconectar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
