#ifndef REPORTE_H
#define REPORTE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class Reporte;
}

class Reporte : public QDialog
{
    Q_OBJECT

public:
    explicit Reporte(QWidget *parent = nullptr);
    ~Reporte();
    void generarR();

private slots:
    void on_generar_clicked();

    void on_descargar_clicked();

    void on_cancelar_clicked();

private:
    Ui::Reporte *ui;
};

#endif // REPORTE_H
