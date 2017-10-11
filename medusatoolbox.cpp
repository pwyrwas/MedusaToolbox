#include "medusatoolbox.h"
#include "ui_medusatoolbox.h"
#include <QThread>
#include <qapplication.h>

#define XMLFILENAME QString("settings.xml")

MedusaToolbox::MedusaToolbox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedusaToolbox)
{
    ui->setupUi(this);
    //this->statusBar()->setSizeGripEnabled(false);

    _login = ui->logIn;
    _uName = ui->userName;
    _pass = ui->password;
    _pass->setEchoMode(QLineEdit::Password);
    _pass->setInputMethodHints(Qt::ImhHiddenText | Qt::ImhNoPredictiveText | Qt::ImhNoAutoUppercase);
    statusInfo = ui->statusInfo;
}

MedusaToolbox::~MedusaToolbox()
{
    delete ui;
}
void MedusaToolbox::on_logIn_clicked()
{
    QFile file(XMLFILENAME);
    if(file.exists())
    {
        qDebug() << "settings.xml istnieje!";
        //connectionStatus = connects(_userName,_password);
        //if(true) //connection was in this place
        //{
            logInProcces();
       // }
    }

}
void MedusaToolbox::sendStatus()
{
    statusInfo->setText("wait");
}
//bool MedusaToolbox::connects(QString username, QString password)
//{
//    return true;
//}
bool MedusaToolbox::logInProcces()
{
    //Tymczasowe !
    //_uName->setText("SYSDBA");
    //_pass->setText("orangepl");
    //

    _userName = _uName->text();
    _password = _pass->text();

    const QString hostName = "localhost";
    const QString dbFileName = "C:/database.FDB";
    const QString userName = _userName;//"SYSDBA";
    const QString password = _password;//"orangepl";

    QSqlDatabase db = QSqlDatabase::addDatabase("QIBASE","soct");
    if (!db.isValid())
        qDebug() << "The data base isn't valid";
    else
        qDebug() << "The data base is valid";

   //db.setHostName(hostName);
   db.setDatabaseName(dbFileName);
   db.setUserName(userName);
   db.setPassword(password);
   QString  text = "Wait";
    //connect(ui->logIn,SIGNAL(clicked()),this,SLOT(sendStatus()));
   statusInfo->setText("Wait!");
   if(!db.open())
   {
       statusInfo->setText(db.lastError().text());
       statusInfo->setStyleSheet("font-weight: bold; color: red");
       qApp->processEvents();
       QThread::msleep(1000);
   }else
   {
       statusInfo->setText("Succesful!");
       statusInfo->setStyleSheet("font-weight: bold; color: green");
       qApp->processEvents();
       QThread::msleep(1000);

       MainWindow *gw = new MainWindow();
       //gw->

       //send login to second window (General window)
       connect(this, SIGNAL(sendDbInfo(QSqlDatabase)),gw,SLOT(sendDbInfo(QSqlDatabase)));
       gw->isWindowType();

       gw->show();
       emit sendDbInfo(db);
       hide();
   }
return true;
}
void MedusaToolbox::on_actionconnection_settings_triggered()
{
     qDebug()<<"Okno konfiguracji";
     cs = new connectionSettings(this);
     cs->setModal(true);
     cs->show();

}

