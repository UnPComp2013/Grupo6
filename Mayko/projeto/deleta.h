#ifndef DELETA_H
#define DELETA_H

#include <QDialog>

namespace Ui {
class deleta;
}

class deleta : public QDialog
{
    Q_OBJECT

public:
    explicit deleta(QWidget *parent = 0);
    ~deleta();

private:
    Ui::deleta *ui;
};

#endif // DELETA_H
