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
    QString miembros = "ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/miembros.csv";
    QFileInfo infoFile(miembros);
    if(infoFile.exists()){
        ARCHIVO_MIEMBRO = infoFile.absoluteFilePath();
        QFile file(ARCHIVO_MIEMBRO);
        if(file.open(QIODevice::Append)){
            QTextStream salida(&file);
            QString nombre = ui->inNombre->text();
            QString apellido = ui->inApellido->text();
            salida << nombre  << ";" << apellido << ";" << 0 << ";" << 0 << "\n";
            file.close();
        }
    } else {
        QDir buildDir("ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug");
        QDir::setCurrent(buildDir.path());
        QFile file("miembros.csv");
        if(file.open(QIODevice::Append)){
            QTextStream salida(&file);
            QString nombre = ui->inNombre->text();
            QString apellido = ui->inApellido->text();
            salida << nombre  << ";" << apellido << ";" << 0 << ";" << 0 << "\n";
            file.close();
        }
    }
    accept();
}

const QString &nuevoEditUser::getARCHIVO_MIEMBRO() const
{
    return ARCHIVO_MIEMBRO;
}

