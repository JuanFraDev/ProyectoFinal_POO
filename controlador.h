#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileInfo>
#include <QList>

class Controlador : public QObject
{
    Q_OBJECT
public:
    explicit Controlador(QObject *parent = nullptr);
    bool iniciarSesion(QString datos);
    bool registrarse(QString verificacion, QString nuevoUsuario);
    bool validReg(QString nuevoUsuario);
    void setArchivo();
    void guardarCategoria(QString cate, QString nombre);
    void guardarEgreso(QString fecha, QString miembro, float monto, QString categoria);
    void guardarIngreso(QString fecha, QString miembro, float monto, QString categoria);
    void eliminarEgreso(QString fecha, QString miembro, float monto, QString categoria);
    void eliminarIngreso(QString fecha, QString miembro, float monto, QString categoria);
    void eliminarMiembro(QString nombre, QString apellido, float ingreso, float egreso);

private:
    QString ARCHIVO;
signals:

};

#endif // CONTROLADOR_H
