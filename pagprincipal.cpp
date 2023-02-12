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

void PagPrincipal::on_actionNuevo_miembro_triggered()
{
    Edit_users users;
    users.cargarDatos();
    users.exec();

}

