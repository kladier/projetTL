#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
 * \file mainwindow.h
 * \brief Représente la fenetre principale du programme. On gère ici les listeners des boutons.

 */

#include <QSvgWidget>
#include <QMainWindow>
#include <QProcess>
#include <vector>
#include "automate.h"
#include <QPushButton>
#include <QFileDialog>
#include <QTextBrowser>
#include <QScrollBar>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:

    QProcess *ProcessT;
    QString program;


    /*!
         *  \brief Constructeur
         *
         *  Construit la fenetre.
         *
         */
    MainWindow(QWidget *parent = 0);

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe MainWindow
         */
    ~MainWindow();

    void startLayouting();
    void afficheAutomate(Automate);
    bool lireDot();
    bool lireDotB();

protected:
    void changeEvent(QEvent *e);

private:

    Ui::MainWindow *ui;

    QSvgWidget *maVue; /*!< Correspond à la partie inférieur de la fenêtre mais aussi à la partie centrale lorsqu'on ouvre un automate*/
    QSvgWidget *maVue1; /*!< Correspond à la partie supérieure droite de la fenêtre*/
    QSvgWidget *maVue2; /*!< Correspond à la partie supérieure gauche de la fenêtre*/
    QString dotFileName;
    QString dotFileNameB;
    Automate a;
    Automate B;
    vector<Automate> monVector; /*!< Vecteur d'automates, utilisé pour le produit.*/
    vector <  pair< Automate , string > > monDeterminisme; /*!< Vecteur d'automates, utilisé pour la déterminisation.*/
    vector <  pair< Automate , string > > monVectorStandard; /*!< Vecteur d'automates, utilisé pour la standardisation.*/
    vector <  pair< Automate , string > > monVectorMinimise; /*!< Vecteur d'automates, utilisé pour la minimisation.*/

    unsigned int actuel;
    void adjust();

public slots:
    /*!
       *  \brief Permet d'ouvrir un automate, stocké dans un fichier .dot
       *
       *  Listener du bouton ouvrir un automate, propose une fenetre pour sélectionner un fichier .dot correspondant à un automate.
       * Cet automate sera ensuite afficher dans maVue
       */
    void openFile();

    /*!
       *  \brief Permet d'accéder à la fenêtre de création d'automate
       *
       *  Listener du bouton ouvrir un automate, propose une fenetre pour créer un automate.
       */
    void creerAuto();

    /*!
       *  \brief Permet de faire le produit de 2 automates
       *
       *  Listener du bouton faire le produit de 2 automates, propose d'abord d'ouvrir une fenetre pour afficher le second automate.
       * L'automate déjà ouvert sera affiché dans maVue1.
       * L'automate ouvert sera affiché dans maVue2.
       * L'automate résultat du produit sera affiché dans maVue.
       */
    void getProduit();

    /*!
       *  \brief Permet de déterminiser un automate
       *
       *  Listener du bouton déterminiser.
       * L'automate ouvert sera affiché dans maVue1.
       * L'automate résultat du produit affiché dans maVue.
       */
    void getDetermin();

    /*!
       *  \brief Permet de passer à l'étape suivant pour une des opérations
       *
       *  Listener du bouton suivant.
       * L'étape suivante, s'il y en a une, d'une des opérations (standardisation, produit etc) sera affichée au lieu de l'actuel.
       */
    void getSuivant();

    /*!
       *  \brief Permet de passer à l'étape précédente pour une des opérations
       *
       *  Listener du bouton précédent.
       * L'étape précédente, s'il y en a une, d'une des opérations (standardisation, produit etc) sera affichée au lieu de l'actuel.
       */
    void getPrecedent();

    /*!
       *  \brief Permet de standardiser un automate
       *
       *  Listener du bouton standardiser.
       * L'automate ouvert sera affiché dans maVue1.
       * L'automate résultat du produit affiché dans maVue.
       */
    void getStandard();

    /*!
       *  \brief Permet de minimiser un automate
       *
       *  Listener du bouton minimiser.
       * L'automate ouvert sera affiché dans maVue1.
       * L'automate résultat du produit affiché dans maVue.
       */
    void getMinimisation();

    /*!
       *  \brief Permet de nettoyer la fenetre
       *
       *  Listener du bouton nettoyer l'interface.
       * Vide la fenetre et la ramène à un état comme au démarrage de l'application
       */
    void resetUi();
    void test();

    /*!
       *  \brief Permet d'afficher des informations sur les boutons et le fonctionnement du logiciel
       *
       *  Listener du bouton Info.
       * Affiche dans la fenetre de droite des informations sur les boutons
       */
    void info();
};

#endif // MAINWINDOW_H
