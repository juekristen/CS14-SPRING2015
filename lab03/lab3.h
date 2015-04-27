#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;
template <typename T>
class TwoStackFixed
{
    public:
        TwoStackFixed(int size, int maxtop )
            :SZ(size), MAX(maxtop)
        {
            fullarr = new T[size];
           
        }
        void pushStack1(T value) //to push element into first stack.
        {
            if(stack1.size() <= MAX)
            {
                stack1.push(value);
                fullarr[countS1] = value;
                countS1++;
                return;
            }
            cout << "Overflowed!\n";
            exit(1);
            
        }
        void pushStack2(T value) //to push element into second stack.
        {
           if(stack2.size() < SZ - MAX) 
           {
                stack2.push(value);
                fullarr[countS2] = value;
                countS2 --;
                return;
           }
           cout << "Overflowed!\n";
           exit(1);
        }
        T popStack1() //to pop element from first stack.
        {
            if(isEmptyStack1())
            {
                cout << "Cannot pop empty stack:\n";
                exit(1);
            }
            T temp = stack1.front();
            stack1.pop();
            fullarr[MAX] = T();
            return temp;
        }
        T popStack2()//to pop element from second stack.
        {
            if(isEmptyStack2())
            {
                cout << "Cannot pop empty stack:\n";
                exit(1);
            }
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
            if(stack2.size() == SZ - MAX)
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
        void display()
        {
            while(stack1.size()!=0)
            {
                cout << stack1.top()<< ' ';
                stack1.pop();
            }
            cout << endl;
            while(stack2.size()!=0)
            {
                cout << stack2.top()<< ' ';
                stack2.pop();
            }
            cout << endl;
            
        }
    private:
        const int SZ;
        T *fullarr;
        const int MAX;
        stack<T> stack1;
        stack<T> stack2;
        int countS1 = 0;
        int countS2 = SZ - 1;
};
template <typename T>
class TwoStackOptimal
{   public:
        TwoStackOptimal(int size) //constructor that constructs array of size and
                                    //constructs empty stacks.
            :SIZE(size)
        {
            fullarr = new T[size];
        }
        void pushFlexStack1(T value) //to push element into first stack.
        {
            if(isFullStack1())
            {
                cout << "Overflowed!\n";
                exit(1);
            }
            stack1.push(value);
            fullarr[countS1] = value;
            countS1++;
        }
        void pushFlexStack2(T value) //to push element into second stack.
        {
            if(isFullStack2())
            {
                cout << "Overflowed!\n";
                exit(1);
            }
            stack2.push(value);
            fullarr[countS2] = value;
            countS2 --;
        }
        T popFlexStack1() //to pop element into first stack.
        {
             if(isEmptyStack1())
            {
                cout << "Cannot pop empty stack:\n";
                exit(1);
            }
            T temp = stack1.front();
            stack1.pop();
            fullarr[countS1] = T();
            return temp;
        }
        T popFlexStack2() //to pop element from second stack.
        {
             if(isEmptyStack2())
            {
                cout << "Cannot pop empty stack:\n";
                exit(1);
            }
            T temp = stack1.front();
            stack1.pop();
            fullarr[countS1] = T();
            return temp;
        }
        bool isFullStack1()//helper function to check whether first stack is full.
        {
            if(stack1.size() + stack2.size() == SIZE)
                return true;
                return false;
        }
        bool isFullStack2() //helper function to check whether second stack is full.
        {
            if(stack1.size() + stack2.size() == SIZE)
                return true;
                return false;
        }
        bool isEmptyStack1() //helper function to check whether first stack is empty.
        {
            if(stack1.size()==0)
            return true;
            return false;
        }
        bool isEmptyStack2() //helper function to check whether second stack is empty.
        {
            if(stack2.size()==0)
            return true;
            return false;
        }
        void display()
        {
            while(stack1.size()!=0)
            {
                cout << stack1.top()<< ' ';
                stack1.pop();
            }
            cout << endl;
            while(stack2.size()!=0)
            {
                cout << stack2.top()<< ' ';
                stack2.pop();
            }
            cout << endl;
            
        }
    private:
        const int SIZE;
        T *fullarr;
        stack<T> stack1;
        stack<T> stack2;
        int countS1 = 0;
        int countS2 = SIZE - 1;
};
template <typename T>
void helpShowTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C,char one, 
    char two, char three)
{
    if(n == 1)
    {
        cout << "Moved " <<  A.top() << " from peg "<< one << " to " << three << endl;
        C.push(A.top());
        A.pop();
    }
    else
    {
        helpShowTowerStates(n-1,A,C,B,one,three,two);
        helpShowTowerStates(1,A,B,C,one,two,three);
        helpShowTowerStates(n-1,B,A,C,two,one,three);
    }
}
template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    helpShowTowerStates(n,A,B,C,'A','B','C');
}

