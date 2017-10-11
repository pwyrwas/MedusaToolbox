#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logAs = ui->user;

    // qDebug() << "Database last error:" << db.lastError().text();
    /*
    QSqlQuery query = QSqlQuery(db);
    QString queryString = "SELECT a.NICKNAME FROM PEOPLE a WHERE a.ID = '1'";
    query.prepare(queryString);
    query.exec();
    query.next();
    QString result = query.value(0).toString();
    qDebug() << "Query result: " << result;
    qDebug() << "query last error:" <<query.lastError().text();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sendDbInfo(QSqlDatabase db)
{
    logAs->setText(db.userName());  // recive username from medusaToolbox window
}
