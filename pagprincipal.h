#ifndef PAGPRINCIPAL_H
#define PAGPRINCIPAL_H

#include <QMainWindow>
#include <edit_users.h>
#include <movingreso.h>
#include <movegreso.h>
#include <nuevo_ing.h>
#include <nueva_cate.h>
#include <categorias.h>
#include <reporte.h>

namespace Ui {
class PagPrincipal;
}

class PagPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit PagPrincipal(QWidget *parent = nullptr);
    ~PagPrincipal();
    void getInfo();

private slots:
    void on_actionNuevo_miembro_triggered();

    void on_actionNuevo_ingreso_triggered();

    void on_actionNuevo_egreso_triggered();

    void on_actionNueva_categoria_triggered();

    void on_action_Ver_Categor_as_triggered();

    void on_categorias_clicked();

    void on_Miembros_clicked();

    void on_ingresos_clicked();

    void on_Reporte_clicked();

    void on_actionNuevo_reporte_triggered();

    void on_egresos_clicked();

private:

    Ui::PagPrincipal *ui;
};

#endif // PAGPRINCIPAL_H
