#ifndef PAGPRINCIPAL_H
#define PAGPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class PagPrincipal;
}

class PagPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit PagPrincipal(QWidget *parent = nullptr);
    ~PagPrincipal();

private:
    Ui::PagPrincipal *ui;
};

#endif // PAGPRINCIPAL_H
