#ifndef CADASTRO_H
#define CADASTRO_H

#include <QMainWindow>

namespace Ui {
class Cadastro;
}

class Cadastro : public QMainWindow
{
    Q_OBJECT

public slots:
    void confirma();
    void cancelar();
    void implementaAcaoSair();

public:
    explicit Cadastro(QWidget *parent = 0);
    ~Cadastro();

private:
    Ui::Cadastro *ui;
    QAction *acaoSair;
    QMenu *menuArquivo;
    void criaAcao();
    void criaMenu();

};

#endif // CADASTRO_H
