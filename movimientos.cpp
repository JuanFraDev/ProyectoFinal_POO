#include "movimientos.h"
#include "ui_movimientos.h"

Movimientos::Movimientos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Movimientos)
{
    ui->setupUi(this);
}

Movimientos::~Movimientos()
{
    delete ui;
}
