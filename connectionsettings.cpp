#include "connectionsettings.h"
#include "ui_connectionsettings.h"
#include <QXmlStreamWriter>

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

    QString filename = "test.xml";
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("LAMPS");
}
