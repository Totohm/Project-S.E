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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QFrame *frame;
    QLabel *label_6;
    QFrame *frame_2;
    QLabel *label_5;
    QFrame *frame_3;
    QLabel *label_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(623, 632);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionRange = new QAction(MainWindow);
        actionRange->setObjectName(QStringLiteral("actionRange"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 601, 181));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 281, 131));
        newButton = new QToolButton(groupBox_4);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(10, 30, 81, 91));
        QIcon icon;
        icon.addFile(QStringLiteral("Ressources/1476926247_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);
        newButton->setIconSize(QSize(60, 60));
        newButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        openButton = new QToolButton(groupBox_4);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(100, 30, 81, 91));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Ressources/1476926622_Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        openButton->setIconSize(QSize(60, 60));
        openButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        openButton_2 = new QToolButton(groupBox_4);
        openButton_2->setObjectName(QStringLiteral("openButton_2"));
        openButton_2->setGeometry(QRect(190, 30, 81, 91));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Ressources/1476926747_floppy_disk_save.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        icon3.addFile(QStringLiteral("Ressources/1476958047_player_record.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        icon4.addFile(QStringLiteral("Ressources/1476928535_sign-emergency-code-sos_50.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_3->setIcon(icon4);
        newButton_3->setIconSize(QSize(60, 60));
        newButton_3->setCheckable(true);
        newButton_3->setPopupMode(QToolButton::DelayedPopup);
        newButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_2 = new QToolButton(groupBox_2);
        newButton_2->setObjectName(QStringLiteral("newButton_2"));
        newButton_2->setGeometry(QRect(10, 30, 81, 91));
        QIcon icon5;
        icon5.addFile(QStringLiteral("Ressources/1476928407_water3.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_2->setIcon(icon5);
        newButton_2->setIconSize(QSize(60, 60));
        newButton_2->setCheckable(true);
        newButton_2->setPopupMode(QToolButton::DelayedPopup);
        newButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_4 = new QToolButton(groupBox_2);
        newButton_4->setObjectName(QStringLiteral("newButton_4"));
        newButton_4->setGeometry(QRect(100, 30, 81, 91));
        QIcon icon6;
        icon6.addFile(QStringLiteral("Ressources/3dfig.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_4->setIcon(icon6);
        newButton_4->setIconSize(QSize(60, 50));
        newButton_4->setCheckable(true);
        newButton_4->setPopupMode(QToolButton::DelayedPopup);
        newButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        newButton_5 = new QToolButton(groupBox_2);
        newButton_5->setObjectName(QStringLiteral("newButton_5"));
        newButton_5->setGeometry(QRect(190, 30, 81, 91));
        QIcon icon7;
        icon7.addFile(QStringLiteral("Ressources/3dfig_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_5->setIcon(icon7);
        newButton_5->setIconSize(QSize(60, 50));
        newButton_5->setCheckable(true);
        newButton_5->setPopupMode(QToolButton::DelayedPopup);
        newButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tabWidget->addTab(tab_3, QString());
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 200, 371, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(130, 180, 111, 16));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(410, 200, 201, 171));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 80, 71, 16));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(410, 390, 201, 171));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 80, 121, 16));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 623, 20));
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
        label_6->setText(QApplication::translate("MainWindow", "3D Reconstruction", 0));
        label_5->setText(QApplication::translate("MainWindow", "RGB Camera", 0));
        label_4->setText(QApplication::translate("MainWindow", "Live PointClpud Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
