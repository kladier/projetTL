#include "etatleft.h"
#include "ui_etatleft.h"
//ceci est un commentaire
etatLeft::etatLeft(int number,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::etatLeft)
{
    ui->setupUi(this);
    setMaximumWidth(180);
    ui->label->setText("Etat "+QString().setNum(number));
    numero = number;
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(sendDad()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(askForSupress()));
}

etatLeft::~etatLeft()
{
    delete ui;
}

void etatLeft::changeEvent(QEvent *e)
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

void etatLeft::sendDad(){
    emit selected(numero);
}

void etatLeft::askForSupress(){
    emit supress(numero);
}
