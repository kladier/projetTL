#include "automate.h"
#include <sstream>
#include <iostream>

using namespace std;

Automate::Automate()
{

}

Automate::~Automate()
{

}

Automate::Automate(const Automate &a){
    etats=a.etats;
}



void Automate::ajoutEtat(etat cible){
    vector<etat>::iterator it;

        //On test si l'état cible existe déja.
    for ( it=etats.begin() ; it != etats.end(); it++ ){

        if((*it).numero == cible.numero){
            return;
        }

    }

    etats.push_back(cible);
}

//renvoie le nombre de transition portant une étiquette différente dans un automate
int Automate::getNbTransition() {
    vector<int> temp;
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
        multimap<int,etat> tempTrans=(*it).getTransitions();
        multimap<int,etat>::iterator it2;
        for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            if ((std::find(temp.begin(),temp.end(),it2->first))==temp.end()) {
                temp.push_back(it2->first);
            }
        }
    }

    return temp.size();


  /*  int res;
    vector<int> temp;
    for (int i=0;i<etats.size();i++) {
        for (int j=0;j<etats[i].getTransitions().size();j++) {
            if ()
        }
    }

    res=temp.size();
    return res;*/
}


bool Automate::isComplet() {
    int nbTrans=getTabTransitions().size();
    for (int i=1;i<nbTrans+1;i++) {
        for (unsigned int j=0;j<etats.size();j++) {
            if (cible_transition(j,i)==-1) {
                return false;
            }
        }
    }
    return true;
}


bool Automate::isDeterministe () {
    //on vérifie déjà qu'il n'y est qu'un seul etat initial
    int compt2=0;
    for (unsigned int i=0;i<etats.size();i++) {
        if (etats[i].isInitial()) {
            compt2++;
        }
    }
    if (compt2>1) {
        return false;
    }
    //pour chaque état, on va vérifier que chaque lettre a une seule destination ou aucune
    int nbTransitions=getNbTransition();
    for (unsigned int i=0;i<etats.size();i++) {
        for (int j=1;j<nbTransitions+1;j++) {
            int compt=0;
            multimap<int,etat> tempTrans=etats[i].getTransitions();
            multimap<int,etat>::iterator it2;
            for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
                if(it2->first==j) {
                    compt++;
                }
            }
            if (compt>1) return false;
        }
    }
    return true;
}




etat* Automate::getEtat(int number){
    vector<etat>::iterator it;
    for ( it=etats.begin() ; it != etats.end(); it++ ){
        if ((*it).numero == number){
            return &(*it);
        }
    }
    return 0 ;
}

vector<etat> Automate::getEtats(){
    return etats;
}

void Automate::ajoutTransition(etat from,etat to, int vocab){
    vector<etat>::iterator it;

    for ( it=etats.begin() ; it != etats.end(); it++ ){
        if ((*it).numero == from.numero){
            (*it).ajoutTransition(to,vocab);
        }
    }
    return;
}

void Automate::supprimeEtat(etat cible){
    vector<etat>::iterator it;

    multimap<int,etat>::iterator it2;
    multimap<int,etat> multi;

    for ( it=etats.begin() ; it != etats.end(); it++ ){
        multi = (*it).getTransitions();
        it2 = multi.begin();
        while(it2 != multi.end()){
            if( ((*it2).second.numero == cible.numero)){
                (*it).supprimeTransition((*it2).second,(*it2).first);
            }
            else if(((*it2).second.numero > cible.numero)){
            (*it).renameTransition((*it2).second);

            }
            it2++;
        }
    }

    for ( it=etats.begin() ; it < etats.end(); it++ ){

        if ((*it).numero == cible.numero){
                etats.erase(it);
            }
        }
//On renome les transition
    for (it=etats.begin() ; it != etats.end(); it++ ){
        multi = (*it).getTransitions();
        it2 = multi.begin();
        while(it2 != multi.end()){
            if( ((*it2).second.numero >= cible.numero)){
                (*it2).second.numero--;
            }
            it2++;
        }
    }
//ON renome ensuite les états
    for ( it=etats.begin() ; it != etats.end(); it++ ){

        if ((*it).numero >= cible.numero){
                (*it).numero--;
            }
        }

    return;
}

