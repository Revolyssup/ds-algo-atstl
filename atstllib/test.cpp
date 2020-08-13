#include<iostream>
#include<vector>
#include<functional>
#include "atstl.hpp"

//takes pointer to a node and doubles data of all nodes
void twice(atstl::node<int>* n){
    n->data=(n->data)*2;
}

int main(){

    /***Testing Linked List***/
    std::vector<int> vec={12,58,96,23,1,4};
    //creates list from vector
    atstl::LinkedList<int> list(vec);

    //prints data of all nodes
    std::cout<<"*********Before all operations**********\n";
    list.print();
    //twice passed as a callback(twice is implictly converted into a function pointer so we could have explicitly use &twice)
    list.Foreach(twice);
    list.pop(24);
    std::cout<<"*********After all operations**********\n";
    list.print();




    /*******Testing heap*********/
    
}