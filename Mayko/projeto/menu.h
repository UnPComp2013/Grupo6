#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "consulta.h"
#include "cadastro.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_btn_cadastrar_clicked();
    void on_btn_consultar_clicked();


private:
    Ui::menu *ui;
    consulta *Consulta;
    cadastro *Cadastro;
};

#endif // MENU_H
