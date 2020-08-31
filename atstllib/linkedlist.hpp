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
    //pops out first element
    void pop();

    //prints all elements
    void print();

    //Iterates over each element of list and executes the callback function
    void Foreach(const std::function<void(atstl::node<T>*)> &cb);
    // void Foreach(void(*cb)(atstl::node<T>*));
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
    temp=head.next;
    while(temp)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}

//Defining check
template<typename T>
int LinkedList<T>::check(T key)
{
    int i=0;
    node<T>* temp= new node<T>();
    temp=head.next;
    while(temp)
    {
        if(temp->data==key) return i;
        temp=temp->next;
        i++;
    }
    return -1;
}

// Defining pop
template<typename T>
void LinkedList<T>::pop(T key){

    if(head.next->data==key){
        node<T>* temp=new node<T>();
        temp=head.next;
        head.next=head.next->next;
        delete temp;
    }
    node<T>* tempHead= new node<T>();
    node<T>* tempTail= new node<T>();
    tempHead=head.next;
    tempTail=head.next;
    while(tempHead)
    {
        if(tempHead->data==key){
            node<T>* del=tempHead;
            tempTail->next=tempHead->next;
            delete del;

        };
        tempTail=tempHead;
        tempHead=tempHead->next;
    

    }
 
}

template<typename T>
void LinkedList<T>::pop(){
        node<T>* temp=new node<T>();
        temp=head.next;
        head.next=head.next->next;
        delete temp;
}
//defining ForEach
template<typename T>
void LinkedList<T>::Foreach(const std::function<void(atstl::node<T>*)> &cb){
    node<T>* temp= new node<T>();
    temp=head.next;
    while(temp)
    {
        cb(temp);
       temp=temp->next;
    
    }
}

}

