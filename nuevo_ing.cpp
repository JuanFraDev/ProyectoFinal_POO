#include "nuevo_ing.h"
#include "ui_nuevo_ing.h"

Nuevo_ing::Nuevo_ing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nuevo_ing)
{
    ui->setupUi(this);
    cargar();
}

Nuevo_ing::~Nuevo_ing()
{
    delete ui;
}

void Nuevo_ing::cargar()
{
    QFile archivo("miembros.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            datos.removeLast();
            datos.removeLast();
            linea = datos.at(0) + " " + datos.at(1);
            ui->inMiembro->addItem(linea);
        }
        archivo.close();
    }

    QFile archivoIngre("catIngreso.csv");
    if (archivoIngre.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivoIngre);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            datos.removeLast();
            linea = datos.at(0);
            ui->inCategoria->addItem(linea);
        }
        archivo.close();
    }
}

void Nuevo_ing::on_Cancelar_clicked()
{
    rejected();
    close();
}

void Nuevo_ing::on_Guardar_clicked()
{
    QString fecha = ui->inFecha->selectedDate().toString();
    QString miembro = ui->inMiembro->currentText();
    float monto = ui->inMonto->value();
    QString categoria = ui->inCategoria->currentText();
    Controlador controlador;
    controlador.guardarIngreso(fecha, miembro, monto, categoria);
    accept();
}

