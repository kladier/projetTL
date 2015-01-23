#include <QtGui>
#include <QFrame>
#include <QMessageBox>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "automate.h"
#include "createautomate.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ProcessT = new QProcess();
    ui->setupUi(this);
    setWindowTitle("Autoroute, en route vers les automates!");
    maVue1 = new QSvgWidget(ui->vue1);
    maVue2 = new QSvgWidget(ui->vue2);
    maVue = new QSvgWidget(ui->vueTomate);

    ui->boutonSuiv->hide();
    ui->boutonPrec->hide();
    ui->scrollArea_2->hide();
    ui->scrollArea_3->hide();
    ui->label->hide();
    connect(ui->boutonPrec,SIGNAL(clicked()),this, SLOT(getPrecedent()));
    connect(ui->boutonSuiv,SIGNAL(clicked()),this, SLOT(getSuivant()));
    connect(ui->actionOuvrir, SIGNAL(triggered()),this, SLOT(openFile()));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(creerAuto()));
    connect(ui->actionTest,SIGNAL(triggered()),this,SLOT(test()));
    connect(ui->actionFermer,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionClean,SIGNAL(triggered()),this,SLOT(resetUi()));
    connect(ui->actionInfo,SIGNAL(triggered()),this,SLOT(info()));
    connect(ui->actionDeterminiser,SIGNAL(triggered()),this,SLOT(getDetermin()));
    connect(ui->actionFaireProduit,SIGNAL(triggered()),this, SLOT(getProduit()));
    connect(ui->actionStandardiser,SIGNAL(triggered()),this,SLOT(getStandard()));

    adjust();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::startLayouting(){
    if( ProcessT->state() != QProcess::NotRunning )
    {
        ProcessT->close();
    }

    if( !dotFileName.isEmpty() )
    {
        ProcessT->close();
        QStringList procargs;
        procargs.push_back("-Tsvg");
        procargs.push_back( dotFileName);

        ProcessT->start("dot",procargs);
        ProcessT->waitForFinished();

        maVue->load(ProcessT->readAll());
        adjust();

    }
}

void MainWindow::getStandard() {

}

void MainWindow::openFile(){
    ui->boutonPrec->hide();
    ui->boutonSuiv->hide();
    ui->scrollArea_2->hide();
    ui->scrollArea_3->hide();
    resetUi();

    dotFileName = QFileDialog::getOpenFileName(
            this, tr( "Ouvrir un fichier DOT" ),"*.dot" );

    if( !QFile::exists(dotFileName) )
    {
        QMessageBox::critical( this, tr( "Erreur" ), tr( "Le fichier \"%1\"n'existe pas!" ).arg(dotFileName ) );
        return;
    }

    lireDot();
    startLayouting();
    ui->actionFaireProduit->setVisible(true);
    ui->actionStandardiser->setVisible(true);
    maVue->show();
    adjust();
    ui->actionDeterminiser->setVisible(true);
}

void MainWindow::getProduit(){
    //On recupère l'automate dont on veut le produit.
    dotFileNameB.clear();
    QFileDialog tempFen;

    lireDot();

    dotFileNameB = tempFen.getOpenFileName(this, tr( "Ouvrir un fichier DOT " ),QString(),"*.dot");


    if( !QFile::exists(dotFileNameB) )
    {
        QMessageBox::critical( this, tr( "Erreur" ), tr( "Le fichier \"%1\"n'existe pas!" ).arg(dotFileName ) );
        return;
    }
    lireDotB();
    //On affiche ensuite les deux automates superieurs.

    QProcess ProcessT;
    QStringList procargs;
    ProcessT.close();

    QFile tmp("./tmp.dot");
    tmp.open(QFile::WriteOnly);

    QTextStream out(&tmp);
    out << QString().fromStdString(a.toDot());
    tmp.close();

    procargs.push_back("-Tsvg");
    procargs.push_back("./tmp.dot");

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue1->load(ProcessT.readAll());

   /*On fait ensuite la même chose pour le second automate */

    ProcessT.close();

    QFile tmp2("./tmp.dot");
    tmp2.open(QFile::WriteOnly);

    QTextStream out2(&tmp2);
    out2 << QString().fromStdString(B.toDot());
    tmp2.close();


    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue2->load(ProcessT.readAll());
    //On affiche ensuite la partie graphique du bas
    actuel = 0;
    monVector=a.produit(B);

    ProcessT.close();

    QFile tmp3("./tmp.dot");
    tmp3.open(QFile::WriteOnly);

    QTextStream out3(&tmp3);
    out3 << QString().fromStdString(monVector[actuel].toDot());
    tmp3.close();

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue->load(ProcessT.readAll());

    ui->boutonPrec->show();
    ui->boutonSuiv->show();
    ui->scrollArea_2->show();
    ui->scrollArea_3->show();
    maVue1->show();
    maVue2->show();
    maVue->show();
    //Ensuite , on met le commentaire à droite.
    ui->label->clear();
    ui->label->insertPlainText("L'automate résultat du produit a une taille de m*n (m taille du premier automate, n taille du second).\n");
    ui->label->insertPlainText("On nomme chaque état de la façon suivante: etat p du premier automate, etat q du second automate.\n");
    ui->label->insertPlainText("Ensuite, une transition existe entre p1,q1 et p2,q2 si et seulement si");
    ui->label->insertPlainText(" il existe une transition entre p1  et p2  par i dans le premier automate ET une transition entre q1 et q2 par i également dans le second automate.\n");
    ui->label->insertPlainText("Enfin, un état est initial si les état p et q sont initiaux. De même pour les états finaux.");
    ui->label->show();
    ui->actionFaireProduit->setVisible(false);
    ui->actionDeterminiser->setVisible(true);
    adjust();
}

