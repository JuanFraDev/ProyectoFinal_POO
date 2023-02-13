#include "nueva_cate.h"
#include "ui_nueva_cate.h"

Nueva_cate::Nueva_cate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nueva_cate)
{
    ui->setupUi(this);
    QStringList categorias;
    categorias << "Egreso" << "Ingreso";
    ui->inTipo_cate->addItems(categorias);
}

Nueva_cate::~Nueva_cate()
{
    delete ui;
}

void Nueva_cate::on_Guardar_clicked()
{
    QString cate = ui->inTipo_cate->currentText();
    QString nombre = ui->inNew_cate->text();
    Controlador contr;
    contr.guardarCategoria(cate, nombre);
    accept();
}


void Nueva_cate::on_Cancelar_clicked()
{
    rejected();
    close();
}

