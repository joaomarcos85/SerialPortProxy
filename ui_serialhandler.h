/********************************************************************************
** Form generated from reading UI file 'serialhandler.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALHANDLER_H
#define UI_SERIALHANDLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialhandler
{
public:
    QGridLayout *gridLayout_3;
    QWidget *gridWidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QLabel *pidLabel;
    QLabel *serialNumberLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *descriptionLabel;
    QLabel *manufacturerLabel;
    QComboBox *serialPortInfoListBox;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QComboBox *baudRateBox;
    QLabel *baudRateLabel;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *dataBitsBox;
    QComboBox *parityBox;
    QComboBox *stopBitsBox;
    QComboBox *flowControlBox;

    void setupUi(QDialog *serialhandler)
    {
        if (serialhandler->objectName().isEmpty())
            serialhandler->setObjectName(QStringLiteral("serialhandler"));
        serialhandler->resize(623, 215);
        gridLayout_3 = new QGridLayout(serialhandler);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridWidget = new QWidget(serialhandler);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(gridWidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        selectBox = new QGroupBox(gridWidget);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectBox->sizePolicy().hasHeightForWidth());
        selectBox->setSizePolicy(sizePolicy1);
        selectBox->setMinimumSize(QSize(150, 0));
        selectBox->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        gridLayout->addWidget(pidLabel, 6, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QStringLiteral("serialNumberLabel"));

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));

        gridLayout->addWidget(vidLabel, 5, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QStringLiteral("manufacturerLabel"));

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);


        horizontalLayout->addWidget(selectBox);

        parametersBox = new QGroupBox(gridWidget);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        label_2 = new QLabel(parametersBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(parametersBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(parametersBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(parametersBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout_2->addWidget(parityBox, 2, 1, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 3, 1, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);


        horizontalLayout->addWidget(parametersBox);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(gridWidget, 0, 0, 1, 1);


        retranslateUi(serialhandler);

        QMetaObject::connectSlotsByName(serialhandler);
    } // setupUi

    void retranslateUi(QDialog *serialhandler)
    {
        serialhandler->setWindowTitle(QApplication::translate("serialhandler", "Dialog", 0));
        selectBox->setTitle(QApplication::translate("serialhandler", "Escolha a porta serial:", 0));
        pidLabel->setText(QApplication::translate("serialhandler", "Produto ID:", 0));
        serialNumberLabel->setText(QApplication::translate("serialhandler", "N\303\272mero de s\303\251rie:", 0));
        locationLabel->setText(QApplication::translate("serialhandler", "Porta:", 0));
        vidLabel->setText(QApplication::translate("serialhandler", "Vendedor ID:", 0));
        descriptionLabel->setText(QApplication::translate("serialhandler", "Descri\303\247\303\243o:", 0));
        manufacturerLabel->setText(QApplication::translate("serialhandler", "Fabricante:", 0));
        parametersBox->setTitle(QApplication::translate("serialhandler", "Parametros porta serial", 0));
        baudRateLabel->setText(QApplication::translate("serialhandler", "BaudRate:", 0));
        label_2->setText(QApplication::translate("serialhandler", "Parity:", 0));
        label->setText(QApplication::translate("serialhandler", "Data bits:", 0));
        label_3->setText(QApplication::translate("serialhandler", "Stop bits", 0));
        label_4->setText(QApplication::translate("serialhandler", "Flow Control:", 0));
    } // retranslateUi

};

namespace Ui {
    class serialhandler: public Ui_serialhandler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALHANDLER_H
