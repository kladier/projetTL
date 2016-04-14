#include "etatright.h"
#include "ui_etatright.h"
#include "choixpointe.h"
#include "transition.h"

etatRight::etatRight(Automate* autom,int number,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::etatRight)
{
    a = autom;
    numero = number;
    ui->setupUi(this);
    ui->label->setText("Etat Numero "+QString().setNum(numero));
    addTrans = new choixPointe();
    ui->Choix->addWidget(addTrans);
    ui->checkBox_2->setChecked(a->getEtat(number)->isInitial());;
    ui->checkBox->setChecked(a->getEtat(number)->isFinal());

    connect(addTrans,SIGNAL(add(int ,int)),this,SLOT(addTransition(int ,int )));
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(etatChange()));
    connect(ui->checkBox_2,SIGNAL(clicked()),this,SLOT(etatChange()));

}

etatRight::~etatRight()
{
    delete ui;
}

void etatRight::changeEvent(QEvent *e)
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

void etatRight::remplirListChoix(){
    addTrans->resetAffichage(*a);
}

void etatRight::addTransition(int to,int vocab){
     a->ajoutTransition(*a->getEtat(numero),*a->getEtat(to),vocab);
     refreshNeeded(numero);
    }

void etatRight::addVisualTransition(int to,int vocab){

    Transition* transtmp = new Transition(to,vocab);
    ui->ShowChoix->addWidget(transtmp);

    mesTrans.push_back(transtmp);
    connect(transtmp,SIGNAL(eraser(int,int)),this,SLOT(eraseTransition(int,int)));

}

void etatRight::cleanTrans(){
    vector<Transition*>::iterator it;
    it = mesTrans.begin();

    while(it != mesTrans.end()){
        (*it)->hide();
        ui->ShowChoix->removeWidget((*it));
        it++;
    }

}

void etatRight::eraseTransition(int to,int vocab){

    a->getEtat(numero)->supprimeTransition(*a->getEtat(to),vocab);
    refreshNeeded(numero);
}

void etatRight::etatChange(){
    emit etatChanges(numero,ui->checkBox_2->isChecked(),ui->checkBox->isChecked());
    emit refreshNeeded(numero);
}
