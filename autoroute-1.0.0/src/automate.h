#ifndef AUTOMATE_H
#define AUTOMATE_H

/*!
 * \file automate.h
 * \brief Représente un automate, son seul attribut est un vector d'états

 */

#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

#include "etat.h"
using namespace std;

class Automate
{
public:

    vector<etat> etats; /*!< Vecteur des états de l'automate*/


    /*!
         *  \brief Constructeur sans paramètre
         *
         *  Constructeur de la classe Automate, produit un automate vide.
         *
         */
    Automate();

    /*!
         *  \brief Constructeur
         *
         *  Construit l'automate passé en paramètre
         *
         *  \param a : automate à construire
         */
    Automate(const Automate&a);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Automate
         */
    ~Automate();

    /*!
       *  \brief Ajout d'un état
       *
       *  Methode qui permet d'ajouter un état à l'automate
       *
       *  \param cible : l'état à ajouter
       */
    void ajoutEtat(etat cible);

    /*!
       *  \brief Liste les différentes transitions de l'automate
       *
       *  Methode permettant de lister dans un vector d'int, les différentes transitions.
       * getTabTransitions().size() permet donc de connaitre le nombre de transitions différentes dans l'automate
       *
       *  \return un vecteur, chaque entier du vecteur représentant un type de transition
       */
    vector<int> getTabTransitions();

    /*!
     *  \brief Test si un automate est déterministe
     *
     *  Permet de tester si un automate est déterministe (voir définition d'un automate déterministe).
     *
     *  \return true si l'automate est déterministe,
     *  false sinon
     */
    bool isDeterministe();

    /*!
     *  \brief Test si un automate est complet
     *
     *  Permet de tester si un automate est complet(voir définition d'un automate complet).
     *
     *  \return true si l'automate est complet,
     *  false sinon
     */
    bool isComplet();

    /*!
     *  \brief Test si un automate est standard
     *
     *  Permet de tester si un automate est standard (voir définition d'un automate standard).
     *
     *  \return true si l'automate est standard,
     *  false sinon
     */
    bool isStandard();

    /*!
     *  \brief Retourne un pointeur vers l'état dont le numéro est précisé en paramètre
     *
     *  Récupère le pointeur vers l'état dont le numéro est précisé en paramètre.
     * Récupère cet état dans le vector d'états (un attribut de l'automate).
     *
     *  \param number : le numéro de l'état à retourner
     *  \return Un pointeur vers l'état
     */
    etat* getEtat(int number);

    /*!
     *  \brief Retourne le vector d'états de l'automate
     *
     *  \return Le vecteur d'états de l'automate.
     */
    vector<etat> getEtats();

    /*!
     *  \brief Ajoute une transition à un état
     *
     *  Ajoute une transition à l'état from en direction de l'état to et portant l'étiquette vocab.
     *
     *  \param from : l'état de départ de la transition
     *  \param to : l'état d'arrivé de la transition
     *  \param vocab : le numéro de la transition, son étiquette.

     */
    void ajoutTransition(etat from,etat to, int vocab);

    /*!
     *  \brief Supprime un état de l'automate
     *
     *  Supprime l'état, passé en paramètre, de l'automate.
     *
     *  \param cible : l'état à supprimer
     */
    void supprimeEtat(etat cible);

    /*!
     *  \brief Retourne l'état ciblé par une transition.
     *
     *  renvoie le numéro de l'état ciblé par la transition partant de etatDepart et portant l'étiquette etiq.
     *  Cette fonction ne fonctionne que si l'automate est déterministe, elle est utilisée seulement dans la minimisation
     *
     *  \param etatDepart : le numéro de l'état d'où part la transition
     *  \param etiq : l'étiquette de la transition, partant de etatDepart
     *  \return le numéro de l'état ciblé par la transition, -1 s'il n'y en a pas
     */
    int cible_transition(int etatDepart, int etiq);

    /*!
     *  \brief Supprime un état de l'automate passé en paramètre
     *
     *  Supprime l'état cible de l'automate dont le pointeur "a" est passé en paramètre.
     *
     *  \param cible : l'état à supprimer
     *  \param a : pointeur vers l'automate
     */
    void supprimeEtat(etat cible, Automate * a);

