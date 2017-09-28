#ifndef MEDUSATOOLBOX_H
#define MEDUSATOOLBOX_H

#include <QMainWindow>

namespace Ui {
class MedusaToolbox;
}

class MedusaToolbox : public QMainWindow
{
    Q_OBJECT

public:
    explicit MedusaToolbox(QWidget *parent = 0);
    ~MedusaToolbox();

private:
    Ui::MedusaToolbox *ui;
};

#endif // MEDUSATOOLBOX_H
