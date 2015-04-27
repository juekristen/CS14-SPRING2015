#include <iostream>
#include <stack>
using namespace std;
class TwoStackFixed
{
    public:
        TwoStackFixed(int size, int maxtop )
            :SIZE(size), MAX(maxtop), stack1(0), stack2(0)
        {}
        void pushStack1(T value) //to push element into first stack.
        {
            if(stack1.size() <= MAX)
            {
                stack1.push(value);
                fullarr[countS1] = value;
                countS1++;
            }
            
        }
        void pushStack2(T value) //to push element into second stack.
        {
           if(stack2.size() < SIZE - MAX) 
           {
                stack2.push(value);
                fullarr[countS2] = value;
                countS2 --;
           }
        }
        T popStack1() //to pop element from first stack.
        {
            T temp = stack1.front();
            stack1.pop();
            fullarr[MAX] = T();
            return temp;
        }
        T popStack2()//to pop element from second stack.
        {
            T temp = stack2.front();
            stack2.pop();
            fullarr[MAX+1] = T();
            return temp;
        }
        bool isFullStack1() //helper function to check whether first stack is full.
        {
            if(stack1.size()== MAX)
            return true;
            return false;
        }
        bool isFullStack2() //helper function to check whether second stack is full.
        {
            if(stack2.size() == SIZE - MAX)
            return true;
            return false;
        }
        bool isEmptyStack1() //helper function to check whether first stack is
                                //empty.
        {
            if(stack1.size()==0)
            return true;
            return false;
        }
        bool isEmptyStack2() //helper function to check whether second stack is
                                //empty.
        {
            if(stack2.size() == 0)
            return true;
            return false;
        }
    private:
        const int SIZE;
        T fullarr[SIZE];
        const int MAX;
        stack<T> stack1;
        stack<T> stack2;
        int countS1 = 0;
        int countS2 = SIZE - 1;
};