#include<iostream>
#include<vector>
#include "atstl.hpp"

void twice(atstl::node<int>* n){
    n->data=(n->data)*2;
}

int main(){
    void(*cb)(atstl::node<int>*)=twice;
    std::vector<int> vec={12,58,96,23,1,4};
    atstl::LinkedList<int> list(vec);
    list.print();
    list.Foreach(cb);
    list.print();
}