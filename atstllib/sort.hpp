#pragma once
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
    }
}