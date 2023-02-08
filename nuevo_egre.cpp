#include "nuevo_egre.h"
#include "ui_nuevo_egre.h"

Nuevo_egre::Nuevo_egre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nuevo_egre)
{
    ui->setupUi(this);
}

Nuevo_egre::~Nuevo_egre()
{
    delete ui;
}
