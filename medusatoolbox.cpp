#include "medusatoolbox.h"
#include "ui_medusatoolbox.h"
#include <QThread>
#include <qapplication.h>



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
    //Tymczasowe !
    //_uName->setText("SYSDBA");
    //_pass->setText("orangepl");
    //
    _userName = _uName->text();
    _password = _pass->text();

    connectionStatus = connects(_userName,_password);
    if(connectionStatus)
    {

        const QString hostName = "localhost";
        const QString dbFileName = "C:/database.FDB";
        const QString userName = _userName;//"SYSDBA";
        const QString password = _password;"orangepl";

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

           //send login to second window (General window)
           connect(this, SIGNAL(sendDbInfo(QSqlDatabase)),gw,SLOT(sendDbInfo(QSqlDatabase)));
           gw->isWindowType();

           gw->show();
           emit sendDbInfo(db);
           hide();
       }
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
}
void MedusaToolbox::sendStatus()
{
    statusInfo->setText("wait");
}
bool MedusaToolbox::connects(QString username, QString password)
{
    return true;
}
