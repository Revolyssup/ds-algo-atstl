#include<iostream>
#include<vector>
#include<thread>
#include<functional>
#include "./atstllib/atstl.hpp"
 

int main(){
    atstl::Queue<int> q(2);
    q.enq(1);
    q.enq(2);
    std::cout<<q.dq()<<'\n';
    std::cout<<q.dq()<<'\n';
    q.enq(5);
     std::cout<<q.dq()<<'\n';
}


    // atstl::GraphAL g(5);
    // g.insertFrom(0,1);
    // g.insertFrom(1,2);
    // g.insertFrom(1,3);
    // g.insertFrom(2,3);
    // g.insertFrom(2,4);
    // g.print();

//Testing pendulum
    // double theta;
    // double theta_dot;
    // double mu;
    // double len;
    // std::cout<<"Enter length of pendulum: \n";
    // std::cin>>len;
    // std::cout<<"Enter initial angle(degrees) at t=0: \n";
    // std::cin>>theta;
    // std::cout<<"Enter initial angular velocity(rad/sec) at t=0: \n";
    // std::cin>>theta_dot;
    // std::cout<<"Enter coefficient of air friction \n";
    // std::cin>>mu;
    // atstl::calculas::pendulum p(len,theta,theta_dot,mu);
    // double t;
    // std::cout<<"Enter at what time(in seconds) from t=0,you want the angle from vertical: \n";
    // std::cin>>t;
    // std::cout<<"The pendulum at t="<<t<<" will be at "<<p.getThetaT(t)<<" degrees."<<std::endl;
    // std::cout<<"The pendulum time period is: "<<p.timePeriod()<<" seconds."<<std::endl;



// void print(atstl::treenode<int> a){
//         std::cout<<a.data<<"\n";
// }





// //takes pointer to a node and doubles data of all nodes

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