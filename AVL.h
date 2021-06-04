#ifndef AVL_H
#define AVL_H
#include <model_email.h>
#include <iostream>
using namespace std;
template <typename T>
class AVL{
    public:
        class node{
            public:
                T key;
                int height;
                unsigned int ref;
                node * left;
                node * right;
                node(T k,unsigned int referencia){
                    height = 1;
                    key = k;
                    ref=referencia;
                    left = NULL;
                    right = NULL;
                }
        };
        AVL(){
            root=NULL;
            ifstream fin("Indices.bin",ios::binary);
            char bandera[sizeof(unsigned int)+(sizeof(char)*10)];
            fin.read(bandera,sizeof(unsigned int)+(sizeof(char)*10));
                if(bandera[0]!='1'){
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
                                stringstream ss;
                                ss << pos;
                                insert(ss.str(),pos);
                            }
                        QMessageBox msgBox;
                    }
                    GuardarIndice();
                }
                else{
                    char llave_recibido[10];
                    unsigned int ref_recibido;
                    fin.read(llave_recibido,(sizeof(char)*10));
                    fin.read((char*)&ref_recibido,sizeof(unsigned int));
                    while(!fin.eof()){
                        string aux=llave_recibido;
                        insert(aux,ref_recibido);
                        fin.read(llave_recibido,(sizeof(char)*10));
                        fin.read((char*)&ref_recibido,sizeof(unsigned int));
                    }
                }
        }
        node * root;
        int n;
        void insert(T x,unsigned int ref){
            root=insertUtil(root, x,ref);
        }
        void remove(T x){
            root=removeUtil(root, x);
        }
        int search(T x){
            node* obj=searchUtil(root,x);
            if(!obj)
                return-1;
            return obj->ref;
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
        }
        void GuardarIndice(){
            ofstream fout("Indices.bin",ios::binary);
            char bandera[sizeof(unsigned int)+(sizeof(char)*10)]={'1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
            fout.write(bandera,sizeof(unsigned int)+(sizeof(char)*10));
            GuardarInorder(root,fout);
        }
        void Desactualizado(){
            ofstream fout("Indices.bin",ios::binary|ios::in);
            char bandera[sizeof(unsigned int)+(sizeof(char)*10)]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
            fout.write(bandera,sizeof(unsigned int)+(sizeof(char)*10));
        }
    private:
        int height(node * head){
            if(head==NULL) return 0;
            return head->height;
        }
        node * rightRotation(node * head){
            node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        node * leftRotation(node * head){
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        void inorderUtil(node * head){
            if(head==NULL) return ;
            inorderUtil(head->left);
            cout<<head->key<<endl;
            cout<<head->ref<<" "<<endl;
            inorderUtil(head->right);
        }

        node * insertUtil(node * head, T x,unsigned int ref){
            if(head==NULL){
                n+=1;
                node * temp = new node(x,ref);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x ,ref);
            else if(x > head->key) head->right = insertUtil(head->right, x,ref);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x < head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                if(x > head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node * removeUtil(node * head, T x){
            if(head==NULL) return NULL;
            if(x < head->key){
                head->left = removeUtil(head->left, x);
            }else if(x > head->key){
                head->right = removeUtil(head->right, x);
            }else{
                node * r = head->right;
                if(head->right==NULL){
                    node * l = head->left;
                    delete(head);
                    head = l;
                }else if(head->left==NULL){
                    delete(head);
                    head = r;
                }else{
                    while(r->left!=NULL) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x > head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal < -1){
                if(x < head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        node * searchUtil(node * head, T x){
            if(head == NULL) return nullptr;
            T k = head->key;
            if(k == x) return head;
            if(k > x) return searchUtil(head->left, x);
            if(k < x) return searchUtil(head->right, x);
        }
        void GuardarInorder(node* head,ofstream &fout){
            if(head==NULL) return ;
            GuardarInorder(head->left,fout);
            char * obj=new char[10];
            string aux=head->key;
            strcpy(obj,aux.c_str());
            fout.write(obj,sizeof(char)*10);
            fout.write((char*)&head->ref,sizeof(unsigned int));
            GuardarInorder(head->right,fout);
        }
};

#endif // AVL_H
