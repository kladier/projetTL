/********************************************************************************
** Form generated from reading UI file 'etatleft.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETATLEFT_H
#define UI_ETATLEFT_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_etatLeft
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *etatLeft)
    {
        if (etatLeft->objectName().isEmpty())
            etatLeft->setObjectName(QString::fromUtf8("etatLeft"));
        etatLeft->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        etatLeft->setWindowIcon(icon);
        gridLayout = new QGridLayout(etatLeft);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(etatLeft);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(etatLeft);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Images/S\303\251l\303\251ction 2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(etatLeft);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Images/suppr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(etatLeft);

        QMetaObject::connectSlotsByName(etatLeft);
    } // setupUi

    void retranslateUi(QWidget *etatLeft)
    {
        etatLeft->setWindowTitle(QApplication::translate("etatLeft", "Form", 0, -1));
        label->setText(QApplication::translate("etatLeft", "TextLabel", 0, -1));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("etatLeft", "Supprimer", 0, -1));
    } // retranslateUi

};

namespace Ui {
    class etatLeft: public Ui_etatLeft {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETATLEFT_H
