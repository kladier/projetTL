#ifndef ETAT_H
#define ETAT_H

#include <map>
#include <list>
#include <iostream>

using namespace std;
class etat
{
public:
     int numero;


    etat(int,bool ini = false,bool fina = false);
    etat(const etat &e);
    etat(){};


    int getNumber();
    void setNumber(int);

    bool isFinal();
    void setFinal(bool);

    bool isInitial();
    void setInitial(bool);

    void ajoutTransition(etat,int); //param: etat cible, vocab
    void supprimeTransition(etat,int);
    void renameTransition(etat,int);

    multimap<int,etat> getTransitions();

    bool operator==(etat &)const;
    bool operator!=(etat &)const;

    bool find_transition(int etiq, etat e);
    bool estDansList(list<etat> liste);
    void setName(string);
    string getName();
    string getNameF();
    void setName(list<etat> l);

private:
    string name;
    bool initial;
    bool final;
    multimap<int,etat> transition;
};

#endif // ETAT_H
