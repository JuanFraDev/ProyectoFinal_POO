#ifndef NUEVO_ING_H
#define NUEVO_ING_H

#include <QDialog>

namespace Ui {
class Nuevo_ing;
}

class Nuevo_ing : public QDialog
{
    Q_OBJECT

public:
    explicit Nuevo_ing(QWidget *parent = nullptr);
    ~Nuevo_ing();

private:
    Ui::Nuevo_ing *ui;
};

#endif // NUEVO_ING_H
