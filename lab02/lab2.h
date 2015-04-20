#include <forward_list>
#include <iostream>
using namespace std;

int primeCount( forward_list<int> lst );
bool isPrime( int i );
template <typename Type>
void listCopy( forward_list <Type> L, forward_list <Type>& P );

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node( T data ) : data(data), next(0) {}
};
template <typename T>
class List
{
     private:
        Node<T> *head;
        Node<T> *tail;
    public:
        List()
            :head(0), tail(0)
        {}
        ~List()
        {
            while(head != 0)
            {
              pop_front();  
            }
        }
        void display() const
        {
            if(!head) return;
            Node <T> *curr;
            cout << head->data; 
            for(curr = head -> next; curr!=0; curr = curr -> next)
            {
                cout << ' ' << curr->data ;
            }
        }
        void push_front( T value )
        {
            Node <T> *k = new Node<T>(value);
            k->next = head;
            head = k;
            if(tail == 0)
            {
                tail = head;
            }
        }
        void pop_front()
        {
            if (!head) return;
            Node<T>*temp = head;
            head = head ->next;
            delete temp;
        }
        // void push_back(int value);
        // void select_sort( );
        // void insert_sorted( int value );
        // void remove_duplicates();
        // void take_out(Node* pre);
        // int sum()const;
        void elementSwap( int pos )
        {
            Node <T> *curr = head;
            Node <T> *temp;
            Node <T> *temp2;
            if(pos == 0)
            {
                head -> next = curr -> next -> next;
                curr -> next -> next = head;
                head = curr -> next;
                return;
            }
            
            //curr -> next -> next -> next  = curr -> next -> next;
            // temp = curr -> next;
            // temp2 = curr-> next -> next ->next;
            // curr -> next = curr -> next -> next;
            // curr -> next -> next = temp;
            // curr -> next -> next -> next= temp2;
            for (int i = 0 ; i < pos; ++i)
            {
                temp = curr -> next;
                temp2 = curr-> next -> next ->next;
                if(i == pos - 1)
                {
                    curr -> next = curr -> next -> next;
                    curr -> next -> next = temp;
                    curr -> next -> next -> next= temp2;
                }
                
                curr = curr -> next;
            }
        }
};