#ifndef ETATRIGHT_H
#define ETATRIGHT_H

#include <QWidget>
#include "automate.h"
#include "choixpointe.h"
#include "transition.h"

namespace Ui {
    class etatRight;
}

class etatRight : public QWidget {
    Q_OBJECT
public:
    etatRight(Automate*,int,QWidget *parent = 0);
    ~etatRight();
    choixPointe* addTrans;
    Automate* a;
    void remplirListChoix();
    int numero;
    void addVisualTransition(int,int);
    void cleanTrans();

public slots:
    void addTransition(int,int);
    void eraseTransition(int,int);
    void etatChange();

signals:
   void refreshNeeded(int);
   void etatChanges(int,bool,bool);

protected:
    void changeEvent(QEvent *e);

private:
    vector<Transition*> mesTrans;
    Ui::etatRight *ui;
};

#endif // ETATRIGHT_H
