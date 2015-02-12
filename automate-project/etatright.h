#ifndef ETATRIGHT_H
#define ETATRIGHT_H

/*!
 * \file etatright.h
 * \brief Représente la partie sup droite lors de la création d'un automate, la partie listant les transitions d'un état, s'il est final/initial etc.

 */

#include <QWidget>
#include "automate.h"
#include "choixpointe.h"
#include "transition.h"

namespace Ui {
    class etatRight;
}

class etatRight : public QWidget {
    Q_OBJECT
public:

    /*!
         *  \brief Constructeur
         *
         *  \param a : automate en cours de construction
         */
    etatRight(Automate* a,int,QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         */
    ~etatRight();

    choixPointe* addTrans; /*!< Pointeur vers l'objet choixPointe permettant de gérer une transition*/
    Automate* a; /*!< Pointeur vers l'automate en construction*/
    int numero; /*!< Numéro de l'état*/

    /*!
       *  \brief Remet à jour la liste dans choixPointe permettant de choisir l'etat cible de la transition
       *
       */
    void remplirListChoix();
    void addVisualTransition(int,int);
    void cleanTrans();

public slots:
    /*!
       *  \brief Ajout d'une transition
       *
       * \param to : numero de l'état cible
       * \param vocab : etiquette de la transition
       */
    void addTransition(int to,int vocab);

    /*!
       *  \brief Suppresion d'une transition
       *
       * \param to : numero de l'état cible
       * \param vocab : etiquette de la transition
       */
    void eraseTransition(int to,int vocab);


    void etatChange();

signals:
   void refreshNeeded(int);
   void etatChanges(int,bool,bool);

protected:
    void changeEvent(QEvent *e);

private:
    vector<Transition*> mesTrans; /*!< Vecteur des transitions de l'état */
    Ui::etatRight *ui;
};

#endif // ETATRIGHT_H
