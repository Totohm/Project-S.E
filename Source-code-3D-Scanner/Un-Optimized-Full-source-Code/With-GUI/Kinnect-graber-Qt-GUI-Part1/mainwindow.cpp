#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newButton->setIcon(QIcon("qrc:/Ressources/1476926247_New.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::set_UI_Images(){

    ui->newButton->setIcon(QIcon("qrc:/Ressources/1476926247_New.png"));

}