void MainWindow::afficheAutomate(Automate a){


    QTextBrowser* m = new QTextBrowser(this);
    QMainWindow* n = new QMainWindow(this);

    n->setCentralWidget(m);;

    m->append(QString().fromStdString(a.toDot()));
    //m->append(QString().setNum(a.getSizealpha()));
    n->show();
}

void MainWindow::creerAuto(){
    CreateAutomate* z  = new CreateAutomate(this);
    z->show();
}

bool MainWindow::lireDot(){
    Automate b;
    if(!dotFileName.isEmpty()){
        QFile monDot(dotFileName);
        if (!monDot.open(QIODevice::ReadOnly)){
            return false;
        }

        //On doit faire un premier parcour, pour ajouter tout les états de l'automate
        QTextStream in(&monDot);

        while (!in.atEnd()) {

            QString line = in.readLine();
            //On separe notre ligne, en utilisant les espaces comment caractere delimiteur
            QStringList maLigne(line.split((QRegExp("\\s+"))));
            //Str permet de garder en mémoire le mot precedent de la ligne.
            QString MotPrec;
            foreach( QString str,maLigne){

                if(str==";"){
                    //Le mot precedent ; est MotPrec
                    //Si il n'est pas null
                    if(!MotPrec.isNull()){
                        int Etat;
                        //Et si son premier char est un int

                        if(MotPrec.at(0).digitValue()!=-1){
                            //On ajoute l'état
                            Etat = MotPrec.at(0).digitValue();
                            b.ajoutEtat(Etat);
                        }
                        if(MotPrec.at(MotPrec.size()-1).digitValue()!=-1 && (MotPrec.size()-1)==4 ){
                            //On ajoute l'état
                            Etat = MotPrec.at(MotPrec.size()-1).digitValue();
                            b.ajoutEtat(Etat);
                            b.getEtat(Etat)->setInitial(true);
                        }
                        //Puis si il est final
                        if(MotPrec.contains("peripheries")){
                            b.getEtat(Etat)->setFinal(true);
                        }
                    }
                }
                MotPrec = str;
            }
        }
        monDot.close();
        if (!monDot.open(QIODevice::ReadOnly)){
            return false;
        }
        // On reparcour une seconde fois, pour ajouter les transitions
        QTextStream in2(&monDot);
        while(!in2.atEnd()){
            QString line = in2.readLine();
            QStringList maLigne(line.split((QRegExp("\\s+"))));
            QString motPrec;
            foreach(QString str,maLigne){
                if(str.contains("->")){
                    motPrec = str;
                }
                if(str.contains("label")){

                    b.ajoutTransition(
                            *b.getEtat(motPrec.at(0).digitValue())
                            ,*b.getEtat(motPrec.at(3).digitValue()),str.at(8).digitValue());

                }
            }
        }
    }
    a = b;
    return false;
}

