#ifndef CREATEAUTOMATE_H
#define CREATEAUTOMATE_H

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
    CreateAutomate(QWidget *parent = 0);
    ~CreateAutomate();
    Automate a;
    QSvgWidget *maVue;
    int actuel;
    vector<etatLeft*> left;
    vector<etatRight*> right;
    void resetAllListChoix();
    void displayAutomate();

public slots:
    void ajoutEtat(bool ini=false,bool fina = false);
    void afficherAutomate();
    void displayRight(int);
    void supprimeEtat(int);
    void refreshAll();
    void sauvegarder();
    void changeState(int,bool,bool);

protected:
    void changeEvent(QEvent *e);
    void adjust();

private:
    Ui::CreateAutomate *ui;
};

#endif // CREATEAUTOMATE_H
