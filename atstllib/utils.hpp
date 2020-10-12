#pragma once
#include<functional>
#include<chrono>
namespace atstl{
    namespace utils{

        //Swap function to swap values at different addresses pointed to by two pointers
        //Made for frequent use of swapping in sorts.
        template<typename T>
        void swap(T* a,T* b){
            T temp=*a;
            *a=*b;
            *b=temp;
        }

       int** create2darr(int k,int row,int col){
           int** arr=new int*[row];
            for(int i=0;i<row;i++){
                arr[i]=new int[col];
            }

            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    arr[i][j]=k;
                }
            }
        return arr;
       }


       int min(int a,int b){
           if(a>b) return b;
           else return a;
       }
        int max(int a,int b){
           if(a>b) return a;
           else return b;
       }
        
        //Needs a heck lot improvement to actually make it variadic
       template<typename T1,typename... args> 
       T1 calcTime(std::function<T1(args...)> cb,args... var){
           auto start=std::chrono::high_resolution_clock::now();
            T1 toreturn=cb(var...);
           auto end=std::chrono::high_resolution_clock::now();
           auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
           std::cout<<"(Time taken by this process in microseconds is: "<<duration.count()<<")";
           return toreturn;
       }

    }//namespace utils
} //namespace atstl