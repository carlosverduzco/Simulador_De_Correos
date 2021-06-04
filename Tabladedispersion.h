#ifndef TABLADEDISPERSION_H
#define TABLADEDISPERSION_H

#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
class TablaDeDispersion
{
private:
    class node{
        public:
            char key[10];
            unsigned int reference;
            node* sig;
            node(char* key){
                strcpy(this->key,key);
                reference=stoi(key);
                sig=nullptr;
            }
            node(char* key,unsigned int reference){
                strcpy(this->key,key);
                cout<<this->key <<endl;
                this->reference=reference;
                sig=nullptr;
            }

    };
    node* HashingTable[211];
public:
    TablaDeDispersion();
    void Serialize();
    unsigned int *Search(char* key);
    int pjwHashing(char *clave);
};

#endif // TABLADEDISPERSION_H
