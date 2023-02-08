#include "iniciodesesion.h"
#include "pagprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IniciodeSesion w;
    PagPrincipal p;
    int r = w.exec();
    if(r!=QDialog::Rejected)
    {
        p.show();
    }
    return a.exec();
}
