#include "busqueda_en_memoria.h"
#include "ui_busqueda_en_memoria.h"

busqueda_en_memoria::busqueda_en_memoria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::busqueda_en_memoria)
{
    ui->setupUi(this);
        Model_email a;
        z.lista=a.BusquedaEnMemoria(z.cont);
        if(z.lista)
            z.shellSort();

        else{
            ui->lineEdit_9->setEnabled(false);
            ui->textBrowser->setText("No existe el archivo o esta vacio.");
        }
}

busqueda_en_memoria::~busqueda_en_memoria()
{
    delete ui;
}

void busqueda_en_memoria::on_pushButton_clicked()
{
    this->close();
}
void busqueda_en_memoria::binaria(email* arr,int p,int r,string num){
    if (p <= r) {
          int i = (p + r)/2;
          if (arr[i].From == num){
              ui->lineEdit->setText(z.lista[i].Identificador);
              ui->lineEdit_2->setText(z.lista[i].Fecha);
              ui->lineEdit_3->setText(z.lista[i].Hora);
              ui->lineEdit_4->setText(z.lista[i].From);
              ui->lineEdit_5->setText(z.lista[i].To);
              ui->lineEdit_6->setText(z.lista[i].CC);
              ui->lineEdit_7->setText(z.lista[i].BCC);
              ui->lineEdit_8->setText(z.lista[i].subject);
              ui->plainTextEdit->setPlainText(z.lista[i].Content);
              ui->textBrowser->clear();
          }
          for(int k=0;(arr[i].From)[k]!='\0' or k<num.size();k++){
              if (arr[i].From[k] > num[k]){
                  binaria(arr, p, i-1, num);
              }
              if (arr[i].From[k] < num[k]){
                  binaria(arr, i+1, r, num);
              }

          }
       }
}

void busqueda_en_memoria::on_pushButton_2_clicked()
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
    if(!z.lista)
        return;
//busqueda binaria recursiva
    binaria(z.lista,0,(*z.cont)-1,ui->lineEdit_9->text().toStdString());
    if(ui->lineEdit->text().toStdString().size()==0)
        ui->textBrowser->setText("No encontrado.");

//busqueda binaria iterativa no funca
//        int i,izq=0,der=(*z.cont)-1;
//        while(izq <= der){
//            i=(izq+der)/2;
//            string aux=z.lista[i].From;
//            if(aux==(ui->lineEdit_9->text().toStdString())){
//                ui->lineEdit->setText(z.lista[i].Identificador);
//                ui->lineEdit_2->setText(z.lista[i].Fecha);
//                ui->lineEdit_3->setText(z.lista[i].Hora);
//                ui->lineEdit_4->setText(z.lista[i].From);
//                ui->lineEdit_5->setText(z.lista[i].To);
//                ui->lineEdit_6->setText(z.lista[i].CC);
//                ui->lineEdit_7->setText(z.lista[i].BCC);
//                ui->lineEdit_8->setText(z.lista[i].subject);
//                ui->plainTextEdit->setPlainText(z.lista[i].Content);
//                ui->textBrowser->clear();
//                break;
//            }
//            for(int k=0;k<ui->lineEdit_9->text().toStdString().size() or k<aux.size();k++){
//                if(aux[k]<(ui->lineEdit_9->text().toStdString())[k]){
//                    izq=i+1;
//                    break;
//                }
//                else if(aux[k]>(ui->lineEdit_9->text().toStdString())[k]){
//                    der=i-1;
//                    break;
//                }
//            }

//           if(!(izq <= der)){
//               ui->lineEdit->clear();
//               ui->lineEdit_2->clear();
//               ui->lineEdit_3->clear();
//               ui->lineEdit_4->clear();
//               ui->lineEdit_5->clear();
//               ui->lineEdit_6->clear();
//               ui->lineEdit_7->clear();
//               ui->lineEdit_8->clear();
//               ui->plainTextEdit->clear();
//               ui->textBrowser->setText("No encontrado.");
//           }
//        }
// busqueda secuencial
//        for(int i=0;i<*z.cont;i++){
//            string aux=z.lista[i].From;
//            if(aux==(ui->lineEdit_9->text().toStdString())){
//                ui->lineEdit->setText(z.lista[i].Identificador);
//                ui->lineEdit_2->setText(z.lista[i].Fecha);
//                ui->lineEdit_3->setText(z.lista[i].Hora);
//                ui->lineEdit_4->setText(z.lista[i].From);
//                ui->lineEdit_5->setText(z.lista[i].To);
//                ui->lineEdit_6->setText(z.lista[i].CC);
//                ui->lineEdit_7->setText(z.lista[i].BCC);
//                ui->lineEdit_8->setText(z.lista[i].subject);
//                ui->plainTextEdit->setPlainText(z.lista[i].Content);
//                ui->textBrowser->clear();
//                break;
//            }
//            else if(i==*z.cont-1){
//                ui->lineEdit->clear();
//                ui->lineEdit_2->clear();
//                ui->lineEdit_3->clear();
//                ui->lineEdit_4->clear();
//                ui->lineEdit_5->clear();
//                ui->lineEdit_6->clear();
//                ui->lineEdit_7->clear();
//                ui->lineEdit_8->clear();
//                ui->plainTextEdit->clear();
//                ui->textBrowser->setText("No encontrado.");
//            }
//        }
//busqueda por posicion
    //            for(int i=0;i<*z.cont;i++){
    //                if(i==(ui->lineEdit_9->text().toInt())){
    //                    ui->lineEdit->setText(z.lista[i].Identificador);
    //                    ui->lineEdit_2->setText(z.lista[i].Fecha);
    //                    ui->lineEdit_3->setText(z.lista[i].Hora);
    //                    ui->lineEdit_4->setText(z.lista[i].From);
    //                    ui->lineEdit_5->setText(z.lista[i].To);
    //                    ui->lineEdit_6->setText(z.lista[i].CC);
    //                    ui->lineEdit_7->setText(z.lista[i].BCC);
    //                    ui->lineEdit_8->setText(z.lista[i].subject);
    //                    ui->plainTextEdit->setPlainText(z.lista[i].Content);
    //                    ui->textBrowser->clear();
    //                    break;
    //                }
    //                else if(i==*z.cont-1){
    //                    ui->lineEdit->clear();
    //                    ui->lineEdit_2->clear();
    //                    ui->lineEdit_3->clear();
    //                    ui->lineEdit_4->clear();
    //                    ui->lineEdit_5->clear();
    //                    ui->lineEdit_6->clear();
    //                    ui->lineEdit_7->clear();
    //                    ui->lineEdit_8->clear();
    //                    ui->plainTextEdit->clear();
    //                    ui->textBrowser->setText("No encontrado.");
    //                }
    //            }

}
