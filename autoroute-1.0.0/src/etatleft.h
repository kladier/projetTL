#ifndef ETATLEFT_H
#define ETATLEFT_H

/*!
 * \file etatleft.h
 * \brief Représente la partie gauche lors de la création d'un automate, la partie listant les états.

 */

#include <QWidget>

namespace Ui {
    class etatLeft;
}

class etatLeft : public QWidget {
    Q_OBJECT
public:
    /*!
         *  \brief Constructeur
         *
         *  Construit l'etat left
         *
         */
    etatLeft(int ,QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         */
    ~etatLeft();

public slots:
    /*!
         *  \brief Listener du bouton permettant d'afficher l'etat right associé à cet état
         *
         */
    void sendDad();
    /*!
         *  \brief Listener du bouton permettant la suppression de l'etat
         *
         */
    void askForSupress();


protected:
    void changeEvent(QEvent *e);
    int numero;  /*!< Numéro de l'état */

signals:
    void selected(int me);
    void supress(int);



private:
    Ui::etatLeft *ui;
};

#endif // ETATLEFT_H
