#include<iostream>
#include<vector>
#include<thread>
#include<functional>
#include "./atstllib/atstl.hpp"

void print(atstl::treenode<int>* a){
    std::cout<<(a->data)<<"\n";
}
void sq(atstl::treenode<int>* a){
    a->data*=a->data;
}

int main(){
   atstl::bst<int> a(10);
   a.insert(12);
   a.insert(7);
   a.inorder(&a.root,print);
   a.inorder(&a.root,sq);
   a.inorder(&a.root,print);
}








// void print(atstl::treenode<int> a){
//         std::cout<<a.data<<"\n";
// }





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