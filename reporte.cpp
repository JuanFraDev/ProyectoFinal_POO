#include "reporte.h"
#include "ui_reporte.h"

Reporte::Reporte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reporte)
{
    ui->setupUi(this);
}

Reporte::~Reporte()
{
    delete ui;
}

void Reporte::generarR()
{
    QStringList miembros, monto, fecha, categoria;
    float ingresos=0, egresos=0;
    QString informe;
    informe.append("\n\t\t   REPORTE GENERADO\n");
    informe.append("\nFecha: \t\tMiembros: \tMonto: \tCategoría:\n\n");
    QFile registro_e("egresos.csv");
    if(registro_e.open(QFile::ReadOnly))
    {
        QTextStream salida(&registro_e);
        while(!salida.atEnd())
        {
            QString linea = salida.readLine();
            QStringList datos = linea.split(";");
            miembros << datos[1];
            monto << datos[2];
            fecha << datos[0];
            categoria << datos[3];
        }
        registro_e.close();
    }
    QStringList miembros2, monto2, fecha2, categoria2;
    QFile registro_i("ingresos.csv");
    if(registro_i.open(QFile::ReadOnly))
    {
        QTextStream salida(&registro_i);
        while(!salida.atEnd())
        {
            QString linea = salida.readLine();
            QStringList datos = linea.split(";");
            miembros2 << datos[1];
            monto2 << datos[2];
            fecha2 << datos[0];
            categoria2 << datos[3];
        }
        registro_i.close();
    }
    for(int i=0; i<miembros.size(); i++){
        egresos+=monto[i].toFloat();
        informe.append(fecha[i]+"\t"+miembros[i]+"\t"+"\t $"+monto[i]+"\t"+categoria[i]+"\n");
    }
    for(int i=0; i<miembros2.size(); i++){
        ingresos+=monto2[i].toFloat();
        informe.append(fecha2[i]+"\t"+miembros2[i]+"\t"+"\t $"+monto2[i]+"\t"+categoria2[i]+"\n");
    }
    informe.append("\n\nINGRESOS TOTALES: $"+QString::number(ingresos));
    informe.append("\nEGRESOS TOTALES: $"+QString::number(egresos));
    ui->reporte->appendPlainText(informe);

}

void Reporte::on_generar_clicked()
{
    generarR();
}


void Reporte::on_descargar_clicked()
{
    if(ui->reporte->toPlainText() == ""){
        QMessageBox adv;
        adv.setIcon(QMessageBox::Warning);
        adv.setWindowTitle("Exportar Reporte");
        adv.setText("No hay información que exportar");
        adv.exec();
        return;
    }
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar reporte",
                                                         QDir::home().absolutePath() + "/reporte.txt",
                                                         "Archivos .txt (*.txt)");
    QFile archivo(nombreArchivo);
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream salida(&archivo);
        salida << ui->reporte->toPlainText();
        archivo.close();
        QMessageBox adv;
        adv.setIcon(QMessageBox::Information);
        adv.setWindowTitle("Exportar Reporte");
        adv.setText("El informe ha sido exportado con éxito");
        adv.exec();
    }else{
        QMessageBox adv;
        adv.setIcon(QMessageBox::Information);
        adv.setWindowTitle("Exportar Reporte");
        adv.setText("El informe no ha podido ser exportado");
        adv.exec();
    }
}


void Reporte::on_cancelar_clicked()
{
    reject();
}