void Automate::supprimeEtat(etat cible, Automate * a){
    vector<etat>::iterator it;

    multimap<int,etat>::iterator it2;
    multimap<int,etat> multi;

    for ( it=a->etats.begin() ; it != a->etats.end(); it++ ){
        multi = (*it).getTransitions();
        it2 = multi.begin();
        while(it2 != multi.end()){
            if( ((*it2).second.numero == cible.numero)){
                (*it).supprimeTransition((*it2).second,(*it2).first);
            }
            else if(((*it2).second.numero > cible.numero)){
            (*it).renameTransition((*it2).second);

            }
            it2++;
        }
    }

    for ( it=a->etats.begin() ; it < a->etats.end(); it++ ){

        if ((*it).numero == cible.numero){
                a->etats.erase(it);
            }
        }
//On renome les transition
    for (it=a->etats.begin() ; it != a->etats.end(); it++ ){
        multi = (*it).getTransitions();
        it2 = multi.begin();
        while(it2 != multi.end()){
            if( ((*it2).second.numero >= cible.numero)){
                (*it2).second.numero--;
            }
            it2++;
        }
    }
//ON renome ensuite les états
    for ( it=a->etats.begin() ; it != a->etats.end(); it++ ){

        if ((*it).numero >= cible.numero){
                (*it).numero--;
            }
        }

    return;
}




string Automate::toDot(){
    string out;

    out = "digraph a { \n";
    vector<etat>::iterator it;

    multimap<int,etat>::iterator it2;
    multimap<int,etat> multi;

    for ( it=etats.begin() ; it != etats.end(); it++ ){
        ostringstream format;
            if((*it).isInitial()&& (*it).isFinal()){
                format <<(*it).getNameF()<<"[shape=point] ;\n";
                format <<(*it).getNameF()<<"->"<<(*it).getName()<<" ;"<<endl;
                format << (*it).getName() << "[peripheries=2] ;\n";
                }
            else if((*it).isInitial()){
                format <<(*it).getNameF()<<"[shape=point] ;\n";
                format <<(*it).getNameF()<<"->"<<(*it).getName()<<" ;"<<endl;
                }
            else if((*it).isFinal()){
                format << (*it).getName() << "[peripheries=2] ;\n";
                }
            else {
                format << (*it).getName() << " ;\n";
                }
            out.append(format.str());

            multi = (*it).getTransitions();
            it2 = multi.begin();
            while(it2 != multi.end()){
                ostringstream formatter1;

                formatter1 << (*it).getName() << "->" <<getEtat((*it2).second.getNumber())->getName();
                formatter1 << " [label=\""<<(*it2).first;
                formatter1 << "\"] ;\n";

                out.append(formatter1.str());

                it2++;
            }
        }

    out.append("\n }");
    return out;
}


//cette fonction est à modifier/tester, elle ne fonctionne pas.
void Automate::supprimerEtatsNonAccessibles(Automate * a) {
    //on vérifie que chaque état soit accessible
    for (unsigned int i=0;i<a->etats.size();i++) {
        if (a->etats[i].isInitial()==false) {
            bool continuer=true;
            unsigned int j=0;
            while (continuer&&j<a->etats.size()) {
               //les transitions allant vers lui même ne compte pas
                if (j!=i) {
                    //on va maintenant vérifier s'il y a une transition de j qui va vers i
                    if (a->etats[j].find_transition(a->etats[i])) {
                        continuer=false;
                    }
                }
                j++;
            }
            if (continuer) {
                supprimeEtat(a->etats[i],a);
            }
        }
    }
}

bool Automate::isStandard() {
    //on vérifie déjà qu'il n'y a qu'un seul état initial
    int comptEtatInit=0, numEtatInit;

    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
        if (it->isInitial()) {
            comptEtatInit++;
            numEtatInit=(*it).numero;
        }
    }

    if (comptEtatInit!=1) {
        return false;
    }

    //on vérifie ensuite qu'aucune transition n'arrive à l'état initial
    //pour cela, on vérifie toutes les transitions de chaque états.
    for (it=etats.begin();it!=etats.end();it++) {
         multimap<int,etat> tempTrans=(*it).getTransitions();
        multimap<int,etat>::iterator it2;
        for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            if (it2->second.numero==numEtatInit) {
                return false;
            }
        }
    }
    return true;
}

string convertIntToString(int i) {
    char numstr[21];
    std::sprintf(numstr, "%d", i);
    return numstr;
}

//cette fonction renvoie le numero de l'état qui est ciblé par la transition partant de l'etat this et portant l'etiquette etiq.
//renvoie -1 sinon
int Automate::cible_transition(int etatDepart, int etiq) {
    multimap<int,etat>::iterator it2;
    multimap<int,etat> tabTransitions=etats[etatDepart].getTransitions();
    for (it2=tabTransitions.begin();it2!=tabTransitions.end();it2++) {
        if ((it2->first)==etiq) {
            return it2->second.numero;
        }
    }
    return -1;
}


