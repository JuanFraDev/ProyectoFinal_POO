#include "pagprincipal.h"
#include "ui_pagprincipal.h"

PagPrincipal::PagPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagPrincipal)
{
    ui->setupUi(this);
}

PagPrincipal::~PagPrincipal()
{
    delete ui;
}
