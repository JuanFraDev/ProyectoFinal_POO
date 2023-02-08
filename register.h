#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "controlador.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    QString verificacion();
    QString newUser();


private slots:

    void on_Guardar_clicked();

    void on_Cancelar_clicked();

private:
    Ui::Register *ui;
    bool m_aceptado = false;
};

#endif // REGISTER_H
