#ifndef LISTAMEMORIA_H
#define LISTAMEMORIA_H

#include <model_email.h>
class ListaMemoria
{
public:
    ListaMemoria();
    int *cont;
    email* lista;
    void ordenarshell();
    void shellSort();
};

#endif // LISTAMEMORIA_H
