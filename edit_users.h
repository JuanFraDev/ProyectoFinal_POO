#ifndef EDIT_USERS_H
#define EDIT_USERS_H

#include <QDialog>

namespace Ui {
class Edit_users;
}

class Edit_users : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_users(QWidget *parent = nullptr);
    ~Edit_users();

private:
    Ui::Edit_users *ui;
};

#endif // EDIT_USERS_H
