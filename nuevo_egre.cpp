#include "nuevo_egre.h"
#include "ui_nuevo_egre.h"

Nuevo_egre::Nuevo_egre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nuevo_egre)
{
    ui->setupUi(this);
    cargar();
}

Nuevo_egre::~Nuevo_egre()
{
    delete ui;
}

void Nuevo_egre::cargar()
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
    QFile archivoEgre("catEgreso.csv");
    if (archivoEgre.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivoEgre);
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

void Nuevo_egre::on_Cancelar_clicked()
{
    rejected();
    close();
}

void Nuevo_egre::setDatos(QString fecha, QString miembro, float monto, QString categoria)
{
    fecha = ui->inFecha->selectedDate().toString();
    miembro = ui->inMiembro->currentText();
    monto = ui->inMonto->value();
    categoria = ui->inCategoria->currentText();
}

void Nuevo_egre::on_Guardar_clicked()
{
    QString fecha = ui->inFecha->selectedDate().toString();
    QString miembro = ui->inMiembro->currentText();
    float monto = ui->inMonto->value();
    QString categoria = ui->inCategoria->currentText();
    Controlador controlador;
    controlador.guardarEgreso(fecha, miembro, monto, categoria);
    accept();
}

