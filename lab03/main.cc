#include "lab3.h"

int main()
{
    TwoStackFixed <int> list1(5,3);
    list1.pushStack1(3);
    list1.pushStack1(2);
    list1.pushStack1(1);
    list1.pushStack2(4);
    list1.pushStack2(5);
    cout << list1.popStack1() << endl;
    list1.display();
    
    TwoStackOptimal<int> list4(5);
    list4.pushFlexStack1(1);
    list4.pushFlexStack1(2);
    list4.pushFlexStack1(3);
    list4.pushFlexStack1(4);
    list4.pushFlexStack2(5);
    cout << list4.popFlexStack2() << endl;
    list4.display();
    
    stack<int> list11;
    list11.push(1);
    list11.push(2);
    list11.push(3);
    list11.push(4);
    list11.push(5);
    stack<int>list2;
    stack<int>list3;
    
    showTowerStates(5,list11,list2,list3);
    return 0;
}