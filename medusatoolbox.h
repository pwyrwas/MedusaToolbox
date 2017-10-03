#ifndef MEDUSATOOLBOX_H
#define MEDUSATOOLBOX_H

#include <generalwindow.h>
#include <mainwindow.h>
#include <QMainWindow>
#include <QtSql>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>


namespace Ui {
class MedusaToolbox;
}

class MedusaToolbox : public QMainWindow {
    Q_OBJECT

public:
    explicit MedusaToolbox(QWidget *parent = 0);
    ~MedusaToolbox();


private slots:
    void on_logIn_clicked();
    //void onLoginPressed(QString text);

public slots:
    void sendStatus();

signals:
    void sendDbInfo(QSqlDatabase db);

private:
    bool connects(QString username, QString password);
    void sendUserName();

    Ui::MedusaToolbox *ui;
    QPushButton *_login;
    QLineEdit *_uName;
    QLineEdit *_pass;

    QString _userName;
    QString _password;

    QLabel *statusInfo;

    bool connectionStatus;



};

#endif // MEDUSATOOLBOX_H
