#include "movegreso.h"
#include "ui_movegreso.h"

MovEgreso::MovEgreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovEgreso)
{
    ui->setupUi(this);
    setWindowTitle("Registro de Egresos");
    ui->movEgresos->setColumnCount(4);
    QStringList titulo;
    titulo << "Fecha" << "Miembro" << "Monto" << "Categoria";
    ui->movEgresos->setHorizontalHeaderLabels(titulo);
    cargar();
}

MovEgreso::~MovEgreso()
{
    delete ui;
}

void MovEgreso::cargar()
{
    ui->movEgresos->clearContents();
    ui->movEgresos->setRowCount(0);
    QFile archivo("egresos.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->movEgresos->rowCount();
            ui->movEgresos->insertRow(fila);
            ui->movEgresos->setItem(fila, FECHA, new QTableWidgetItem(datos[FECHA]));
            ui->movEgresos->setItem(fila, MIEMBRO, new QTableWidgetItem(datos[MIEMBRO]));
            ui->movEgresos->setItem(fila, MONTO, new QTableWidgetItem(datos[MONTO]));
            ui->movEgresos->setItem(fila, CATEGORIA, new QTableWidgetItem(datos[CATEGORIA]));
        }
        archivo.close();
    }
}

void MovEgreso::on_nuevo_egre_clicked()
{
    Nuevo_egre egre(this);
    int res = egre.exec();
    if (res == QDialog::Rejected){
        return;
    }
    ui->movEgresos->clearContents();
    ui->movEgresos->setRowCount(0);
    QFile archivo("egresos.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->movEgresos->rowCount();
            ui->movEgresos->insertRow(fila);
            ui->movEgresos->setItem(fila, FECHA, new QTableWidgetItem(datos[FECHA]));
            ui->movEgresos->setItem(fila, MIEMBRO, new QTableWidgetItem(datos[MIEMBRO]));
            ui->movEgresos->setItem(fila, MONTO, new QTableWidgetItem(datos[MONTO]));
            ui->movEgresos->setItem(fila, CATEGORIA, new QTableWidgetItem(datos[CATEGORIA]));
        }
        archivo.close();
    }
}

void MovEgreso::on_eliminar_egre_clicked()
{
    QString fch, mim, cate;
    float mon;
    QList <QModelIndex> big = ui->movEgresos->selectionModel()->selectedRows();
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
        QTableWidgetItem *fecha = ui->movEgresos->item(x, FECHA);
        QTableWidgetItem *miembro = ui->movEgresos->item(x, MIEMBRO);
        QTableWidgetItem *monto = ui->movEgresos->item(x, MONTO);
        QTableWidgetItem *categoria = ui->movEgresos->item(x, CATEGORIA);
        fch = fecha->text();
        mim = miembro->text();
        mon = monto->text().toFloat();
        cate = categoria->text();
        ui->movEgresos->removeRow(x);
    }

    int filas = ui->movEgresos->rowCount();
    // Abrir el archivo y guardar
    QFile archivo("egresos.csv");
    if (archivo.open(QFile::WriteOnly | QFile::Text)) {
        archivo.seek(0);
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *fecha = ui->movEgresos->item(i, FECHA);
            QTableWidgetItem *miembro = ui->movEgresos->item(i, MIEMBRO);
            QTableWidgetItem *monto = ui->movEgresos->item(i, MONTO);
            QTableWidgetItem *categoria = ui->movEgresos->item(i, CATEGORIA);
            salida << fecha->text() << ";" << miembro->text() << ";";
            salida << monto->text() << ";" << categoria->text() << "\n";

        }
        Controlador cr;
        cr.eliminarEgreso(fch, mim, mon, cate);
        archivo.close();
    }
}

