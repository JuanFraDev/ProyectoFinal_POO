#include "iniciodesesion.h"
#include "ui_iniciodesesion.h"

IniciodeSesion::IniciodeSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciodeSesion)
{
    Controlador contr;
    ui->setupUi(this);
}

IniciodeSesion::~IniciodeSesion()
{
    delete ui;
}

QString IniciodeSesion::user()
{
    return ui->in_user->text() + ";" + ui->in_pass->text();
}
void IniciodeSesion::on_btn_ini_clicked()
{
    Controlador controlador;
    bool contr;
    contr = controlador.iniciarSesion(user());
    if(contr == 0){
        QMessageBox::warning(this, "Error", "Usuario no encontrado..!");
        return;
    }
    accept();
}

void IniciodeSesion::on_btn_regis_clicked()
{

    Register reg(this);
    reg.setWindowTitle("Registro de nuevo Usuario");
    int res = reg.exec();
    if (res == QDialog::Rejected){
        return;
    }
}

