#pragma once
#include "node.hpp"
#include "utils.hpp"
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
        int getHeight(); //Gives the height of the tree
        treenode<T>* min(treenode<T>* root); //Finds the minimum element of tree routed at root.
        treenode<T>* max(treenode<T>* root); //Finds the maximum element of tree routed at root.
        treenode<T>* deletenode(treenode<T>* root,int key) ;//If a key is present,then deletes it.Returns the pointer to the new root node.
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
         treenode<int>* x;
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

//min
template<typename T>
treenode<T>* bst<T>::min(treenode<T>* root){
        while(root->left!=NULL){
            root=root->left;
        }
      return root;

    }
//max

template<typename T>
treenode<T>* bst<T>::max(treenode<T>* root){
        while(root->right!=NULL){
            root=root->right;
        }
      return root;

    }

//delete the node and returns new root
template<typename T>
treenode<T>* bst<T>::deletenode(treenode<T>* root,int key)  {
        if(root==NULL) {
            std::cout<<"No element found or NULL root\n";
            return root;
        }
        if(root->data>key) root->left= deletenode(root->left,key);
        else if(root->data<key) root->right=deletenode(root->right,key);
        else{// we found the node to be deleted
            //If thats a leaf node
            if(root->right==NULL && root->left==NULL){
                treenode<int>* toDelete=root;
                delete toDelete;
                root=NULL;
            }

            //If it has only one child
            else if(root->left==NULL){
                treenode<int>* toDelete=root;
                root=root->right;
                delete toDelete;
            }
            else if(root->right==NULL){
                treenode<int>* toDelete=root;
                root=root->left;
                delete toDelete;
            }


            //if it has two childs,then we will have to modify the situation to land this in first case or second.
            /*We can replace any root node with the largest from left or smallest from right subtree. And then we can delete that leaf node,as in case 1*/
            else{
                treenode<int>* toDelete=min(root->right);
                root->data=toDelete->data;
                root->right=deletenode(root->right,toDelete->data);
            }
        }
    return root; //Return modified root
    }




//OBST
template<typename T>
class obst:public bst{
            int** expectation;
            int** w;
            int** roots;
            int* prob;
            int numberOfnodes;
            public:
            int optExpectation;
            atstl::treenode<int> root; 
           //Constructor for an Optimal BST which also takes in the probability pi of key ki.So there are two arrays.
           obst(int* arr,int* p,int n):numberOfnodes(n){
               obstProb=new int[n];
               for(int i=0;i<n;i++){
                   prob[i]=p[i];
               }

               makeObst();

               optExpectation=expectation[1][numberOfnodes+1];
              root.data=roots[1][n];

              //Inserting other nodes according to probability.
              for(int i=0;i<numberOfnodes-1;i++){
                  this.insert()
              }

           }

           //Gives recipi for making obst
           void makeObst(){
                expectation=utils::create2darr(0,numberOfnodes+1,numberOfnodes+2);//we will take from e[0][1] to e[n][n+1] as 0.
                w=utils::create2darr(0,numberOfnodes+1,numberOfnodes+2);
                roots=utils::create2darr(-1,numberOfnodes+1,numberOfnodes);
                //For the subtree of length 1 to n;
                for(int l=1;l<=n;l++){

                    //Possible i's for all that lengths.
                    for(int i=0;i<=numberOfnodes-l+1;i++){

                        //the corresponding value of j will be.
                        int j=i+l-1;

                        //For this subtree i,j we want to find a root such that expectation is minimized
                        expectation[i][j]=INT8_MAX;
                        w[i][j]=w[i][j-1]+prob[j];
                        //Checking for all possible roots in [i,j]
                        for(int r=i;r<=j;r++){
                            int t=e[i][r-1]+e[r+1][j]+w[i][j];
                            if(t<expectation[i][j]){
                                 expectation[i][j]=t;
                                 roots[i][j]=r;
                            } 
                        }
                    }
                }

           }
           ~obst(){
               delete[] obstarr;
               delete[] obstProb;
           }
    };
}