bool MainWindow::lireDotB(){
    Automate b;
    if(!dotFileNameB.isEmpty()){
        QFile monDot(dotFileNameB);
        if (!monDot.open(QIODevice::ReadOnly)){
            return false;
        }

        //On doit faire un premier parcour, pour ajouter tout les états de l'automate
        QTextStream in(&monDot);

        while (!in.atEnd()) {

            QString line = in.readLine();
            //On separe notre ligne, en utilisant les espaces comment caractere delimiteur
            QStringList maLigne(line.split((QRegExp("\\s+"))));
            //Str permet de garder en mémoire le mot precedent de la ligne.
            QString MotPrec;
            foreach( QString str,maLigne){

                if(str==";"){
                    //Le mot precedent ; est MotPrec
                    //Si il n'est pas null
                    if(!MotPrec.isNull()){
                        int Etat;
                        bool initial;
                        //Et si son premier char est un int

                        if(MotPrec.at(0).digitValue()!=-1){
                            //On ajoute l'état
                            Etat = MotPrec.at(0).digitValue();
                            b.ajoutEtat(Etat);
                        }
                        if(MotPrec.at(MotPrec.size()-1).digitValue()!=-1 && (MotPrec.size()-1)==4 ){
                            //On ajoute l'état
                            Etat = MotPrec.at(MotPrec.size()-1).digitValue();
                            b.ajoutEtat(Etat);
                            b.getEtat(Etat)->setInitial(true);
                            initial = true;

                        }
                        //Puis si il est final
                        if(MotPrec.contains("peripheries")){
                            b.getEtat(Etat)->setFinal(true);
                        }
                    }
                }
                MotPrec = str;
            }
        }
        monDot.close();
        if (!monDot.open(QIODevice::ReadOnly)){
            return false;
        }
        // On reparcour une seconde fois, pour ajouter les transitions
        QTextStream in2(&monDot);
        while(!in2.atEnd()){
            QString line = in2.readLine();
            QStringList maLigne(line.split((QRegExp("\\s+"))));
            QString motPrec;
            foreach(QString str,maLigne){
                if(str.contains("->")){
                    motPrec = str;
                }
                if(str.contains("label")){

                    b.ajoutTransition(
                            *b.getEtat(motPrec.at(0).digitValue())
                            ,*b.getEtat(motPrec.at(3).digitValue()),str.at(8).digitValue());

                }
            }
        }
    }
    B = b;
    return false;
}

void MainWindow::getSuivant(){
    if(monVector.empty()==false){
        if(actuel<monVector.size()-1){
            actuel++;
        }
    }
    else{
        if(actuel<monDeterminisme.size()-1){
            actuel++;        }
    }
    QProcess ProcessT;
    QStringList procargs;
    ProcessT.close();

    QFile tmp("./tmp.dot");
    tmp.open(QFile::WriteOnly);

    QTextStream out(&tmp);
    if (monVector.empty()== false){
        out << QString().fromStdString(monVector[actuel].toDot());
    }
    else{
        out << QString().fromStdString(monDeterminisme[actuel].first.toDot());
        ui->label->clear();
        for(unsigned int j = 0;j<=actuel;j++){
            QString texte;
            string texte2 = monDeterminisme[j].second;
            QTextStream(&texte)<<"\n--ETAPE "<<(j+1)<<"--\n";
            ui->label->insertPlainText(texte);
            ui->label->insertPlainText(QString().fromStdString(texte2));
        }
    }
    tmp.close();

    procargs.push_back("-Tsvg");
    procargs.push_back("./tmp.dot");

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue->load(ProcessT.readAll());
    adjust();
}

void MainWindow::getPrecedent(){
    if(actuel>0){
        actuel--;
    }
    QProcess ProcessT;
    QStringList procargs;
    ProcessT.close();

    QFile tmp("./tmp.dot");
    tmp.open(QFile::WriteOnly);

    QTextStream out(&tmp);
    if (monVector.empty()== false){
        out << QString().fromStdString(monVector[actuel].toDot());
    }
    else{
        out << QString().fromStdString(monDeterminisme[actuel].first.toDot());
        ui->label->clear();
        for(unsigned int j = 0;j<=actuel;j++){
            QString texte;
            string texte2 = monDeterminisme[j].second;
            QTextStream(&texte)<<"\n--ETAPE "<<(j+1)<<"--\n";
            ui->label->insertPlainText(texte);
            ui->label->insertPlainText(QString().fromStdString(texte2));
        }
    }
    tmp.close();

    procargs.push_back("-Tsvg");
    procargs.push_back("./tmp.dot");

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue->load(ProcessT.readAll());
    adjust();
}

