#ifndef MOVINGRESO_H
#define MOVINGRESO_H

#include <QDialog>
#include <QStringList>
#include <QFile>
#include <controlador.h>
#include <nuevo_ing.h>

namespace Ui {
class MovIngreso;
}

class MovIngreso : public QDialog
{
    Q_OBJECT

public:
    explicit MovIngreso(QWidget *parent = nullptr);
    ~MovIngreso();
    void cargar();
private slots:
    void on_nuevo_ingre_clicked();

    void on_eliminar_ingre_clicked();

private:
    Ui::MovIngreso *ui;
    enum Columna
    {
        FECHA, MIEMBRO, MONTO, CATEGORIA
    };
};

#endif // MOVINGRESO_H
