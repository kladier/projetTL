#ifndef CHOIXPOINTE_H
#define CHOIXPOINTE_H

/*!
 * \file choixpointe.h
 * \brief Utilisé pour la création d'un automate.
 * Sert à définir les transitions en demandant à l'utilisateur de saisir vers quel état la transition va et quel étiquette porte cette transition.
 */

#include <QWidget>
#include "automate.h"

namespace Ui {
    class choixPointe;
}

class choixPointe : public QWidget {
    Q_OBJECT
public:
    /*!
         *  \brief Constructeur
         *
         * Instancie cette partie de la fenêtre.
         *
         */
    choixPointe(QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         *
         */
    ~choixPointe();

    /*!
       *  \brief Clean du widget
       *
       *  Methode permettant de nettoyer le widget de ce qui a été ajouté et de remettre a jour la liste de choix pour les états cibles
       *
       *  \param a : l'état qu'on est en train de construire
       */
    void resetAffichage(Automate a);

public slots:
    /*!
       *  \brief Listener du bouton +
       *
       *  Méthode qui ajoute la transition seulement si les deux champs sont complétés.
       * Listener du bouton +
       *
       */
    void sendDad();


signals:
    /*!
       *  \brief Signal permettant d'ajouter la transition
       *
       */
    void add(int cible,int vocab);


protected:

    /*!
       *  \brief Change d'évènement
       *
       *  \param e : l'évènement pour lequel on doit changer.
       */
    void changeEvent(QEvent *e);

private:
    Ui::choixPointe *ui;
};

#endif // CHOIXPOINTE_H
