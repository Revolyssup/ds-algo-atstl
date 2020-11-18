#include<iostream>
namespace atstl{
    template<typename T>
    class Stack{
        int size;
        int top=-1;
        T* pts;
        public:
        Stack(int s):size(s),pts(new T[s]){}
        ~Stack(){
            delete pts;
        }

        void push(T ele){
            if(top==size-1){
                std::cout<<"Stack Overflow!!\n";
                return;
            }
            pts[++top]=ele;
        }

        T pop(){
            if(top==-1){
                std::cout<<"Stack underflow!!\n";
                return T();
            }
            return pts[top--];

        }
    };
}