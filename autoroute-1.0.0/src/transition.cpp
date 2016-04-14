#include "transition.h"
#include "ui_transition.h"

Transition::Transition(int to,int voc,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    cible = to;
    vocab = voc;

    ui->label->setText("vers l'état "+QString().setNum(cible)+" par le chiffre "+QString().setNum(vocab));
    connect(ui->supress,SIGNAL(clicked()),this,SLOT(getOff()));
}

Transition::~Transition()
{
    delete ui;
}

void Transition::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Transition::getOff(){
    emit eraser(cible,vocab);
}
