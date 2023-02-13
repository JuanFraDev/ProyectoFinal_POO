#ifndef EDIT_USERS_H
#define EDIT_USERS_H

#include <QDialog>
#include <nuevoedituser.h>

namespace Ui {
class Edit_users;
}

class Edit_users : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_users(QWidget *parent = nullptr);
    ~Edit_users();
    void cargarDatos();

private slots:
    void on_addUser_clicked();
    void on_eliminarUser_clicked();

private:
    Ui::Edit_users *ui;
    enum Columna
    {
        NOMBRE, APELLIDO, INGRESO, EGRESO
    };
};

#endif // EDIT_USERS_H
