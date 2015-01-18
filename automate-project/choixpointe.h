#ifndef CHOIXPOINTE_H
#define CHOIXPOINTE_H

#include <QWidget>
#include "automate.h"

namespace Ui {
    class choixPointe;
}

class choixPointe : public QWidget {
    Q_OBJECT
public:
    choixPointe(QWidget *parent = 0);
    ~choixPointe();
    void resetAffichage(Automate);

public slots:
    void sendDad();


signals:
    void add(int cible,int vocab);


protected:
    void changeEvent(QEvent *e);

private:
    Ui::choixPointe *ui;
};

#endif // CHOIXPOINTE_H
