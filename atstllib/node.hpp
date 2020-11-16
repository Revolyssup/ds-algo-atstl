#pragma once
namespace atstl{
    template<typename T>
    class node{
        //node has data and pointer to next node
        public:
        T data;
        node* next;

        //adding constructor
        public:
        node(): data(T()),next(nullptr){};
        node(T data){
            this->data=data;
            this->next=nullptr;
        }

    };
    template<typename T>
     class treenode{
        //node has data and pointer to next node
        public:
        T data;
        treenode* left;
        treenode* right;

        //adding constructor
        public:
        treenode(): data(T()),left(nullptr),right(nullptr){};
        treenode(T data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }

    };

    // template<typename T>
    // class btreeinternal{
    //     btreenode<T>* left;
    //     btreenode<T>* right;
    //     T key;
    // };

    // template<typename T>
    //  class btreenode{ 
    //      int numberOfKeys;
    //      btreeinternal<T>* Nodes;
    //      public:
    //      btreenode(int n):numberOfKeys(n)){
    //          Nodes=new btreeinternal[numberOfKeys];
    //          for(int i=0;i<numberOfKeys;i++){
    //              Nodes[i]->left=NULL;
    //              Nodes[i]->right=NULL;
    //          }
    //      }
    //      btreenode(int n,T[] keys):numberOfKeys(n)){
    //          Nodes=new btreeinternal[numberOfKeys];
    //          for(int i=0;i<numberOfKeys;i++){
    //              Nodes[i].data=keys[i];
    //              Nodes[i]->left=NULL;
    //              Nodes[i]->right=NULL;
    //          }
    //      }
         
    //  };

     template<typename T>
     class RBtreenode{
        //node has data and pointer to next node
        public:
        T data;
        bool color; //If this bit is 1,then node is red,otherwise black
        RBtreenode* left;
        RBtreenode* right;

        //adding constructor
        public:
        RBtreenode(bool rb): data(T()),left(nullptr),right(nullptr),color(rb){};
        RBtreenode(bool rb,T data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->color=rb;
        }

    };
}//namspace atstl