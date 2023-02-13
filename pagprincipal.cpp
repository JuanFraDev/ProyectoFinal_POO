#include "pagprincipal.h"
#include "ui_pagprincipal.h"



PagPrincipal::PagPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PagPrincipal)
{
    ui->setupUi(this);
    getInfo();
}

PagPrincipal::~PagPrincipal()
{
    delete ui;
}

void PagPrincipal::getInfo()
{
    float m_ingresos = 0, m_egresos = 0;
    QFile ingres ("ingresos.csv");
    QFile egres ("egresos.csv");
    if(ingres.open(QFile::ReadOnly)){
        QTextStream entrada (&ingres);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            m_ingresos+=datos[2].toFloat();
        }
        ingres.close();
    }

    if(egres.open(QFile::ReadOnly)){
        QTextStream entrada (&egres);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            m_egresos+=datos[2].toFloat();
        }
        egres.close();
    }
    ui->ingreso_l->setText("$"+QString::number(m_ingresos));
    ui->egreso_l->setText("$"+QString::number(m_egresos));
}

void PagPrincipal::on_actionNuevo_miembro_triggered()
{
    Edit_users users;
    users.exec();

}


void PagPrincipal::on_actionNuevo_ingreso_triggered()
{
    MovIngreso ingre;
    ingre.cargar();
    ingre.exec();
}


void PagPrincipal::on_actionNuevo_egreso_triggered()
{
    MovEgreso egre;
    egre.cargar();
    egre.exec();
}


void PagPrincipal::on_actionNueva_categoria_triggered()
{
    Nueva_cate cat;
    cat.exec();
}


void PagPrincipal::on_action_Ver_Categor_as_triggered()
{
    Categorias cate;
    cate.exec();
}

void PagPrincipal::on_actionNuevo_reporte_triggered()
{
    Reporte r;
    r.exec();
}

void PagPrincipal::on_categorias_clicked()
{
    on_action_Ver_Categor_as_triggered();
}


void PagPrincipal::on_Miembros_clicked()
{
    on_actionNuevo_miembro_triggered();
}


void PagPrincipal::on_ingresos_clicked()
{
    on_actionNuevo_ingreso_triggered();
}


void PagPrincipal::on_Reporte_clicked()
{
    on_actionNuevo_reporte_triggered();
}


void PagPrincipal::on_egresos_clicked()
{
    on_actionNuevo_egreso_triggered();
}
