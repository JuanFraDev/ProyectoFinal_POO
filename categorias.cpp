#include "categorias.h"
#include "ui_categorias.h"

Categorias::Categorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorias)
{
    ui->setupUi(this);
    setWindowTitle("Categorías");
    ui->tblCate->setColumnCount(2);
    QStringList titulo;
    titulo << "Nombre" << "Tipo";
    ui->tblCate->setHorizontalHeaderLabels(titulo);
    cargar();
}

Categorias::~Categorias()
{
    delete ui;
}

void Categorias::cargar()
{
    ui->tblCate->clearContents();
    ui->tblCate->setRowCount(0);
    QFile archivo("catIngreso.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblCate->rowCount();
            ui->tblCate->insertRow(fila);
            ui->tblCate->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblCate->setItem(fila, TIPO, new QTableWidgetItem(datos[TIPO]));
        }
        archivo.close();
    }
    QFile archivo2("catEgreso.csv");
    if (archivo2.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo2);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblCate->rowCount();
            ui->tblCate->insertRow(fila);
            ui->tblCate->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblCate->setItem(fila, TIPO, new QTableWidgetItem(datos[TIPO]));
        }
        archivo.close();
    }
}

void Categorias::on_nuevo_cate_clicked()
{
    Nueva_cate n;
    n.exec();
    cargar();
}


void Categorias::on_eliminar_cate_clicked()
{
    QString nom, tip;
    QList <QModelIndex> big = ui->tblCate->selectionModel()->selectedRows();
    if(big.isEmpty()){
        QMessageBox::information(this,"Eliminacion","Seleccione una fila para poder eliminarla");
        return;
    }

    QList<int> list;
    QList <int> :: iterator x;
    QList<QModelIndex>::iterator i;

    for (auto &&i : big){
        list.append(i.row());
    }
    for (auto &&x : list){
        QTableWidgetItem *nombre = ui->tblCate->item(x, NOMBRE);
        QTableWidgetItem *tipo = ui->tblCate->item(x, TIPO);

        nom = nombre->text();
        tip = tipo->text();
        ui->tblCate->removeRow(x);
    }

    int filas = ui->tblCate->rowCount();

    // Abrir el archivo y guardar
    QFile archivo("catIngreso.csv");
    if (archivo.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblCate->item(i, NOMBRE);
            QTableWidgetItem *tipo = ui->tblCate->item(i, TIPO);
            salida << nombre->text() << ";" << tipo->text() << "\n";
        }
        archivo.close();
    }
    // Abrir el archivo y guardar
    QFile archivo2("catEgreso.csv");
    if (archivo.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream salida(&archivo2);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblCate->item(i, NOMBRE);
            QTableWidgetItem *tipo = ui->tblCate->item(i, TIPO);
            salida << nombre->text() << ";" << tipo->text() << "\n";
        }
        archivo.close();
    }
}

