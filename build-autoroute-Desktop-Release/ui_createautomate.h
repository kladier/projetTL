/********************************************************************************
** Form generated from reading UI file 'createautomate.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEAUTOMATE_H
#define UI_CREATEAUTOMATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAutomate
{
public:
    QAction *actionFermer;
    QAction *actionVoir;
    QAction *actionSauvegarder;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *etatVert;
    QPushButton *pushButton;
    QVBoxLayout *Droite;
    QFrame *frame1;
    QGridLayout *etatDroite;
    QScrollArea *scrollArea;
    QWidget *vueTomate;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CreateAutomate)
    {
        if (CreateAutomate->objectName().isEmpty())
            CreateAutomate->setObjectName(QStringLiteral("CreateAutomate"));
        CreateAutomate->setWindowModality(Qt::NonModal);
        CreateAutomate->resize(384, 403);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CreateAutomate->setWindowIcon(icon);
        CreateAutomate->setAutoFillBackground(true);
        CreateAutomate->setTabShape(QTabWidget::Rounded);
        actionFermer = new QAction(CreateAutomate);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Images/suppr.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFermer->setIcon(icon1);
        actionVoir = new QAction(CreateAutomate);
        actionVoir->setObjectName(QStringLiteral("actionVoir"));
        actionVoir->setVisible(false);
        actionSauvegarder = new QAction(CreateAutomate);
        actionSauvegarder->setObjectName(QStringLiteral("actionSauvegarder"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSauvegarder->setIcon(icon2);
        centralwidget = new QWidget(CreateAutomate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setMouseTracking(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        etatVert = new QVBoxLayout(frame);
        etatVert->setObjectName(QStringLiteral("etatVert"));
        etatVert->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        etatVert->addWidget(pushButton);


        horizontalLayout->addWidget(frame);

        Droite = new QVBoxLayout();
        Droite->setObjectName(QStringLiteral("Droite"));
        frame1 = new QFrame(centralwidget);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setMinimumSize(QSize(0, 0));
        frame1->setFrameShape(QFrame::Box);
        frame1->setFrameShadow(QFrame::Plain);
        etatDroite = new QGridLayout(frame1);
        etatDroite->setObjectName(QStringLiteral("etatDroite"));

        Droite->addWidget(frame1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(false);
        vueTomate = new QWidget();
        vueTomate->setObjectName(QStringLiteral("vueTomate"));
        vueTomate->setGeometry(QRect(0, 0, 244, 204));
        scrollArea->setWidget(vueTomate);

        Droite->addWidget(scrollArea);


        horizontalLayout->addLayout(Droite);

        CreateAutomate->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateAutomate);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 384, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        CreateAutomate->setMenuBar(menubar);
        toolBar = new QToolBar(CreateAutomate);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        CreateAutomate->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionSauvegarder);
        menuFichier->addSeparator();
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionVoir);
        toolBar->addAction(actionSauvegarder);

        retranslateUi(CreateAutomate);
        QObject::connect(actionFermer, SIGNAL(triggered()), CreateAutomate, SLOT(close()));

        QMetaObject::connectSlotsByName(CreateAutomate);
    } // setupUi

    void retranslateUi(QMainWindow *CreateAutomate)
    {
        CreateAutomate->setWindowTitle(QApplication::translate("CreateAutomate", "Cr\303\251ation d'automate", 0));
#ifndef QT_NO_ACCESSIBILITY
        CreateAutomate->setAccessibleDescription(QApplication::translate("CreateAutomate", "Un outil pour cr\303\251er des automates", 0));
#endif // QT_NO_ACCESSIBILITY
        actionFermer->setText(QApplication::translate("CreateAutomate", "fermer", 0));
        actionFermer->setShortcut(QApplication::translate("CreateAutomate", "Esc", 0));
        actionVoir->setText(QApplication::translate("CreateAutomate", "Voir", 0));
        actionSauvegarder->setText(QApplication::translate("CreateAutomate", "sauvegarder", 0));
#ifndef QT_NO_TOOLTIP
        actionSauvegarder->setToolTip(QApplication::translate("CreateAutomate", "sauvegarder l'automate", 0));
#endif // QT_NO_TOOLTIP
        actionSauvegarder->setShortcut(QApplication::translate("CreateAutomate", "Ctrl+S", 0));
        pushButton->setText(QApplication::translate("CreateAutomate", "Ajouter Etat", 0));
        menuFichier->setTitle(QApplication::translate("CreateAutomate", "Fichier", 0));
        toolBar->setWindowTitle(QApplication::translate("CreateAutomate", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAutomate: public Ui_CreateAutomate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEAUTOMATE_H
