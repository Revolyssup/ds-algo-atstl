namespace atstl{
    namespace utils{

        //Swap function to swap values at different addresses pointed to by two pointers
        //Made of frequent use of swapping in sorts.
        template<typename T>
        void swap(T* a,T* b){
            T temp=*a;
            *a=*b;
            *b=temp;
        }
    }//namespace utils
} //namespace atstl