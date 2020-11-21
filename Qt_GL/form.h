#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "glwidget.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_DEMARRAGE1_clicked();

    void on_Arretage1_clicked();

    void on_DEMARAGE2_clicked();

    void on_Arretage2_clicked();

    void on_DEMARRAGE3_clicked();

    void on_Arretage3_clicked();

    void on_DEMARRAGE4_clicked();

    void on_Arretage4_clicked();

private:
    Ui::Form *ui;
    //Pour pouvoir lancer plusieurs simulations en même temps
    GLWidget* w1;
    GLWidget* w2;
    GLWidget* w3;
    GLWidget* w4;
};

#endif // FORM_H
