#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QProcess *ProcessT;
    void startLayouting();
    QString program;

    void afficheAutomate(Automate);
    bool lireDot();
    bool lireDotB();

protected:
    void changeEvent(QEvent *e);

private:

    Ui::MainWindow *ui;

    QSvgWidget *maVue;
    QSvgWidget *maVue1;
    QSvgWidget *maVue2;
    QString dotFileName;
    QString dotFileNameB;
    Automate a;
    Automate B;
    vector<Automate> monVector; //utiliser pour le produit
    vector <  pair< Automate , string > > monDeterminisme; //utiliser pour le determinisme
    vector <  pair< Automate , string > > monVectorStandard; //Utiliser pour la standardisation
    vector <  pair< Automate , string > > monVectorMinimise; //Utiliser pour la minimisation

    unsigned int actuel;
    void adjust();

public slots:
    void openFile();
    void creerAuto();
    void getProduit();
    void getDetermin();
    void getSuivant();
    void getPrecedent();
    void getStandard();
    void getMinimisation();
    void resetUi();
    void test();
    void info();
};

#endif // MAINWINDOW_H
