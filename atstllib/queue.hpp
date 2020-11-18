#include<iostream>
namespace atstl{
    template<typename T>
    class Queue{
        int front=-1;
        int back=-1;
        int* q;
        int size;
        bool noElemLeft=true;
        public:
        Queue(int s):size(s),q(new T(size)){}
        void enq(T ele){

            if(!noElemLeft && (back+1)%size==front){
                std::cout<<"Queue full!!\n";
                return;
            }
        if(noElemLeft){
            noElemLeft=false;
            q[++back]=ele;
            front=back;
        }
       else{
        back=(back+1)%size;
        q[back]=ele;
       }
       
        }

        T dq(){
            if(noElemLeft){
                 std::cout<<"Queue Empty [Returning -1 in next line as err code, not element from Queue]!!\n";
                return -1;
            }
            else if(back==front){
                noElemLeft=true;
            }
            T temp=q[front];
            front=(front+1)%size;
            return temp;
        }
    };
}