#ifndef AULAYOUTUBE_H
#define AULAYOUTUBE_H

#include <QMainWindow>

namespace Ui {
class AulaYouTube;
}

class AulaYouTube : public QMainWindow
{
    Q_OBJECT
    
public:
    QSqlDatabase mydb;

    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
                     }
    bool connOpen()
    {
        mydb =QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/DIEGO/Desktop/hiran/db/database.db");
        
        if(!mydb.open())
        {
            qDebug()<<("Falha ao abrir a database");
            return false;
        }

        else
        {
            qDebug()<<("conectado...");
            return true;
        }
    }

public slots:
    void Sair();
    void Confirma();
    
private slots:
    void on_btn_ok_clicked();

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