    /*!
     *  \brief Supprime les états non accessibles de l'automate passés en paramètre
     *
     *  Supprime les états non accessibles de l'automate dont le pointeur est passé en paramètre
     *
     *  \param a : pointeur vers l'automate
     */
    void supprimerEtatsNonAccessibles(Automate * a);

    /*!
     *
    * \brief Fonction permettant de renvoyer une chaine à partir de l'automate actuel.
    *
    * Cette chaine correspond à la représentation de l'automate en graphe dans le langage de descrition DOT
    *
    * \return La chaine décrivrant l'automate, à mettre dans un .dot ensuite
     */
    string toDot();

    /*!
     *  \brief Réalise le produit de deux automates
     *
     *  Réalise le produit de deux automates (this et A), et renvoie un vecteur d'automates.
     * Dans ce vecteur, chaque élément correspond à une étape du processus de produit de 2 automates.
     *
     *  \param A : le produit est réalisé avec cet automate A, passé en paramètre
     *
     * \return un vecteur d'automate, chaque automate correspondant à une étape dans le logiciel
     */
    vector<Automate> produit(Automate A);
    /*!
     *  \brief Taille de l'alphabet de l'automate
     *
     *   Fonction qui retourne la taille de l'alphabet d'un automate
     *
     * \return un vecteur d'entier, représentant l'ensemble des étiquettes différentes des transitions, c'est-à-dire l'alphabet de l'automate
     */
    vector<int> getAlpha();

    /*!
     *  \brief Réalise la déterminisation de l'automate
     *
     *  Réalise la déterminisation de l'automate, et renvoie un vecteur.
     * Dans ce vecteur, chaque élément correspond à une paire : un automate et une chaine.
     * Chaque élément pair représente en fait une étape dans le processus de déterminisation.
     * La chaine est le texte correspondant aux explications et l'automate est l'automate à afficher pendant cette étape.
     *
     * \return le vecteur servant pour la déterminisation
     */
    vector <  pair< Automate , string > > determinise();

    /*!
     *  \brief Réalise la standardisation de l'automate
     *
     *  Réalise la standardisation de l'automate, et renvoie un vecteur.
     * Dans ce vecteur, chaque élément correspond à une paire : un automate et une chaine.
     * Chaque élément pair représente en fait une étape dans le processus de standardisation.
     * La chaine est le texte correspondant aux explications et l'automate est l'automate à afficher pendant cette étape.
     *
     * \return le vecteur servant pour la standardisation
     */
    vector <  pair< Automate , string > > standardise();

    /*!
     *  \brief Réalise la minimisation de l'automate
     *
     *  Réalise la minimisation de l'automate, et renvoie un vecteur.
     * Dans ce vecteur, chaque élément correspond à une paire : un automate et une chaine.
     * Chaque élément pair représente en fait une étape dans le processus de minimisation.
     * La chaine est le texte correspondant aux explications et l'automate est l'automate à afficher pendant cette étape.
     *
     * \return le vecteur servant pour la minimisation
     */
    vector <  pair< Automate , string > > minimise();


    string toStringTabMini(vector< vector<int> > tabMinimisation);


    /*!
     *  \brief renvoie le nombre de transitions portant une étiquette différente
     *
     * Fonction utilisée dans la minimisation
     *
     * \return le nombre de transitions différentes de l'automate
     */
    int getNbTransition();

};

/*!
 *  \brief Test l'égalité entre deux listes d'états
 *
 *  Test l'égalité entre deux listes d'états l1 et l2
 *
 * \return true si les listes sont égales, false sinon
 */
bool equal(list<etat> &l1 ,list<etat> &l2);

/*!
 *  \brief Test si une liste d'états a au moins un état final
 *
 * Fonction utilisée seulement pour la déterminisation
 *
 *  \param l : liste d'états testée
 *
 * \return true s'il y a au moins un état final dans la liste d'états, false sinon
 */
bool isFinal(list <etat> l);




#endif // AUTOMATE_H
