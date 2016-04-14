#ifndef TRANSITION_H
#define TRANSITION_H

/*!
 * \file transition.h
 * \brief Représente une transition d'un état.
 */

#include <QWidget>

namespace Ui {
    class Transition;
}

class Transition : public QWidget {
    Q_OBJECT
public:

    /*!
         *  \brief Constructeur
         *
         *  Construit la transition passée en paramètre
         *
         *  \param to : numero de l'état cible de la transition
         *  \param vocab : etiquette de la transition
         */
    Transition(int to,int vocab,QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Transition
         */
    ~Transition();
    int cible; /*!< Numéro de l'état ciblé par la transition */
    int vocab; /*!< Numéro de l'étiquette portée par la transition */

signals:
    void eraser(int to,int vocab);

public slots:
    /*!
         *  \brief Appelle la fonction eraser permettant de supprimer la transition.
         */
    void getOff();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Transition *ui;
};

#endif // TRANSITION_H
