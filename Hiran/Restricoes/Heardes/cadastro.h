#ifndef CADASTRO_H
#define CADASTRO_H

# include <QMainWindow>

namespace  Ui  {
classe  Cadastro ;
}

classe  Cadastro  :  público  QMainWindow
{
    Q_OBJECT

públicas  ranhuras :
    vazio  Confirma ();
    vazio  Cancelar ();
    anular  implementaAcaoSair ();

público :
    explícita  Cadastro ( QWidget  * pai  =  0 );
    ~ Cadastro ();

privado :
    Ui :: Cadastro  * ui ;
    QAction  * acaoSair ;
    QMenu  * menuArquivo ;
    anular  criaAcao ();
    anular  criaMenu ();
};
#endif // CADASTRO_H
