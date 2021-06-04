#ifndef AVL2_H
#define AVL2_H
#include <model_email.h>
#include <ListaSimplementeLigada.h>
using namespace std;

template <typename T>
class AVL2{
    public:
        class node{
            public:
                T key;
                int height;
                LinkedList<unsigned int> ref;
                node * left;
                node * right;
                node(T k,unsigned int referencia){
                    height = 1;
                    ref.add(referencia);
                    key = k;
                    left = NULL;
                    right = NULL;
                }
        };
        AVL2(){
            root=NULL;
        }
        node * root;
        int n;
        void insert(T x,unsigned int ref){
            root=insertUtil(root, x,ref);
        }
        LinkedList<unsigned int>* search(T x){
            node* obj=searchUtil(root,x);
            if(!obj)
                return nullptr;
//            LinkedList<unsigned int>* lista=new LinkedList<unsigned int>();
//            lista=&(obj->ref);
//            return lista;
            return &(obj->ref);
        }
        void remove(T x){
            root=removeUtil(root, x);
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
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

        node * insertUtil(node * head, T x,unsigned int refe){
            if(head==NULL){
                n+=1;
                node * temp = new node(x,refe);
                return temp;
            }
            if(x == head->key)
                head->ref.add(refe);
            if(x < head->key){
                head->left = insertUtil(head->left, x ,refe);
            }
            else if(x > head->key){
                head->right = insertUtil(head->right, x,refe);
            }

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

};
#endif // AVL2_H
