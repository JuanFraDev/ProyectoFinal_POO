#include "controlador.h"


Controlador::Controlador(QObject *parent)
    : QObject{parent}
{

}

bool Controlador::iniciarSesion(QString datos)
{
    bool encontrado = false;
    QStringList usuariosIn = datos.split(";");
    if(usuariosIn[0].isEmpty() || usuariosIn[1].isEmpty()){
        return encontrado;
    } else {
        QFile archivo("usuarios.csv");
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
    QStringList contras = verificacion.split(";");
    if(!(contras[0] == contras[1])){
        return 0;
    } else {
        QFile archivo("usuarios.csv");
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

void Controlador::guardarCategoria(QString cate, QString nombre)
{
    if(cate == "Ingreso"){
        QFile file("catIngreso.csv");
        if(!file.exists()){
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                file.close();
            }
            guardarCategoria(cate,nombre);
        } else {
            if(file.open(QIODevice::Append)){
                QTextStream entrada(&file);
                entrada << nombre << ";" << cate << "\n";
                file.close();
            }
        }
    } else {
        QFile file("catEgreso.csv");
        if(!file.exists()){
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                file.close();
            }
            guardarCategoria(cate,nombre);
        } else {
            if(file.open(QIODevice::Append)){
                QTextStream entrada(&file);
                entrada << nombre << ";" << cate << "\n";
                file.close();
            }
        }
    }
}

void Controlador::guardarEgreso(QString fecha, QString miembro, float monto, QString categoria)
{
    bool flag;
    QFile file("egresos.csv");
    flag = file.exists();
    if(!file.exists()){
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            file.close();
        }
        guardarEgreso(fecha,miembro,monto,categoria);
    } else {
        if(file.open(QIODevice::Append)){
            QTextStream entrada(&file);
            entrada << fecha << ";" << miembro << ";" << monto << ";" << categoria << "\n";
            file.close();
        }
    }
    if(flag){
        QFile fileMiembro("miembros.csv");
        if(fileMiembro.open(QIODevice::ReadWrite | QIODevice::Text)){
            QTextStream in(&fileMiembro);
            QTextStream out(&fileMiembro);
            QStringList lineas, datos, aux, usuarioEncontrado;
            QString nombres;
            float cantidad = 0;
            int contador = 0, selec = 0;
            while (!in.atEnd()) {
                QString line = in.readLine();
                lineas.append(line);
                datos = line.split(";");
                nombres = datos.at(0) + " " + datos.at(1);
                if(nombres == miembro){
                    usuarioEncontrado = line.split(";");
                    aux = lineas.at(contador).split(";");
                    cantidad = aux.at(3).toFloat(); //Aquí tengo almacenado el valor de ingresos de la persona
                    cantidad += monto;
                    selec = contador;
                }
                contador++;
            }
            fileMiembro.seek(0);
            for(int i = 0; i < lineas.size(); i++){
                if(i == selec){
                    out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                        << usuarioEncontrado.at(2) << ";" << QString::number(cantidad) << "\n";
                } else {
                    out << lineas.at(i) << "\n";
                }
            }
            fileMiembro.close();
        } else {
            qDebug() << "No se pudo abrir el archivo";
        }
    }
}

void Controlador::guardarIngreso(QString fecha, QString miembro, float monto, QString categoria)
{
    bool flag;
    QFile file("ingresos.csv");
    flag = file.exists();
    if(!file.exists()){
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            file.close();
        }
        guardarIngreso(fecha,miembro,monto,categoria);
    } else {
        if(file.open(QIODevice::Append)){
            QTextStream entrada(&file);
            entrada << fecha << ";" << miembro << ";" << monto << ";" << categoria << "\n";
            file.close();
        }
    }

    if(flag){
        QFile fileMiembro("miembros.csv");
        if(fileMiembro.open(QIODevice::ReadWrite | QIODevice::Text)){
            QTextStream in(&fileMiembro);
            QTextStream out(&fileMiembro);
            QStringList lineas, datos, aux, usuarioEncontrado;
            QString nombres;
            float cantidad;
            int contador = 0, selec = 0;
            while (!in.atEnd()) {
                QString line = in.readLine();
                lineas.append(line);
                datos = line.split(";");
                nombres = datos.at(0) + " " + datos.at(1);
                if(nombres == miembro){
                    usuarioEncontrado = line.split(";");
                    aux = lineas.at(contador).split(";");
                    cantidad = aux.at(2).toFloat(); //Aquí tengo almacenado el valor de ingresos de la persona
                    cantidad += monto;
                    selec = contador;
                }
                contador++;
            }
            fileMiembro.seek(0);
            for(int i = 0; i < lineas.size(); i++){
                if(i == selec){
                    out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                        << QString::number(cantidad) << ";" << usuarioEncontrado.at(3) << "\n";
                } else {
                    out << lineas.at(i) << "\n";
                }
            }
            fileMiembro.close();
        } else {
            qDebug() << "No se pudo abrir el archivo";
        }
    }
}

