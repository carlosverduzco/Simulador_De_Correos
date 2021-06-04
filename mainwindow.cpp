#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <math.h>

string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setVisible(false);
    ui->textBrowser_2->setVisible(false);
    ui->textBrowser_5->setVisible(false);
    ui->plainTextEdit_2->setReadOnly(true);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->lineEdit_5_old->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    arbolavl.GuardarIndice();

}
void MainWindow::on_pushButton_clicked()//agregar
{
    QString Identificador= ui->lineEdit->text();
    QString From= ui->lineEdit_2->text();
    QString To= ui->lineEdit_3->text();
    QString CC= ui->lineEdit_4->text();
    QString BCC= ui->lineEdit_5->text();
    QString subject= ui->lineEdit_6->text();
    QString Content= ui->plainTextEdit->toPlainText();
    Model_email model;
    int cod_error=model.agregar(Identificador.toStdString(),From.toStdString(),To.toStdString(),CC.toStdString(),BCC.toStdString(),subject.toStdString(),Content.toStdString());
    if(cod_error!=10){
        if(cod_error!=9){
            if(cod_error!=8){
                if(cod_error!=7){
                    if(cod_error!=6){
                        if(cod_error!=5){
                            if(cod_error!=4){
                                if(cod_error!=3){
                                    if(cod_error!=2){
                                        if(cod_error==1){
                                            ui->textBrowser->setVisible(true);
                                            ui->textBrowser->setText("Ya existe un correo con ese identificador");
                                        }
                                        else{
                                            ui->textBrowser->setVisible(false);
                                            arbolavl.insert(Identificador.toStdString(),Identificador.toUInt());
                                            arbolavl.Desactualizado();
                                        }
                                    }
                                    else{
                                        ui->textBrowser->setVisible(true);
                                        ui->textBrowser->setText("El contenido debe ser de igual o menos de 100 caracteres.");
                                    }
                                }else{
                                    ui->textBrowser->setVisible(true);
                                    ui->textBrowser->setText("El asunto debe ser de igual o menos de 30 caracteres.");
                                }
                            }else{
                                ui->textBrowser->setVisible(true);
                                ui->textBrowser->setText("El BCC debe ser de igual o menos de 50 caracteres.");
                            }
                        }else{
                            ui->textBrowser->setVisible(true);
                            ui->textBrowser->setText("El CC debe ser de igual o menos de 50 caracteres.");
                        }
                    }else{
                        ui->textBrowser->setVisible(true);
                        ui->textBrowser->setText("El Destinatario debe ser igual o de menos de 30 caracteres.");
                    }
                }else{
                    ui->textBrowser->setVisible(true);
                    ui->textBrowser->setText("El Remitente debe ser de igual o menos de 30 caracteres.");
                }
            }else{
                ui->textBrowser->setVisible(true);
                ui->textBrowser->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser->setVisible(true);
            ui->textBrowser->setText("El Identificador debe ser un entero positivo.");
        }
    }else{
        ui->textBrowser->setVisible(true);
        ui->textBrowser->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->plainTextEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()//limpiar todo(agregar)
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->plainTextEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()//LeerDirecto
{
    string Identificador=ui->lineEdit_15->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->plainTextEdit_2->clear();
    ui->pushButton_5->setVisible(false);
    if(Identificador.length()<=10){
        if(Identificador.length()>0){
            if(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(Identificador, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
                    ui->lineEdit_7->setText(Identificador.c_str());
                    ui->lineEdit_8->setText(Fecha.c_str());
                    ui->lineEdit_9->setText(Hora.c_str());
                    ui->lineEdit_10->setText(From.c_str());
                    ui->lineEdit_11->setText(To.c_str());
                    ui->lineEdit_12->setText(CC.c_str());
                    ui->lineEdit_13->setText(BCC.c_str());
                    ui->lineEdit_14->setText(subject.c_str());
                    ui->plainTextEdit_2->setPlainText(Content.c_str());
                    ui->textBrowser_2->setVisible(false);
                }
                else{
                    ui->textBrowser_2->setVisible(true);
                    ui->textBrowser_2->setText("No existe un correo con ese identificador.");
                }
            }else{
                ui->textBrowser_2->setVisible(true);
                ui->textBrowser_2->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_2->setVisible(true);
            ui->textBrowser_2->setText("El Identificador debe ser de mas de 0 caracteres.");
        }
    }else{
        ui->textBrowser_2->setVisible(true);
        ui->textBrowser_2->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
}

void MainWindow::on_pushButton_4_clicked()//LeerSecuencial
{

    string Identificador;
    string Fecha;
    string Hora;
    string From=ui->lineEdit_15->text().toStdString();
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->plainTextEdit_2->clear();
    ui->pushButton_5->setVisible(false);
    if(From.length()>0){
        if(From.length()<=30){
                    if(model.leerSecuencial(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content,-1)){
                        ui->lineEdit_7->setText(Identificador.c_str());
                        ui->lineEdit_8->setText(Fecha.c_str());
                        ui->lineEdit_9->setText(Hora.c_str());
                        ui->lineEdit_10->setText(From.c_str());
                        ui->lineEdit_11->setText(To.c_str());
                        ui->lineEdit_12->setText(CC.c_str());
                        ui->lineEdit_13->setText(BCC.c_str());
                        ui->lineEdit_14->setText(subject.c_str());
                        ui->plainTextEdit_2->setPlainText(Content.c_str());
                        ui->pushButton_5->setVisible(true);
                        ui->textBrowser_2->setVisible(false);
                    }
                    else{
                        ui->textBrowser_2->setVisible(true);
                        ui->textBrowser_2->setText("No existe un correo con ese destinatario.");
                    }
        }else{
            ui->textBrowser_2->setVisible(true);
            ui->textBrowser_2->setText("El destinatario debe ser menor de 30 caracteres.");
        }
    }else{
        ui->textBrowser_2->setVisible(true);
        ui->textBrowser_2->setText("El destinatario debe tener almenos 1 caracter.");
    }
}

void MainWindow::on_pushButton_5_clicked()//LeerSecuencial(siguiente)
{
    QString actual= ui->lineEdit_7->text();
    string Identificador;
    string Fecha;
    string Hora;
    string From=ui->lineEdit_15->text().toStdString();
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    double input;
    stringstream sso;
    if(ui->lineEdit_10->text().toStdString()!=From){
        ui->pushButton_5->setVisible(false);
        return;
    }
    sso << actual.toStdString();
    sso >> input;
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->plainTextEdit_2->clear();
    ui->pushButton_5->setVisible(false);
    if(From.length()<=30){
                if(model.leerSecuencial(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content,input)){
                    ui->lineEdit_7->setText(Identificador.c_str());
                    ui->lineEdit_8->setText(Fecha.c_str());
                    ui->lineEdit_9->setText(Hora.c_str());
                    ui->lineEdit_10->setText(From.c_str());
                    ui->lineEdit_11->setText(To.c_str());
                    ui->lineEdit_12->setText(CC.c_str());
                    ui->lineEdit_13->setText(BCC.c_str());
                    ui->lineEdit_14->setText(subject.c_str());
                    ui->plainTextEdit_2->setPlainText(Content.c_str());
                    ui->pushButton_5->setVisible(true);
                    ui->textBrowser_2->setVisible(false);
                }
                else{
                    ui->textBrowser_2->setVisible(true);
                    ui->textBrowser_2->setText("No existen mas correos con ese destinatario.");
                }
    }else{
        ui->textBrowser_2->setVisible(true);
        ui->textBrowser_2->setText("El destinatario debe ser menor de 30");
    }
}


void MainWindow::on_pushButton_12_clicked()//modificareliminarleerdir
{
    string Identificador=ui->lineEdit_47->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
    ui->pushButton_13->setVisible(false);
    if(Identificador.length()<=10){
        if(Identificador.length()>0){
            if(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(Identificador, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
                    ui->lineEdit_16->setText(Identificador.c_str());
                    ui->lineEdit_17->setText(Fecha.c_str());
                    ui->lineEdit_18->setText(Hora.c_str());
                    ui->lineEdit_19->setText(From.c_str());
                    ui->lineEdit_20->setText(To.c_str());
                    ui->lineEdit_21->setText(CC.c_str());
                    ui->lineEdit_22->setText(BCC.c_str());
                    ui->lineEdit_23->setText(subject.c_str());
                    ui->plainTextEdit_3->setPlainText(Content.c_str());
                    ui->textBrowser_5->setVisible(false);
                }
                else{
                    ui->textBrowser_5->setVisible(true);
                    ui->textBrowser_5->setText("No existe un correo con ese identificador.");
                }
            }else{
                ui->textBrowser_5->setVisible(true);
                ui->textBrowser_5->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_5->setVisible(true);
            ui->textBrowser_5->setText("El Identificador debe ser de mas de 0 caracteres.");
        }
    }else{
        ui->textBrowser_5->setVisible(true);
        ui->textBrowser_5->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
}

void MainWindow::on_pushButton_11_clicked()//modelimleersec
{
    string Identificador;
    string Fecha;
    string Hora;
    string From=ui->lineEdit_47->text().toStdString();
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
    ui->pushButton_13->setVisible(false);
    if(From.length()>0){
        if(From.length()<=30){
                    if(model.leerSecuencial(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content,-1)){
                        ui->lineEdit_16->setText(Identificador.c_str());
                        ui->lineEdit_17->setText(Fecha.c_str());
                        ui->lineEdit_18->setText(Hora.c_str());
                        ui->lineEdit_19->setText(From.c_str());
                        ui->lineEdit_20->setText(To.c_str());
                        ui->lineEdit_21->setText(CC.c_str());
                        ui->lineEdit_22->setText(BCC.c_str());
                        ui->lineEdit_23->setText(subject.c_str());
                        ui->plainTextEdit_3->setPlainText(Content.c_str());
                        ui->pushButton_13->setVisible(true);
                        ui->textBrowser_5->setVisible(false);
                    }else{
                        ui->textBrowser_5->setVisible(true);
                        ui->textBrowser_5->setText("No existe un correo con ese destinatario.");
                    }
        }else{
            ui->textBrowser_5->setVisible(true);
            ui->textBrowser_5->setText("El destinatario debe ser menor de 30 caracteres.");
        }
    }else{
        ui->textBrowser_5->setVisible(true);
        ui->textBrowser_5->setText("El destinatario debe tener almenos 1 caracter.");
    }
}

void MainWindow::on_pushButton_13_clicked()//moddelleersec(cont)
{
    double input;
    stringstream sso;
    string Identificador;
    string Fecha;
    string Hora;
    string From=ui->lineEdit_47->text().toStdString();
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    if(ui->lineEdit_19->text().toStdString()!=From){
        ui->pushButton_13->setVisible(false);
        return;
    }
    sso << ui->lineEdit_16->text().toStdString();
    sso >> input;
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
    ui->pushButton_13->setVisible(false);
    if(From.length()<=30){
        if(model.leerSecuencial(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content,input)){
            ui->lineEdit_16->setText(Identificador.c_str());
            ui->lineEdit_17->setText(Fecha.c_str());
            ui->lineEdit_18->setText(Hora.c_str());
            ui->lineEdit_19->setText(From.c_str());
            ui->lineEdit_20->setText(To.c_str());
            ui->lineEdit_21->setText(CC.c_str());
            ui->lineEdit_22->setText(BCC.c_str());
            ui->lineEdit_23->setText(subject.c_str());
            ui->plainTextEdit_3->setPlainText(Content.c_str());
            ui->pushButton_13->setVisible(true);
            ui->textBrowser_5->setVisible(false);
        }
        else{
            ui->textBrowser_5->setVisible(true);
            ui->textBrowser_5->setText("No existen mas correos con ese destinatario.");
        }
    }else{
        ui->textBrowser_5->setVisible(true);
        ui->textBrowser_5->setText("El destinatario debe ser menor de 30");
    }
}

void MainWindow::on_pushButton_14_clicked()//modificar
{

    QString Identificador= ui->lineEdit_16->text();
    QString Fecha=ui->lineEdit_17->text();
    QString Hora=ui->lineEdit_18->text();
    QString From= ui->lineEdit_19->text();
    QString To= ui->lineEdit_20->text();
    QString CC= ui->lineEdit_21->text();
    QString BCC= ui->lineEdit_22->text();
    QString subject= ui->lineEdit_23->text();
    QString Content= ui->plainTextEdit_3->toPlainText();
    Model_email model;

    if(Identificador.toStdString()==""){
        ui->lineEdit_16->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_19->clear();
        ui->lineEdit_20->clear();
        ui->lineEdit_21->clear();
        ui->lineEdit_22->clear();
        ui->lineEdit_23->clear();
        ui->plainTextEdit_3->clear();
        return;
    }
    int cod_error=model.modificar(Identificador.toStdString(),From.toStdString(),To.toStdString(),CC.toStdString(),BCC.toStdString(),subject.toStdString(),Content.toStdString());
    if(cod_error!=10){
        if(cod_error!=9){
            if(cod_error!=8){
                if(cod_error!=7){
                    if(cod_error!=6){
                        if(cod_error!=5){
                            if(cod_error!=4){
                                if(cod_error!=3){
                                    if(cod_error!=2){
                                        if(cod_error==1){
                                            ui->textBrowser_5->setVisible(true);
                                            ui->textBrowser_5->setText("No existe el documento de correos");
                                        }
                                        else{
                                            ui->textBrowser_5->setVisible(true);
                                            ui->textBrowser_5->setText("Correo Modificado Exitosamente");
                                            arbolavl.Desactualizado();
                                        }
                                    }
                                    else{
                                        ui->textBrowser_5->setVisible(true);
                                        ui->textBrowser_5->setText("El contenido debe ser de igual o menos de 100 caracteres.");
                                    }
                                }else{
                                    ui->textBrowser_5->setVisible(true);
                                    ui->textBrowser_5->setText("El asunto debe ser de igual o menos de 30 caracteres.");
                                }
                            }else{
                                ui->textBrowser_5->setVisible(true);
                                ui->textBrowser_5->setText("El BCC debe ser de igual o menos de 50 caracteres.");
                            }
                        }else{
                            ui->textBrowser_5->setVisible(true);
                            ui->textBrowser_5->setText("El CC debe ser de igual o menos de 50 caracteres.");
                        }
                    }else{
                        ui->textBrowser_5->setVisible(true);
                        ui->textBrowser_5->setText("El Destinatario debe ser igual o de menos de 30 caracteres.");
                    }
                }else{
                    ui->textBrowser_5->setVisible(true);
                    ui->textBrowser_5->setText("El Remitente debe ser de igual o menos de 30 caracteres.");
                }
            }else{
                ui->textBrowser_5->setVisible(true);
                ui->textBrowser_5->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_5->setVisible(true);
            ui->textBrowser_5->setText("El Identificador debe ser un entero positivo.");
        }
    }else{
        ui->textBrowser_5->setVisible(true);
        ui->textBrowser_5->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->textBrowser->setVisible(false);
    ui->textBrowser_2->setVisible(false);
    ui->textBrowser_5->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->plainTextEdit->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->plainTextEdit_2->clear();
    ui->pushButton_5->setVisible(false);
    ui->lineEdit_15->clear();
    ui->lineEdit_47->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
    ui->pushButton_13->setVisible(false);
}

void MainWindow::on_pushButton_15_clicked()//eliminar
{
    QString Identificador= ui->lineEdit_16->text();

    Model_email model;

    if(Identificador.toStdString()==""){
        ui->lineEdit_16->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_19->clear();
        ui->lineEdit_20->clear();
        ui->lineEdit_21->clear();
        ui->lineEdit_22->clear();
        ui->lineEdit_23->clear();
        ui->plainTextEdit_3->clear();
        return;
    }
   if(model.eliminar(Identificador.toStdString())){
            ui->textBrowser_5->setVisible(true);
            ui->textBrowser_5->setText("El correo fue eliminado correctamente.");
            arbolavl.remove(Identificador.toStdString());
            arbolavl.Desactualizado();
   }
   else{
        ui->textBrowser_5->setVisible(true);
        ui->textBrowser_5->setText("El correo no fue eliminado.");
   }
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
    ui->lineEdit_22->clear();
    ui->lineEdit_23->clear();
    ui->plainTextEdit_3->clear();
}

void MainWindow::on_actionExportar_triggered()
{
    Model_email a;
    a.exportar();
}

void MainWindow::on_actionImportar_triggered()
{
    Model_email a;
    bool* modificar=new bool(0);
    bool* final=new bool(1);
    int pos=-1;
    string nombre_recuperado;

    while(*final){
        pos= a.importar(modificar,final,pos,&nombre_recuperado);
        if(pos!=-1){
            string question;
            question+="Se encontro una coincidencia con el ID: "+nombre_recuperado;
            question+=",¿desea sobreescribirla?";
        QMessageBox::StandardButton reply=QMessageBox::question(this,
                              "Posible modificar",question.c_str(),
                              QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
            *modificar=1;
        else{
            pos++;
            *modificar=0;
        }
        }




    }

}

void MainWindow::on_pushButton_BusquedaID_CSV_clicked()
{
    string Identificador=ui->lineEdit_4_9->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    ui->lineEdit_4_1->clear();
    ui->lineEdit_4_2->clear();
    ui->lineEdit_4_3->clear();
    ui->lineEdit_4_4->clear();
    ui->lineEdit_4_5->clear();
    ui->lineEdit_4_6->clear();
    ui->lineEdit_4_7->clear();
    ui->lineEdit_4_8->clear();
    ui->plainTextEdit_4_1->clear();
    Model_email model;
    if(Identificador.length()<=10){
        if(Identificador.length()>0){
            if(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(Identificador, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(model.leerDirectoCSV(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
                    ui->lineEdit_4_1->setText(Identificador.c_str());
                    ui->lineEdit_4_2->setText(Fecha.c_str());
                    ui->lineEdit_4_3->setText(Hora.c_str());
                    ui->lineEdit_4_4->setText(From.c_str());
                    ui->lineEdit_4_5->setText(To.c_str());
                    ui->lineEdit_4_6->setText(CC.c_str());
                    ui->lineEdit_4_7->setText(BCC.c_str());
                    ui->lineEdit_4_8->setText(subject.c_str());
                    ui->plainTextEdit_4_1->setPlainText(Content.c_str());
                    ui->textBrowser_4_1->setVisible(false);
                }
                else{
                    ui->textBrowser_4_1->setVisible(true);
                    ui->textBrowser_4_1->setText("No existe un correo con ese identificador.");
                }
            }else{
                ui->textBrowser_4_1->setVisible(true);
                ui->textBrowser_4_1->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_4_1->setVisible(true);
            ui->textBrowser_4_1->setText("El Identificador debe ser de mas de 0 caracteres.");
        }
    }else{
        ui->textBrowser_4_1->setVisible(true);
        ui->textBrowser_4_1->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
}

void MainWindow::on_pushButton_Modificar_CSV_clicked()
{
    QString Identificador= ui->lineEdit_4_1->text();
    QString Fecha=ui->lineEdit_4_2->text();
    QString Hora=ui->lineEdit_4_3->text();
    QString From= ui->lineEdit_4_4->text();
    QString To= ui->lineEdit_4_5->text();
    QString CC= ui->lineEdit_4_6->text();
    QString BCC= ui->lineEdit_4_7->text();
    QString subject= ui->lineEdit_4_8->text();
    QString Content= ui->plainTextEdit_4_1->toPlainText();
    Model_email model;

    if(Identificador.toStdString()==""){
        ui->lineEdit_4_1->clear();
        ui->lineEdit_4_2->clear();
        ui->lineEdit_4_3->clear();
        ui->lineEdit_4_4->clear();
        ui->lineEdit_4_5->clear();
        ui->lineEdit_4_6->clear();
        ui->lineEdit_4_7->clear();
        ui->lineEdit_4_8->clear();
        ui->plainTextEdit_4_1->clear();
        return;
    }
    int cod_error=model.modificarCSV(Identificador.toStdString(),Fecha.toStdString(),Hora.toStdString(),From.toStdString(),To.toStdString(),CC.toStdString(),BCC.toStdString(),subject.toStdString(),Content.toStdString());
    if(cod_error!=10){
        if(cod_error!=9){
            if(cod_error!=8){
                if(cod_error!=7){
                    if(cod_error!=6){
                        if(cod_error!=5){
                            if(cod_error!=4){
                                if(cod_error!=3){
                                    if(cod_error!=2){
                                        if(cod_error==1){
                                            ui->textBrowser_4_1->setVisible(true);
                                            ui->textBrowser_4_1->setText("No existe el documento de correos");
                                        }
                                        else{
                                            ui->textBrowser_4_1->setVisible(true);
                                            ui->textBrowser_4_1->setText("Correo Modificado Exitosamente");
                                        }
                                    }
                                    else{
                                        ui->textBrowser_4_1->setVisible(true);
                                        ui->textBrowser_4_1->setText("El contenido debe ser de igual o menos de 100 caracteres.");
                                    }
                                }else{
                                    ui->textBrowser_4_1->setVisible(true);
                                    ui->textBrowser_4_1->setText("El asunto debe ser de igual o menos de 30 caracteres.");
                                }
                            }else{
                                ui->textBrowser_4_1->setVisible(true);
                                ui->textBrowser_4_1->setText("El BCC debe ser de igual o menos de 50 caracteres.");
                            }
                        }else{
                            ui->textBrowser_4_1->setVisible(true);
                            ui->textBrowser_4_1->setText("El CC debe ser de igual o menos de 50 caracteres.");
                        }
                    }else{
                        ui->textBrowser_4_1->setVisible(true);
                        ui->textBrowser_4_1->setText("El Destinatario debe ser igual o de menos de 30 caracteres.");
                    }
                }else{
                    ui->textBrowser_4_1->setVisible(true);
                    ui->textBrowser_4_1->setText("El Remitente debe ser de igual o menos de 30 caracteres.");
                }
            }else{
                ui->textBrowser_4_1->setVisible(true);
                ui->textBrowser_4_1->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_4_1->setVisible(true);
            ui->textBrowser_4_1->setText("El Identificador debe ser un entero positivo.");
        }
    }else{
        ui->textBrowser_4_1->setVisible(true);
        ui->textBrowser_4_1->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
    ui->lineEdit_4_1->clear();
    ui->lineEdit_4_2->clear();
    ui->lineEdit_4_3->clear();
    ui->lineEdit_4_4->clear();
    ui->lineEdit_4_5->clear();
    ui->lineEdit_4_6->clear();
    ui->lineEdit_4_7->clear();
    ui->lineEdit_4_8->clear();
    ui->plainTextEdit_4_1->clear();
}

void MainWindow::on_pushButton_Eliminar_CSV_clicked()
{
    QString Identificador= ui->lineEdit_4_1->text();
    Model_email aka;
    aka.eliminarCSV(Identificador.toStdString());
    ui->lineEdit_4_1->clear();
    ui->lineEdit_4_2->clear();
    ui->lineEdit_4_3->clear();
    ui->lineEdit_4_4->clear();
    ui->lineEdit_4_5->clear();
    ui->lineEdit_4_6->clear();
    ui->lineEdit_4_7->clear();
    ui->lineEdit_4_8->clear();
    ui->plainTextEdit_4_1->clear();
}

void MainWindow::on_actionExportar_2_triggered()
{
    Model_email aka;
    aka.exportar2();
}

void MainWindow::on_pushButton_BusquedaID_CdD_clicked(){
    string Identificador=ui->lineEdit_5_9->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    ui->lineEdit_5_1->clear();
    ui->lineEdit_5_2->clear();
    ui->lineEdit_5_3->clear();
    ui->lineEdit_5_4->clear();
    ui->lineEdit_5_5->clear();
    ui->lineEdit_5_6->clear();
    ui->lineEdit_5_7->clear();
    ui->lineEdit_5_8->clear();
    ui->plainTextEdit_5_1->clear();
    if(Identificador.length()<=10){
        if(Identificador.length()>0){
            if(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(ReplaceAll(Identificador, string("9"), string("")), string("8"), string("")), string("7"), string("")), string("6"), string("")), string("5"), string("")), string("4"), string("")), string("3"), string("")), string("2"), string("")), string("1"), string("")), string("0"), string("")).length()==0){
                if(model.leerDirectoCdD(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
                    ui->lineEdit_5_1->setText(Identificador.c_str());
                    ui->lineEdit_5_2->setText(Fecha.c_str());
                    ui->lineEdit_5_3->setText(Hora.c_str());
                    ui->lineEdit_5_4->setText(From.c_str());
                    ui->lineEdit_5_5->setText(To.c_str());
                    ui->lineEdit_5_6->setText(CC.c_str());
                    ui->lineEdit_5_7->setText(BCC.c_str());
                    ui->lineEdit_5_8->setText(subject.c_str());
                    ui->plainTextEdit_5_1->setPlainText(Content.c_str());
                    ui->textBrowser_5_1->setVisible(false);
                    ui->lineEdit_5_old->setText(Identificador.c_str());
                }
                else{
                    ui->textBrowser_5_1->setVisible(true);
                    ui->textBrowser_5_1->setText("No existe un correo con ese identificador.");
                }
            }else{
                ui->textBrowser_5_1->setVisible(true);
                ui->textBrowser_5_1->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_5_1->setVisible(true);
            ui->textBrowser_5_1->setText("El Identificador debe ser de mas de 0 caracteres.");
        }
    }else{
        ui->textBrowser_4_1->setVisible(true);
        ui->textBrowser_4_1->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
}

void MainWindow::on_pushButton_Modificar_CdD_clicked()
{
    QString Identificador= ui->lineEdit_5_old->text();
    QString Identificador_new= ui->lineEdit_5_1->text();
    QString Fecha=ui->lineEdit_5_2->text();
    QString Hora=ui->lineEdit_5_3->text();
    QString From= ui->lineEdit_5_4->text();
    QString To= ui->lineEdit_5_5->text();
    QString CC= ui->lineEdit_5_6->text();
    QString BCC= ui->lineEdit_5_7->text();
    QString subject= ui->lineEdit_5_8->text();
    QString Content= ui->plainTextEdit_5_1->toPlainText();
    Model_email model;

    if(Identificador.toStdString()==""){
        ui->lineEdit_5_1->clear();
        ui->lineEdit_5_2->clear();
        ui->lineEdit_5_3->clear();
        ui->lineEdit_5_4->clear();
        ui->lineEdit_5_5->clear();
        ui->lineEdit_5_6->clear();
        ui->lineEdit_5_7->clear();
        ui->lineEdit_5_8->clear();
        ui->plainTextEdit_5_1->clear();
        return;
    }
    int cod_error=model.modificarCdD(Identificador.toStdString(),Fecha.toStdString(),Hora.toStdString(),From.toStdString(),To.toStdString(),CC.toStdString(),BCC.toStdString(),subject.toStdString(),Content.toStdString(),Identificador_new.toStdString());
    if(cod_error!=11){
    if(cod_error!=10){
        if(cod_error!=9){
            if(cod_error!=8){
                if(cod_error!=7){
                    if(cod_error!=6){
                        if(cod_error!=5){
                            if(cod_error!=4){
                                if(cod_error!=3){
                                    if(cod_error!=2){
                                        if(cod_error==1){
                                            ui->textBrowser_5_1->setVisible(true);
                                            ui->textBrowser_5_1->setText("No existe el documento de correos");
                                        }
                                        else{
                                            ui->textBrowser_5_1->setVisible(true);
                                            ui->textBrowser_5_1->setText("Correo Modificado Exitosamente");
                                        }
                                    }
                                    else{
                                        ui->textBrowser_5_1->setVisible(true);
                                        ui->textBrowser_5_1->setText("El contenido debe ser de igual o menos de 100 caracteres.");
                                    }
                                }else{
                                    ui->textBrowser_5_1->setVisible(true);
                                    ui->textBrowser_5_1->setText("El asunto debe ser de igual o menos de 30 caracteres.");
                                }
                            }else{
                                ui->textBrowser_5_1->setVisible(true);
                                ui->textBrowser_5_1->setText("El BCC debe ser de igual o menos de 50 caracteres.");
                            }
                        }else{
                            ui->textBrowser_5_1->setVisible(true);
                            ui->textBrowser_5_1->setText("El CC debe ser de igual o menos de 50 caracteres.");
                        }
                    }else{
                        ui->textBrowser_5_1->setVisible(true);
                        ui->textBrowser_5_1->setText("El Destinatario debe ser igual o de menos de 30 caracteres.");
                    }
                }else{
                    ui->textBrowser_5_1->setVisible(true);
                    ui->textBrowser_5_1->setText("El Remitente debe ser de igual o menos de 30 caracteres.");
                }
            }else{
                ui->textBrowser_5_1->setVisible(true);
                ui->textBrowser_5_1->setText("El Identificador debe ser numerico.");
            }
        }else{
            ui->textBrowser_5_1->setVisible(true);
            ui->textBrowser_5_1->setText("El Identificador debe ser un entero positivo.");
        }
    }else{
        ui->textBrowser_5_1->setVisible(true);
        ui->textBrowser_5_1->setText("El Identificador debe ser de igual o menos de 10 caracteres.");
    }
    }
    else{
        ui->textBrowser_5_1->setVisible(true);
        ui->textBrowser_5_1->setText("Ya existe otro correo con ese identificador.");
    }
    ui->lineEdit_5_1->clear();
    ui->lineEdit_5_2->clear();
    ui->lineEdit_5_3->clear();
    ui->lineEdit_5_4->clear();
    ui->lineEdit_5_5->clear();
    ui->lineEdit_5_6->clear();
    ui->lineEdit_5_7->clear();
    ui->lineEdit_5_8->clear();
    ui->lineEdit_5_old->clear();
    ui->plainTextEdit_5_1->clear();
}

void MainWindow::on_pushButton_Eliminar_CdD_clicked()
{
    QString Identificador= ui->lineEdit_5_old->text();
    Model_email aka;
    aka.eliminarCdD(Identificador.toStdString());
    ui->lineEdit_5_1->clear();
    ui->lineEdit_5_2->clear();
    ui->lineEdit_5_3->clear();
    ui->lineEdit_5_4->clear();
    ui->lineEdit_5_5->clear();
    ui->lineEdit_5_6->clear();
    ui->lineEdit_5_7->clear();
    ui->lineEdit_5_8->clear();
    ui->lineEdit_5_old->clear();
    ui->plainTextEdit_5_1->clear();
}

void MainWindow::on_actionMemoria_triggered()
{
   busqueda_en_memoria ui2;
   ui2.setModal(true);
   ui2.exec();

}


void MainWindow::on_pushButton_Indice_clicked()
{
    ui->pushButton_Indice->setEnabled(false);
    Model_email a;
    int pos=0;
    string nombre_recuperado;
    string otronombre_recuperado;
    while(pos!=-1){
        pos= a.crearavl(pos,&nombre_recuperado,&otronombre_recuperado);
        if(pos==-1)
            break;
        else
            if(pos>=0){
                from.insert(nombre_recuperado,pos);
                to.insert(otronombre_recuperado,pos);
            }
        QMessageBox msgBox;
    }
    ui->pushButton_OR->setEnabled(true);
    ui->pushButton_AND->setEnabled(true);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_Indices->clear();
    ui->lineEdit_Indices_2->clear();
    ui->lineEdit_Indices_3->clear();
    ui->lineEdit_Indices_4->clear();
    ui->lineEdit_Indices_5->clear();
    ui->lineEdit_Indices_6->clear();
    ui->lineEdit_Indices_7->clear();
    ui->lineEdit_Indices_8->clear();
    ui->plainTextEdit_Indice->clear();
    string aux=ui->lineEdit_Indices_9->text().toStdString();

    int aux2=arbolavl.search(aux);
    if(aux2!=-1){
        ui->lineEdit_Indices_9->setText(QString::number(aux2));
    }
    else{
        ui->textBrowser_Indice->setVisible(true);
        ui->textBrowser_Indice->setText("No se encontro en el arbol avl.");
        return;
    }
    string Identificador=ui->lineEdit_Indices_9->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
        ui->lineEdit_Indices->setText(Identificador.c_str());
        ui->lineEdit_Indices_2->setText(Fecha.c_str());
        ui->lineEdit_Indices_3->setText(Hora.c_str());
        ui->lineEdit_Indices_4->setText(From.c_str());
        ui->lineEdit_Indices_5->setText(To.c_str());
        ui->lineEdit_Indices_6->setText(CC.c_str());
        ui->lineEdit_Indices_7->setText(BCC.c_str());
        ui->lineEdit_Indices_8->setText(subject.c_str());
        ui->plainTextEdit_Indice->setPlainText(Content.c_str());
        ui->textBrowser_Indice->setVisible(false);
    }
    else{
        ui->textBrowser_Indice->setVisible(true);
        ui->textBrowser_Indice->setText("No se encontro en el archivo.");
    }
}
unsigned int* ArreglosOR(unsigned int* a,unsigned int* b,int sizea,int sizeb,int*tamanio){
    int i=0,conta=0,contb=0;
    unsigned int ultimo;
    unsigned int* arreglo=new unsigned int[sizea+sizeb];

    while(sizea!=conta and sizeb!=contb){
        if(contb==sizeb){
            arreglo[i]=a[conta];
            conta++;
            i++;
        }
        else if(conta==sizea){
            arreglo[i]=b[contb];
            contb++;
            i++;
        }
        else if(a[conta]<b[contb]){
            arreglo[i]=a[conta];
            conta++;
            i++;
        }
        else if(a[conta]>b[contb]){
            arreglo[i]=b[contb];
            contb++;
            i++;
        }
        else if(a[conta]==b[contb]){
            arreglo[i]=a[conta];
            conta++;
            contb++;
            i++;
        }
    }

    *tamanio=i;
    return arreglo;
}

void MainWindow::on_pushButton_OR_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    string Remitente=ui->lineEdit_from->text().toStdString();
    string Destinatario=ui->lineEdit_to->text().toStdString();
    LinkedList<unsigned int>* f=from.search(Remitente);
    LinkedList<unsigned int>* t=to.search(Destinatario);
    QStringList titulos;
    if(!f and !t){
        ui->tableWidget->setColumnCount(1);
        titulos <<"Error";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,
                                         new QTableWidgetItem("No se encontro nada."));
        return;
    }
    unsigned int* arreglo;
    int nuevo_tamanio=0;
    if(!f and t){
        arreglo=t->toArray();
        nuevo_tamanio=t->size();
    }
    else if(!t and f){
        arreglo=f->toArray();
        nuevo_tamanio=f->size();
    }
    else{
        unsigned int* cont_f=f->toArray();
        unsigned int* cont_t=t->toArray();
        arreglo=ArreglosOR(&(*cont_f),&(*cont_t),f->size(),t->size(),&nuevo_tamanio);
        delete cont_f;
        delete cont_t;
    }
    ui->tableWidget->setColumnCount(9);
    titulos <<"Identificador"<<"Fecha"<<"Hora"<<"Remitente"<<"Destinatario"<<"Copia Carbon(CC)"<<"Copia Carbon Ciega(BCC)"<<"Asunto"<<"Contenido";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    for(int i=0;i<nuevo_tamanio;i++){
        stringstream ss;
        ss<<arreglo[i];
        string Identificador=ss.str();
        string Fecha;
        string Hora;
        string From;
        string To;
        string CC;
        string BCC;
        string subject;
        string Content;
        Model_email model;
        if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,
                                             new QTableWidgetItem(Identificador.c_str()/*QString::number(f->size())*/));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,
                                             new QTableWidgetItem(Fecha.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,
                                             new QTableWidgetItem(Hora.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,
                                             new QTableWidgetItem(From.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,
                                             new QTableWidgetItem(To.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,
                                             new QTableWidgetItem(CC.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,
                                             new QTableWidgetItem(BCC.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,
                                             new QTableWidgetItem(subject.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,
                                             new QTableWidgetItem(Content.c_str()));
        }
    }
    delete arreglo;


}

unsigned int* ArreglosAND(unsigned int* a,unsigned int* b,int sizea,int sizeb,int*tamanio){
    int i=0,conta=0,contb=0;
    unsigned int ultimo;
    unsigned int* arreglo=new unsigned int[sizea+sizeb];

    while(sizea!=conta and sizeb!=contb){
        if(contb==sizeb){
            conta++;
            i++;
        }
        else if(conta==sizea){
            contb++;
            i++;
        }
        else if(a[conta]<b[contb]){
            conta++;
            i++;
        }
        else if(a[conta]>b[contb]){
            contb++;
            i++;
        }
        else if(a[conta]==b[contb]){
            arreglo[i]=a[conta];
            conta++;
            contb++;
            i++;
        }
    }

    *tamanio=i;
    return arreglo;
}
void MainWindow::on_pushButton_AND_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    string Remitente=ui->lineEdit_from->text().toStdString();
    string Destinatario=ui->lineEdit_to->text().toStdString();
    LinkedList<unsigned int>* f=from.search(Remitente);
    LinkedList<unsigned int>* t=to.search(Destinatario);
    QStringList titulos;
    if(!f or !t){
        ui->tableWidget->setColumnCount(1);
        titulos <<"Error";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,
                                         new QTableWidgetItem("No se encontro nada."));
        return;
    }
    unsigned int* arreglo;
    int nuevo_tamanio=0;
        unsigned int* cont_f=f->toArray();
        unsigned int* cont_t=t->toArray();
        arreglo=ArreglosAND(&(*cont_f),&(*cont_t),f->size(),t->size(),&nuevo_tamanio);
        delete cont_f;
        delete cont_t;
    ui->tableWidget->setColumnCount(9);
    titulos <<"Identificador"<<"Fecha"<<"Hora"<<"Remitente"<<"Destinatario"<<"Copia Carbon(CC)"<<"Copia Carbon Ciega(BCC)"<<"Asunto"<<"Contenido";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    for(int i=0;i<nuevo_tamanio;i++){
        stringstream ss;
        ss<<arreglo[i];
        string Identificador=ss.str();
        string Fecha;
        string Hora;
        string From;
        string To;
        string CC;
        string BCC;
        string subject;
        string Content;
        Model_email model;
        if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,
                                             new QTableWidgetItem(Identificador.c_str()/*QString::number(f->size())*/));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,
                                             new QTableWidgetItem(Fecha.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,
                                             new QTableWidgetItem(Hora.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,
                                             new QTableWidgetItem(From.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,
                                             new QTableWidgetItem(To.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,
                                             new QTableWidgetItem(CC.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,
                                             new QTableWidgetItem(BCC.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,
                                             new QTableWidgetItem(subject.c_str()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,
                                             new QTableWidgetItem(Content.c_str()));
        }
    }
    delete arreglo;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_Page_9->setEnabled(true);
        ui->pushButton_Page->setEnabled(true);
        paginas=page.crear_paginado();

    }
    else{
        ui->lineEdit_Page_9->setEnabled(false);
        ui->pushButton_Page->setEnabled(false);

    }
}

void MainWindow::on_pushButton_Page_clicked()
{
    ui->lineEdit_Page->clear();
    ui->lineEdit_Page_2->clear();
    ui->lineEdit_Page_3->clear();
    ui->lineEdit_Page_4->clear();
    ui->lineEdit_Page_5->clear();
    ui->lineEdit_Page_6->clear();
    ui->lineEdit_Page_7->clear();
    ui->lineEdit_Page_8->clear();
    ui->plainTextEdit_Page->clear();
    ui->textBrowser_Page->setVisible(false);
    string Buscado=ui->lineEdit_Page_9->text().toStdString();
    int aux2=page.search(Buscado);
    if(aux2!=-1){
        ui->lineEdit_Page_9->setText(QString::number(aux2));
    }
    else{
        ui->textBrowser_Page->setVisible(true);
        string Identificador=ui->lineEdit_Page_9->text().toStdString();
        string Fecha;
        string Hora;
        string From;
        string To;
        string CC;
        string BCC;
        string subject;
        string Content;
        Model_email model;
        if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
            page.insertpage(Identificador,ui->lineEdit_Page_9->text().toUInt());
            ui->textBrowser_Page->setText("No se encontro en el arbol, por lo tanto se busco y encontro en el archivo.");
            ui->lineEdit_Page->setText(Identificador.c_str());
            ui->lineEdit_Page_2->setText(Fecha.c_str());
            ui->lineEdit_Page_3->setText(Hora.c_str());
            ui->lineEdit_Page_4->setText(From.c_str());
            ui->lineEdit_Page_5->setText(To.c_str());
            ui->lineEdit_Page_6->setText(CC.c_str());
            ui->lineEdit_Page_7->setText(BCC.c_str());
            ui->lineEdit_Page_8->setText(subject.c_str());
            ui->plainTextEdit_Page->setPlainText(Content.c_str());
            ui->textBrowser_Page->setVisible(false);
            paginas++;
            if(paginas>=10){
                ui->textBrowser_Page->setVisible(true);
                ui->textBrowser_Page->setText(page.BuscarMenosUsado().c_str());
            }

        }
        else{
            ui->textBrowser_Page->setText("No se encontro en el arbol ni en el archivo.");
        }
        return;
    }
    string Identificador=ui->lineEdit_Page_9->text().toStdString();
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
    Model_email model;
    if(model.leerDirecto(&Identificador,&Fecha,&Hora,&From,&To,&CC,&BCC,&subject,&Content)){
        ui->lineEdit_Page->setText(Identificador.c_str());
        ui->lineEdit_Page_2->setText(Fecha.c_str());
        ui->lineEdit_Page_3->setText(Hora.c_str());
        ui->lineEdit_Page_4->setText(From.c_str());
        ui->lineEdit_Page_5->setText(To.c_str());
        ui->lineEdit_Page_6->setText(CC.c_str());
        ui->lineEdit_Page_7->setText(BCC.c_str());
        ui->lineEdit_Page_8->setText(subject.c_str());
        ui->plainTextEdit_Page->setPlainText(Content.c_str());
        ui->textBrowser_Page->setVisible(false);
    }
    else{
        ui->textBrowser_Page->setVisible(true);
        ui->textBrowser_Page->setText("No se encontro en el archivo.");
    }
}

void MainWindow::on_action8_4_B_squeda_R_pida_con_Dispersi_n_triggered()
{
    Hashing_Window ui2;
    ui2.setModal(true);
    ui2.exec();
}

void MainWindow::on_actionCifrar_triggered()
{
    Cifrar_Window ui2;
    ui2.setModal(true);
    ui2.exec();
}

void MainWindow::on_actionDescifrar_triggered()
{

}

void MainWindow::on_actionComprimir_triggered()
{
    Model_email k;
    k.ComprimirDescomprimir(1);

}

void MainWindow::on_actionDescomprimir_triggered()
{
    Model_email k;
    k.ComprimirDescomprimir(0);

}
