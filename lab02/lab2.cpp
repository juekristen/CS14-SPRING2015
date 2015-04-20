//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: April 20,2015
//=====================================================
#include "lab2.h"


int primeCount( forward_list<int> lst )
{
    if(lst.empty())
    {
        return 0;
    }
    if(isPrime(lst.front()))
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    else 
        lst.pop_front();
        return primeCount(lst);
}
bool isPrime( int i )
{
    for(int p = 2; p < i; ++p)
    {
        if(i % p == 0)
            return false;
    }
    return true;
}
template <typename Type>
void listCopy( forward_list <Type> L, forward_list <Type>& P )
{
    L.reverse();
    L.splice_after(L.before_begin(),P);
    P = L;
}
int main()
{
    forward_list <int> list1;
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(20);
    list1.push_front(17);
    
    forward_list <int> list2;
    list2.push_front(12);
    list2.push_front(22);
    list2.push_front(52);
    list2.push_front(9);
    for(auto it = list2.begin(); it != list2.end();++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    cout << primeCount(list1) << endl;
    cout << primeCount(list2) << endl;
    
    listCopy(list1,list2);
    
    // cout << list2.front() << ' ';
    // while(!list2.empty())
    // {
    //     list2.pop_front();
    //      cout << list2.front() << ' ';
    // }
    for(auto it = list2.begin(); it != list2.end();++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    
    cout << isPrime(2) << endl;
    cout << isPrime(3) << endl;
    cout << isPrime(20) << endl;
    cout << isPrime(17) << endl;
    
    List <int> k;
    k.push_front(3);
    k.push_front(2);
    k.push_front(1);
    k.push_front(0);
    
    cout << k.size() << endl;
    
    k.display();
    cout << endl;
    
    k.elementSwap(3);
    k.display();
    cout << endl;
    return 0;
    
}
