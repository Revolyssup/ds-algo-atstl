#pragma once
#include "utils.hpp"
#include<cmath>
namespace atstl{
        namespace heap{
                //O(logn)
                //i is the root.
            void maxHeapify(int* arr,int i,int size){
                int l=2*i+1;
                int r=2*i+2;
                int largest;
                if(l<size && arr[i]<arr[l]) largest=l;
                else largest=i;
                if(r<size && arr[largest]<arr[r]) largest=r;
                if(largest!=i){  //Means that heap isn't already max_heaped.
                    atstl::utils::swap(&arr[i],&arr[largest]); //Swap the root of subtree with max number
                    //now we no more have largest element on largest index after the swap.
                    maxHeapify(arr,largest,size); //max_heapify the subtree where our old root went
                    
                } 
            }
          

            //Building a max heap bottom up
            //O(nlogn)
            void buildMaxHeap(int* arr,int size){
                //All leaf nodes are trivially maxHeaped
                //Starting from last node of just-above-leaf layer,we go down to 0th element and keep maxHeaping
                //last node of JAL layer is at floor((size-1)/2)
                for(int i=floor((size-1)/2);i>-1;i--){
                    maxHeapify(arr,i,size);
                }
            }

        }   
        
 
}