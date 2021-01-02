# Implemented Basic Data structure/ algorithm and sorts
# Also contains POSIX compliant shell scripts to execute C/C++ files in a docker container with features like monitoring and re-compilation and execution on saving.
### Run this command to make it executable by giving permissions.
```shell
    chmod +x main.sh
```
#### (Make sure to have docker installed.)
## Linked List-
```C++
atstl::LinkedList<T data>()
atstl::LinkedList<T data>(vector V)
```

## Heap-
```C++
atstl::heap::buildMaxHeap(int* arr,int size) //takes an array and converts it into a max heap
atstl::heap::maxHeapify(int* arr,int i,int size) //takes a defaulter heap and an index from which it's needed to be corrected
```

## Sorting algorithms
```C++
atstl::Sort::bubbleSort(vec) //where vec is a given vector
atstl::Sort::bubbleSort(arr,l) //where arr is an array and l is its length

atstl::Sort::insertionSort(vec) //where vec is a given vector
atstl::Sort::insertionSort(arr,l) //where arr is an array and l is its length

atstl::Sort::merge(vec1,vec2) //merges two vectors
atstl::Sort::merge(arr1,arr2,s1,s2) //s1 and s2 are lengths of arr1 and arr2 respectively

atstl::Sort::mergeSort(vec) //where vec is a given vector
atstl::Sort::mergeSort(arr,l) //where arr is an array and l is its length

atstl::Sort::maxheapSort(arr,l)
atstl::Sort::QuickSort(arr,p,q) //p and q are lowest and highest index of the array
```
-------------------------------------------------
### You can clone this repository and include atstl.hpp from atstllib to use all data structures and algorithms.

