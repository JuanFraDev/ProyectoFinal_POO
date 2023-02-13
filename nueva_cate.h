#ifndef NUEVA_CATE_H
#define NUEVA_CATE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <controlador.h>

namespace Ui {
class Nueva_cate;
}

class Nueva_cate : public QDialog
{
    Q_OBJECT

public:
    explicit Nueva_cate(QWidget *parent = nullptr);
    ~Nueva_cate();

private slots:
    void on_Guardar_clicked();

private:
    Ui::Nueva_cate *ui;
};

#endif // NUEVA_CATE_H
