#include "movingreso.h"
#include "ui_movingreso.h"

MovIngreso::MovIngreso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MovIngreso)
{
    ui->setupUi(this);
    setWindowTitle("Registro de Ingresos");
    ui->movIngresos->setColumnCount(4);
    QStringList titulo;
    titulo << "Fecha" << "Miembro" << "Monto" << "Categoria";
    ui->movIngresos->setHorizontalHeaderLabels(titulo);
    cargar();
}

MovIngreso::~MovIngreso()
{
    delete ui;
}

void MovIngreso::cargar()
{
    ui->movIngresos->clearContents();
    ui->movIngresos->setRowCount(0);
    QFile archivo("ingresos.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->movIngresos->rowCount();
            ui->movIngresos->insertRow(fila);
            ui->movIngresos->setItem(fila, FECHA, new QTableWidgetItem(datos[FECHA]));
            ui->movIngresos->setItem(fila, MIEMBRO, new QTableWidgetItem(datos[MIEMBRO]));
            ui->movIngresos->setItem(fila, MONTO, new QTableWidgetItem(datos[MONTO]));
            ui->movIngresos->setItem(fila, CATEGORIA, new QTableWidgetItem(datos[CATEGORIA]));
        }
        archivo.close();
    }
}




void MovIngreso::on_nuevo_ingre_clicked()
{
    Nuevo_ing ing(this);
    int res = ing.exec();
    if (res == QDialog::Rejected){
        return;
    }
    ui->movIngresos->clearContents();
    ui->movIngresos->setRowCount(0);
    QFile archivo("ingresos.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->movIngresos->rowCount();
            ui->movIngresos->insertRow(fila);
            ui->movIngresos->setItem(fila, FECHA, new QTableWidgetItem(datos[FECHA]));
            ui->movIngresos->setItem(fila, MIEMBRO, new QTableWidgetItem(datos[MIEMBRO]));
            ui->movIngresos->setItem(fila, MONTO, new QTableWidgetItem(datos[MONTO]));
            ui->movIngresos->setItem(fila, CATEGORIA, new QTableWidgetItem(datos[CATEGORIA]));
        }
        archivo.close();
    }
}

void MovIngreso::on_eliminar_ingre_clicked()
{
    QString fch, mim, cate;
    float mon;
    QList <QModelIndex> big = ui->movIngresos->selectionModel()->selectedRows();
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
        QTableWidgetItem *fecha = ui->movIngresos->item(x, FECHA);
        QTableWidgetItem *miembro = ui->movIngresos->item(x, MIEMBRO);
        QTableWidgetItem *monto = ui->movIngresos->item(x, MONTO);
        QTableWidgetItem *categoria = ui->movIngresos->item(x, CATEGORIA);
        fch = fecha->text();
        mim = miembro->text();
        mon = monto->text().toFloat();
        cate = categoria->text();
        ui->movIngresos->removeRow(x);
    }

    int filas = ui->movIngresos->rowCount();

    // Abrir el archivo y guardar
    QFile archivo("ingresos.csv");
    if (archivo.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *fecha = ui->movIngresos->item(i, FECHA);
            QTableWidgetItem *miembro = ui->movIngresos->item(i, MIEMBRO);
            QTableWidgetItem *monto = ui->movIngresos->item(i, MONTO);
            QTableWidgetItem *categoria = ui->movIngresos->item(i, CATEGORIA);
            salida << fecha->text() << ";" << miembro->text() << ";";
            salida << monto->text() << ";" << categoria->text() << "\n";
        }
        Controlador cr;
        cr.eliminarIngreso(fch, mim, mon, cate);
        archivo.close();
    }

}


