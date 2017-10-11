#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H

#include <QDialog>
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include <QFile>


namespace Ui {
class connectionSettings;
}

class connectionSettings : public QDialog
{
    Q_OBJECT

public:
    explicit connectionSettings(QWidget *parent = 0);
    ~connectionSettings();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::connectionSettings *ui;
    QLineEdit *hostname;
    QLineEdit *dbName;
    QString s_hostName;
    QString s_dbName;

    bool checkConnectSettingFile();

};

#endif // CONNECTIONSETTINGS_H
