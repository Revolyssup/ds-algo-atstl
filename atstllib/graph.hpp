#pragma once
#include "./linkedlist.hpp"
#include<vector>
#include<iostream>
namespace atstl{

    //Vertices are numbered 0 to n-1.
    class GraphAL{
        std::vector<std::vector<std::pair<int,int>>*> Al; 

        //Each node in list will have a vector containing pairs.Each pair representing an edge from that point.(v,w)
        int noOfVertices;
        public:
        GraphAL(int n):noOfVertices(n){
            for(int i=0;i<n;i++){
                std::vector<std::pair<int,int>>* v=new std::vector<std::pair<int,int>>(); 
                Al.push_back(v);
            }
        }

        ~GraphAL(){
            for(auto i:Al){
                delete i;
            }
        }
        void insertFrom(int i,int v,int w);
        void insertFrom(int i,int v);
        void insertFrom(int i,std::vector<std::pair<int,int>>& v);

        void print();


    };

    void GraphAL::insertFrom(int i,int v,int w){ //i will now also point to v
            Al[i]->push_back(std::make_pair(v,w));
        }
    void GraphAL::insertFrom(int i,int v){ //i will now also point to v
            Al[i]->push_back(std::make_pair(v,1)); //default weight is 1
        }
    void GraphAL::insertFrom(int i,std::vector<std::pair<int,int>>& v){ //i will now also point to v
        for(int j=0;j<v.size();j++){
             Al[i]->push_back(v[j]);
        }
        }
    
    void GraphAL::print(){

            for(int i=0;i<noOfVertices;i++){
                std::cout<<"Vertex: "<<i<<"->";
                for(int j=0;j<Al[i]->size();j++){
                   std::cout<<"|v="<< Al[i]->at(j).first<<" w="<<Al[i]->at(j).second;
                }
                 std::cout<<"\n";
            }
        }
}