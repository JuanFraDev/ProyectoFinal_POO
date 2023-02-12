#include "movingreso.h"
#include "ui_movingreso.h"

MovIngreso::MovIngreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovIngreso)
{
    ui->setupUi(this);
}

MovIngreso::~MovIngreso()
{
    delete ui;
}