void MainWindow::adjust(){
    maVue->adjustSize();
    ui->vueTomate->adjustSize();
    maVue1->adjustSize();
    ui->vue1->adjustSize();
    maVue2->adjustSize();
    ui->vue2->adjustSize();
    ui->label->setMaximumWidth(this->width()*(0.25));
    ui->label->verticalScrollBar()->setSliderPosition(100000);
}

void MainWindow::test(){
    QTextBrowser* m = new QTextBrowser(this);
    QMainWindow* n = new QMainWindow(this);

    n->setCentralWidget(m);

    vector <  pair< Automate , string > > test;

    test=a.determinise();

    for(unsigned int i=0;i<test.size();i++){
       cout<<test[i].second<<endl;
    }

    afficheAutomate(test[test.size()-1].first);


}

void MainWindow::resetUi(){
    ui->boutonPrec->hide();
    ui->boutonSuiv->hide();
    ui->scrollArea_2->hide();
    ui->scrollArea_3->hide();
    ui->actionFaireProduit->setVisible(false);
    maVue->clearFocus();
    maVue->hide();
    maVue1->hide();
    maVue2->hide();
    ui->label->hide();
    ui->actionDeterminiser->setVisible(false);

}

void MainWindow::info(){
    if (ui->label->isVisible()){
        ui->label->hide();
    }
    else{
        ui->label->clear();
        ui->label->show();


        ui->label->insertHtml("<img src = \":./new/prefix1/Images/nouveau.png\" WIDTH = 20 HEIGHT = 20 alt = \"Nouveau \"/>");
        ui->label->insertPlainText(" : ce bouton permet de créer un nouvel automate.\n");
        ui->label->insertHtml("<img src = \":./new/prefix1/Images/home.png\" WIDTH = 20 HEIGHT = 20 alt = \"Nouveau \"/>");
        ui->label->insertPlainText(" : ce bouton permet de charger un automate.\n");
        ui->label->insertHtml("<img src = \":./new/prefix1/Images/clean.png\" WIDTH = 20 HEIGHT = 20 alt = \"Nouveau \"/>");
        ui->label->insertPlainText(" : ce bouton permet de nettoyer l'interface.\n");
        ui->label->insertPlainText("\n \nUne fois que vous avez chargé un automate, de nouvelles options apparaissent :\n");
        ui->label->insertHtml("<img src = \":./new/prefix1/Images/produit.png\" WIDTH = 20 HEIGHT = 20 alt = \"Nouveau \"/>");
        ui->label->insertPlainText(" : ce bouton permet de faire le produit de l'automate courant avec un autre automate.\n");
        ui->label->insertHtml("<img src = \":./new/prefix1/Images/determin.png\" WIDTH = 20 HEIGHT = 20 alt = \"Nouveau \"/>");
        ui->label->insertPlainText(" : ce bouton determinise l'automate courant.\n");

        adjust();
    }
}

void MainWindow::getDetermin(){
    resetUi();
    ui->actionFaireProduit->setVisible(true);
    //On netoi l'eventuel vecteur de produit
    monVector.clear();
    actuel = 0;
    //On affiche l'automate a dans la vue superieur.
    QProcess ProcessT;
    QStringList procargs;
    ProcessT.close();

    QFile tmp("./tmp.dot");
    tmp.open(QFile::WriteOnly);

    QTextStream out(&tmp);
    out << QString().fromStdString(a.toDot());
    tmp.close();

    procargs.push_back("-Tsvg");
    procargs.push_back("./tmp.dot");

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue1->load(ProcessT.readAll());
    ui->scrollArea_3->show();
    maVue1->show();
    //on recupere le vecteur de determinisme
    monDeterminisme = a.determinise();
    //On affiche le premier element en bas

    ProcessT.close();

    QFile tmp2("./tmp.dot");
    tmp2.open(QFile::WriteOnly);

    QTextStream out2(&tmp2);
    out2 << QString().fromStdString(monDeterminisme[0].first.toDot());
    tmp2.close();

    ProcessT.start("dot",procargs);
    ProcessT.waitForFinished();

    maVue->load(ProcessT.readAll());
    maVue->show();
    ui->boutonPrec->show();
    ui->boutonSuiv->show();
    //On affiche ensuite l'aide à droite
    ui->label->clear();
    ui->label->show();
    string texte = monDeterminisme[actuel].second;
    ui->label->insertPlainText("--ETAPE 1--\n");
    ui->label->insertPlainText(QString().fromStdString(texte));
    adjust();
}
