#include "etat.h"
#include <sstream>


etat::etat(int number,bool ini,bool fina)
{
    numero = number;
    final = fina;
    initial = ini;
    name = "";
}

etat::etat(const etat &e){
    numero=e.numero;
    final=e.final;
    initial=e.initial;
    transition = e.transition;
    name = e.name;
}

bool etat::isFinal(){
    return final;
}

bool etat::isInitial(){
    return initial;
    }

void etat::setFinal(bool decision){

    final = decision;
}

void etat::setInitial(bool decision){
    initial = decision;

}

void etat::ajoutTransition(const etat cible,int vocab){

    multimap<int,etat>::iterator it;

    it = transition.find(vocab);


    while(it != transition.end()){
        //Si il y a un état de transition vocab, qui mene a l'etat cible, pas la peine d'ajouter
        if( (*it).second.numero == cible.numero){
            return;
        }
        it++;
    }
    //Sinon , on ajoute l'état.
    transition.insert(pair<int,etat>(vocab,cible));
}

int etat::getNumber(){
    return numero;
}

void etat::setNumber(int number){
    numero = number;
}

void etat::supprimeTransition(etat cible,int vocab){

    multimap<int,etat>::iterator it;
    it = transition.find(vocab);

    while(it != transition.end()){
    //    Si il y a un état de transition vocab, qui mene a l'etat cible, on le supprime
        if( ((*it).second.numero == cible.numero) && ((*it).first == vocab)){
            transition.erase(it);
        }
        it++;
    }
}

multimap<int,etat> etat::getTransitions(){
    return transition;

}

void etat::renameTransition(etat cible){
    multimap<int,etat>::iterator it;
    it = transition.begin();

    while(it != transition.end()){
    //    Si il y a un état de transition vocab, qui mene a l'etat cible, on le supprime
        if( (*it).second.numero == cible.numero){
            (*it).second.numero--;
        }
        it++;
    }

}

 bool etat::operator==(etat &e)const {
    if(numero==e.numero){
        return true;
    }
    else
    {
        return false;
    }
}

 bool etat::operator!=(etat &e)const {
    if(numero!=e.numero){
        return true;
    }
    else
    {
        return false;
    }
}

bool etat::find_transition(int etiq, etat e){
     multimap<int,etat>::iterator it=transition.begin();

     bool trouve=false;

     while(trouve==false && it!=transition.end()){

         if( (*it).first==etiq && (*it).second==e ){
             trouve=true;
         }

         it++;
     }

     return trouve;
 }


bool etat::estDansList(list<etat> liste){

    list<etat>::iterator it;

    it=liste.begin();
    while(it!=liste.end()){
        if(*this==*it){
            return true;
        }
        it++;
    }

    return false;
}

void etat::setName(string rename){
    name = rename;
}

void etat::setName(list<etat> l){

    list <etat>::iterator it;

    ostringstream tmp;


    tmp<<l.begin()->numero;
    name=tmp.str();


    for(it=l.begin();it!=l.end();it++){

        tmp.str("");

        if(it!=l.begin()){
            tmp<<it->numero;
            name=name+","+tmp.str();

        }
    }

}

string etat::getName(){
    if (name == ""){
        std::ostringstream out;
        out << numero;
        return out.str();
    }
    else{
        return ("\""+name+"\"");
    }
}

string etat::getNameF(){
    if (name == ""){
        std::ostringstream out;
        out <<"F"<<numero;
        return out.str();
    }
    else{
        return ("\"F"+name+"\"");
    }
}
