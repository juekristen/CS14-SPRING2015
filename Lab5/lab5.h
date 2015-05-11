//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: May 11,2015
//Approach: used helper functions in order to do the functions recursively
//used recursion to go through the whole tree
//need to use recursion in order to go through all the elements in the correct
//order. placed cout statements in certain placesto make sure it was 
//outputed correctly
//=====================================================
// -*- bst.h -*-
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0
// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    
    class Node 
    { // binary tree node
        public:
            Node* left;
            Node* right;
            bool selected;
            Value value;
            Node( const Value v = Value() )
            : value(v), left(nil), right(nil),selected(false)
            {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() 
            {
                // returns the height of the subtree rooted at this node
                // FILL IN
                if(size(left) > size(right))
                {
                    return size(left);
                }
                return size(right);
            }
            int size() 
            {
                
                // returns the size of the subtree rooted at this node,
                // FILL IN
                return sizehelp(this);
            }
            int sizehelp(Node* curr)
            {
                if(curr == 0)
                {
                    return 0;
                }
                return sizehelp(curr->left) + sizehelp(curr -> right) + 1;
            }
    }; // Node
// const Node* nil; // later nil will point to a sentinel node.
    
    int count;
    
    public:
        Node* root;
        int size() 
        {
            // size of the overall tree.
            // FILL IN
            return sizehelp(root);
        }
        int sizehelp(Node* curr)
        {
            if(curr == 0)
            {
                return 0;
            }
            return sizehelp(curr->left) + sizehelp(curr -> right) + 1;
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) 
        {
            // Print the node’s value.
            // FILL IN
            if(n==0)
            {
                return;
            }
            cout << n -> value << endl;
        }
        bool search ( Value x ) 
        {
            // search for a Value in the BST and return true iff it was found
            // FILL IN
            return finder(x, root);
        
        }
        void preorder()const 
        {
            preorderhelp(root);
            // Traverse and print the tree one Value per line in preorder.
            // FILL IN
        }
        void preorderhelp(Node* curr) const
        {
            if(curr != 0)
            {
                cout << curr -> value << endl;
                preorderhelp(curr-> left);
                preorderhelp(curr-> right);
            }
        }
        void postorder()const 
        {
            // Traverse and print the tree one Value per line in postorder
            // FILL IN
            postorderhelp(root);
        }
        void postorderhelp(Node* curr)const
        {
            if(curr != 0)
            {
                postorderhelp(curr->left);
                postorderhelp(curr-> right);
                cout << curr -> value << endl;
            }
        }
        void inorder()const 
        {
            // Traverse and print the tree one Value per line in inorder.
            // FILL IN
            inorderhelp(root);
        }
        void inorderhelp(Node* curr) const
        {
            if(curr!=0)
            {
                inorderhelp(curr->left);
                cout << curr -> value << endl;
                inorderhelp(curr-> right);
            }
        }
        Value& operator[] (int n) 
        {
            // returns reference to the value field of the n-th Node.
            // FILL IN
            int count = 0;
            return helpOp(root,n,count);
            
        }
        Value& helpOp(Node* curr, int n,int count)
        {
            return curr->value;
        }
        BST() : count(0), root(nil) {}
        
        void insert( Value X ) { root = insert( X, root ); }
        Node* insert( Value X, Node* T ) 
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
            T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
            T->left = insert( X, T->left );
            } else if ( X > T->value ) {
            T->right = insert( X, T->right );
            } else {
            T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                else 
                {
                    // X == T->value
                    if ( T->right != nil ) 
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                    else 
                    { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
        // later, rebalancing code will be installed here
        return T;
        }
        
        void okay( ) { okay( root ); }
        void okay( Node* T ) {
        // diagnostic code can be installed here
        return;
        }
        void minCover()
        {
            
            minCoverHelper(root);
             
        }
        void minCoverHelper(Node*curr)
        {
           if(curr->isLeaf())return;
           if(curr->left != 0)(minCoverHelper(curr-> left));
           if(curr->right != 0) minCoverHelper(curr-> right);
           if( curr->left !=0 && !curr->left->selected)
           {
               curr->selected = true;
           }
           else if(curr->right!=0 && !curr->right->selected)
           {
               curr->selected = true;
           }
          
        }
        void displayMinCover()
        {
            cout << "Part 1" << endl;
            displayMinCoverHelp(root);
            cout << endl;
            cout << counter<< endl;
        }
        void displayMinCoverHelp(Node* curr)
        {
            // if(!curr -> selected)
            // {
            //     displayMinCoverHelp(curr -> left);
            //     displayMinCoverHelp(curr-> right);
            //     return;
            // }
            if(curr!=0)
            {
                displayMinCoverHelp(curr->left);
                if(curr->selected)
                {
                    cout << curr -> value << ' ';
                    counter++;
                }
                displayMinCoverHelp(curr-> right);
            }
        }
        void findSumPath(Node* n, int sum, int buffer[])
        {
            cout << "Part 2" << endl;
            findSumPathHelper(root,sum,buffer);
            if(printCount == 0)
            {
                cout << 0 << endl;
                return;
            }
            for(int i = 0; i< printCount-1;++i)
            {
                int min = buffer[i];
                int minloc = i;
                for(int k = i; k < printCount-1;++k)
                {
                    if(min > buffer[k])
                    {
                        min = buffer[k];
                        minloc = k;
                    }
                }
                int temp = buffer[minloc];
                buffer[minloc] = buffer[i];
                buffer[i] = temp;
            }
            for(int i = 0; i < printCount-1; ++i)
            {
                cout << buffer[i] << ' ';
            }
           
          cout << endl;
            
        }
        void findSumPathHelper(Node* n, int sum, int buffer[])
        {
            if(currsum  > sum)
            {
                buffcount = 0;
                currsum = 0;
                // findSumPathHelper(root,sum,buffer);
                printCount = 0;
                return;
            }
            else if(currsum  == sum && n->isLeaf())
            {
                return;
            }
                currsum+= n->value;
                buffer[buffcount] = n->value;
                buffcount ++;
                printCount++;
                if(n->left!=0)
                findSumPathHelper(n->left,sum,buffer);
                if(n->right!=0)
                findSumPathHelper(n->right,sum,buffer);
                return;
                
                if(n->isLeaf())
                {
                    currsum = 0;
                    buffer[0] = 0;
                    printCount = 0;
                    return;
                }
            
            
        }
        void vertSum(Node* node, int hd, std::map<int, int>& m)
        {
            cout << "Part 3" << endl;
            int right = 0;
            int left = 0;
            vertSumHelper(node,m,left,right);
            for(auto i = m.begin(); i != m.end();++i)
            {
                cout << i->second << ' ';
            }
            cout << endl;
        }
        void vertSumHelper(Node* node, std::map<int,int>& m, int left1, int right1)
        {
            if(node != 0)
            {
                vertSumHelper(node->left, m, left1 + 1, right1 );
                vertSumHelper(node->right,m, left1, right1+1);
                int difference = right1 - left1;
                m[difference] = node -> value + m[difference];
            }
        }
        private:
        int counter = 0;
        int currsum = 0;
        int buffcount = 0;
        int printCount = 0;
            bool finder(Value x, Node* k)
            {
                if(k == 0)
                {
                    return 0;
                }
                if(x == k -> data)
                {
                    return k;
                }
                else if(x < k -> data)
                {
                    return finder(x, k->left);
                }
                else 
                    return finder(x, k-> right );
                    return 0;
                
            }
}; // BST
#endif