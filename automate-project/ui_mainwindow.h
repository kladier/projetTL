/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFermer;
    QAction *actionNew;
    QAction *actionFaireProduit;
    QAction *actionOuvrir;
    QAction *actionVoir;
    QAction *actionTest;
    QAction *actionClean;
    QAction *actionInfo;
    QAction *actionDeterminiser;
    QAction *actionStandardiser;
    QAction *actionMinimiser;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *TopLayout;
    QPushButton *boutonPrec;
    QPushButton *boutonSuiv;
    QHBoxLayout *MiddleLayout;
    QScrollArea *scrollArea_3;
    QWidget *vue1;
    QScrollArea *scrollArea_2;
    QWidget *vue2;
    QHBoxLayout *LowerLayout;
    QScrollArea *scrollArea;
    QWidget *vueTomate;
    QTextEdit *label;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QToolBar *toolBar_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(912, 504);
        MainWindow->setMinimumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/myAppIco.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        actionFermer = new QAction(MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Images/suppr.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFermer->setIcon(icon1);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/Images/nouveau.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionFaireProduit = new QAction(MainWindow);
        actionFaireProduit->setObjectName(QStringLiteral("actionFaireProduit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/Images/produit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFaireProduit->setIcon(icon3);
        actionFaireProduit->setVisible(false);
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/Images/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrir->setIcon(icon4);
        actionVoir = new QAction(MainWindow);
        actionVoir->setObjectName(QStringLiteral("actionVoir"));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/Images/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionTest->setIcon(icon5);
        actionTest->setVisible(false);
        actionClean = new QAction(MainWindow);
        actionClean->setObjectName(QStringLiteral("actionClean"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/Images/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClean->setIcon(icon6);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/Images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon7);
        actionDeterminiser = new QAction(MainWindow);
        actionDeterminiser->setObjectName(QStringLiteral("actionDeterminiser"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/Images/determin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeterminiser->setIcon(icon8);
        actionDeterminiser->setVisible(false);
        actionStandardiser = new QAction(MainWindow);
        actionStandardiser->setObjectName(QStringLiteral("actionStandardiser"));
        actionStandardiser->setEnabled(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/Images/standardiser.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionStandardiser->setIcon(icon9);
        actionStandardiser->setVisible(true);
        actionMinimiser = new QAction(MainWindow);
        actionMinimiser->setObjectName(QStringLiteral("actionMinimiser"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/Images/minimiser.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionMinimiser->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        TopLayout = new QHBoxLayout();
        TopLayout->setSpacing(6);
        TopLayout->setObjectName(QStringLiteral("TopLayout"));
        boutonPrec = new QPushButton(centralWidget);
        boutonPrec->setObjectName(QStringLiteral("boutonPrec"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/prefix1/Images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        boutonPrec->setIcon(icon11);

        TopLayout->addWidget(boutonPrec);

        boutonSuiv = new QPushButton(centralWidget);
        boutonSuiv->setObjectName(QStringLiteral("boutonSuiv"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/Images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        boutonSuiv->setIcon(icon12);
        boutonSuiv->setIconSize(QSize(16, 16));

        TopLayout->addWidget(boutonSuiv);


        verticalLayout->addLayout(TopLayout);

        MiddleLayout = new QHBoxLayout();
        MiddleLayout->setSpacing(6);
        MiddleLayout->setObjectName(QStringLiteral("MiddleLayout"));
        scrollArea_3 = new QScrollArea(centralWidget);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setMaximumSize(QSize(16777215, 150));
        scrollArea_3->setWidgetResizable(false);
        vue1 = new QWidget();
        vue1->setObjectName(QStringLiteral("vue1"));
        vue1->setGeometry(QRect(0, 0, 322, 69));
        vue1->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_3->setWidget(vue1);

        MiddleLayout->addWidget(scrollArea_3);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMaximumSize(QSize(16777215, 150));
        scrollArea_2->setWidgetResizable(false);
        vue2 = new QWidget();
        vue2->setObjectName(QStringLiteral("vue2"));
        vue2->setGeometry(QRect(0, 0, 321, 69));
        vue2->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_2->setWidget(vue2);

        MiddleLayout->addWidget(scrollArea_2);


        verticalLayout->addLayout(MiddleLayout);

        LowerLayout = new QHBoxLayout();
        LowerLayout->setSpacing(6);
        LowerLayout->setObjectName(QStringLiteral("LowerLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setWidgetResizable(false);
        vueTomate = new QWidget();
        vueTomate->setObjectName(QStringLiteral("vueTomate"));
        vueTomate->setGeometry(QRect(0, 0, 651, 284));
        scrollArea->setWidget(vueTomate);

        LowerLayout->addWidget(scrollArea);


        verticalLayout->addLayout(LowerLayout);


        horizontalLayout->addLayout(verticalLayout);

        label = new QTextEdit(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setAutoFillBackground(true);
        label->setReadOnly(true);

        horizontalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 912, 21));
        menuBar->setAutoFillBackground(true);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addSeparator();
        menuFichier->addAction(actionNew);
        menuFichier->addSeparator();
        menuFichier->addAction(actionStandardiser);
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        toolBar_2->addAction(actionNew);
        toolBar_2->addAction(actionOuvrir);
        toolBar_2->addAction(actionClean);
        toolBar_2->addAction(actionInfo);
        toolBar_2->addAction(actionFaireProduit);
        toolBar_2->addAction(actionTest);
        toolBar_2->addAction(actionDeterminiser);
        toolBar_2->addAction(actionStandardiser);
        toolBar_2->addAction(actionMinimiser);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionFermer->setText(QApplication::translate("MainWindow", "Fermer", 0));
        actionFermer->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        actionNew->setText(QApplication::translate("MainWindow", "Nouveau", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Cr\303\251er un automate", 0));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionFaireProduit->setText(QApplication::translate("MainWindow", "FaireProduit", 0));
#ifndef QT_NO_TOOLTIP
        actionFaireProduit->setToolTip(QApplication::translate("MainWindow", "Faire le produit de deux automates", 0));
#endif // QT_NO_TOOLTIP
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0));
#ifndef QT_NO_TOOLTIP
        actionOuvrir->setToolTip(QApplication::translate("MainWindow", "Ouvrir un automate", 0));
#endif // QT_NO_TOOLTIP
        actionOuvrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionVoir->setText(QApplication::translate("MainWindow", "voir", 0));
        actionTest->setText(QApplication::translate("MainWindow", "Test", 0));
        actionClean->setText(QApplication::translate("MainWindow", "Clean", 0));
#ifndef QT_NO_TOOLTIP
        actionClean->setToolTip(QApplication::translate("MainWindow", "Nettoyer l'interface", 0));
#endif // QT_NO_TOOLTIP
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0));
        actionDeterminiser->setText(QApplication::translate("MainWindow", "Determiniser", 0));
#ifndef QT_NO_TOOLTIP
        actionDeterminiser->setToolTip(QApplication::translate("MainWindow", "Determiniser L'automate", 0));
#endif // QT_NO_TOOLTIP
        actionStandardiser->setText(QApplication::translate("MainWindow", "Standardiser", 0));
        actionMinimiser->setText(QApplication::translate("MainWindow", "Minimiser", 0));
#ifndef QT_NO_TOOLTIP
        actionMinimiser->setToolTip(QApplication::translate("MainWindow", "Minimiser l'automate", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        boutonPrec->setToolTip(QApplication::translate("MainWindow", "Voir l'\303\251tape pr\303\251cedente", 0));
#endif // QT_NO_TOOLTIP
        boutonPrec->setText(QApplication::translate("MainWindow", "Pr\303\251c\303\251dent", 0));
        boutonPrec->setShortcut(QApplication::translate("MainWindow", "Left", 0));
#ifndef QT_NO_TOOLTIP
        boutonSuiv->setToolTip(QApplication::translate("MainWindow", "Voir l'\303\251tape suivante", 0));
#endif // QT_NO_TOOLTIP
        boutonSuiv->setText(QApplication::translate("MainWindow", "Suivant", 0));
        boutonSuiv->setShortcut(QApplication::translate("MainWindow", "Right", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
#ifndef QT_NO_TOOLTIP
        statusBar->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
