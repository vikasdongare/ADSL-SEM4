#include<iostream>
using namespace std;

template<class T>
class stack
{
    T arr[50];
    int top;

public:
        stack()
        {
            top=-1;
        }

        bool isempty()
        {
            if(top==-1)
                return true;
            return false;
        }
        bool isfull()
        {
            if(top==50)
                return true;
            return false;
        }
        void push(T a)
        {
            if(!isfull())
                arr[top++]=a;
            else
                cout<<"\n\t !!! STACK IS FULL !!!";
        }
        T pop()
        {
            if(!isempty())
            {
                return arr[--top];
            }
            else
                cout<<"\n\t !!! STACK IS EMPTY !!!";
        }
};
