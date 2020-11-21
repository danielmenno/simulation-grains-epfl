#include "form.h"
#include "ui_form.h"
#include "glwidget.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    w1 = nullptr; w2 = nullptr; w3 = nullptr; w4 = nullptr;
    ui->setupUi(this);
    this->resize(1000, 1000);

}

Form::~Form()
{
    delete ui;
    delete w1; delete w2; delete w3; delete w4;
}

void Form::on_DEMARRAGE1_clicked()
{
    if(w1 == nullptr) {
        w1 = new GLWidget(0);
        ui->gridLayout->addWidget(w1);
    }
}

void Form::on_Arretage1_clicked()
{
    if(w1 != nullptr) {
        w1->~GLWidget();
        ui->gridLayout->removeWidget(w1);
        w1 = nullptr;
    }
}

void Form::on_DEMARAGE2_clicked()
{
    if(w2 == nullptr) {
        w2 = new GLWidget(1);
        ui->gridLayout_2->addWidget(w2);
    }

}

void Form::on_Arretage2_clicked()
{
    if(w2 != nullptr) {
        w2->~GLWidget();
        ui->gridLayout_2->removeWidget(w2);
        w2 = nullptr;
    }

}

void Form::on_DEMARRAGE3_clicked()
{
    if(w3 == nullptr) {
        w3 = new GLWidget(2);
        ui->gridLayout_3->addWidget(w3);
    }

}

void Form::on_Arretage3_clicked()
{
    if(w3 != nullptr) {
        w3->~GLWidget();
        ui->gridLayout_3->removeWidget(w3);
        w3 = nullptr;
    }

}

void Form::on_DEMARRAGE4_clicked()
{
    if(w4 == nullptr) {
        w4 = new GLWidget(3);
        ui->gridLayout_5->addWidget(w4);
    }

}

void Form::on_Arretage4_clicked()
{
    if(w4 != nullptr) {
        w4->~GLWidget();
        ui->gridLayout_5->removeWidget(w4);
        w4 = nullptr;
    }

}
