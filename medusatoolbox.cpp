#include "medusatoolbox.h"
#include "ui_medusatoolbox.h"

MedusaToolbox::MedusaToolbox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MedusaToolbox)
{
    ui->setupUi(this);
}

MedusaToolbox::~MedusaToolbox()
{
    delete ui;
}
