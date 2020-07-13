#include<iostream>
#include<vector>
#include "atstl.hpp"

int main(){
    std::vector<int> vec={12,58,96,23,1,4};
    atstl::LinkedList<int> list(vec);
    std::cout<<"Before pop"<<std::endl;
    list.print();
    
    list.pop(9);
    std::cout<<"After pop"<<std::endl;
    list.print();
    
}