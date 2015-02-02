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

        //On test si l'�tat cible existe d�ja.
    for ( it=etats.begin() ; it != etats.end(); it++ ){

        if((*it).numero == cible.numero){
            return;
        }

    }

    etats.push_back(cible);
}

bool Automate::isDeterministe(){
    vector<etat>::iterator it;
    for ( it=etats.begin() ; it != etats.end(); it++ ){
        if ((*it).isFinal()){
            return false;
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
            (*it).renameTransition((*it2).second,((*it2).second.numero-1));

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
//ON renome ensuite les �tats
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
            (*it).renameTransition((*it2).second,((*it2).second.numero-1));

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
//ON renome ensuite les �tats
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

//renvoit true si au moins une transition va vers cette �tat et partant d'un autre �tat que lui-meme, false sinon
bool transitionExist(etat e, Automate a) {
    vector<etat>::iterator it;
    for( it=a.etats.begin() ; it!=a.etats.end() ; it++) {
       multimap<int,etat> tempTrans=(*it).getTransitions();
       multimap<int,etat>::iterator it2;
       for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            if (it->numero!=e.numero&&it2->second.numero==e.numero) {
                return true;
            }
       }
    }
    return false;
}

void Automate::supprimerEtatsNonAccessibles(Automate * a) {
    vector<etat>::iterator it;
    for( it=a->etats.begin() ; it!=a->etats.end() ; it++) {
        if (transitionExist(*it,*a)==false) {
            supprimeEtat(*it,a);
        }
    }
}

bool Automate::isStandard() {
    //on v�rifie d�j� qu'il n'y a qu'un seul �tat initial
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

    //on v�rifie ensuite qu'aucune transition n'arrive � l'�tat initial
    //pour cela, on v�rifie toutes les transitions de chaque �tats.
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

vector <  pair< Automate , string > > Automate::minimise() {
    vector <  pair< Automate , string > > res;
    Automate *temp = new Automate;


    //On s'occupe des 2 premi�res lignes
    string tableau, commentaire="Avant de minimiser, il faut d'abord construire un tableau de minimisation.\n";
    tableau="            |";
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
        tableau=tableau+"  "+it->getName()+"  |";
    }
    tableau=tableau+"\nBilan 0 |";
    for( it=etats.begin() ; it!=etats.end() ; it++){
        if (it->isFinal()) {
            tableau=tableau+"  II   |";
        }
        else {
            tableau=tableau+"  I   |";
        }
    }
    commentaire=commentaire+"\n"+tableau+"\nSur la premi�re ligne, chaque num�ro correspond � un �tat.\nLe bilan 0 est simple, on attribue I � tout les �tats non finaux et II � tout les etats finaux.\n";
    res.push_back(pair< Automate , string >(*temp,commentaire));

    //on s'occupe de la premiere s�rie de ligne en 1 , en 2 etc
    commentaire="\n";
    tableau=tableau+"\n";

    //
  /*  vector<int> tabTransition=getTabTransitions();
    vector<int>::iterator it3;
    for( it3=tabTransition.begin() ; it3!=tabTransition.end() ; it3++){
        tableau=tableau+"En "+convertIntToString(*it3)+"       |";
        for (it=)
    }*/
    //PB DE CONCEPTION, IL FAUT UN TAB INT DU TAB DE MINIMISATION
    res.push_back(pair< Automate , string >(*temp,commentaire));

    return res;

}

//on remplit un vecteur d'automates, chaque �l�ment correspondant � un automate
//quand le vecteur est lu (avec le bouton suivant), cela correspond � une �tape dans l'ui
//numEtatCurr correspond au num�ro de l'�tat suivant � ajouter
//temp est l'automate qu'on ajoute au fur et a mesure au vecteur de standardisation res
vector <  pair< Automate , string > > Automate::standardise() {
    vector <  pair< Automate , string > > res;
    Automate *temp = new Automate;
    int numEtatCurr=0;

    // 1) On cr�e le nouvel etat initial
    etat *e = new etat(numEtatCurr,false,false);
    numEtatCurr++;
    e->setName("0'");
    temp->ajoutEtat(*e);
    res.push_back(pair< Automate , string >(*temp,"On cr�� le nouvel �tat initial appel� 0'.\n"));

    // 2)on cr�e tout les autres �tats sans aucune transition (y compris les anciens �tats initial)
    vector<etat>::iterator it;
    for( it=etats.begin() ; it!=etats.end() ; it++){
       etat *e = new etat(numEtatCurr,false,it->isFinal());
       numEtatCurr++;
       e->setName(it->getName());
       temp->ajoutEtat(*e);
    }
    res.push_back(pair< Automate , string >(*temp,"On cr�e tout les autres �tats sans aucune transition (y compris les anciens �tats initial).\n"));

    // 3) on s'occupe des cas particuliers (voir ci-dessous)
    //Cas particulier : quand un ancien �tat initial a une transition allant vers lui-m�me.
    //Dans ce cas l�, il faut cr�er 2 transitions : une transition partant du nouvel �tat initial et allant vers le nouvel �tat correspondant et une transition partant de cet �tat et allant vers lui-m�me
    int numberCasParticulier=0;
    for( it=etats.begin() ; it!=etats.end() ; it++){
       if (it->isInitial()) {
            //si c'est un ancien etat initial, on v�rifie qu'il n'a pas de transition allant vers lui-meme
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

    string ajoutPourCasParticulier="Il y a dans cet automate "+convertIntToString(numberCasParticulier)+" cas particuliers � g�rer.";
    res.push_back(pair< Automate , string >(*temp,"On s'occupe des cas particuliers.\nCas particulier : quand un ancien �tat initial a une transition allant vers lui-m�me. Dans ce cas l�, il faut cr�er 2 transitions et un �tat : une transition partant du nouvel �tat initial et allant vers l'�tat nouvellement cr�� et une transition partant de cet �tat et allant vers lui-m�me.\n"+ajoutPourCasParticulier));


    // 4) on s'occupe des transitions partant du nouvel etat initial (correspondant aux transitions partant des anciens �tats initiaux)
    for( it=etats.begin() ; it!=etats.end() ; it++){
        if (it->isInitial()) {
            multimap<int,etat> tempTrans=(*it).getTransitions();
            multimap<int,etat>::iterator it2;
            for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
                //on pr�cise qu'on ne s'occupe du cas ou cette transition allait vers l'�tat initial duquel il partait
                if (it2->second.numero!=it->numero) {
                    temp->ajoutTransition(*(temp->getEtat(0)),*(temp->getEtat(it->numero+2)),it2->first);
                }
            }
        }
    }
    res.push_back(pair< Automate , string >(*temp,"on s'occupe des transitions partant du nouvel etat initial : on ajoute toutes les transitions qui partaient des anciens �tats initiaux."));

    // 5) on reproduit toutes les anciennes transitions (sauf les cas particuliers, c'est d�j� g�r� avant)
    for( it=etats.begin() ; it!=etats.end() ; it++){
        multimap<int,etat> tempTrans=(*it).getTransitions();
        multimap<int,etat>::iterator it2;
        for (it2=tempTrans.begin();it2!=tempTrans.end();it2++) {
            //on pr�cise qu'on ne s'occupe du cas ou cette transition allait vers l'�tat initial duquel il partait
            if ((it->isInitial()&&it2->second.numero==it->numero)==false) {
                temp->ajoutTransition(*(temp->getEtat(it->numero+1)),*(temp->getEtat(it2->second.numero+1)),it2->first);
            }
        }
    }

    res.push_back(pair< Automate , string >(*temp,"on reproduit toutes les anciennes transitions (sauf les cas particuliers, c'est d�j� g�r� avant).\n"));

    // 6) on supprime d�sormais tout les etats non accessibles
    supprimerEtatsNonAccessibles(temp);
    res.push_back(pair< Automate , string >(*temp,"On supprime d�sormais tout les �tats non accessibles, c'est-�-dire tout les �tats non initiaux vers lesquelles aucune transition ne pointe.\n L'automate est maintenant standardiser.\n"));

    return res;
}

//a modifier : il faut avoir une structure comme la determinisation et la standardisation
vector<Automate> Automate::produit(Automate A){
   vector<Automate> produit;
   map< int, pair<etat,etat> > etat_prod; // �quivalence etat automate f -> (etat_automate1,etat_automate2)

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

            //cr�ation d'un nouvel automate recopiant celui de l'�tape pr�c�dente
            if(p!=0 || q!=0){
                temp=Automate(produit[(p*m+q)-1]);

            }
            else
            {
                temp = Automate();

            }
            //cr�ation du nouvel �tat p*m+q
            e=etat(p*m+q,(this->getEtat(p))->isInitial() && (A.getEtat(q))->isInitial(),(this->getEtat(p))->isFinal() && (A.getEtat(q))->isFinal());
            ostringstream tmp;
            tmp<<p<<","<<q;
            e.setName(tmp.str());
            tmp.str("");
            (temp.etats).push_back(e);

            //remplissage de la map d'�quivalence des �tats
            etat_prod[p*m+q]=pair<etat,etat>(*(this->getEtat(p)),*(A.getEtat(q)));


            //remplissage des transitions pointant sur le nouvel �tat
            i=0;

            while(i<etat_prod.size()){

                //on cherche si l'�tat nouvellement cr�er pointe sur l'�tat i par une trans qcq

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

                //on cherche si il existe une transition pointant sur l'etat de l'autom init1 qui correspond au nouvel etat cr�e
                multiTmp = (etat_prod[i].first).getTransitions();
                it_trans1=multiTmp.begin();
                j=0;
                while(j<((etat_prod[i].first).getTransitions()).size()){



                     if((*it_trans1).second==etat_prod[p*m+q].first){

                        etiq=(*it_trans1).first;

                        //on cherche alors dans autom init2 si il existe une transition avec la meme �tiquette pointant sur l'etat eq au nouvel etat cree
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
    //Pour chaque �tat
    for(it_etat = etats.begin();it_etat != etats.end();it_etat++){
        transitions = (*it_etat).getTransitions();
        //Pour chaque transition de cet �tat
        for(it_trans=transitions.begin();it_trans!=transitions.end();it_trans++){ //probl�me avec l'iterator end
            i=0;
            while(i<sizealpha && (*it_trans).first!=tab[i]){
                i++;
            }
            if(i==sizealpha){
                tab.push_back((*it_trans).first); // on ajoute la cl� trouv� au tableau pour la m�moris�
                j++;
                sizealpha++;
            }
       }
    }
    return tab;
}



//--------------------------------------------------------
// Fonction qui d�terminise un automate
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

 //recherce des �tats initiaux pour cr�er le premier �tats
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
     determin.push_back(pair<Automate,string>(*temp_det,"L'automate n'a pas d'etat initial, il ne peut etre d�terminis�"));
     delete temp_det;
     return determin;
 }
 etat_det[0]=list_etat;

 e=etat(0,true,init_isFinal);
 e.setName(list_etat);
 temp_det=new Automate;
 temp_det->ajoutEtat(e);

    comment="creation de l'etat initial � partir des �tats initiaux des deux automates";
    determin.push_back(pair<Automate,string>(*temp_det,comment));



 //d�terminisation
 //it_det=etat_det.begin();
 while(k<etat_det.size()){ // on parcours la liste d'�tat de l'automate d�ter

    for(i=0;i<alpha.size();i++){ // on parcours l'alphabet

        list_etat.clear();

        it_etat=etat_det[k].begin();

        for(j=0;j<etat_det[k].size();j++){ // on parcoures la liste de corres pour l'�tat k de l'auto deter

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

         //v�rifier si la liste est d�j� un �tat d�terminis�
        if(list_etat.begin()!=list_etat.end()){

            existe=false;

            it_det=etat_det.begin();

            while(it_det!=etat_det.end() && existe==false ){


                if(equal(list_etat,it_det->second)){ //esp�rer que le test d'�galit� est bon ;)
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
                //si non, nouvel �tat, si oui trans de l'�tat encours vers l'�tat trouv�
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

//fonction d'aide au d�bugage: affiche une list d'�tat

void affichageList(list<etat> l){

    list<etat>::iterator it=l.begin();

    for(it=l.begin();it!=l.end();it++){
    }
}
