#ifndef MOVINGRESO_H
#define MOVINGRESO_H

#include <QDialog>

namespace Ui {
class MovIngreso;
}

class MovIngreso : public QDialog
{
    Q_OBJECT

public:
    explicit MovIngreso(QWidget *parent = nullptr);
    ~MovIngreso();

private:
    Ui::MovIngreso *ui;
};

#endif // MOVINGRESO_H