vector<int> Automate::getTabTransitions() {
    vector<int> res;
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
        multimap<int,etat> tempTrans=(*it).getTransitions();
        multimap<int,etat>::iterator it2;
        for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            if ((std::find(res.begin(),res.end(),it2->first))==res.end()) {
                res.push_back(it2->first);
            }
        }
    }

    return res;
}


//Fonction utilisée uniquement pour la minimisation
//cette fonction renvoie le numero de l'etat en fonction de son bilan precedent et de ces lignes pour les transitions
//elle sert en fait pour définir un nouveau bilan
//si l'etat n'existe pas déjà, il l'ajoute
int existInTabBilan(int numEtat, vector < pair< vector<int> , int > > * tabBilan, vector< vector<int> > tabMinimisation, int nbTransitions, int iBilanCourant) {
    //on récupére dans un vector<int> tout les chiffres dont on a besoin (bilan 0, en 1, en 2 etc)
    vector<int> nbUtilises;
    for (int i=iBilanCourant;i<nbTransitions+1+iBilanCourant;i++) {
        nbUtilises.push_back(tabMinimisation[numEtat][i]);
        //tabMinimisation[numEtat][i])
    }

    //pour chaque ligne de tabBilan, on regarde si on a le meme vector (on compare donc nbUtilises avec le premier element de la pair)
    for (unsigned int i=0;i<tabBilan->size();i++) {
        bool continuer=true;
        int j=0;
        while (continuer) {
            if (tabBilan->at(i).first[j]==nbUtilises[j]) {
                j++;
            }
            else {
                continuer=false;
            }
            if (j==nbTransitions+1) {
                return tabBilan->at(i).second;
            }
        }
    }

    //si l'on arrive là, c'est que cette combinaison n'existe pas, on l'ajoute donc
    tabBilan->push_back(pair< vector<int> , int >(nbUtilises,tabBilan->size()+1));
    return tabBilan->at(tabBilan->size()-1).second;
}

//Fonction utilisée uniquement pour la minimisation
//Sert à comparer 2 bilans, retourne true s'ils sont égaux, false sinon
bool compareBilans(int iBilanCourant, int iBilanPrec, vector< vector<int> > tabMinimisation) {
    for (unsigned int i=0;i<tabMinimisation.size();i++) {
        if (tabMinimisation[i][iBilanCourant]!=tabMinimisation[i][iBilanPrec]) {
            return false;
        }
    }
    return true;
}

//utilisé seulement dans la minimisation, permet de savoir combien d'états il y a selon le dernier bilan fait dans tabMinimisation
int compteNbEtatsDansBilan(vector< vector<int> > tabMinimisation) {
    vector<int> temp;
    for (unsigned int i=0;i<tabMinimisation.size();i++) {
        if (std::find(temp.begin(), temp.end(), tabMinimisation[i][tabMinimisation[i].size()-1])==temp.end()) {
            temp.push_back(tabMinimisation[i][tabMinimisation[i].size()-1]);
        }
    }
    return temp.size();
}

//permet, pour un numéro d'état, de renvoyer le tableau dont chaque élément correspond à la cible de la transition
//utilisé seulement dans la minimisation
vector<int> renvoyerTabTransition(vector< vector<int> > tabMinimisation,int nbTransition, int iColonne) {
    vector<int> res;

    for (int i=0;i<nbTransition;i++) {
        int ligne=tabMinimisation[iColonne].size()-1-nbTransition+i;
        res.push_back(tabMinimisation[iColonne][ligne]);
    }
    return res;
}

//utilisé seulement pour la minimisation, renvoie l'indice de la colonne de l'état
//renvoie -1 s'il ne trouve pas
int trouverIndiceColonne(vector< vector<int> > tabMinimisation,int numEtat) {
    for (unsigned int i=0;i<tabMinimisation.size();i++) {
        if (numEtat==tabMinimisation[i][tabMinimisation[0].size()-1]) {
            return i;
        }
    }
    return -1;
}

string Automate::toStringTabMini(vector< vector<int> > tabMinimisation) {
    string affichageTableau;
    for (unsigned int k=0;k<etats.size();k++) {
        affichageTableau+="  E"+etats[k].getName()+" |";
    }
    affichageTableau+="\n";
    for (unsigned int i=0;i<tabMinimisation[0].size();i++) {
        for (unsigned int j=0;j<tabMinimisation.size();j++) {
            affichageTableau=affichageTableau+"  "+convertIntToString(tabMinimisation[j][i])+"   |";
        }
        affichageTableau=affichageTableau+"\n";
    }
    return affichageTableau;
}


