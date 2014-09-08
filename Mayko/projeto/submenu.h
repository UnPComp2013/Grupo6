#ifndef SUBMENU_H
#define SUBMENU_H

#include <QMainWindow>

namespace Ui {
class submenu;
}

class submenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit submenu(QWidget *parent = 0);
    ~submenu();

private:
    Ui::submenu *ui;
};

#endif // SUBMENU_H
