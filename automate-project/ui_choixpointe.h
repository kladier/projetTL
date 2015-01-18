/********************************************************************************
** Form generated from reading UI file 'choixpointe.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXPOINTE_H
#define UI_CHOIXPOINTE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_choixPointe
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *Widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *lesChoix;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *choixPointe)
    {
        if (choixPointe->objectName().isEmpty())
            choixPointe->setObjectName(QString::fromUtf8("choixPointe"));
        choixPointe->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(choixPointe);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Widget = new QFrame(choixPointe);
        Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setFrameShape(QFrame::StyledPanel);
        Widget->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lesChoix = new QComboBox(Widget);
        lesChoix->setObjectName(QString::fromUtf8("lesChoix"));

        horizontalLayout->addWidget(lesChoix);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Images/Ajouter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(Widget);


        retranslateUi(choixPointe);

        QMetaObject::connectSlotsByName(choixPointe);
    } // setupUi

    void retranslateUi(QWidget *choixPointe)
    {
        choixPointe->setWindowTitle(QApplication::translate("choixPointe", "Form", 0, -1));
        label_3->setText(QApplication::translate("choixPointe", "Vers l'\303\251tat", 0, -1));
        label_4->setText(QApplication::translate("choixPointe", "Par le chiffre", 0, -1));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class choixPointe: public Ui_choixPointe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXPOINTE_H
