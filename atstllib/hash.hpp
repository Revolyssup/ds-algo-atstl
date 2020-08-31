#pragma once
#include "linkedlist.hpp"
#include<vector>
namespace atstl{
    template<typename T>
    class hashMap{
        int n;
        int hash(int key){
            return (key%n);
        }
        public:
        std::vector<atstl::LinkedList<T>> table;

        //constructor
        hashMap(int x):n(x),table(n,atstl::LinkedList<T>()){}
        //hash function
    
        void insert(int key,T value){
         
            int index=hash(key);      
            table[index].insert(value);
        } 
        void print(){
            for(auto ll: table){
                ll.print();
                std::cout<<"/ \n ";
            }
        }
        bool search(int key,int value){
            int index=hash(key);
            
            if(table[index].check(value)==-1) return 0 ;
            else return 1;
        }
    };
}