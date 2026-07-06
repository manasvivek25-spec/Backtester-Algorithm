/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *tickerInput;
    QComboBox *strategyComboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *strategyParamsStackedWidget;
    QWidget *page;
    QSpinBox *shortPeriodInput;
    QSpinBox *longPeriodInput;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *bbPeriodInput;
    QDoubleSpinBox *bbStdDevInput;
    QWidget *page_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *rsiPeriodInput;
    QSpinBox *rsiOversoldInput;
    QSpinBox *rsiOverboughtInput;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *runButton;
    QTextEdit *resultsOutput;
    QDoubleSpinBox *capitalInput;
    QLabel *capiltalinput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1957, 1285);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("/* This styles your main window's background */\n"
"QWidget#centralwidget {\n"
"    background-color: #f0f2f5;\n"
"}\n"
"\n"
"/* This styles ALL QLabels */\n"
"QLabel {\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 10pt;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"	text-align: center;\n"
"}\n"
"\n"
"/* This styles ALL QSpinBox and QDoubleSpinBox widgets */\n"
"QSpinBox, QDoubleSpinBox, QLineEdit {\n"
"    font-size: 10pt;\n"
"    padding: 3px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* This styles ALL QComboBox (dropdowns) */\n"
"QComboBox {\n"
"    font-size: 10pt;\n"
"    padding: 3px;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* This styles ALL QPushButtons */\n"
"QPushButton {\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 11pt;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #0078d4;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"}\n"
"\n"
"/* This styles "
                        "any button WHEN YOU HOVER over it */\n"
"QPushButton:hover {\n"
"    background-color: #005a9e;\n"
"}\n"
"\n"
"/* This styles your \"Run\" button specifically */\n"
"/* We use the #objectName we created! */\n"
"QPushButton#runButton {\n"
"    background-color: #107c10; /* A \"go\" green */\n"
"}\n"
"\n"
"QPushButton#runButton:hover {\n"
"    background-color: #0d630d;\n"
"}\n"
"\n"
"/* This styles your output text box */\n"
"QTextEdit#resultsOutput {\n"
"    font-family: \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 10pt;\n"
"    color: #222;\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 4px;\n"
"	qproperty-alignment: 'AlignCenter';\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QFont font;
        font.setPointSize(10);
        centralwidget->setFont(font);
        centralwidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(550, 20, 419, 102));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        tickerInput = new QLineEdit(layoutWidget);
        tickerInput->setObjectName("tickerInput");

        verticalLayout->addWidget(tickerInput);

        strategyComboBox = new QComboBox(layoutWidget);
        strategyComboBox->setObjectName("strategyComboBox");

        verticalLayout->addWidget(strategyComboBox);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(370, 130, 771, 211));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        strategyParamsStackedWidget = new QStackedWidget(layoutWidget1);
        strategyParamsStackedWidget->setObjectName("strategyParamsStackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        shortPeriodInput = new QSpinBox(page);
        shortPeriodInput->setObjectName("shortPeriodInput");
        shortPeriodInput->setGeometry(QRect(30, 100, 71, 26));
        shortPeriodInput->setMinimum(1);
        shortPeriodInput->setValue(2);
        longPeriodInput = new QSpinBox(page);
        longPeriodInput->setObjectName("longPeriodInput");
        longPeriodInput->setGeometry(QRect(150, 100, 71, 26));
        longPeriodInput->setMinimum(1);
        longPeriodInput->setMaximum(1000);
        longPeriodInput->setValue(3);
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 101, 20));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 70, 101, 20));
        strategyParamsStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 60, 63, 20));
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(120, 60, 131, 20));
        bbPeriodInput = new QSpinBox(page_2);
        bbPeriodInput->setObjectName("bbPeriodInput");
        bbPeriodInput->setGeometry(QRect(20, 90, 81, 26));
        bbStdDevInput = new QDoubleSpinBox(page_2);
        bbStdDevInput->setObjectName("bbStdDevInput");
        bbStdDevInput->setGeometry(QRect(131, 90, 101, 26));
        strategyParamsStackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 40, 63, 20));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 40, 81, 20));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, 110, 111, 20));
        rsiPeriodInput = new QSpinBox(page_3);
        rsiPeriodInput->setObjectName("rsiPeriodInput");
        rsiPeriodInput->setGeometry(QRect(11, 70, 81, 26));
        rsiOversoldInput = new QSpinBox(page_3);
        rsiOversoldInput->setObjectName("rsiOversoldInput");
        rsiOversoldInput->setGeometry(QRect(151, 70, 81, 26));
        rsiOverboughtInput = new QSpinBox(page_3);
        rsiOverboughtInput->setObjectName("rsiOverboughtInput");
        rsiOverboughtInput->setGeometry(QRect(91, 140, 81, 26));
        strategyParamsStackedWidget->addWidget(page_3);

        horizontalLayout->addWidget(strategyParamsStackedWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(630, 430, 258, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        runButton = new QPushButton(layoutWidget2);
        runButton->setObjectName("runButton");

        verticalLayout_2->addWidget(runButton);

        resultsOutput = new QTextEdit(layoutWidget2);
        resultsOutput->setObjectName("resultsOutput");

        verticalLayout_2->addWidget(resultsOutput);

        capitalInput = new QDoubleSpinBox(centralwidget);
        capitalInput->setObjectName("capitalInput");
        capitalInput->setGeometry(QRect(700, 390, 121, 26));
        capitalInput->setMinimum(100.000000000000000);
        capitalInput->setMaximum(1000000.000000000000000);
        capitalInput->setValue(10000.000000000000000);
        capiltalinput = new QLabel(centralwidget);
        capiltalinput->setObjectName("capiltalinput");
        capiltalinput->setGeometry(QRect(710, 360, 131, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1957, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        strategyParamsStackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Algorithmic Trading Strategy Back Tester Simulator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Short Period", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Long Period", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Period:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Std Deviations:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Period:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Oversold:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Overbought:", nullptr));
        runButton->setText(QCoreApplication::translate("MainWindow", "Run Backtest", nullptr));
        capitalInput->setPrefix(QCoreApplication::translate("MainWindow", "$", nullptr));
        capitalInput->setSuffix(QString());
        capiltalinput->setText(QCoreApplication::translate("MainWindow", "Capital Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
