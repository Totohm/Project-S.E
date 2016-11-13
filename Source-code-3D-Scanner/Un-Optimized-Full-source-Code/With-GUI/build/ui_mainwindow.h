/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionRange;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QToolButton *newButton;
    QToolButton *openButton;
    QToolButton *openButton_2;
    QGroupBox *groupBox_5;
    QToolButton *openButton_3;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QDoubleSpinBox *xRange;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *yRange;
    QDoubleSpinBox *zRange;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QToolButton *newButton_3;
    QToolButton *newButton_2;
    QToolButton *newButton_4;
    QToolButton *newButton_5;
    QSlider *horizontalSlider_p;
    QLabel *label_4;
    QLabel *label_5;
    QLCDNumber *lcdNumber_G;
    QLabel *label_6;
    QSlider *horizontalSlider_R;
    QSlider *horizontalSlider_G;
    QPushButton *pushButton_random;
    QLCDNumber *lcdNumber_B;
    QSlider *horizontalSlider_B;
    QLCDNumber *lcdNumber_p;
    QLCDNumber *lcdNumber_R;
    QLabel *label_7;
    QVTKWidget *qvtkWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(991, 739);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionRange = new QAction(MainWindow);
        actionRange->setObjectName(QStringLiteral("actionRange"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 911, 181));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 281, 131));
        newButton = new QToolButton(groupBox_4);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(10, 30, 81, 91));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/1476926247_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);
        newButton->setIconSize(QSize(60, 60));
        newButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        openButton = new QToolButton(groupBox_4);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(100, 30, 81, 91));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/1476926622_Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        openButton->setIconSize(QSize(60, 60));
        openButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        openButton_2 = new QToolButton(groupBox_4);
        openButton_2->setObjectName(QStringLiteral("openButton_2"));
        openButton_2->setGeometry(QRect(190, 30, 81, 91));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/1476926747_floppy_disk_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton_2->setIcon(icon2);
        openButton_2->setIconSize(QSize(60, 60));
        openButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(310, 10, 261, 131));
        openButton_3 = new QToolButton(groupBox_5);
        openButton_3->setObjectName(QStringLiteral("openButton_3"));
        openButton_3->setGeometry(QRect(10, 30, 81, 91));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/1476958047_player_record.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton_3->setIcon(icon3);
        openButton_3->setIconSize(QSize(60, 60));
        openButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 141, 131));
        xRange = new QDoubleSpinBox(groupBox);
        xRange->setObjectName(QStringLiteral("xRange"));
        xRange->setGeometry(QRect(70, 30, 62, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 41, 20));
        label->setLayoutDirection(Qt::LeftToRight);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 41, 20));
        label_2->setLayoutDirection(Qt::LeftToRight);
        yRange = new QDoubleSpinBox(groupBox);
        yRange->setObjectName(QStringLiteral("yRange"));
        yRange->setGeometry(QRect(70, 60, 62, 22));
        zRange = new QDoubleSpinBox(groupBox);
        zRange->setObjectName(QStringLiteral("zRange"));
        zRange->setGeometry(QRect(70, 90, 62, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 41, 20));
        label_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(170, 10, 141, 131));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 30, 111, 20));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 90, 111, 20));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 111, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 411, 131));
        newButton_3 = new QToolButton(groupBox_2);
        newButton_3->setObjectName(QStringLiteral("newButton_3"));
        newButton_3->setGeometry(QRect(280, 30, 81, 91));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/1476928535_sign-emergency-code-sos_50.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_3->setIcon(icon4);
        newButton_3->setIconSize(QSize(60, 60));
        newButton_3->setCheckable(true);
        newButton_3->setPopupMode(QToolButton::DelayedPopup);
        newButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_2 = new QToolButton(groupBox_2);
        newButton_2->setObjectName(QStringLiteral("newButton_2"));
        newButton_2->setGeometry(QRect(10, 30, 81, 91));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_2->setIcon(icon5);
        newButton_2->setIconSize(QSize(60, 60));
        newButton_2->setCheckable(true);
        newButton_2->setPopupMode(QToolButton::DelayedPopup);
        newButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_4 = new QToolButton(groupBox_2);
        newButton_4->setObjectName(QStringLiteral("newButton_4"));
        newButton_4->setGeometry(QRect(100, 30, 81, 91));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/3dfig.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_4->setIcon(icon6);
        newButton_4->setIconSize(QSize(60, 50));
        newButton_4->setCheckable(true);
        newButton_4->setPopupMode(QToolButton::DelayedPopup);
        newButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_5 = new QToolButton(groupBox_2);
        newButton_5->setObjectName(QStringLiteral("newButton_5"));
        newButton_5->setGeometry(QRect(190, 30, 81, 91));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/3dfig_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_5->setIcon(icon7);
        newButton_5->setIconSize(QSize(60, 50));
        newButton_5->setCheckable(true);
        newButton_5->setPopupMode(QToolButton::DelayedPopup);
        newButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabWidget->addTab(tab_3, QString());
        horizontalSlider_p = new QSlider(centralWidget);
        horizontalSlider_p->setObjectName(QStringLiteral("horizontalSlider_p"));
        horizontalSlider_p->setGeometry(QRect(20, 510, 160, 29));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 290, 191, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 470, 141, 31));
        label_5->setFont(font);
        lcdNumber_G = new QLCDNumber(centralWidget);
        lcdNumber_G->setObjectName(QStringLiteral("lcdNumber_G"));
        lcdNumber_G->setGeometry(QRect(190, 320, 81, 41));
        lcdNumber_G->setDigitCount(3);
        lcdNumber_G->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_G->setProperty("intValue", QVariant(128));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 210, 191, 31));
        label_6->setFont(font);
        horizontalSlider_R = new QSlider(centralWidget);
        horizontalSlider_R->setObjectName(QStringLiteral("horizontalSlider_R"));
        horizontalSlider_R->setGeometry(QRect(20, 250, 160, 29));
        horizontalSlider_R->setMaximum(255);
        horizontalSlider_R->setValue(128);
        horizontalSlider_R->setOrientation(Qt::Horizontal);
        horizontalSlider_G = new QSlider(centralWidget);
        horizontalSlider_G->setObjectName(QStringLiteral("horizontalSlider_G"));
        horizontalSlider_G->setGeometry(QRect(20, 330, 160, 29));
        horizontalSlider_G->setMaximum(255);
        horizontalSlider_G->setValue(128);
        horizontalSlider_G->setOrientation(Qt::Horizontal);
        pushButton_random = new QPushButton(centralWidget);
        pushButton_random->setObjectName(QStringLiteral("pushButton_random"));
        pushButton_random->setGeometry(QRect(30, 560, 201, 81));
        lcdNumber_B = new QLCDNumber(centralWidget);
        lcdNumber_B->setObjectName(QStringLiteral("lcdNumber_B"));
        lcdNumber_B->setGeometry(QRect(190, 400, 81, 41));
        lcdNumber_B->setDigitCount(3);
        lcdNumber_B->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_B->setProperty("intValue", QVariant(128));
        horizontalSlider_B = new QSlider(centralWidget);
        horizontalSlider_B->setObjectName(QStringLiteral("horizontalSlider_B"));
        horizontalSlider_B->setGeometry(QRect(20, 410, 160, 29));
        horizontalSlider_B->setMaximum(255);
        horizontalSlider_B->setValue(128);
        horizontalSlider_B->setOrientation(Qt::Horizontal);
        lcdNumber_p = new QLCDNumber(centralWidget);
        lcdNumber_p->setObjectName(QStringLiteral("lcdNumber_p"));
        lcdNumber_p->setGeometry(QRect(190, 500, 81, 41));
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));
        lcdNumber_R = new QLCDNumber(centralWidget);
        lcdNumber_R->setObjectName(QStringLiteral("lcdNumber_R"));
        lcdNumber_R->setGeometry(QRect(190, 240, 81, 41));
        lcdNumber_R->setDigitCount(3);
        lcdNumber_R->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_R->setProperty("intValue", QVariant(128));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 380, 191, 31));
        label_7->setFont(font);
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(290, 200, 640, 480));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 991, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionRange->setText(QApplication::translate("MainWindow", "Range", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Project", 0));
        newButton->setText(QApplication::translate("MainWindow", "New", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
        openButton_2->setText(QApplication::translate("MainWindow", "Save", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Figure", 0));
        openButton_3->setText(QApplication::translate("MainWindow", "Capture", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "File", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Range", 0));
        label->setText(QApplication::translate("MainWindow", "  X", 0));
        label_2->setText(QApplication::translate("MainWindow", "  Y", 0));
        label_3->setText(QApplication::translate("MainWindow", "  Z", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Geometry", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Background grid", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "Vertex points", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "Bounding box", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Parameters", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "3D Compositing", 0));
        newButton_3->setText(QApplication::translate("MainWindow", "Watertight", 0));
        newButton_2->setText(QApplication::translate("MainWindow", "Points", 0));
        newButton_4->setText(QApplication::translate("MainWindow", "Wireframe", 0));
        newButton_5->setText(QApplication::translate("MainWindow", "Flat lines", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Process", 0));
        label_4->setText(QApplication::translate("MainWindow", "Green component", 0));
        label_5->setText(QApplication::translate("MainWindow", "Point size", 0));
        label_6->setText(QApplication::translate("MainWindow", "Red component", 0));
        pushButton_random->setText(QApplication::translate("MainWindow", "Random colors", 0));
        label_7->setText(QApplication::translate("MainWindow", "Blue component", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
