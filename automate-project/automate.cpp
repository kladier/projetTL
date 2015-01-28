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
//ON renome ensuite les états
    for ( it=etats.begin() ; it != etats.end(); it++ ){

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

//A FAIRE
//on remplit un vecteur d'automates, chaque élément correspondant à un automate
//quand le vecteur est lu (avec le bouton suivant), cela correspond à une étape dans l'ui
vector <  pair< Automate , string > > Automate::standardise() {

}

//en développement
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

 unsigned int i,j,k=0,m,l;
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

                 l=0;
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
    unsigned j;

    list<etat>::iterator it1;

    if(l1.size()!=l2.size()){
        return false;
    }
    else
    {
        it1=l1.begin();
        while(it1!=l1.end()){

            j=0;

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

//fonction d'aide au débugage: affiche une list d'état

void affichageList(list<etat> l){

    list<etat>::iterator it=l.begin();

    for(it=l.begin();it!=l.end();it++){
    }
}
