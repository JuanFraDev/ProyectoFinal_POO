#ifndef PAGPRINCIPAL_H
#define PAGPRINCIPAL_H

#include <QMainWindow>
#include <edit_users.h>

namespace Ui {
class PagPrincipal;
}

class PagPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit PagPrincipal(QWidget *parent = nullptr);
    ~PagPrincipal();

private slots:
    void on_actionNuevo_miembro_triggered();

private:

    Ui::PagPrincipal *ui;
};

#endif // PAGPRINCIPAL_H