vector <  pair< Automate , string > > Automate::minimise() {
    vector <  pair< Automate , string > > res;
    Automate *temp = new Automate;

    string commentaire="\nAvant de minimiser, il faut d'abord construire un tableau de minimisation.\n";
    commentaire+="Chaque colonne représente un état de l'automate à minimiser.\n";
    commentaire+="Cette première ligne appelée bilan 0 est simple à réaliser, les états finaux prennent le chiffre 2, les autres états prennent le chiffre 1.\n\n";


    vector< vector<int> > tabMinimisation;


    //on s'occupe du bilan 0
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
        if (it->isFinal()) {
            tabMinimisation.push_back(vector<int>(1,2));
        }
        else {
            tabMinimisation.push_back(vector<int>(1,1));
        }
    }

    commentaire+=toStringTabMini(tabMinimisation);

    res.push_back(pair< Automate , string >(*temp,commentaire));


    commentaire="\nOn réalise désormais, pour chaque transition (par exemple, pour la transition qui porte l'étiquette 1), une ligne où l'on va spécifier, pour chaque état, vers quel état il va.)";
    vector<int> tabTransition=getTabTransitions();
    int nbTransDiff=tabTransition.size();
    int iBilanCourant=0;

    //on s'occupe ici des lignes "en 1", "en 2" etc
    for (int i=1;i<nbTransDiff+1;i++) {
        for (unsigned int j=0;j<tabMinimisation.size();j++) {
            //a partir de l'etat n° j et de la transition n°i, on détermine ou vers quel état va cette transition
            int etatcible=cible_transition(j,i);
            tabMinimisation[j].push_back(tabMinimisation[etatcible][iBilanCourant]);
        }
    }


    commentaire+="\n\n"+toStringTabMini(tabMinimisation);

    res.push_back(pair< Automate , string >(*temp,commentaire));

    commentaire="\nOn réalise désormais le bilan 1, en prenant en compte toutes les lignes de type \"pour la transition 1\" et le dernier bilan, c'est-à-dire le bilan 0.\n";
    commentaire+="Chaque groupe formé est unique et s'il n'existe pas déjà, on lui attribue un numéro";

    //on réalise désormais le bilan 1, pour cela on associe un chiffre à un tableau d'entier
    //concrétement, on utilise les n dernières lignes (du bilan 0 et ttes les lignes des transitions) pour définir un chiffre
    vector < pair< vector<int> , int > > tabBilan;
    for (unsigned int i=0;i<tabMinimisation.size();i++) {
        tabMinimisation[i].push_back(existInTabBilan(i,&tabBilan,tabMinimisation,nbTransDiff,iBilanCourant));
    }
    iBilanCourant=iBilanCourant+nbTransDiff+1;

    commentaire+="\n\n"+toStringTabMini(tabMinimisation)+"\nOn compare désormais les bilans, pour chaque état, on doit avoir le même chiffre, si c'est le cas les bilans sont égaux et le tableau de minimisation est terminé.\n";

    //on compare le bilan 0 au bilan 1
    if (compareBilans(iBilanCourant,iBilanCourant-nbTransDiff-1,tabMinimisation)) {
        commentaire+="\n On voit que les bilans 0 et 1 sont les memes, la minimisation s'arrete donc ici.\n";
        res.push_back(pair< Automate , string >(*temp,commentaire));
    }
    else {
        //on continue de miniser
        commentaire=commentaire+"\n Les bilans 0 et 1 n'étant pas égaux, on continue la minimisation.\n";
        res.push_back(pair< Automate , string >(*temp,commentaire));

        commentaire="\nOn refait l'étape pour les transitions, en prenant en compte le nouveau bilan.\n";
        //on s'occupe ici des lignes "en 1", "en 2" etc
        for (int i=1;i<nbTransDiff+1;i++) {
            for (unsigned int j=0;j<tabMinimisation.size();j++) {
                //a partir de l'etat n° j et de la transition n°i, on détermine ou vers quel état va cette transition
                int etatcible=cible_transition(j,i);
                tabMinimisation[j].push_back(tabMinimisation[etatcible][iBilanCourant]);
            }
        }

        commentaire+="\n"+toStringTabMini(tabMinimisation);

        res.push_back(pair< Automate , string >(*temp,commentaire));

        commentaire="\nOn réalise maintenant le bilan 2 et on le compare au bilan 1.\n";

        //on réalise désormais le bilan 2
        tabBilan.clear();
        for (unsigned int i=0;i<tabMinimisation.size();i++) {
            tabMinimisation[i].push_back(existInTabBilan(i,&tabBilan,tabMinimisation,nbTransDiff,iBilanCourant));
        }
        iBilanCourant=iBilanCourant+nbTransDiff+1;

        //on compare le bilan 1 au bilan 2
        if (compareBilans(iBilanCourant,iBilanCourant-nbTransDiff-1,tabMinimisation)) {
            commentaire+="\n On voit que les bilans 1 et 2 sont les memes, la minimisation s'arrete donc ici.\n";

            res.push_back(pair< Automate , string >(*temp,commentaire));

        }
        else {
            //on continue de miniser jusqu'a ce que les bilans soient égaux
            commentaire+="\n Les bilans 1 et 2 n'étant pas égaux, on continue la minimisation.\n";

            res.push_back(pair< Automate , string >(*temp,commentaire));

            commentaire="On va au bout de la minimisation : on s'occupe des lignes concernant les transitions, on fait le bilan, on le compare au précédent et si ce n'est pas les mêmes on refait la même chose.\n";
            while (!compareBilans(iBilanCourant,iBilanCourant-nbTransDiff-1,tabMinimisation)) {
                //on s'occupe ici des lignes "en 1", "en 2" etc
                for (int i=1;i<nbTransDiff+1;i++) {
                    for (unsigned int j=0;j<tabMinimisation.size();j++) {
                        //a partir de l'etat n° j et de la transition n°i, on détermine ou vers quel état va cette transition
                        int etatcible=cible_transition(j,i);
                        tabMinimisation[j].push_back(tabMinimisation[etatcible][iBilanCourant]);
                    }
                }

                //on réalise désormais le bilan
                tabBilan.clear();
                for (unsigned int i=0;i<tabMinimisation.size();i++) {
                    tabMinimisation[i].push_back(existInTabBilan(i,&tabBilan,tabMinimisation,nbTransDiff,iBilanCourant));
                }
                iBilanCourant=iBilanCourant+nbTransDiff+1;

            }

            commentaire+="\n"+toStringTabMini(tabMinimisation);
            commentaire+="\nOn remarque que les deux derniers bilans sont égaux, le tableau de minimisation est terminé.\n";
            res.push_back(pair< Automate , string >(*temp,commentaire));
        }
    }


    commentaire="\nA partir du dernier bilan et des dernières lignes concernant les transitions, nous allons construire l'automate minimisé.\n";
    commentaire+="\n On s'occupe de créer tout les états. S'ils étaient initiaux et/ou finaux, ils le restent.\n";

    //on associe ici l'indice du num de colonne dans tabMinimisation a un nouvel état : l'état 1 va correspondre à la colonne 0 par exemple
    int nbEtatsDansBilan = compteNbEtatsDansBilan(tabMinimisation);
    vector< pair< int , int > > assoEtatIndiceTabMini;
    for (int i=1;i<nbEtatsDansBilan+1;i++) {
        assoEtatIndiceTabMini.push_back(pair< int , int >(i,trouverIndiceColonne(tabMinimisation,i)));
    }

    //une fois cette association réalisée, il est facile de s'occuper des états
    //lorsqu'on ajoute un état, on vérifie s'il est initial ou non grace à l'indice associée, correspondant au numéro de l'état actuel
    for (int i=1;i<nbEtatsDansBilan+1;i++) {
        int j=0;
        for (unsigned int k=0;k<assoEtatIndiceTabMini.size();k++) {
            if (assoEtatIndiceTabMini[k].first==i) {
                j=assoEtatIndiceTabMini[k].second;
            }
        }
        temp->ajoutEtat((*new etat(i,etats[j].isInitial(),etats[j].isFinal())));
    }

    res.push_back(pair< Automate , string >(*temp,commentaire));

    commentaire="\nOn s'occupe maintenant des transitions, pour chaque nouvel état, on va voir vers quel état vont chaque transition et on les dessine.\n";
    //cela simplifie aussi le travail pour les transitions
    for (int i=1;i<nbEtatsDansBilan+1;i++) {
        int j=0;
        for (unsigned int k=0;k<assoEtatIndiceTabMini.size();k++) {
            if (assoEtatIndiceTabMini[k].first==i) {
                j=assoEtatIndiceTabMini[k].second;
            }
        }
        vector<int> tempTransitions = renvoyerTabTransition(tabMinimisation,nbTransDiff,j);

        for (unsigned int l=0;l<tempTransitions.size();l++) {
            temp->getEtat(i)->ajoutTransition(*temp->getEtat(tempTransitions[l]),l+1);
        }
    }

    res.push_back(pair< Automate , string >(*temp,commentaire));


    return res;

}












