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
}//namspace atstl