#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QDialog>
#include <medusatoolbox.h>
#include <QString>
#include <QLabel>
#include <QtSql>

namespace Ui {
class GeneralWindow;

}

class GeneralWindow : public QDialog
{
    Q_OBJECT

public:
    QString loggedAs;
    explicit GeneralWindow(QWidget *parent = 0);
    ~GeneralWindow();

private slots:

public slots:
    void sendDbInfo(QSqlDatabase db);

private:

    Ui::GeneralWindow *ui;
    QLabel * logAs;

};

#endif // GENERALWINDOW_H
