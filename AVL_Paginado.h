#ifndef AVL_PAGINADO_H
#define AVL_PAGINADO_H
#include <model_email.h>
#include <iostream>
using namespace std;
template <typename T>
class AVL_PAGE{
    public:
        class node{
            public:
                T key;
                int height;
                unsigned int ref;
                unsigned int timestamp;
                node * left;
                node * right;
                node(T k,unsigned int referencia,unsigned int timestamp){
                    height = 1;
                    key = k;
                    ref=referencia;
                    this->timestamp=timestamp;
                    left = NULL;
                    right = NULL;
                }
        };
        AVL_PAGE(){
        }
        node * root;
        int n;
        int crear_paginado(){
            root=NULL;
            n=0;
            ifstream fin("Indices.bin",ios::binary);
            char bandera[sizeof(unsigned int)+(sizeof(char)*10)];
            fin.read(bandera,sizeof(unsigned int)+(sizeof(char)*10));
            char llave_recibido[10];
            unsigned int ref_recibido;
            fin.read(llave_recibido,(sizeof(char)*10));
            fin.read((char*)&ref_recibido,sizeof(unsigned int));
            while(!fin.eof()){
                if(n==10)
                    break;
                string aux=llave_recibido;
                insertpage(aux,ref_recibido);
                fin.read(llave_recibido,(sizeof(char)*10));
                fin.read((char*)&ref_recibido,sizeof(unsigned int));
            }
            return n;
        }
        void insertpage(T x,unsigned int ref){
            root=insertUtilpage(root, x,ref);
        }
        void remove(T x){
            root=removeUtil(root, x);
        }
        int search(T x){
            node* obj=searchUtil(root,x);
            if(!obj)
                return-1;
            obj->timestamp=n;
            n++;
            return obj->ref;
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
        }
        string BuscarMenosUsado(){
            node* eliminar=root;
            BuscarMenosUsadoUtil(root,eliminar);
            string eliminado=eliminar->key;
            remove(eliminado);
            return eliminado;
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

        node * insertUtilpage(node * head, T x,unsigned int ref){
            if(head==NULL){
                node * temp = new node(x,ref,n);
                n++;
                return temp;
            }
            if(x < head->key) head->left = insertUtilpage(head->left, x ,ref);
            else if(x > head->key) head->right = insertUtilpage(head->right, x,ref);
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
        void BuscarMenosUsadoUtil(node* head,node * &eli){
            if(head==NULL) return ;
            BuscarMenosUsadoUtil(head->left,eli);
            if(head->timestamp<eli->timestamp)
                eli=head;
            BuscarMenosUsadoUtil(head->right,eli);
        }
};
#endif // AVL_PAGINADO_H
