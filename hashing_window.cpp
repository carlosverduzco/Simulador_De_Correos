#include "hashing_window.h"
#include "ui_hashing_window.h"

Hashing_Window::Hashing_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hashing_Window)
{
    ui->setupUi(this);
}

Hashing_Window::~Hashing_Window()
{
    hash.Serialize();
    delete ui;
}

void Hashing_Window::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->plainTextEdit->clear();
    ui->textBrowser->setVisible(false);
    string Identificador=ui->lineEdit_9->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    if(Identificador.length()<=10){
        if(Identificador.length()>0){
            char array[10];
            strcpy(array,Identificador.c_str());
            unsigned int* referencia=hash.Search(array);
            if(!referencia){
                ui->textBrowser->setVisible(true);
                ui->textBrowser->setPlainText("No encontrada en la tabla de dispersion.");
                return;
            }
                if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
                    ui->lineEdit->setText(Identificador.c_str());
                    ui->lineEdit_2->setText(Fecha.c_str());
                    ui->lineEdit_3->setText(Hora.c_str());
                    ui->lineEdit_4->setText(From.c_str());
                    ui->lineEdit_5->setText(To.c_str());
                    ui->lineEdit_6->setText(CC.c_str());
                    ui->lineEdit_7->setText(BCC.c_str());
                    ui->lineEdit_8->setText(subject.c_str());
                    ui->plainTextEdit->setPlainText(Content.c_str());
                    ui->textBrowser->setVisible(false);
                }
                else{
                    ui->textBrowser->setVisible(true);
                    ui->textBrowser->setText("No existe un correo con ese identificador.");
                }
        }
        else{
            ui->textBrowser->setVisible(true);
            ui->textBrowser->setText("El Identificador debe ser de mas de 0 caracteres.");
        }
    }
    else{
        ui->textBrowser->setVisible(true);
        ui->textBrowser->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
}
