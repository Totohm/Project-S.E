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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionRange;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_4;
    QToolButton *newButton;
    QToolButton *openButton;
    QToolButton *saveButton;
    QGroupBox *groupBox_5;
    QToolButton *captureButton;
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
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider_R;
    QSlider *horizontalSlider_G;
    QSlider *horizontalSlider_B;
    QLabel *label_5;
    QLabel *label_4;
    QLCDNumber *lcdNumber_G;
    QLCDNumber *lcdNumber_B;
    QLabel *label_7;
    QLCDNumber *lcdNumber_p;
    QSlider *horizontalSlider_p;
    QLabel *label_6;
    QLCDNumber *lcdNumber_R;
    QPushButton *pushButton_random;
    QVTKWidget *qvtkWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(732, 565);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionRange = new QAction(MainWindow);
        actionRange->setObjectName(QStringLiteral("actionRange"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        newButton = new QToolButton(groupBox_4);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(10, 30, 81, 91));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy3);
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
        saveButton = new QToolButton(groupBox_4);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(190, 30, 81, 91));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/1476926747_floppy_disk_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon2);
        saveButton->setIconSize(QSize(60, 60));
        saveButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(groupBox_4);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        sizePolicy2.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy2);
        captureButton = new QToolButton(groupBox_5);
        captureButton->setObjectName(QStringLiteral("captureButton"));
        captureButton->setGeometry(QRect(10, 30, 81, 91));
        sizePolicy1.setHeightForWidth(captureButton->sizePolicy().hasHeightForWidth());
        captureButton->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/1476958047_player_record.png"), QSize(), QIcon::Normal, QIcon::Off);
        captureButton->setIcon(icon3);
        captureButton->setIconSize(QSize(60, 60));
        captureButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(groupBox_5);

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

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSlider_R = new QSlider(centralWidget);
        horizontalSlider_R->setObjectName(QStringLiteral("horizontalSlider_R"));
        sizePolicy2.setHeightForWidth(horizontalSlider_R->sizePolicy().hasHeightForWidth());
        horizontalSlider_R->setSizePolicy(sizePolicy2);
        horizontalSlider_R->setMaximum(255);
        horizontalSlider_R->setValue(128);
        horizontalSlider_R->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_R, 1, 0, 1, 1);

        horizontalSlider_G = new QSlider(centralWidget);
        horizontalSlider_G->setObjectName(QStringLiteral("horizontalSlider_G"));
        sizePolicy2.setHeightForWidth(horizontalSlider_G->sizePolicy().hasHeightForWidth());
        horizontalSlider_G->setSizePolicy(sizePolicy2);
        horizontalSlider_G->setMaximum(255);
        horizontalSlider_G->setValue(128);
        horizontalSlider_G->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_G, 3, 0, 1, 1);

        horizontalSlider_B = new QSlider(centralWidget);
        horizontalSlider_B->setObjectName(QStringLiteral("horizontalSlider_B"));
        sizePolicy2.setHeightForWidth(horizontalSlider_B->sizePolicy().hasHeightForWidth());
        horizontalSlider_B->setSizePolicy(sizePolicy2);
        horizontalSlider_B->setMaximum(255);
        horizontalSlider_B->setValue(128);
        horizontalSlider_B->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_B, 6, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lcdNumber_G = new QLCDNumber(centralWidget);
        lcdNumber_G->setObjectName(QStringLiteral("lcdNumber_G"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdNumber_G->sizePolicy().hasHeightForWidth());
        lcdNumber_G->setSizePolicy(sizePolicy4);
        lcdNumber_G->setDigitCount(3);
        lcdNumber_G->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_G->setProperty("intValue", QVariant(128));

        gridLayout->addWidget(lcdNumber_G, 3, 1, 1, 1);

        lcdNumber_B = new QLCDNumber(centralWidget);
        lcdNumber_B->setObjectName(QStringLiteral("lcdNumber_B"));
        sizePolicy4.setHeightForWidth(lcdNumber_B->sizePolicy().hasHeightForWidth());
        lcdNumber_B->setSizePolicy(sizePolicy4);
        lcdNumber_B->setDigitCount(3);
        lcdNumber_B->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_B->setProperty("intValue", QVariant(128));

        gridLayout->addWidget(lcdNumber_B, 6, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        lcdNumber_p = new QLCDNumber(centralWidget);
        lcdNumber_p->setObjectName(QStringLiteral("lcdNumber_p"));
        sizePolicy4.setHeightForWidth(lcdNumber_p->sizePolicy().hasHeightForWidth());
        lcdNumber_p->setSizePolicy(sizePolicy4);
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));

        gridLayout->addWidget(lcdNumber_p, 8, 1, 1, 1);

        horizontalSlider_p = new QSlider(centralWidget);
        horizontalSlider_p->setObjectName(QStringLiteral("horizontalSlider_p"));
        sizePolicy2.setHeightForWidth(horizontalSlider_p->sizePolicy().hasHeightForWidth());
        horizontalSlider_p->setSizePolicy(sizePolicy2);
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_p, 8, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lcdNumber_R = new QLCDNumber(centralWidget);
        lcdNumber_R->setObjectName(QStringLiteral("lcdNumber_R"));
        sizePolicy4.setHeightForWidth(lcdNumber_R->sizePolicy().hasHeightForWidth());
        lcdNumber_R->setSizePolicy(sizePolicy4);
        lcdNumber_R->setDigitCount(3);
        lcdNumber_R->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_R->setProperty("intValue", QVariant(128));

        gridLayout->addWidget(lcdNumber_R, 1, 1, 1, 1);

        pushButton_random = new QPushButton(centralWidget);
        pushButton_random->setObjectName(QStringLiteral("pushButton_random"));
        sizePolicy2.setHeightForWidth(pushButton_random->sizePolicy().hasHeightForWidth());
        pushButton_random->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_random, 9, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        sizePolicy2.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(qvtkWidget);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        label_5->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 732, 21));
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
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Figure", 0));
        captureButton->setText(QApplication::translate("MainWindow", "Capture", 0));
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
        label_5->setText(QApplication::translate("MainWindow", "Point size", 0));
        label_4->setText(QApplication::translate("MainWindow", "Green component", 0));
        label_7->setText(QApplication::translate("MainWindow", "Blue component", 0));
        label_6->setText(QApplication::translate("MainWindow", "Red component", 0));
        pushButton_random->setText(QApplication::translate("MainWindow", "Random colors", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
