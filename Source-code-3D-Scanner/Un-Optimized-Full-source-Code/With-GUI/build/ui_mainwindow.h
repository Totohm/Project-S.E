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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
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
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionStart_capture;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QToolButton *newButton_3;
    QWidget *widget_2;
    QToolButton *newButton_2;
    QWidget *widget_3;
    QToolButton *newButton_4;
    QWidget *widget_4;
    QToolButton *newButton_5;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_8;
    QGroupBox *groupBox_5;
    QDoubleSpinBox *xRange_3;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *yRange_3;
    QDoubleSpinBox *zRange_3;
    QLabel *label_9;
    QGroupBox *groupBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(702, 643);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(176, 176, 176, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(95, 95, 95, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MainWindow->setPalette(palette);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/1476926247_New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/1476926622_Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/1476926747_floppy_disk_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionStart_capture = new QAction(MainWindow);
        actionStart_capture->setObjectName(QStringLiteral("actionStart_capture"));
        actionStart_capture->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/1476958047_player_record.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_capture->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        qvtkWidget = new QVTKWidget(widget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(qvtkWidget);


        verticalLayout->addWidget(widget);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 702, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_5 = new QWidget(dockWidgetContents);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        newButton_3 = new QToolButton(widget_5);
        newButton_3->setObjectName(QStringLiteral("newButton_3"));
        newButton_3->setGeometry(QRect(10, 10, 81, 91));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newButton_3->sizePolicy().hasHeightForWidth());
        newButton_3->setSizePolicy(sizePolicy1);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/1476928535_sign-emergency-code-sos_50.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_3->setIcon(icon4);
        newButton_3->setIconSize(QSize(60, 60));
        newButton_3->setCheckable(true);
        newButton_3->setPopupMode(QToolButton::DelayedPopup);
        newButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_5);

        widget_2 = new QWidget(dockWidgetContents);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        newButton_2 = new QToolButton(widget_2);
        newButton_2->setObjectName(QStringLiteral("newButton_2"));
        newButton_2->setGeometry(QRect(10, 10, 81, 91));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_2->setIcon(icon5);
        newButton_2->setIconSize(QSize(60, 60));
        newButton_2->setCheckable(true);
        newButton_2->setPopupMode(QToolButton::DelayedPopup);
        newButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_2);

        widget_3 = new QWidget(dockWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        newButton_4 = new QToolButton(widget_3);
        newButton_4->setObjectName(QStringLiteral("newButton_4"));
        newButton_4->setGeometry(QRect(10, 10, 81, 91));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/3dfig.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_4->setIcon(icon6);
        newButton_4->setIconSize(QSize(60, 50));
        newButton_4->setCheckable(true);
        newButton_4->setPopupMode(QToolButton::DelayedPopup);
        newButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(dockWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        newButton_5 = new QToolButton(widget_4);
        newButton_5->setObjectName(QStringLiteral("newButton_5"));
        newButton_5->setGeometry(QRect(10, 10, 81, 91));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/3dfig_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton_5->setIcon(icon7);
        newButton_5->setIconSize(QSize(60, 50));
        newButton_5->setCheckable(true);
        newButton_5->setPopupMode(QToolButton::DelayedPopup);
        newButton_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(widget_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        groupBox_5 = new QGroupBox(dockWidgetContents_8);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 0, 281, 61));
        xRange_3 = new QDoubleSpinBox(groupBox_5);
        xRange_3->setObjectName(QStringLiteral("xRange_3"));
        xRange_3->setGeometry(QRect(30, 30, 62, 22));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 21, 20));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 30, 21, 20));
        label_8->setLayoutDirection(Qt::LeftToRight);
        yRange_3 = new QDoubleSpinBox(groupBox_5);
        yRange_3->setObjectName(QStringLiteral("yRange_3"));
        yRange_3->setGeometry(QRect(120, 30, 62, 22));
        zRange_3 = new QDoubleSpinBox(groupBox_5);
        zRange_3->setObjectName(QStringLiteral("zRange_3"));
        zRange_3->setGeometry(QRect(210, 30, 62, 22));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 30, 21, 20));
        label_9->setLayoutDirection(Qt::LeftToRight);
        groupBox_6 = new QGroupBox(dockWidgetContents_8);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(300, 0, 311, 61));
        checkBox_7 = new QCheckBox(groupBox_6);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setGeometry(QRect(10, 30, 101, 20));
        checkBox_8 = new QCheckBox(groupBox_6);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));
        checkBox_8->setGeometry(QRect(220, 30, 111, 20));
        checkBox_9 = new QCheckBox(groupBox_6);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));
        checkBox_9->setGeometry(QRect(120, 30, 91, 20));
        dockWidget_4->setWidget(dockWidgetContents_8);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_4);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionStart_capture);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create new model", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open external model", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current model", 0));
#endif // QT_NO_TOOLTIP
        actionStart_capture->setText(QApplication::translate("MainWindow", "Start capture", 0));
#ifndef QT_NO_TOOLTIP
        actionStart_capture->setToolTip(QApplication::translate("MainWindow", "Starts capturing from Kinect", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        newButton_3->setText(QApplication::translate("MainWindow", "Watertight", 0));
        newButton_2->setText(QApplication::translate("MainWindow", "Points", 0));
        newButton_4->setText(QApplication::translate("MainWindow", "Wireframe", 0));
        newButton_5->setText(QApplication::translate("MainWindow", "Flat lines", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Depth range", 0));
        label_7->setText(QApplication::translate("MainWindow", "  X", 0));
        label_8->setText(QApplication::translate("MainWindow", "  Y", 0));
        label_9->setText(QApplication::translate("MainWindow", "  Z", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Geometry", 0));
        checkBox_7->setText(QApplication::translate("MainWindow", "Background grid", 0));
        checkBox_8->setText(QApplication::translate("MainWindow", "Vertex points", 0));
        checkBox_9->setText(QApplication::translate("MainWindow", "Bounding box", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
