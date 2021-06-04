#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <busqueda_en_memoria.h>
#include <AVL.h>
#include <AVL2.h>
#include <AVL_Paginado.h>
#include <hashing_window.h>
#include <cifrar_window.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_15_clicked();

    void on_actionExportar_triggered();

    void on_actionImportar_triggered();

    void on_pushButton_BusquedaID_CSV_clicked();

    void on_pushButton_Modificar_CSV_clicked();

    void on_pushButton_Eliminar_CSV_clicked();

    void on_actionExportar_2_triggered();

    void on_pushButton_BusquedaID_CdD_clicked();

    void on_pushButton_Modificar_CdD_clicked();

    void on_pushButton_Eliminar_CdD_clicked();

    void on_actionMemoria_triggered();

    void on_pushButton_Indice_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_OR_clicked();

    void on_pushButton_AND_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_Page_clicked();

    void on_action8_4_B_squeda_R_pida_con_Dispersi_n_triggered();

    void on_actionCifrar_triggered();

    void on_actionDescifrar_triggered();

    void on_actionComprimir_triggered();

    void on_actionDescomprimir_triggered();

private:
    Ui::MainWindow *ui;
    AVL<string> arbolavl;
    AVL2<string> to;
    AVL2<string> from;
    AVL_PAGE<string> page;
    unsigned int paginas;



};
#endif // MAINWINDOW_H
