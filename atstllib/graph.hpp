#pragma once
#include "./linkedlist.hpp"
#include<vector>
#include<iostream>
namespace atstl{

    //Vertices are numbered 0 to n-1.
    class GraphAL{
        std::vector<atstl::LinkedList<int>*> Al; //Vector will contain pointer to the list containing all the nodes its directed to.
        //Each index of vector denotes,each vertex. Vertices are numbered from 0 to n-1;
        int noOfVertices;
        public:
        GraphAL(int n):noOfVertices(n){
            for(int i=0;i<n;i++){
                atstl::LinkedList<int>* v=new atstl::LinkedList<int>(); 
                Al.push_back(v);
            }
        }

        void insertFrom(int i,int v){ //i will now also point to v
            Al[i]->insert(v);
        }
        
        void insertFrom(int i,std::vector<int> v){ //i will now also point to v
        for(int j=0;j<v.size();j++){
             Al[i]->insert(v[j]);
        }
        }

        void print(){
            for(int i=0;i<noOfVertices;i++){
                Al[i]->print(i);
            }
        }

    };
}