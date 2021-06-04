#ifndef CONTROLADOR_BIN_H
#define CONTROLADOR_BIN_H

#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

struct email
{
    char Identificador[12];
    char Fecha[12];
    char Hora[10];
    char From[32];
    char To[32];
    char CC[52];
    char BCC[52];
    char subject[32];
    char Content[102];
};
class Controlador_bin
{
private:
    string* toCSV(email res);
    string* kaiser(unsigned long* ite,ifstream &fin);
    char *toSerialize(email recibido,int* tamanio,char* &s);
    bool validaN(string entrada);
public:
    Controlador_bin();
    bool agregar(email e);
    email busquedaID(string Id);
    email busquedaFrom(string From,double secuencia);
    bool modificar(email e);
    void exportarCSV();
    unsigned long importarCSV(bool *modificarp, bool *final,int pos,string* recuperado);
    email busquedaIDCSV(string Id);
    bool modificarCSV(email e);
    void exportarCdD();
    email busquedaIDCdD(string Id);
    bool modificarCdD(email e,string old);

    email *BusquedaEnMemoriaArchivo(int* cont);

    unsigned long crearavl(int pos,string *recuperado,string* otronombre_recuperado);

    int Caesar_cipher(string contrasena);
    int Caesar_decipher(string contrasena);

    int RLE_compression();
    int RLE_decompression();
};

#endif // CONTROLADOR_BIN_H
