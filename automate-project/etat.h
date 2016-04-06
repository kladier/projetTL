#ifndef ETAT_H
#define ETAT_H

#include <map>
#include <list>
#include <iostream>

using namespace std;
class etat
{
public:
     int numero; /*!< Numéro de l'état*/

     /*!
          *  \brief Constructeur
          *
          *  Construit l'état passé avec le numéro number, peut être initial et/ou final
          *
          *  \param number : numéro de l'état
          * \param ini : par défaut false, true si l'état est initial
          *  \param fina : par défaut false, true si l'état est final

          */
    etat(int number,bool ini = false,bool fina = false);

    /*!
         *  \brief Constructeur
         *
         *  Construit l'état passé en paramètre
         *
         *  \param e : pointeur vers l'état à construire
         */
    etat(const etat &e);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Etat
         */
    etat(){};

    /*!
     *  \brief Retourne le numéro de l'état
     *
     *  Getter de l'attribut number.
     *
     *  \return Le numéro de l'état
     */
    int getNumber();

    /*!
     *  \brief Définit le numéro de l'état
     *
     *  Setter de l'attribut number.
     *
     *  \param number : le numéro de l'état à mettre
     */
    void setNumber(int number);

    /*!
     *  \brief Test si l'état est un état final
     *
     *  renvoie un booléen en fonction de si l'état est final ou non
     *
     *  \return true si l'état est final, false sinon
     */
    bool isFinal();

    /*!
     *  \brief Définit si l'état est final ou non
     *
     *  Setter de l'attribut final.
     *
     *  \param decision : true si l'état est final, false sinon
     */
    void setFinal(bool decision);

    /*!
     *  \brief Test si l'état est un état initial
     *
     *  renvoie un booléen en fonction de si l'état est initial ou non
     *
     *  \return true si l'état est initial, false sinon
     */
    bool isInitial();

    /*!
     *  \brief Définit si l'état est initial ou non
     *
     *  Setter de l'attribut initial.
     *
     *  \param decision : true si l'état est initial, false sinon
     */
    void setInitial(bool decision);

    /*!
     *  \brief Ajoute une transition à l'état
     *
     *  Ajoute une transition allant vers l'état cible et portant l'étiquette vocab.
     *
     *  \param cible : l'état d'arrivée de la transition
     *  \param vocab : l'étiquette de la transition
     */
    void ajoutTransition(etat cible,int vocab);

    /*!
     *  \brief Supprime une transition à l'état
     *
     *  Supprime la transition allant vers l'état cible et portant l'étiquette vocab.
     *
     *  \param cible : l'état d'arrivée de la transition
     *  \param vocab : l'étiquette de la transition
     */
    void supprimeTransition(etat cible,int vocab);

    /*!
     *  \brief Renomme une transition de l'état
     *
     *  Renomme la transition allant vers l'état cible et portant l'étiquette vocab.
     *
     *  \param cible : l'état d'arrivée de la transition
     *  \param vocab : l'étiquette de la transition
     */
    void renameTransition(etat cible);

    /*!
     *  \brief Retourne les transitions de l'état
     *
     *  Getter de l'attribut transition.
     * Le premier membre est l'étiquette de la transition et le deuxieme est l'état ciblé par la transition.
     *
     *  \return Multimap représentant les transitions de l'état
     */
    multimap<int,etat> getTransitions();

    /*!
     *  \brief Opérateur d'égalité entre 2 états
     *
     *  L'égalité entre deux états se teste seulement sur le numéro de l'état.
     *
     *  \param e : l'état à tester
     *  \return true si les numéros sont les mêmes, false sinon
     */
    bool operator==(etat &e)const;

    /*!
     *  \brief Opérateur d'inégalité entre 2 états
     *
     *  L'inégalité entre deux états se teste seulement sur le numéro de l'état.
     *
     *  \param e : l'état à tester
     *  \return true si les numéros sont différents, false sinon
     */
    bool operator!=(etat &e)const;

    /*!
     *  \brief Teste l'existence d'une transition
     *
     *  Teste si la transition allant vers l'état e et portant l'étiquette etiq existe.
     *
     *  \param e : l'état d'arrivée de la transition
     *  \param etiq : l'étiquette de la transition
     *  \return true si cette transition existe, false sinon
     */
    bool find_transition(int etiq, etat e);

    /*!
     *  \brief Teste l'existence d'une transition
     *
     *  Teste si la transition allant vers l'état e existe.
     *
     *  \param e : l'état d'arrivée de la transition
     *  \return true si cette transition existe, false sinon
     */
    bool find_transition(etat e);

    /*!
     *  \brief Teste si l'état est dans une liste
     *
     *  Teste si l'état est dans la liste passée en paramètre. Se base sur l'opérateur d'égalité entre deux états.
     *
     *  \param liste : la liste d'états dans laquelle on va chercher l'état.
     *  \return true si cette transition existe, false sinon
     */
    bool estDansList(list<etat> liste);

    /*!
     *  \brief Attribue un nom à l'état
     *
     *  Setter sur l'attribut name.
     *
     *  \param rename : le nom à donner à l'état
     */
    void setName(string rename);

    /*!
     *  \brief renvoie le nom de l'état
     *
     *  renvoie le nom de l'état. Si aucun nom n'a été attribué, cela renvoie le numéro.
     *
     *  \return le nom de l'état
     */
    string getName();

    /*!
     *  \brief renvoie le nom de l'état
     *
     *  Fonctionne comme getName() mais en ajoutant un F avant le nom de l'état.
     *
     *  \return le nom de l'état, précédé d'un F
     */
    string getNameF();

    void setName(list<etat> l);

private:
    string name; /*!< Nom de l'état (sera affiché dans le graphe)*/
    bool initial; /*!< true si l'état est initial, false sinon*/
    bool final; /*!< true si l'état est final, false sinon*/
    multimap<int,etat> transition; /*!< représente les transitions partant de cet état, l'entier correspond au numéro de la transition et etat à l'état d'arrivée de la transition.*/
};

#endif // ETAT_H
