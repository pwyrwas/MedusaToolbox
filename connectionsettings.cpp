#include "connectionsettings.h"
#include "ui_connectionsettings.h"
#include <QXmlStreamWriter>

#define XMLFILENAME QString("settings.xml")

connectionSettings::connectionSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectionSettings)
{
    ui->setupUi(this);
    hostname = ui->hostName;
    dbName = ui->dbName;
}

connectionSettings::~connectionSettings()
{
    delete ui;
}

void connectionSettings::on_buttonBox_accepted()
{
    s_hostName = hostname->text();
    s_dbName = dbName->text();

    qDebug() << "Host name: " << s_hostName << "Database name:" << s_dbName;

    //check if xml file exist.
    if(checkConnectSettingFile())
    {
        qDebug() << "istnieje";
    }else{
        qDebug() << "nie istnieje";

        QFile file(XMLFILENAME);
        file.open(QIODevice::WriteOnly);

            QXmlStreamWriter xmlWriter(&file);
            xmlWriter.setAutoFormatting(true);
            xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("ConnectionSettings");
        xmlWriter.writeEndElement();
    }


}
bool connectionSettings::checkConnectSettingFile()
{
    //check if settings.xml are exist
    QFile file(XMLFILENAME);
    if(file.exists())
        return true;
    else
        return false;
}
