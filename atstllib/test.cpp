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
    std::cout<<"*********Before all operations on linkd list**********\n";
    list.print();
    //twice passed as a callback(twice is implictly converted into a function pointer so we could have explicitly use &twice)
    list.Foreach(twice);
    list.pop(24);
    std::cout<<"*********After all operations on linked list**********\n";
    list.print();
   


    /*******Testing Sorting*********/

    //Bubble sort
    atstl::Sort::bubbleSort(vec);
    std::cout<<"********* After insertion sort **********\n";
    for(auto i:vec){
        std::cout<<i<<std::endl;

    }

    //Bubble sort with arrays
    int arr[]={10,9,8,7,5,3,1};
    atstl::Sort::bubbleSort(arr,7);
    std::cout<<"********* After insertion sort **********\n";
    for(int i=0;i<7;i++){
        std::cout<<arr[i]<<std::endl;

    }
    //insertion sort
    
    
}