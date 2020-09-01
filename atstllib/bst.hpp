#pragma once
#include "node.hpp"
#include<cmath>
#include<functional>
namespace atstl{
    template<typename T>
    class bst{
        int numberOfnodes;
        public:
            atstl::treenode<int> root; //root of the tree
           bst(int data):root(data),numberOfnodes(){} //initializing with a root value
           bst():root(){} //initializing an empty binary search tree
        
        /*Declaring member functions*/
        void insert(int data); //Inserts a new node at leaf with the specified data
        treenode<T>* search(int key); //Searches and returns a treenode with given key.If not found,returns NULL.
        void inorder(atstl::treenode<int> *root,const std::function<void(atstl::treenode<T>*)> cb) ;//inorder traversal.
        int getHeight();

    };

/***********Defining member functions***************/

//Insert
template<typename T>
void bst<T>::insert(int d){
    treenode<int>* toinsert= new treenode<int>(d);
    treenode<int>* y=NULL;
    treenode<int>* x=&this->root;
    while(x!=NULL){
        y=x;
        if(d<x->data) x=x->left;
        else x=x->right; 
    }
    if(y==NULL)  this->root.data=d; //Insertion is occuring in an empty tree.
    else if(d<=(y->data)) y->left=toinsert;
    else y->right=toinsert;
    numberOfnodes++;
    // delete x;
    }

//Search
template<typename T>
treenode<T>* bst<T>::search(int key){
         treenode<int>* x=new treenode<int>();
         x=&this->root;
         while(x!=NULL){
             if(x->data==key)  return x;
             if(x->data>key) x=x->left;
             else x=x->right;
         }
         return NULL;
    }

//inorder
template<typename T>
void bst<T>::inorder(atstl::treenode<int> *root,const std::function<void(atstl::treenode<T>*)> cb){
    if(root==NULL)  return;
    inorder(root->left,cb);
    cb(root);
    inorder(root->right,cb);
    
    }
 
 //to get height of the tree;
template<typename T>
int bst<T>::getHeight(){
        return ceil(log2(numberOfnodes));
        }

}