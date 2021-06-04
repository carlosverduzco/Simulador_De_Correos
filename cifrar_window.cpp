#include "cifrar_window.h"
#include "ui_cifrar_window.h"
#include <iostream>
Cifrar_Window::Cifrar_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cifrar_Window)
{
    ui->setupUi(this);
}

Cifrar_Window::~Cifrar_Window()
{
    delete ui;
}

void Cifrar_Window::on_pushButton_clicked()
{
    Model_email z;
    string contrasena=ui->lineEdit->text().toStdString();
    if(ui->radioButton->isChecked()){
        z.CifrarDescifrar(1,contrasena);
    }
    else if(ui->radioButton_2->isChecked()){
        z.CifrarDescifrar(0,contrasena);
    }
    else{
        std::cout << "No seleccionado" << std::endl;
    }
    ui->lineEdit->clear();
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);


}

void Cifrar_Window::on_pushButton_2_clicked()
{
    this->close();
}
