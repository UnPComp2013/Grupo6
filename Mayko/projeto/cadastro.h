#ifndef CADASTRO_H
#define CADASTRO_H

#include <QDialog>
#include "login.h"
#include <QMessageBox>

namespace Ui {
class cadastro;
}

class cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit cadastro(QWidget *parent = 0);
    ~cadastro();

private slots:
    void on_btn_confirma_clicked();

    void on_btn_update_clicked();

    void on__1_clicked();

private:
    Ui::cadastro *ui;
};

#endif // CADASTRO_H
