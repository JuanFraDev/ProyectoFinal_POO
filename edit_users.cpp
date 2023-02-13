#include "edit_users.h"
#include "ui_edit_users.h"

Edit_users::Edit_users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_users)
{
    ui->setupUi(this);
    setWindowTitle("Registro de Usuarios");
    ui->tblUsuarios->setColumnCount(4);
    QStringList titulo;
    titulo << "Nombre" << "Apellido" << "Ingreso" << "Egreso";
    ui->tblUsuarios->setHorizontalHeaderLabels(titulo);
    cargarDatos();
}

Edit_users::~Edit_users()
{
    delete ui;
}

void Edit_users::cargarDatos()
{
    qDebug() << "Llega en edit usuario";
    ui->tblUsuarios->clearContents();
    ui->tblUsuarios->setRowCount(0);
    QFile archivo("miembros.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblUsuarios->rowCount();
            ui->tblUsuarios->insertRow(fila);
            ui->tblUsuarios->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblUsuarios->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
            ui->tblUsuarios->setItem(fila, INGRESO, new QTableWidgetItem(datos[INGRESO]));
            ui->tblUsuarios->setItem(fila, EGRESO, new QTableWidgetItem(datos[EGRESO]));
        }
        archivo.close();
    }
    qDebug() << "Final tabla";
}


void Edit_users::on_addUser_clicked()
{
    nuevoEditUser user(this);
    int res = user.exec();
    if (res == QDialog::Rejected){
        return;
    }
    ui->tblUsuarios->clearContents();
    ui->tblUsuarios->setRowCount(0);
    QFile archivo("miembros.csv");
    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            //Agregar a la tabla
            fila = ui->tblUsuarios->rowCount();
            ui->tblUsuarios->insertRow(fila);
            ui->tblUsuarios->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
            ui->tblUsuarios->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
            ui->tblUsuarios->setItem(fila, INGRESO, new QTableWidgetItem(datos[INGRESO]));
            ui->tblUsuarios->setItem(fila, EGRESO, new QTableWidgetItem(datos[EGRESO]));
        }
        archivo.close();
    }
}


void Edit_users::on_eliminarUser_clicked()
{
    QString nom, ape;
    float ing, egre;
    QList <QModelIndex> big = ui->tblUsuarios->selectionModel()->selectedRows();
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
        QTableWidgetItem *nombre = ui->tblUsuarios->item(x, NOMBRE);
        QTableWidgetItem *apellido = ui->tblUsuarios->item(x, APELLIDO);
        QTableWidgetItem *ingreso = ui->tblUsuarios->item(x, INGRESO);
        QTableWidgetItem *egreso = ui->tblUsuarios->item(x, EGRESO);
        nom = nombre->text();
        ape = apellido->text();
        ing = ingreso->text().toFloat();
        egre = egreso->text().toFloat();
        ui->tblUsuarios->removeRow(x);
    }

    int filas = ui->tblUsuarios->rowCount();
    // Abrir el archivo y guardar
    QString miembros = "ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/miembros.csv";
    QFileInfo infoFile(miembros);
    QFile archivo("miembros.csv");
    if (archivo.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblUsuarios->item(i, NOMBRE);
            QTableWidgetItem *apellido = ui->tblUsuarios->item(i, APELLIDO);
            QTableWidgetItem *ingreso = ui->tblUsuarios->item(i, INGRESO);
            QTableWidgetItem *egreso = ui->tblUsuarios->item(i, EGRESO);
            salida << nombre->text() << ";" << apellido->text() << ";";
            salida << ingreso->text() << ";" << egreso->text() << "\n";
        }
        Controlador contr;
        contr.eliminarMiembro(nom, ape, ing, egre);
        archivo.close();
    }


}

