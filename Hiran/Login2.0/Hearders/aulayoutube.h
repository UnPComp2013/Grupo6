#ifndef AULAYOUTUBE_H
#define AULAYOUTUBE_H

#include <QMainWindow>

namespace Ui {
class AulaYouTube;
}

class AulaYouTube : public QMainWindow
{
    Q_OBJECT
public slots:
    void Sair();
    void Confirma();

public:
    explicit AulaYouTube(QWidget *parent = 0);
    ~AulaYouTube();

private:
    Ui::AulaYouTube *ui;
    QAction *AcaoSair;
    QMenu *MenuArquivo;
    void CriaAcao();
    void CriaMenu();

};

#endif // AULAYOUTUBE_H
