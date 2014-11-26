#ifndef DELETAR_H
#define DELETAR_H

#include <QDialog>

namespace Ui {
class Deletar;
}

class Deletar : public QDialog
{
    Q_OBJECT

public:
    explicit Deletar(QWidget *parent = 0);
    ~Deletar();

private:
    Ui::Deletar *ui;
};

#endif // DELETAR_H
