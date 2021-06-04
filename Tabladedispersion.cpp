#include "Tabladedispersion.h"

#define PRIMO 211
TablaDeDispersion::TablaDeDispersion()
{
//    for(int i=0;i<=PRIMO;i++)
//        HashingTable[i]=nullptr;
//    ifstream fin("Indices.bin",ios::binary);
//    char bandera[sizeof(unsigned int)+(sizeof(char)*10)];
//    fin.read(bandera,sizeof(unsigned int)+(sizeof(char)*10));
//    char llave_recibido[10];
//    unsigned int ref_recibido;
//    fin.read(llave_recibido,(sizeof(char)*10));
//    fin.read((char*)&ref_recibido,sizeof(unsigned int));
//    while(!fin.eof()){
//        int posicion=pjwHashing(llave_recibido);
//        cout <<posicion <<endl;
//        node* nuevo=new node(llave_recibido,ref_recibido);
//        HashingTable[posicion]=nuevo;
//        fin.read(llave_recibido,(sizeof(char)*10));
//        fin.read((char*)&ref_recibido,sizeof(unsigned int));
//    }
    ifstream fread ("Serialize.txt");
    if(fread.is_open()){
        for(int i=0;i<=PRIMO;i++){
            string aux;
            getline(fread,aux);
            if(aux=="N"){
                HashingTable[i]=nullptr;
            }
            else{
                int campos=0;
                 for(int j=0;j<aux.size();j++){
                     if(aux[j]==','){
                         campos++;
                     }
                 }
                 if(campos==0){
                    char array[10];
                    strcpy(array,aux.c_str());
                    node* nuevo=new node(array,stoi(array));
                    HashingTable[i]=nuevo;
                 }
                 else{
                     int campo_actual=0;
                     string vector[campos+1];
                     for(int k=0;k<aux.size();k++){
                         if(aux[k]==',')
                             campo_actual++;
                         else
                             vector[campo_actual]+=aux[k];
                     }
                     char array[10];
                     strcpy(array,vector[0].c_str());
                     node* nuevo=new node(array,stoi(array));
                     HashingTable[i]=nuevo;
                     node* aux=HashingTable[i];
                     for(int k=1;k<campos;k++){
                         char array2[10];
                         strcpy(array2,vector[k].c_str());
                         node* nuevo=new node(array2,stoi(array2));
                         aux->sig= nuevo;
                         aux=aux->sig;
                     }
                 }
                }
            }
    }
    else{
        for(int i=0;i<=PRIMO;i++)
            HashingTable[i]=nullptr;
        ifstream fin("Indices.bin",ios::binary);
        char bandera[sizeof(unsigned int)+(sizeof(char)*10)];
        fin.read(bandera,sizeof(unsigned int)+(sizeof(char)*10));
        char llave_recibido[10];
        unsigned int ref_recibido;
        fin.read(llave_recibido,(sizeof(char)*10));
        fin.read((char*)&ref_recibido,sizeof(unsigned int));
        while(!fin.eof()){
            int posicion=pjwHashing(llave_recibido);
            cout <<posicion <<endl;
            node* nuevo=new node(llave_recibido,ref_recibido);
            if(!HashingTable[posicion])
                HashingTable[posicion]=nuevo;
            else{
                node* aux=HashingTable[posicion];
                while(aux->sig){
                    aux=aux->sig;
                }
                aux->sig=nuevo;
            }
            fin.read(llave_recibido,(sizeof(char)*10));
            fin.read((char*)&ref_recibido,sizeof(unsigned int));
        }
    }
}

void TablaDeDispersion::Serialize()
{
    ofstream fout("Serialize.txt");
    for(int i=0;i<=PRIMO;i++){
        if(HashingTable[i]){
            fout << HashingTable[i]->key;
            node* aux=HashingTable[i]->sig;
            while(aux){
                fout<<","<<aux->key;
                aux=aux->sig;
            }
            fout << endl;
        }
        else{
            fout << 'N' <<endl;
        }
    }
}

unsigned int *TablaDeDispersion::Search(char *key)
{
    node* aux=HashingTable[pjwHashing(key)];
    unsigned int* pointer=nullptr;
    while(aux){
        if(stoi(aux->key)==stoi(key)){
            pointer=new unsigned int(stoi(key));
            return pointer;
        }
        aux=aux->sig;
    }
    return pointer;
}

int TablaDeDispersion::pjwHashing(char *clave)
{
    char *p;
    unsigned int h = 0, g;
    for(p = clave ; *p != '\0' ; p++){
        h = (h << 4) + (*p);
        g = h&0xF0000000;
        if(g > 1){
            h = h ^ (g << 24);
            h = h ^ g;
        }
    }
    return(h%PRIMO);
}
