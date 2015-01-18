#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include "etat.h"
using namespace std;

class Automate
{
public:
    Automate();
    Automate(const Automate&);
    ~Automate();
    void ajoutEtat(etat);
    bool isDeterministe();
    etat* getEtat(int);
    vector<etat> getEtats();
    void ajoutTransition(etat,etat,int);
    void supprimeEtat(etat);
    string toDot();
    vector<Automate> produit(Automate);
    vector<int> getAlpha();
    vector <  pair< Automate , string > > determinise();


private:

    vector<etat> etats;
};

bool equal(list<etat> &l1 ,list<etat> &l2);
bool isFinal(list <etat> l);

//debug
void affichageList(list<etat> l);

#endif // AUTOMATE_H
