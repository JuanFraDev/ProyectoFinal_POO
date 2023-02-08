#include "edit_users.h"
#include "ui_edit_users.h"

Edit_users::Edit_users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_users)
{
    ui->setupUi(this);
}

Edit_users::~Edit_users()
{
    delete ui;
}
