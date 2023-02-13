#ifndef NUEVO_EGRE_H
#define NUEVO_EGRE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <controlador.h>

namespace Ui {
class Nuevo_egre;
}

class Nuevo_egre : public QDialog
{
    Q_OBJECT

public:
    explicit Nuevo_egre(QWidget *parent = nullptr);
    ~Nuevo_egre();
    void setDatos(QString fecha, QString miembro, float monto, QString categoria);
    void cargar();

private slots:
    void on_Cancelar_clicked();

    void on_Guardar_clicked();

private:
    Ui::Nuevo_egre *ui;
};

#endif // NUEVO_EGRE_H
