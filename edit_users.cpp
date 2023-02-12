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
}

Edit_users::~Edit_users()
{
    delete ui;
}

void Edit_users::cargarDatos()
{
    QString miembros = "ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/miembros.csv";
    QFileInfo infoFile(miembros);
    if(infoFile.exists()){
        //nuevoEditUser user(this);
        QFile archivo(infoFile.absoluteFilePath());
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
    QFile archivo(user.getARCHIVO_MIEMBRO());
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
        ui->tblUsuarios->removeRow(x);
    }

    int filas = ui->tblUsuarios->rowCount();
    if (filas == 0){
        QMessageBox::warning(this,"Advertencia","Tabla sin datos para guardar");
        return;
    } else {
        // Abrir el archivo y guardar
        QString miembros = "ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/miembros.csv";
        QFileInfo infoFile(miembros);
        QFile archivo(infoFile.absoluteFilePath());
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
            archivo.close();
        }
    }

}


void Edit_users::on_editUser_clicked()
{
    //    int cont=0;
    //    QList<QModelIndex>seleccion = ui->tblUsuarios->selectionModel()->selectedRows();

    //    if(seleccion.isEmpty()){
    //        QMessageBox::information(this,"Editar","Por favor, seleccione la fila que desea editar");
    //        return;
    //    }

    //    QList<QModelIndex>::iterator i;

    //    for (auto &&i : seleccion){
    //        cont++;
    //    }

    //    if(cont>1){
    //        QMessageBox::information(this,"Seleccion","Seleccione unicamente una fila");
    //        return;
    //    }

    //    int row = ui->tblUsuarios->currentRow();

    //    QTableWidgetItem *nombre = ui->tblUsuarios->item(row, NOMBRE);
    //    QTableWidgetItem *apellido = ui->tblUsuarios->item(row, APELLIDO);

    //    nuevoEditUser neu(this);
    //    neu.setWindowTitle("Editar Miembro");

    //    neu.setDatos(nombre->text(), apellido->text());

    //    int res = neu.exec();
    //    if (res == QDialog::Rejected){
    //        return;
    //    }
    //    // Recuperar el objeto del cuadro de dialogo
    //    QFile archivo(neu.getARCHIVO_MIEMBRO());
    //    if (archivo.open(QFile::ReadOnly)) {
    //        QTextStream entrada(&archivo);
    //        int fila;
    //        while(!entrada.atEnd()){
    //            QString linea = entrada.readLine();
    //            QStringList datos = linea.split(";");
    //            //Agregar a la tabla
    //            fila = ui->tblUsuarios->rowCount();
    //            ui->tblUsuarios->insertRow(fila);
    //            ui->tblUsuarios->setItem(fila, NOMBRE, new QTableWidgetItem(datos[NOMBRE]));
    //            ui->tblUsuarios->setItem(fila, APELLIDO, new QTableWidgetItem(datos[APELLIDO]));
    //        }
    //        archivo.close();
    //    }
}

