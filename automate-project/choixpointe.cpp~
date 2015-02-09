#include "choixpointe.h"
#include "ui_choixpointe.h"

choixPointe::choixPointe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choixPointe)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(sendDad()));
}

choixPointe::~choixPointe()
{
    delete ui;
}

void choixPointe::changeEvent(QEvent *e)
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


void choixPointe::resetAffichage(Automate a){
    ui->lesChoix->clear();

    vector<etat>::iterator it;
    vector<etat> list;
    list = a.getEtats();

    for ( it=list.begin() ; it < list.end(); it++ ){
        ui->lesChoix->addItem(QString().setNum((*it).numero));
    }
}

void choixPointe::sendDad(){
    if((!ui->lesChoix->currentText().isEmpty()) &&( !ui->lineEdit->text().isEmpty() ) ){
        emit add(ui->lesChoix->currentText().toInt(),ui->lineEdit->text().toInt());

    }
}
