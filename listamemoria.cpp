#include "listamemoria.h"

ListaMemoria::ListaMemoria()
{
    cont = new int();
    *cont=0;
    lista=nullptr;
}

void ListaMemoria::ordenarshell()
{

}

void ListaMemoria::shellSort()
{
    for (int gap = (*cont)/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < *cont; i += 1)
        {
            email temp = lista[i];
            int j;
            for (j = i; j >= gap && lista[j - gap].From[0] > temp.From[0]; j -= gap){
                lista[j] = lista[j - gap];
            }
            lista[j] = temp;
            if(lista[j].From[0]==lista[j-1].From[0]){
                for(int k=1;lista[j].From[k]!='\0';k++){
                    if(lista[j].From[k]<lista[j-1].From[k]){
                        temp=lista[j];
                        lista[j]=lista[j-1];
                        lista[j-1]=temp;
                        break;
                    }
                    else if(lista[j].From[k]>lista[j-1].From[k])
                        break;
                }
            }
            if(lista[j].From[0]==lista[j+1].From[0]){
                for(int k=1;lista[j].From[k]!='\0';k++){
                    if(lista[j].From[k]>lista[j+1].From[k]){
                        temp=lista[j];
                        lista[j]=lista[j+1];
                        lista[j+1]=temp;
                        break;
                    }
                    else if(lista[j].From[k]<lista[j+1].From[k])
                        break;
                }
            }
        }
    }
}
