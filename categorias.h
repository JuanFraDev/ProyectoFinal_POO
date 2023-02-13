#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <nueva_cate.h>

namespace Ui {
class Categorias;
}

class Categorias : public QDialog
{
    Q_OBJECT

public:
    explicit Categorias(QWidget *parent = nullptr);
    ~Categorias();
    void cargar();

private slots:
    void on_nuevo_cate_clicked();

    void on_eliminar_cate_clicked();

private:
    Ui::Categorias *ui;
    enum Columna
    {
        NOMBRE, TIPO
    };
};

#endif // CATEGORIAS_H
