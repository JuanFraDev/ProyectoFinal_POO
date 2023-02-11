#ifndef NUEVOEDITUSER_H
#define NUEVOEDITUSER_H

#include <QDialog>
#include <QDebug>
#include <QStringList>
#include <controlador.h>

namespace Ui {
class nuevoEditUser;
}

class nuevoEditUser : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoEditUser(QWidget *parent = nullptr);
    ~nuevoEditUser();
    void setDatos(QString nombre, QString apellido);
    const QString &getARCHIVO_MIEMBRO() const;

private slots:
    void on_Guardar_clicked();

private:
    Ui::nuevoEditUser *ui;
    QString ARCHIVO_MIEMBRO;
};

#endif // NUEVOEDITUSER_H
