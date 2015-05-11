//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: May 11,2015
//======================================================
#include "lab5.h"

int main()
{
    BST<int> k;
    std::map<int,int> lab;
    //k.Node <int> l;
    int test[1000];
    
    k.insert(50);
    k.insert(20);
    k.insert(10);
    k.insert(40);
    k.insert(35);
    k.insert(45);
    k.insert(60);
    k.insert(70);
    //k.preorder();
    //k.inorder();
    k.minCover();
    k.displayMinCover();
    k.findSumPath(k.root,80,test);
    k.vertSum(k.root,1,lab);

    return 0;
}