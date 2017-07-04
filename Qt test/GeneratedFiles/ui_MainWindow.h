/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *rules;
    QTextBrowser *textBrowser;
    QWidget *settings;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelRows;
    QPushButton *buttonStart;
    QRadioButton *radioNovice;
    QRadioButton *radioExperienced;
    QLabel *labelBombs;
    QLabel *labelCols;
    QSpinBox *spinCols;
    QSpinBox *spinRows;
    QSpinBox *spinBombs;
    QPushButton *buttonStop;
    QRadioButton *radioCustom;
    QRadioButton *radioExpert;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(896, 406);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 181, 221));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        rules = new QWidget();
        rules->setObjectName(QStringLiteral("rules"));
        textBrowser = new QTextBrowser(rules);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 191, 261));
        tabWidget->addTab(rules, QString());
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        gridLayoutWidget = new QWidget(settings);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 171, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(7, 0, 0, 0);
        labelRows = new QLabel(gridLayoutWidget);
        labelRows->setObjectName(QStringLiteral("labelRows"));
        labelRows->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(labelRows, 2, 0, 1, 1);

        buttonStart = new QPushButton(gridLayoutWidget);
        buttonStart->setObjectName(QStringLiteral("buttonStart"));

        gridLayout->addWidget(buttonStart, 5, 0, 1, 1);

        radioNovice = new QRadioButton(gridLayoutWidget);
        radioNovice->setObjectName(QStringLiteral("radioNovice"));

        gridLayout->addWidget(radioNovice, 0, 0, 1, 1);

        radioExperienced = new QRadioButton(gridLayoutWidget);
        radioExperienced->setObjectName(QStringLiteral("radioExperienced"));

        gridLayout->addWidget(radioExperienced, 1, 0, 1, 1);

        labelBombs = new QLabel(gridLayoutWidget);
        labelBombs->setObjectName(QStringLiteral("labelBombs"));
        labelBombs->setMaximumSize(QSize(35, 16777215));

        gridLayout->addWidget(labelBombs, 4, 0, 1, 1);

        labelCols = new QLabel(gridLayoutWidget);
        labelCols->setObjectName(QStringLiteral("labelCols"));
        labelCols->setMaximumSize(QSize(24, 16777215));

        gridLayout->addWidget(labelCols, 3, 0, 1, 1);

        spinCols = new QSpinBox(gridLayoutWidget);
        spinCols->setObjectName(QStringLiteral("spinCols"));

        gridLayout->addWidget(spinCols, 3, 1, 1, 1);

        spinRows = new QSpinBox(gridLayoutWidget);
        spinRows->setObjectName(QStringLiteral("spinRows"));

        gridLayout->addWidget(spinRows, 2, 1, 1, 1);

        spinBombs = new QSpinBox(gridLayoutWidget);
        spinBombs->setObjectName(QStringLiteral("spinBombs"));

        gridLayout->addWidget(spinBombs, 4, 1, 1, 1);

        buttonStop = new QPushButton(gridLayoutWidget);
        buttonStop->setObjectName(QStringLiteral("buttonStop"));

        gridLayout->addWidget(buttonStop, 5, 1, 1, 1);

        radioCustom = new QRadioButton(gridLayoutWidget);
        radioCustom->setObjectName(QStringLiteral("radioCustom"));

        gridLayout->addWidget(radioCustom, 1, 1, 1, 1);

        radioExpert = new QRadioButton(gridLayoutWidget);
        radioExpert->setObjectName(QStringLiteral("radioExpert"));

        gridLayout->addWidget(radioExpert, 0, 1, 1, 1);

        tabWidget->addTab(settings, QString());
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">The objective of the game is to clear a rectangular board containing hidden &quot;mines&quot; or bombs without detonating any of them, with help from clues about the number of neighboring mines in each field.</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(rules), QApplication::translate("MainWindowClass", "Rules", Q_NULLPTR));
        labelRows->setText(QApplication::translate("MainWindowClass", "Rows:", Q_NULLPTR));
        buttonStart->setText(QApplication::translate("MainWindowClass", "Start", Q_NULLPTR));
        radioNovice->setText(QApplication::translate("MainWindowClass", "Novice", Q_NULLPTR));
        radioExperienced->setText(QApplication::translate("MainWindowClass", "Experienced", Q_NULLPTR));
        labelBombs->setText(QApplication::translate("MainWindowClass", "Bombs:", Q_NULLPTR));
        labelCols->setText(QApplication::translate("MainWindowClass", "Cols:", Q_NULLPTR));
        buttonStop->setText(QApplication::translate("MainWindowClass", "Stop", Q_NULLPTR));
        radioCustom->setText(QApplication::translate("MainWindowClass", "Custom", Q_NULLPTR));
        radioExpert->setText(QApplication::translate("MainWindowClass", "Expert", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(settings), QApplication::translate("MainWindowClass", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
