#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logAs = ui->user;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sendDbInfo(QSqlDatabase db)
{
    logAs->setText(db.userName());  // recive username from medusaToolbox window
}
