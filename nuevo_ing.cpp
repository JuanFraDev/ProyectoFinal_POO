#include "nuevo_ing.h"
#include "ui_nuevo_ing.h"

Nuevo_ing::Nuevo_ing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nuevo_ing)
{
    ui->setupUi(this);
}

Nuevo_ing::~Nuevo_ing()
{
    delete ui;
}