//on remplit un vecteur d'automates, chaque élément correspondant à un automate
//quand le vecteur est lu (avec le bouton suivant), cela correspond à une étape dans l'ui
//numEtatCurr correspond au numéro de l'état suivant à ajouter
//temp est l'automate qu'on ajoute au fur et a mesure au vecteur de standardisation res
vector <  pair< Automate , string > > Automate::standardise() {
    vector <  pair< Automate , string > > res;
    Automate *temp = new Automate;
    int numEtatCurr=0;

    // 1) On crée le nouvel etat initial
    etat *e = new etat(numEtatCurr,true,false);
    numEtatCurr++;
    e->setName("0'");
    temp->ajoutEtat(*e);
    res.push_back(pair< Automate , string >(*temp,"On créé le nouvel état initial appelé 0'.\n"));

    // 2)on crée tout les autres états sans aucune transition (y compris les anciens états initial)
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
       etat *e = new etat(numEtatCurr,false,it->isFinal());
       numEtatCurr++;
       e->setName(it->getName());
       temp->ajoutEtat(*e);
    }
    res.push_back(pair< Automate , string >(*temp,"On créé tout les autres états sans aucune transition (y compris les anciens états initiaux).\n"));

    // 3) on s'occupe des cas particuliers (voir ci-dessous)
    //Cas particulier : quand un ancien état initial a une transition allant vers lui-même.
    //Dans ce cas là, il faut créer 2 transitions : une transition partant du nouvel état initial et allant vers le nouvel état correspondant et une transition partant de cet état et allant vers lui-même
    int numberCasParticulier=0;
    for( it=etats.begin() ; it!=etats.end() ; it++){
       if (it->isInitial()) {
            //si c'est un ancien etat initial, on vérifie qu'il n'a pas de transition allant vers lui-meme
           multimap<int,etat> tempTrans=(*it).getTransitions();
           multimap<int,etat>::iterator it2;
           for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
               if (it2->second.numero==it->numero) {
                    temp->ajoutTransition(*(temp->getEtat(it->numero+1)),*(temp->getEtat(it->numero+1)),it2->first);
                    temp->ajoutTransition(*(temp->getEtat(0)),*(temp->getEtat(it->numero+1)),it2->first);
                    numberCasParticulier++;
               }
           }
       }
    }

    string ajoutPourCasParticulier="Il y a dans cet automate "+convertIntToString(numberCasParticulier)+" cas particuliers à gérer.";
    res.push_back(pair< Automate , string >(*temp,"On s'occupe des cas particuliers.\nCas particulier : quand un ancien état initial a une transition allant vers lui-même. Dans ce cas là, il faut créer 2 transitions et un état : une transition partant du nouvel état initial et allant vers l'état nouvellement créé et une transition partant de cet état et allant vers lui-même.\n"+ajoutPourCasParticulier));


    // 4) on s'occupe des transitions partant du nouvel etat initial (correspondant aux transitions partant des anciens états initiaux)
    for( it=etats.begin() ; it!=etats.end() ; it++){
        if (it->isInitial()) {
            multimap<int,etat> tempTrans=(*it).getTransitions();
            multimap<int,etat>::iterator it2;
            for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
                //on précise qu'on ne s'occupe du cas ou cette transition allait vers l'état initial duquel il partait
                if (it2->second.numero!=it->numero) {
                    temp->ajoutTransition(*(temp->getEtat(0)),*(temp->getEtat(it->numero+2)),it2->first);
                }
            }
        }
    }
    res.push_back(pair< Automate , string >(*temp,"on s'occupe des transitions partant du nouvel etat initial : on ajoute toutes les transitions qui partaient des anciens états initiaux."));

    // 5) on reproduit toutes les anciennes transitions (sauf les cas particuliers, c'est déjà géré avant)
    for( it=etats.begin() ; it!=etats.end() ; it++){
        multimap<int,etat> tempTrans=(*it).getTransitions();
        multimap<int,etat>::iterator it2;
        for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            //on précise qu'on ne s'occupe du cas ou cette transition allait vers l'état initial duquel il partait
            if ((it->isInitial()&&it2->second.numero==it->numero)==false) {
                temp->ajoutTransition(*(temp->getEtat(it->numero+1)),*(temp->getEtat(it2->second.numero+1)),it2->first);
            }
        }
    }

    res.push_back(pair< Automate , string >(*temp,"on reproduit toutes les anciennes transitions (sauf les cas particuliers, c'est déjà géré avant).\n"));

    //Il faut modifier la fonction supprimerEtatsNonAccessibles()
    // 6) on supprime désormais tout les etats non accessibles
   supprimerEtatsNonAccessibles(temp);
    res.push_back(pair< Automate , string >(*temp,"On supprime désormais tout les états non accessibles, c'est-à-dire tout les états non initiaux vers lesquels aucune transition ne pointe.\n L'automate est maintenant standardisé.\n"));

    return res;
}

