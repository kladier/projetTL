#include "createautomate.h"
#include "ui_createautomate.h"
#include "etatleft.h"
#include <QtGui>
#include <QFrame>
#include <QMessageBox>
#include <QFile>
#include "transition.h"


CreateAutomate::CreateAutomate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateAutomate)
{
    ui->setupUi(this);
    connect(ui->actionVoir,SIGNAL(triggered()),this,SLOT(afficherAutomate()));
    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(ajoutEtat()));
    connect(ui->actionSauvegarder,SIGNAL(triggered()),this,SLOT(sauvegarder()));
    connect(ui->actionFermer,SIGNAL(triggered()),this,SLOT(close()));

    maVue = new QSvgWidget(ui->vueTomate);

    actuel = 0;
}

CreateAutomate::~CreateAutomate()
{
    delete ui;
}

void CreateAutomate::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CreateAutomate::ajoutEtat(bool ini, bool fina){
   if(a.getEtats().size()>9){
       QMessageBox::critical( this, tr( "Erreur" ), tr( "Vous ne pouvez pas créer un automates de plus de 10 états" ));
       return;
   }

   a.ajoutEtat(etat(right.size(),ini,fina));

   etatLeft* g = new etatLeft(left.size(),this);
   left.push_back(g);
   ui->etatVert->addWidget(g);
   connect(g,SIGNAL(selected(int)),this,SLOT(displayRight(int)));
   connect(g,SIGNAL(supress(int)),this,SLOT(supprimeEtat(int)));


   etatRight* h = new etatRight(&a,right.size());
   right.push_back(h);
   resetAllListChoix();
   connect(h,SIGNAL(refreshNeeded(int)),this,SLOT(displayRight(int)));
   connect(h,SIGNAL(etatChanges(int,bool,bool)),this,SLOT(changeState(int,bool,bool)));
   displayRight(right.size()-1);

    //On remet à jour toutes les lists

}

void CreateAutomate::afficherAutomate(){

    QTextBrowser* m = new QTextBrowser(this);
    QMainWindow* n = new QMainWindow(this);

    n->setCentralWidget(m);;

    vector<etat>::iterator it;
    multimap<int,etat> multi;

    multimap<int,etat>::iterator it2;

    vector<etat> states;
    states = a.getEtats();

    m->append(QString().fromStdString(a.toDot()));
    n->show();

}

void CreateAutomate::resetAllListChoix(){
    unsigned int i;


    for (i=0;i<right.size();i++  ){
        right[i]->remplirListChoix();
    }

}

void CreateAutomate::displayRight(int toDisplay){
    displayAutomate();
    if (actuel>0){
         right[actuel-1]->hide();
    }
    ui->etatDroite->removeWidget(right[actuel]);
    ui->etatDroite->addWidget(right[toDisplay]);
    right[toDisplay]->show();
    actuel = toDisplay+1;

    right[toDisplay]->cleanTrans();
    multimap<int,etat>::iterator multit;
    multimap<int,etat> multi;

    multi = a.getEtat(toDisplay)->getTransitions();

    multit = multi.begin();

    while(multit != multi.end()){
        //On ajoute la transition à la liste des transitions
       right[toDisplay]->addVisualTransition((*multit).second.getNumber(),(*multit).first);
       multit++;
    }
}

void CreateAutomate::supprimeEtat(int cible){
    a.supprimeEtat(*a.getEtat(cible));
    refreshAll();
}

void CreateAutomate::refreshAll(){

    vector<etatLeft*>::iterator it;

    for(it=left.begin();it<left.end();it++){
        (*it)->hide();
        ui->etatVert->removeWidget((*it));
    }

    vector<etatRight*>::iterator it2;

    for(it2=right.begin();it2<right.end();it2++){
        (*it2)->hide();

    }

   left.clear();
   right.clear();

   //Maintenant il faut reconstruire en fonction de l'automate,
   vector<etat>::iterator it3;
   vector<etat> state;
   state = a.getEtats();

   for ( it3=state.begin() ; it3 < state.end(); it3++ ){
        ajoutEtat((*it3).isInitial(),(*it3).isFinal());
   }

   return;
}

void CreateAutomate::sauvegarder(){
    QFile destination(QFileDialog::getSaveFileName(
            this, tr( "Enregistrer dans un fichier DOT" ),"*.dot" ));
    destination.open(QFile::WriteOnly);

    QTextStream out(&destination);
    out << QString().fromStdString(a.toDot());

}

void CreateAutomate::displayAutomate(){
   QProcess ProcessT;
   QStringList procargs;
   ProcessT.close();

   QFile tmp("./tmp.dot");
   QFileInfo tmpInfo(tmp);
   tmp.open(QFile::WriteOnly);

   QTextStream out(&tmp);
   out << QString().fromStdString(a.toDot());
   tmp.close();

   procargs.push_back("-Tsvg");
   procargs.push_back("./tmp.dot");

   ProcessT.start("dot",procargs);
   ProcessT.waitForFinished();

   maVue->load(ProcessT.readAll());

   adjust();
}

void CreateAutomate::changeState(int etat,bool init,bool final){
    a.getEtat(etat)->setFinal(final);
    a.getEtat(etat)->setInitial(init);
}

void CreateAutomate::adjust(){
    maVue->adjustSize();
    ui->vueTomate->adjustSize();
    //adjustSize();
}
