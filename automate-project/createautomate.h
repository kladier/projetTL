#ifndef CREATEAUTOMATE_H
#define CREATEAUTOMATE_H

/*!
 * \file createautomate.h
 * \brief Représente la fenêtre principale lors de la création d'un automate, contient les autres éléments : etatleft, etatright, transition et choixpointe

 */

#include <QMainWindow>
#include "automate.h"
#include "etatleft.h"
#include "etatright.h"
#include <QSvgWidget>
#include <QTextBrowser>
#include <QFileDialog>


namespace Ui {
    class CreateAutomate;
}

class CreateAutomate : public QMainWindow {
    Q_OBJECT
public:
    /*!
         *  \brief Constructeur
         *
         * Instancie cette partie de la fenêtre.
         *
         */
    CreateAutomate(QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         */
    ~CreateAutomate();
    Automate a; /*!< L'automate en train d'être construit*/
    QSvgWidget *maVue; /*!< Partie inférieure droite de la fenetre, où l'automate est affiché*/
    int actuel;
    vector<etatLeft*> left; /*!< Vecteur représentant les états déjà construits*/
    vector<etatRight*> right; /*!< Vecteur dont chaque élément représente une transition à modifier éventuellement pour un état*/

    /*!
         *  \brief Remet à jour la liste des états de droite
         *
         */
    void resetAllListChoix();

    /*!
         *  \brief Réactualise l'affichage de l'automate dans maVue
         *
         */
    void displayAutomate();

public slots:
    /*!
         *  \brief Ajoute un état à la fenetre
         *
         *  Construit un etat left et un etat right associés à ce nouvel état.
         *
         *  \param ini : true si l'état est initial
         *  \param fina : true si l'état est final
         */
    void ajoutEtat(bool ini=false,bool fina = false);

    /*!
         *  \brief Affiche un automate en grand
         */
    void afficherAutomate();
    /*!
         *  \brief Affiche l'etat right spécifié
         *
         * \param toDisplay : l'état à afficher
         */
    void displayRight(int toDisplay);

    /*!
         *  \brief Supprime un état et réactualise l'affichage
         *
         * \param cible : l'état à supprimer
         */
    void supprimeEtat(int cible);

    /*!
         *  \brief Réactualise tout l'affichage
         *
         */
    void refreshAll();

    /*!
         *  \brief Sauvegarder l'automate créé
         *
         */
    void sauvegarder();

    /*!
         *  \brief Modifie un état
         *
         * \param etat : l'état à modifier
         * \param ini : true si l'état est initial
         * \param final : true si l'état est final
         */
    void changeState(int etat ,bool ini ,bool final);

protected:
    void changeEvent(QEvent *e);

    /*!
         *  \brief Ajuste l'affichage
         *
         */
    void adjust();

private:
    Ui::CreateAutomate *ui;
};

#endif // CREATEAUTOMATE_H
