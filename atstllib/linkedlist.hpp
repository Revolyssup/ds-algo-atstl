#pragma once
#include "node.hpp"
#include<vector>

namespace atstl{

template<class T>
class LinkedList{
    node<T> head;

    public:
    int length;

    //constructor 
    LinkedList():head(),length(0){}

    //constructor to create linked list from vector.
    LinkedList(std::vector<T> &values){
        /*insert(T data) method inserts at the beginning so we
         traverse the array backwards to form a linkedlist from a vector in order*/
        for(int i=values.size()-1;i>-1;i--){
            this->insert(values[i]);
        }
    }

    //deconstructor-frees the memory
    ~LinkedList(){
        node<T>* itr=head.next;
        while(itr){
            node<T>* temp= itr;
            itr=itr->next;
            delete temp;
            length--;
        }
    }


    /*Declaring member functions*/

    //It inserts a node at the beginning of linkedlist
     void insert(T data);

    
    //checks if an element exists in linkedlist and returns its pos,if doesnt exist,returns -1.
    int check(T key);

    //pops out given element somewhere in linkedlist.
    void pop(T key);

    //prints all elements
    void print();
};

/***************************************Defining Member functions**************************************************/

//Defining insert
template<typename T>
void LinkedList<T>::insert(T data){
        node<T>* newnode= new node<T>(data);
        newnode->next=head.next;
        head.next=newnode;
        
}

//defining print
template<typename T>
void LinkedList<T>::print(){
    node<T>* temp= new node<T>();
    temp->next=head.next;
    while(temp->next)
    {
        std::cout<<temp->next->data<<std::endl;
        temp->next=temp->next->next;
        
    }
}

//Defining check
template<typename T>
int LinkedList<T>::check(T key)
{
    int i=0;
    node<T>* temp= new node<T>();
    temp->next=head.next;
    while(temp)
    {
        if(temp->next->data==key) return i;
        temp->next=temp->next->next;
        i++;
    }
    return -1;
}

// Defining pop
template<typename T>
void LinkedList<T>::pop(T key){

    node<T>* tempHead= new node<T>();
    node<T>* tempTail= new node<T>();
    tempHead->next=head.next;
    tempTail->next=head.next;
    while(tempHead->next)
    {
        if(tempHead->next->data==key){
            node<T>* del=tempHead->next;
            tempTail->next->next=tempHead->next->next;
            delete del;

        };
        tempTail->next=tempHead->next;
        tempHead->next=tempHead->next->next;
    

    }
 
}

}

