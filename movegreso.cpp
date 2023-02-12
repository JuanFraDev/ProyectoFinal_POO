#include "movegreso.h"
#include "ui_movegreso.h"

MovEgreso::MovEgreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovEgreso)
{
    ui->setupUi(this);
}

MovEgreso::~MovEgreso()
{
    delete ui;
}
