#ifndef MOVEGRESO_H
#define MOVEGRESO_H

#include <QDialog>
#include <controlador.h>
#include <nuevo_egre.h>
#include <QTableView>

namespace Ui {
class MovEgreso;
}

class MovEgreso : public QDialog
{
    Q_OBJECT

public:
    explicit MovEgreso(QWidget *parent = nullptr);
    ~MovEgreso();
    void cargar();

private slots:
    void on_nuevo_egre_clicked();

    void on_eliminar_egre_clicked();

private:
    Ui::MovEgreso *ui;
    enum Columna
    {
        FECHA, MIEMBRO, MONTO, CATEGORIA
    };
};

#endif // MOVEGRESO_H
