#ifndef ETATLEFT_H
#define ETATLEFT_H

#include <QWidget>

namespace Ui {
    class etatLeft;
}

class etatLeft : public QWidget {
    Q_OBJECT
public:
    etatLeft(int ,QWidget *parent = 0);
    ~etatLeft();

public slots:
    void sendDad();
    void askForSupress();


protected:
    void changeEvent(QEvent *e);
    int numero;

signals:
    void selected(int me);
    void supress(int);



private:
    Ui::etatLeft *ui;
};

#endif // ETATLEFT_H
