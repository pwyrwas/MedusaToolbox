#include "generalwindow.h"
#include "ui_generalwindow.h"
#include "medusatoolbox.h"

GeneralWindow::GeneralWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralWindow)
{
    ui->setupUi(this);
    logAs = ui->user;
   // connect(ui, SIGNAL(),this, SLOT(onLoginButtonPresed(QString)));
}

GeneralWindow::~GeneralWindow()
{
    delete ui;
}
void GeneralWindow::sendDbInfo(QSqlDatabase db)
{
    logAs->setText(db.userName()); // recive username from medusaToolbox window
}


