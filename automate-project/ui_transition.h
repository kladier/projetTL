/********************************************************************************
** Form generated from reading UI file 'transition.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSITION_H
#define UI_TRANSITION_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transition
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *supress;

    void setupUi(QWidget *Transition)
    {
        if (Transition->objectName().isEmpty())
            Transition->setObjectName(QString::fromUtf8("Transition"));
        Transition->resize(400, 64);
        horizontalLayout = new QHBoxLayout(Transition);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Transition);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        supress = new QPushButton(Transition);
        supress->setObjectName(QString::fromUtf8("supress"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Images/supprimer.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        supress->setIcon(icon);

        horizontalLayout->addWidget(supress);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 5);

        retranslateUi(Transition);

        QMetaObject::connectSlotsByName(Transition);
    } // setupUi

    void retranslateUi(QWidget *Transition)
    {
        Transition->setWindowTitle(QApplication::translate("Transition", "Form", 0, -1));
        label->setText(QApplication::translate("Transition", "TextLabel", 0, -1));
        supress->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Transition: public Ui_Transition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSITION_H
