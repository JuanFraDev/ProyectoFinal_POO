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

class Controlador : public QObject
{
    Q_OBJECT
public:
    explicit Controlador(QObject *parent = nullptr);
    bool iniciarSesion(QString datos);
    bool registrarse(QString verificacion, QString nuevoUsuario);
    bool validReg(QString nuevoUsuario);
    void setArchivo();

private:
    QString ARCHIVO;

signals:

};

#endif // CONTROLADOR_H
