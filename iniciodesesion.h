#ifndef INICIODESESION_H
#define INICIODESESION_H

#include <QDialog>
#include "controlador.h"
#include "register.h"
#include "pagprincipal.h"

namespace Ui {
class IniciodeSesion;
}

class IniciodeSesion : public QDialog
{
    Q_OBJECT

public:
    explicit IniciodeSesion(QWidget *parent = nullptr);
    ~IniciodeSesion();
    QString user();

private slots:
    void on_btn_ini_clicked();
    void on_btn_regis_clicked();

private:
    Ui::IniciodeSesion *ui;
};

#endif // INICIODESESION_H
