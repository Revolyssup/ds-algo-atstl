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
}//namspace atstl