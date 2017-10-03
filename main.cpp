#include "medusatoolbox.h"
#include "generalwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MedusaToolbox w;
    GeneralWindow g;
    w.show();


    return a.exec();
}