//a modifier : il faut avoir une structure comme la determinisation et la standardisation
vector<Automate> Automate::produit(Automate A){
   vector<Automate> produit;
   map< int, pair<etat,etat> > etat_prod; // équivalence etat automate f -> (etat_automate1,etat_automate2)

   int m=(A.etats).size();
   unsigned int i=0,j=0;
   int p,q,etiq;
   Automate temp;
   etat e;

   vector<etat>::iterator it_auto1;
   vector<etat>::iterator it_auto2;
   multimap<int, etat>::iterator it_trans1;
   multimap<int, etat> multiTmp;

   for(it_auto1=etats.begin();it_auto1!=etats.end();it_auto1++){

        p=(*it_auto1).numero;

        for(it_auto2=(A.etats).begin();it_auto2!=(A.etats).end();it_auto2++){

            q=(*it_auto2).numero;

            //création d'un nouvel automate recopiant celui de l'étape précédente
            if(p!=0 || q!=0){
                temp=Automate(produit[(p*m+q)-1]);

            }
            else
            {
                temp = Automate();

            }
            //création du nouvel état p*m+q
            e=etat(p*m+q,(this->getEtat(p))->isInitial() && (A.getEtat(q))->isInitial(),(this->getEtat(p))->isFinal() && (A.getEtat(q))->isFinal());
            ostringstream tmp;
            tmp<<p<<","<<q;
            e.setName(tmp.str());
            tmp.str("");
            (temp.etats).push_back(e);

            //remplissage de la map d'équivalence des états
            etat_prod[p*m+q]=pair<etat,etat>(*(this->getEtat(p)),*(A.getEtat(q)));


            //remplissage des transitions pointant sur le nouvel état
            i=0;

            while(i<etat_prod.size()){

                //on cherche si l'état nouvellement créer pointe sur l'état i par une trans qcq

                multiTmp = (etat_prod[p*m+q].first).getTransitions();
                it_trans1=multiTmp.begin();

                j=0;
                while( j<((etat_prod[p*m+q].first).getTransitions()).size() ){
                    if((*it_trans1).second==etat_prod[i].first){
                        etiq=(*it_trans1).first;
                        if((etat_prod[p*m+q].second).find_transition(etiq, etat_prod[i].second)==true){

                            (temp.etats[p*m+q]).ajoutTransition(temp.etats[i],etiq);
                        }

                    }

                    j++;
                    it_trans1++;

                }

                //on cherche si il existe une transition pointant sur l'etat de l'autom init1 qui correspond au nouvel etat crée
                multiTmp = (etat_prod[i].first).getTransitions();
                it_trans1=multiTmp.begin();
                j=0;
                while(j<((etat_prod[i].first).getTransitions()).size()){



                     if((*it_trans1).second==etat_prod[p*m+q].first){

                        etiq=(*it_trans1).first;

                        //on cherche alors dans autom init2 si il existe une transition avec la meme étiquette pointant sur l'etat eq au nouvel etat cree
                            if( (etat_prod[i].second).find_transition( etiq, etat_prod[p*m+q].second )==true ){
                               (temp.etats[i]).ajoutTransition(e,etiq);
                            }
                        }
                    it_trans1++;
                    j++;
                }
                i++;
            }
            //remplissage du vecteur d'automate du produit
            produit.push_back(temp);
        }
    }

return produit;
}

