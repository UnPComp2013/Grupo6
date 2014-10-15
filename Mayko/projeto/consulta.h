#ifndef CONSULTA_H
#define CONSULTA_H

#include <QDialog>
#include "login.h"
#include <QMessageBox>

namespace Ui {
class consulta;
}

class consulta : public QDialog
{
    Q_OBJECT

public:
    explicit consulta(QWidget *parent = 0);
    ~consulta();

private slots:
    void on_btn_update_clicked();

    void on_btn_atabela_clicked();

private:
    Ui::consulta *ui;
};

#endif // CONSULTA_H
