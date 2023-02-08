#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

QString Register::verificacion()
{
    return ui->inContra->text() + ";" + ui->inContraVeri->text();
}

QString Register::newUser()
{
    return ui->inNombre->text() + ";" + ui->inContra->text();
}

void Register::on_Guardar_clicked()
{
    Controlador controlador;
    bool contr, fillcontr;
    contr = controlador.registrarse(verificacion(),newUser());
    fillcontr = controlador.validReg(newUser());
    if(contr == 0){
        QMessageBox::warning(this, "Error", "Las contraseñas no coinciden..!");
    }
    if(fillcontr == 0){
        QMessageBox::warning(this, "Error", "Se necesita llenar todos los campos..!");
    }
    if(contr && fillcontr){
        QFile Users("C:/Users/lab/Desktop/ProyectoFInal-Ahorro-main/usuarios.csv");
        if(!Users.exists()){
            QFile Users("C:/Users/lab/Desktop/ProyectoFInal-Ahorro-main/usuarios.csv");
        }
        close();
    }
    accepted();
}


void Register::on_Cancelar_clicked()
{
    rejected();
    close();
}