void Controlador::eliminarEgreso(QString fecha, QString miembro, float monto, QString categoria)
{
    QFile fileMiembro("miembros.csv");
    if(fileMiembro.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream in(&fileMiembro);
        QTextStream out(&fileMiembro);
        QStringList lineas, datos, aux, usuarioEncontrado;
        QString nombres;
        float cantidad = 0;
        int contador = 0, selec = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            lineas.append(line);
            datos = line.split(";");
            nombres = datos.at(0) + " " + datos.at(1);
            if(nombres == miembro){
                usuarioEncontrado = line.split(";");
                aux = lineas.at(contador).split(";");
                cantidad = aux.at(3).toFloat(); //Aquí tengo almacenado el valor de ingresos de la persona
                qDebug()<<"cantidad antes acum: " <<cantidad;
                qDebug()<<"monto antes acum: " <<monto;
                cantidad -= monto;
                qDebug()<<"cantidad desp acum: " <<cantidad;
                qDebug()<<"monto desp acum: " <<monto;
                selec = contador;
                qDebug() << "Numero de contador: " << selec;
            }
            contador++;
        }
        fileMiembro.seek(0);
        for(int i = 0; i < lineas.size(); i++){
            if(i == selec && i == lineas.size()-1){
                out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                    << usuarioEncontrado.at(2) << ";" << QString::number(cantidad) << " ";
            } else if (i == selec){
                out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                    << usuarioEncontrado.at(2) << ";" << QString::number(cantidad) << "\n";
            } else if(i == lineas.size()-1){
                out << lineas.at(i) << " ";
            } else {
                out << lineas.at(i) << "\n";
            }
        }
        fileMiembro.close();
        qDebug() << "Llega en controlador";
    } else {
        qDebug() << "No se pudo abrir el archivo";
    }
}

void Controlador::eliminarIngreso(QString fecha, QString miembro, float monto, QString categoria)
{
    QFile fileMiembro("miembros.csv");
    if(fileMiembro.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream in(&fileMiembro);
        QTextStream out(&fileMiembro);
        QStringList lineas, datos, aux, usuarioEncontrado;
        QString nombres;
        float cantidad = 0;
        int contador = 0, selec = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            lineas.append(line);
            datos = line.split(";");
            nombres = datos.at(0) + " " + datos.at(1);
            if(nombres == miembro){
                usuarioEncontrado = line.split(";");
                aux = lineas.at(contador).split(";");
                cantidad = aux.at(2).toFloat(); //Aquí tengo almacenado el valor de ingresos de la persona
                cantidad -= monto;
                selec = contador;
            }
            contador++;
        }
        fileMiembro.seek(0);
        for(int i = 0; i < lineas.size(); i++){
            if(i == selec && i == lineas.size()-1){
                out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                    << QString::number(cantidad) << ";" << usuarioEncontrado.at(3) << " " ;
            } else if (i == selec){
                out << usuarioEncontrado.at(0) << ";" << usuarioEncontrado.at(1) << ";"
                    << QString::number(cantidad) << ";" << usuarioEncontrado.at(3) << "\n";
            } else if(i == lineas.size()-1){
                out << lineas.at(i) << " ";
            } else {
                out << lineas.at(i) << "\n";
            }
        }
        fileMiembro.close();
    } else {
        qDebug() << "No se pudo abrir el archivo";

    }
}

void Controlador::eliminarMiembro(QString nombre, QString apellido, float ingreso, float egreso)
{
    QList <int> acumulador;
    QFile fileIngresos("ingresos.csv");
    if(!fileIngresos.exists())
        return;
    if(fileIngresos.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream in(&fileIngresos);
        QTextStream out(&fileIngresos);
        QStringList lineas, datos;
        QString nombres, nombresAr, encontrado;
        int contador = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            lineas.append(line);
            datos = line.split(";");
            nombres = datos.at(1);
            nombresAr = nombre + " " + apellido;
            if(nombres == nombresAr){
                qDebug() << "Encuentra el miembro";
                acumulador.append(contador);
            }
            contador++;
        }
        for(int i = 0; i < acumulador.size(); i++){
            QString eliminador;
            eliminador = lineas.at(acumulador.at(i));
            lineas.removeOne(eliminador);
        }
        fileIngresos.seek(0);
        qDebug() << "Tamano de la lista antes de entrar al for: " << lineas.size();
        qDebug() << "Cadena antes de entrar al for: " << lineas;
        if(lineas.size() != 0){
            for(int i = 0; i < lineas.size(); i++){
                if(i == lineas.size()-1){
                    qDebug() << "Llega al ultimo elemento" <<lineas.at(i);
                    out << lineas.at(i) << " ";
                } else {
                    qDebug() << "Llega a cualquier elemento" << lineas.at(i);
                    out << lineas.at(i) << "\n";
                }
            }
        } else {
            out << " ";
        }

        fileIngresos.close();
    }
}


