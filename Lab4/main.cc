//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: May 4,2015
//======================================================
#include "lab4.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: <max size>\n";
        return -1;
    }
    priority_queue p;
    int k =std::atoi(argv[1]);
    preOrder(k);
    postOrder(k);
    p.sortedOrder(k);
    return 0;
}