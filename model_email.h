#ifndef MODEL_EMAIL_H
#define MODEL_EMAIL_H

#include <controlador_bin.h>

class Model_email
{
public:
    Model_email();
    int agregar(string Id,string R,string D,string CC,string BCC,string S,string C);
    bool leerDirecto(string* Id,string* F,string* H,string* R,string* D,string* CC,string* BCC,string* S,string* C);
    bool leerSecuencial(string* Id,string* F,string* H,string* R,string* D,string* CC,string* BCC,string* S,string* C,double input);
    int modificar(string Id,string R,string D,string CC,string BCC,string S,string C);
    bool eliminar(string Id);
    void exportar();
    int importar(bool * modificar,bool * final,int pos,string* recuperado);
    bool leerDirectoCSV(string* Id,string* F,string* H,string* R,string* D,string* CC,string* BCC,string* S,string* C);
    int  modificarCSV(string Id,string F,string H,string R,string D,string CC,string BCC,string S,string C);
    bool eliminarCSV(string Id);
    void exportar2();
    bool leerDirectoCdD(string* Id,string* F,string* H,string* R,string* D,string* CC,string* BCC,string* S,string* C);
    int  modificarCdD(string Id,string F,string H,string R,string D,string CC,string BCC,string S,string C,string old);
    bool eliminarCdD(string Id);

    email * BusquedaEnMemoria(int * cont);

    int crearavl(int pos,string* recuperado,string* otronombre_recuperado);

    int CifrarDescifrar(bool opcion,string contrasena);

    int ComprimirDescomprimir(bool opcion);
};

#endif // MODEL_EMAIL_H
