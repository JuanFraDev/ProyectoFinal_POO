#include "controlador.h"


Controlador::Controlador(QObject *parent)
    : QObject{parent}
{

}

bool Controlador::iniciarSesion(QString datos)
{
    bool encontrado = false;
    setArchivo();
    QStringList usuariosIn = datos.split(";");
    if(usuariosIn[0].isEmpty() || usuariosIn[1].isEmpty()){
        return encontrado;
    } else {

        QFile archivo(ARCHIVO);
        if (archivo.open(QFile::ReadOnly)) {
            QTextStream salida(&archivo);

            while(!salida.atEnd()){
                QString lineaArch = salida.readLine();
                QStringList usuariosArch = lineaArch.split(";");
                if(usuariosIn == usuariosArch){
                    encontrado = true;
                }
            }
            archivo.close();
        }else{
            qDebug() << "No se pudo abrir el archivo";
        }
        return encontrado;
    }

}

bool Controlador::registrarse(QString verificacion, QString nuevoUsuario)
{
    setArchivo();
    QStringList contras = verificacion.split(";");
    if(!(contras[0] == contras[1])){
        return 0;
    } else {
        QFile archivo(ARCHIVO);
        if (archivo.open(QFile::Append)) {
            QTextStream salida(&archivo);
            salida << nuevoUsuario << "\n";
            archivo.close();
            return 1;

        }
    }
}

bool Controlador::validReg(QString nuevoUsuario)
{
    QStringList veri = nuevoUsuario.split(";");
    if(veri[0].isEmpty() || veri[1].isEmpty()){
        return 0;
    } else {
        return 1;
    }
}

void Controlador::setArchivo()
{
    QString usuarios = "usuarios.csv";
    QFileInfo infoFile(usuarios);
    if(infoFile.exists()){
        ARCHIVO = infoFile.absoluteFilePath();
        qDebug() << infoFile.absoluteFilePath();
    } else {
        QDir buildDir("ProyectoFinal-Ahorro/build-ProytectoFinal-Ahorro-Desktop_Qt_5_15_2_MinGW_64_bit-Debug");
        QDir::setCurrent(buildDir.path());
        QFile file("usuarios.csv");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            file.close();
        }
        setArchivo();
    }
}
