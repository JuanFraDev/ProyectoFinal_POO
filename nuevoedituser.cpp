#include "nuevoedituser.h"
#include "ui_nuevoedituser.h"

nuevoEditUser::nuevoEditUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoEditUser)
{
    ui->setupUi(this);
}

nuevoEditUser::~nuevoEditUser()
{
    delete ui;
}

void nuevoEditUser::setDatos(QString nombre, QString apellido)
{
    ui->inNombre->setText(nombre);
    ui->inApellido->setText(apellido);
}

void nuevoEditUser::on_Guardar_clicked()
{
        QFile file("miembros.csv");
        if(file.open(QIODevice::Append)){
            QTextStream salida(&file);
            QString nombre = ui->inNombre->text();
            QString apellido = ui->inApellido->text();
            salida << nombre  << ";" << apellido << ";" << 0 << ";" << 0 << "\n";
            file.close();
        }
    accept();
}

const QString &nuevoEditUser::getARCHIVO_MIEMBRO() const
{
    return ARCHIVO_MIEMBRO;
}


void nuevoEditUser::on_Cancelar_clicked()
{
    rejected();
    close();
}

