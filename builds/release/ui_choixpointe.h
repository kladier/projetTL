/********************************************************************************
** Form generated from reading UI file 'choixpointe.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXPOINTE_H
#define UI_CHOIXPOINTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            choixPointe->setObjectName(QStringLiteral("choixPointe"));
        choixPointe->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(choixPointe);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Widget = new QFrame(choixPointe);
        Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setFrameShape(QFrame::StyledPanel);
        Widget->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lesChoix = new QComboBox(Widget);
        lesChoix->setObjectName(QStringLiteral("lesChoix"));

        horizontalLayout->addWidget(lesChoix);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Images/Ajouter.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(Widget);


        retranslateUi(choixPointe);

        QMetaObject::connectSlotsByName(choixPointe);
    } // setupUi

    void retranslateUi(QWidget *choixPointe)
    {
        choixPointe->setWindowTitle(QApplication::translate("choixPointe", "Form", 0));
        label_3->setText(QApplication::translate("choixPointe", "Vers l'\303\251tat", 0));
        label_4->setText(QApplication::translate("choixPointe", "Par le chiffre", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class choixPointe: public Ui_choixPointe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXPOINTE_H
