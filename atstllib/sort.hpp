#pragma once
#include<thread>
#include "heap.hpp"
namespace atstl{
    namespace Sort{

        //performs bubblesort for vectors
        void bubbleSort(std::vector<int>& arr){
            for(int i=0;i<arr.size()-1;i++){
                for(int j=i+1;j<arr.size();j++){

                    if(arr[j]<arr[i]) atstl::utils::swap<int>(&arr[i],&arr[j]);
                }
            }
        }

         //performs bubblesort for arrays
        void bubbleSort(int arr[],int l){
            for(int i=0;i<l-1;i++){
                for(int j=i+1;j<l;j++){

                    if(arr[j]<arr[i]) atstl::utils::swap<int>(&arr[i],&arr[j]);
                }
            }
        }


        /***********************************************************************/

        //performs insertion sort for vectors
        void insertionSort(std::vector<int>& arr){
            int temp;
            for(int key=1;key<arr.size();key++){
                for(int j=key-1;j>-1;j--){
                    temp=arr[key];
                    if(arr[j]<=temp) break;
                    atstl::utils::swap<int>(&temp,&arr[j]);

                }
            }
        }

         //performs insertion sort for array
        void insertionSort(int arr[],int l){
            int temp;
            for(int key=1;key<l;key++){
                for(int j=key-1;j>-1;j--){
                    temp=arr[key];
                    if(arr[j]<=temp) break;
                    atstl::utils::swap<int>(&temp,&arr[j]);

                }
            }
        }

        /***********************************************************************/


        //Takes two sorted arrays and returns a combined sorted array

        int* merge(int arr1[],int arr2[],int s1,int s2){
            int* ans= new int[s1+s2];
            int i=0;
            int j=0;
            int ansi=0;
            while(i<s1 && j<s2){
                if(arr1[i]<=arr2[j]){
                    ans[ansi++]=arr1[i++];
                }
                else{
                    ans[ansi++]=arr2[j++];
                }
            }
            while(i<s1){    
                ans[ansi++]=arr1[i++];
            }
             while(j<s2){
                 ans[ansi++]=arr2[j++];
            }
            return ans;
        }


        //performs merge sort for vec
        int* mergeSort(int arr[],int start,int end){

            //T(1)
            if(start==end){ //base case,when arrray is divided upto one element
                int* leaf= new int[1];
                leaf[0]=arr[start];
                return leaf;
            } 

            int mid=(start+end)/2; 
            //2T(n/2)
            int* arr1=mergeSort(arr,start,mid);
            int* arr2=mergeSort(arr,mid+1,end);
            
            //T(n)
            int* ans=merge(arr1,arr2,(mid-start)+1,end-(mid+1)+1);
            delete arr1;
            delete arr2;
            return ans;
        }
            
            //HeapSort
             void maxheapSort(int* arr, int size){
                int heapSize=size;
                atstl::heap::buildMaxHeap(arr,size); //convert the array into max heap such that 1st element is always maximum
                for(int i=size-1;i>-1;i--){
                    atstl::utils::swap(&arr[i],&arr[0]); //starting from last element,we keep exchanging root(max) with arr[i]
                    heapSize--;
                    atstl::heap::maxHeapify(arr,0,heapSize); //We messed the top so we will reheapify to get largest at top
                }
            }

            /***************************Quick Sort*******************************/
            
            //O(n)
            int partition(int* arr,int p,int q){
                int pivot=q;
                int i=p-1;
                
                //every element that i let pass through is smaller than pivot
                for(int j=p;j<q;j++) if(arr[j]<=arr[pivot]) atstl::utils::swap(&arr[j],&arr[++i]); 
                atstl::utils::swap(&arr[pivot],&arr[i+1]);
                return i+1;
                
            }
            /*Instead of using just one helper i along with pivot and exchanging values of pivot and i index,
            we can use two helpers i and j and keep exchanging them instead of pivot*/
             int hoardePartition(int* arr,int p,int q){
               int pivot=p;
               int i=p;
               int j=q;
               while(true){
                   while(arr[j]>arr[pivot]) j--; //every element that j let pass through is grtr than pivot
                   while(arr[i]<arr[pivot]) i++; //every element that i let pass through is smaller than pivot
                   
                   if(i<j) atstl::utils::swap(&arr[j],&arr[i]);
                   else return j;
               }
            }
            
            int randomPartition(int* arr,int p,int q){
                 /*Randomization ensures the time complexity to be O(nlogn)*/
                int pivot=(rand()%(q-p+1)+p); //generating a random index between p and q 
                atstl::utils::swap(&arr[pivot],&arr[q]); 
                return hoardePartition(arr,p,q);
            }


            void QuickSort(int* arr,int p,int q){
                if(p<q){
                //theta(n)
                int pivot=randomPartition(arr,p,q);

                //2T(n/2)
                QuickSort(arr,p,pivot-1);
                QuickSort(arr,pivot+1,q);
                }
               
            }
            /*In worst case of non randomized quick sort,that is when array is in descending order,2T(n/2)~T(n-1). Then time complexity will come as n^2*/


            /******************Counting Sort***********/
            //This sort maintains a count of number of elements before an element in sorted position.
            //This should be used only when array contains positive numbers in a small range [0,k]
            //It takes O(k) extra space
            int* countingSort(int* arr,int l,int k){
               
                int auxilliary[k+1];
                for(int i=0;i<=k;i++){
                    auxilliary[i]=0;
                }
                int* answer= new int[l];
                // //Count of each element in arr[i] is at the index arr[i] in auxilliary
                for(int i=0;i<l;i++){
                    auxilliary[arr[i]]++;
                }

                // //Count of number of elements before each element in arr[i] is at index arr[i] in auxilliary
                for(int i=1;i<=k;i++){
                    auxilliary[i]+=auxilliary[i-1];
                }
                // //For every element arr[i],we can see the number of elements before it from auxilliary[arr[i]]. 
                // //This element will be pushed at index auxilliary[arr[i]] in answer array.
                for(int i=0;i<l;i++){
                    answer[auxilliary[arr[i]]]=arr[i];
                    auxilliary[arr[i]]--;
                }
                return answer;
            }

            
    }
}