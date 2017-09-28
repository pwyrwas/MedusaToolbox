#include "medusatoolbox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MedusaToolbox w;
    w.show();

    return a.exec();
}
