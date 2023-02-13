#ifndef NUEVO_ING_H
#define NUEVO_ING_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <controlador.h>

namespace Ui {
class Nuevo_ing;
}

class Nuevo_ing : public QDialog
{
    Q_OBJECT

public:
    explicit Nuevo_ing(QWidget *parent = nullptr);
    ~Nuevo_ing();
    void cargar();
    QString setDatos(QString fecha, QString miembro, QString monto, QString categoria);

private slots:
    void on_Cancelar_clicked();

    void on_Guardar_clicked();

private:
    Ui::Nuevo_ing *ui;
};

#endif // NUEVO_ING_H
