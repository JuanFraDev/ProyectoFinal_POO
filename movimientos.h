#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <QDialog>

namespace Ui {
class Movimientos;
}

class Movimientos : public QDialog
{
    Q_OBJECT

public:
    explicit Movimientos(QWidget *parent = nullptr);
    ~Movimientos();

private:
    Ui::Movimientos *ui;
};

#endif // MOVIMIENTOS_H
