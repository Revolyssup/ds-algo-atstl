#include<iostream>
#include<vector>
#include<functional>
#include "atstl.hpp"



int main(){
    int arr[]={8,7,6,5,4,3,2,1};
    atstl::Sort::maxheapSort(arr,8);
    for(int i=0;i<8;i++){
        std::cout<<arr[i]<<std::endl;
    }

   
}
// //takes pointer to a node and doubles data of all nodes
// void twice(atstl::node<int>* n){
//     n->data=(n->data)*2;
// }

//  /***Testing Linked List***/
//     std::vector<int> vec={12,58,96,23,1,4};
//     //creates list from vector
//     atstl::LinkedList<int> list(vec);

//     //prints data of all nodes
//     std::cout<<"*********Before all operations on linkd list**********\n";
//     list.print();
//     //twice passed as a callback(twice is implictly converted into a function pointer so we could have explicitly use &twice)
//     list.Foreach(twice);
//     list.pop(24);
//     std::cout<<"*********After all operations on linked list**********\n";
//     list.print();
   


//     /*******Testing Sorting*********/
//     int arr[]={10,9,8,7,5,3,1};

//     //Bubble sort
//     atstl::Sort::bubbleSort(vec);
//     std::cout<<"********* After bubble sort on vector**********\n";
//     for(auto i:vec){
//         std::cout<<i<<std::endl;

//     }

//     //Bubble sort with arrays
//     atstl::Sort::bubbleSort(arr,7);
//     std::cout<<"********* After bubble sort on array**********\n";
//     for(int i=0;i<7;i++){
//         std::cout<<arr[i]<<std::endl;

//     }
//     //insertion sort on vector
//      atstl::Sort::insertionSort(vec);
//     std::cout<<"********* After insertion sort on vector**********\n";
//     for(auto i:vec){
//         std::cout<<i<<std::endl;

//     }

//     //insertion sort on array
//     atstl::Sort::bubbleSort(arr,7);
//     std::cout<<"********* After insertion sort on array**********\n";
//     for(int i=0;i<7;i++){
//         std::cout<<arr[i]<<std::endl;

//     }
    

//     //checking merge
//     int v[10]={10,9,8,7,6,5,4,3,2,1};
//     int* v3=atstl::Sort::mergeSort(v,0,9);
//     std::cout<<"After merge sort"<<std::endl;
//     for(int i=0;i<10;i++){
//         std::cout<<v3[i]<<std::endl;
//     }