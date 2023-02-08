#ifndef NUEVO_EGRE_H
#define NUEVO_EGRE_H

#include <QDialog>

namespace Ui {
class Nuevo_egre;
}

class Nuevo_egre : public QDialog
{
    Q_OBJECT

public:
    explicit Nuevo_egre(QWidget *parent = nullptr);
    ~Nuevo_egre();

private:
    Ui::Nuevo_egre *ui;
};

#endif // NUEVO_EGRE_H
