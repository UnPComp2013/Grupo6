#ifndef MOD_H
#define MOD_H

#include <QDialog>

namespace Ui {
class mod;
}

class mod : public QDialog
{
    Q_OBJECT

public:
    explicit mod(QWidget *parent = 0);
    ~mod();

private slots:
    void on__1_clicked();

private:
    Ui::mod *ui;
};

#endif // MOD_H
