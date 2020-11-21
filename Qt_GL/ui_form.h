/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *DEMARRAGE1;
    QPushButton *Arretage1;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QPushButton *DEMARAGE2;
    QPushButton *Arretage2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *DEMARRAGE3;
    QPushButton *Arretage3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_9;
    QPushButton *DEMARRAGE4;
    QPushButton *Arretage4;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(913, 766);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(Form);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(1, 50));

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer);

        DEMARRAGE1 = new QPushButton(tab);
        DEMARRAGE1->setObjectName(QStringLiteral("DEMARRAGE1"));
        sizePolicy1.setHeightForWidth(DEMARRAGE1->sizePolicy().hasHeightForWidth());
        DEMARRAGE1->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(DEMARRAGE1);

        Arretage1 = new QPushButton(tab);
        Arretage1->setObjectName(QStringLiteral("Arretage1"));
        sizePolicy1.setHeightForWidth(Arretage1->sizePolicy().hasHeightForWidth());
        Arretage1->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(Arretage1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);

        DEMARAGE2 = new QPushButton(tab_2);
        DEMARAGE2->setObjectName(QStringLiteral("DEMARAGE2"));
        sizePolicy1.setHeightForWidth(DEMARAGE2->sizePolicy().hasHeightForWidth());
        DEMARAGE2->setSizePolicy(sizePolicy1);
        DEMARAGE2->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(DEMARAGE2);

        Arretage2 = new QPushButton(tab_2);
        Arretage2->setObjectName(QStringLiteral("Arretage2"));
        sizePolicy1.setHeightForWidth(Arretage2->sizePolicy().hasHeightForWidth());
        Arretage2->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(Arretage2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_5);

        DEMARRAGE3 = new QPushButton(tab_3);
        DEMARRAGE3->setObjectName(QStringLiteral("DEMARRAGE3"));
        sizePolicy1.setHeightForWidth(DEMARRAGE3->sizePolicy().hasHeightForWidth());
        DEMARRAGE3->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(DEMARRAGE3);

        Arretage3 = new QPushButton(tab_3);
        Arretage3->setObjectName(QStringLiteral("Arretage3"));
        sizePolicy1.setHeightForWidth(Arretage3->sizePolicy().hasHeightForWidth());
        Arretage3->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(Arretage3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_5->addItem(verticalSpacer_6);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_4 = new QHBoxLayout(tab_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetMinimumSize);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_7->addItem(verticalSpacer_9);

        DEMARRAGE4 = new QPushButton(tab_4);
        DEMARRAGE4->setObjectName(QStringLiteral("DEMARRAGE4"));
        sizePolicy1.setHeightForWidth(DEMARRAGE4->sizePolicy().hasHeightForWidth());
        DEMARRAGE4->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(DEMARRAGE4);

        Arretage4 = new QPushButton(tab_4);
        Arretage4->setObjectName(QStringLiteral("Arretage4"));
        sizePolicy1.setHeightForWidth(Arretage4->sizePolicy().hasHeightForWidth());
        Arretage4->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(Arretage4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_7->addItem(verticalSpacer_10);


        horizontalLayout_4->addLayout(verticalLayout_7);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_5);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "Projet de programmation 2017 PH-BA2 ", Q_NULLPTR));
        DEMARRAGE1->setText(QApplication::translate("Form", "D\303\251marrer", Q_NULLPTR));
        Arretage1->setText(QApplication::translate("Form", "Arr\303\252ter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form", "Simulation n\302\2601", Q_NULLPTR));
        DEMARAGE2->setText(QApplication::translate("Form", "D\303\251marrer", Q_NULLPTR));
        Arretage2->setText(QApplication::translate("Form", "Arr\303\252ter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Form", "Simulation n\302\2602", Q_NULLPTR));
        DEMARRAGE3->setText(QApplication::translate("Form", "D\303\251marrer", Q_NULLPTR));
        Arretage3->setText(QApplication::translate("Form", "Arr\303\252ter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form", "Simulation n\302\2603", Q_NULLPTR));
        DEMARRAGE4->setText(QApplication::translate("Form", "D\303\251marrer", Q_NULLPTR));
        Arretage4->setText(QApplication::translate("Form", "Arr\303\252ter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Form", "Simulation n\302\2604", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
