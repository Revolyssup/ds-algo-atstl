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

    }
}