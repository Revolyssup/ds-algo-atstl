#include<iostream>
namespace atstl{
    template<typename T>
    class Queue{
        int front=-1;
        int back=-1;
        T* q;
        int size;
        bool noElemLeft=true;
        public:
        Queue(int s):size(s),q(new T[s]){}

        ~Queue(){
            delete[] q;
        }

        void enq(T ele);
        T dq();
        bool isEmpty();
    };

    template<typename T>
     void Queue<T>::enq(T ele){

            if(!noElemLeft && (back+1)%size==front){
                std::cout<<"Queue full!!\n";
                return;
            }
        back=(back+1)%size;
        q[back]=ele;
        if(noElemLeft){
            noElemLeft=false;
            front=back;
        }     
     }
    
    template<typename T>
    T Queue<T>::dq(){
            if(noElemLeft){
                 std::cout<<"Queue Empty !!\n";
                return T();
            }
            else if(back==front){
                noElemLeft=true;
            }
            T temp=q[front];
            front=(front+1)%size;
            return temp;
        }

    template<typename T>
    bool Queue<T>::isEmpty(){
        return noElemLeft;
    }

}
