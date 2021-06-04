#ifndef BUSQUEDA_EN_MEMORIA_H
#define BUSQUEDA_EN_MEMORIA_H

#include <QDialog>
#include <model_email.h>
#include <listamemoria.h>

namespace Ui {
class busqueda_en_memoria;
}

class busqueda_en_memoria : public QDialog
{
    Q_OBJECT

public:
    explicit busqueda_en_memoria(QWidget *parent = nullptr);
    ~busqueda_en_memoria();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::busqueda_en_memoria *ui;
    void binaria(email* arr,int p,int r,string num);
    ListaMemoria z;
};

#endif // BUSQUEDA_EN_MEMORIA_H