//--------------------------------------------------------
// Fonction qui retourne la taille de l'alphabet d'un automate
//-----------------------------------------------------------

vector<int> Automate::getAlpha(){
    vector<int> tab;

    int sizealpha=0;
    int i=0,j=0;
    string commentaire;

    multimap<int,etat> transitions;
    multimap<int,etat>::iterator it_trans;
    vector<etat>::iterator it_etat;
    //Pour chaque état
    for(it_etat = etats.begin();it_etat != etats.end();it_etat++){
        transitions = (*it_etat).getTransitions();
        //Pour chaque transition de cet état
        for(it_trans=transitions.begin();it_trans!=transitions.end();it_trans++){ //problème avec l'iterator end
            i=0;
            while(i<sizealpha && (*it_trans).first!=tab[i]){
                i++;
            }
            if(i==sizealpha){
                tab.push_back((*it_trans).first); // on ajoute la clé trouvé au tableau pour la mémorisé
                j++;
                sizealpha++;
            }
       }
    }
    return tab;
}



//--------------------------------------------------------
// Fonction qui déterminise un automate
//-----------------------------------------------------------
vector <  pair< Automate , string > > Automate::determinise(){

 vector <  pair< Automate , string > > determin;
 vector<int> alpha=this->getAlpha();
 Automate *temp_det;
 etat e;
 string comment;
 ostringstream tmp;

 map<int , list< etat> > etat_det;
 multimap<int ,etat> trans;
 list<etat> list_etat;

 list<etat>::iterator it_etat;
 multimap< int , etat >::iterator it_trans;
 map<int , list < etat> >::iterator it_det;

 unsigned int i,j,k=0,m;
 bool init_isFinal=false ,existe=false, isEtatInit=false;

 //recherce des états initiaux pour créer le premier états
 for(i=0;i<etats.size();i++){

     if(etats[i].isInitial()){

        list_etat.push_back(etats[i]);
         isEtatInit=true;

        if(etats[i].isFinal() && init_isFinal!=true){
            init_isFinal=true;
        }

     }

 }

 if(isEtatInit!=true){
     e=etat(0,false,false);
     temp_det=new Automate;
     temp_det->ajoutEtat(e);
     determin.push_back(pair<Automate,string>(*temp_det,"L'automate n'a pas d'etat initial, il ne peut etre déterminisé"));
     delete temp_det;
     return determin;
 }
 etat_det[0]=list_etat;

 e=etat(0,true,init_isFinal);
 e.setName(list_etat);
 temp_det=new Automate;
 temp_det->ajoutEtat(e);

    comment="creation de l'etat initial à partir des états initiaux des deux automates";
    determin.push_back(pair<Automate,string>(*temp_det,comment));



 //déterminisation
 //it_det=etat_det.begin();
 while(k<etat_det.size()){ // on parcours la liste d'état de l'automate déter

    for(i=0;i<alpha.size();i++){ // on parcours l'alphabet

        list_etat.clear();

        it_etat=etat_det[k].begin();

        for(j=0;j<etat_det[k].size();j++){ // on parcoures la liste de corres pour l'état k de l'auto deter

            trans=it_etat->getTransitions();

             it_trans=trans.begin();

             for(m=0;m<trans.size();m++){//on parcoure la liste des trans pour l'etat k;

                 if(it_trans->first == alpha[i] && it_trans->second.estDansList(list_etat)==false ){

                        list_etat.push_back(*(this->getEtat(it_trans->second.numero)));

                 }

                 it_trans++;

             }

             ++it_etat;

         }

         //vérifier si la liste est déjà un état déterminisé
        if(list_etat.begin()!=list_etat.end()){

            existe=false;

            it_det=etat_det.begin();

            while(it_det!=etat_det.end() && existe==false ){


                if(equal(list_etat,it_det->second)){ //espérer que le test d'égalité est bon ;)
                    existe=true;
                }
                else
                {
                it_det++;
                }
            }

            if(existe==false){


                int taille=etat_det.size();

                etat_det[taille]=list_etat;

                e=etat(taille,false,isFinal(list_etat));

                e.setName(list_etat);
                comment="Creation de l'etat "+e.getName()+". ";
                temp_det->ajoutEtat(e);


                tmp<<alpha[i];
                comment=comment+" Dessin de la transition de "+temp_det->etats[k].getName()+" vers "+e.getName()+" par "+tmp.str();
                tmp.str("");
                (temp_det->etats[k]).ajoutTransition(e,alpha[i]);

            }
            else
            {
                tmp<<alpha[i];
                comment=" Dessin de la transition de "+temp_det->etats[k].getName()+" vers "+e.getName()+" par "+tmp.str();
                tmp.str("");
                (temp_det->etats[k]).ajoutTransition(temp_det->etats[it_det->first],alpha[i]);
            }

            determin.push_back(pair<Automate,string>(*temp_det,comment));
                //si non, nouvel état, si oui trans de l'état encours vers l'état trouvé
                //nouvel auto dans vecteur
        }
     }

    k++;
 }

 return determin;
}



bool equal(list<etat> &l1 ,list<etat> &l2) {
    list<etat>::iterator it1;

    if(l1.size()!=l2.size()){
        return false;
    }
    else
    {
        it1=l1.begin();
        while(it1!=l1.end()){

            if(it1->estDansList(l2)==false){

                return false;
            }

            it1++;
        }
    }
    return true;
}


bool isFinal(list <etat> l){

    list <etat>::iterator it;

    it=l.begin();

    while(it!=l.end()){
        if(it->isFinal()){
            return true;
        }
        it++;
    }

    return false;


}
