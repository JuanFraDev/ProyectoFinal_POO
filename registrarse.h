#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QWidget>

namespace Ui {
class Registrarse;
}

class Registrarse : public QWidget
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = nullptr);
    ~Registrarse();

private:
    Ui::Registrarse *ui;
};

#endif // REGISTRARSE_H
