#ifndef TRANSITION_H
#define TRANSITION_H

#include <QWidget>

namespace Ui {
    class Transition;
}

class Transition : public QWidget {
    Q_OBJECT
public:
    Transition(int,int,QWidget *parent = 0);
    ~Transition();
    int cible;
    int vocab;

signals:
    void eraser(int,int);

public slots:
    void getOff();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Transition *ui;
};

#endif // TRANSITION_H
