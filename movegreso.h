#ifndef MOVEGRESO_H
#define MOVEGRESO_H

#include <QDialog>

namespace Ui {
class MovEgreso;
}

class MovEgreso : public QDialog
{
    Q_OBJECT

public:
    explicit MovEgreso(QWidget *parent = nullptr);
    ~MovEgreso();

private:
    Ui::MovEgreso *ui;
};

#endif // MOVEGRESO_H
