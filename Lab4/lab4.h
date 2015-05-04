//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: May 4,2015
//Approach: used helper functions in order to do the functions recursively
//used recursion to go through the whole tree
//need to use recursion in order to go through all the elements in the correct
//order. placed cout statements in certain placesto make sure it was 
//outputed correctly
//=====================================================
#include <iostream>
#include <utility>
#include <vector>

void preOrderRec(int a, int b, int n)
{
    std::pair<int,int> curr(a,b);
    if(a+b >= n)
    {
        return;
    }

    std::cout << curr.first << ' ' << curr.second << std::endl;
    preOrderRec(2*a-b,a,n);
    preOrderRec(2*a+b,a,n);
    preOrderRec(a+2*b,b,n);
}
void preOrder(int n)
{
    std::cout << "Pre-Order" << std::endl;
    preOrderRec(2,1,n);
    preOrderRec(3,1,n);
}

void postOrderRec(int a, int b, int n)
{
    std::pair<int,int> curr(a,b);
    if(a+b >= n)
    {
        return;
    }
    postOrderRec(2*a-b,a,n);
    postOrderRec(2*a+b,a,n);
    postOrderRec(a+2*b,b,n);
    
    std::cout << curr.first << ' ' << curr.second << std::endl;
}
void postOrder(int n)
{
    std::cout << "Post-Order" << std::endl;
    postOrderRec(2,1,n);
    postOrderRec(3,1,n);
}

typedef std::pair<int,int> Entry;
class priority_queue {
public:
  std::vector<Entry> entries;
  Entry& front() { return entries.back(); }
  void pop() { entries.pop_back(); }
  void push( Entry e ) { 
    entries.push_back( e );
    for ( int i = entries.size()-1; i != 0; --i ) {
      if ( entries[i].first + entries[i].second < entries[i-1].first +
        entries[i-1].second) break;  // replace this comparison with code for comparing int pairs.
      swap(entries[i], entries[i-1]);
    }
  }
  void sortedOrderRec(int a, int b, int n)
{
    std::pair<int,int> curr(a,b);
    if(a+b >= n)
    {
        return;
    }
   
    sortedOrderRec(2*a-b,a,n);
    sortedOrderRec(2*a+b,a,n);
    sortedOrderRec(a+2*b,b,n);
    push(curr);
}
void sortedOrder(int n)
{
    priority_queue p;
    std::cout << "Sorted-Order" << std::endl;
    sortedOrderRec(2,1,n);
    sortedOrderRec(3,1,n);
   for ( int i = entries.size()-1; i >= 0; --i )
    {
        std::cout << entries.at(i).first << ' ' << entries.at(i).second << std:: endl;
    }
}
    
};



