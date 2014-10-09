#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QtSql/QtSql>
#include <QtDebug>
#include<QFileInfo>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
        
public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        mydb =QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("D:/QT-Project/BancoDeDados/database.db");

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
 
public:
        explicit Login(QWidget *parent = 0);
    ~Login();
    

private slots:
    void on_btn_ok_clicked();
    
private:
    Ui::AulaYouTube *ui;
    QAction *AcaoSair;
    QMenu *MenuArquivo;
    void CriaAcao();
    void CriaMenu();
};
