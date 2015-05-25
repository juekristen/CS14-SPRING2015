//======================================================
//Name: Kristen Jue
//SID: 861149364
//Date: May 25,2015
//Approach: used chrono to test how long each insert or 
//find took and inputed it into a file. then graphed the
//representation. for my scrambler I made it so that
//random strings would be swaped. 
//=====================================================
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <algorithm>
void fillvctr(std::vector<std::string> &words,std::string file1)
{
    std::ifstream file;
    std::string word;
    file.open(file1.c_str());
    if(!file.is_open())
    {
        std::cout << "Could not open" << std::endl;
        exit(0);
    }
    file >> word;
    while(!file.eof())
    {
        words.push_back(word);
        file >> word;
    }
    file.close(); 
}

double tree_insert_time(int n,std::vector<std::string>wordvctr,std::set<std::string> &tree )
{
    using namespace std::chrono;
    
    steady_clock::time_point t1 = steady_clock::now();

    for(int i = 0; i < n;++i)
    {
        tree.insert(wordvctr.at(i));
    }
    steady_clock::time_point t2 = steady_clock::now();

    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(t2 - t1);

    return time_span.count();
}
double tree_query_time(int n,std::vector<std::string>wordvctr,std::set<std::string> tree )
{
    using namespace std::chrono;
   
    steady_clock::time_point t1 = steady_clock::now();

     for(int i = 0; i < n; ++i)
    {
        tree.find(wordvctr.at(i));
    }

    steady_clock::time_point t2 = steady_clock::now();

    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(t2 - t1);

    return time_span.count();
}
double hash_insert_time(int n,std::vector<std::string>wordvctr,std::unordered_set<std::string> &hash )
{
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();

    for(int i = 0; i < n;++i)
    {
        hash.insert(wordvctr.at(i));
    }
    steady_clock::time_point t2 = steady_clock::now();

    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(t2 - t1);

    return time_span.count();
}
double hash_query_time(int n,std::vector<std::string>wordvctr,std::unordered_set<std::string> hash )
{
    using namespace std::chrono;
    
    steady_clock::time_point t1 = steady_clock::now();

    for(int i = 0; i < n; ++i)
    {
        hash.find(wordvctr.at(i));
    }

    steady_clock::time_point t2 = steady_clock::now();

    duration<int,std::milli> time_span = duration_cast<duration<int,std::milli>>(t2 - t1);

    return time_span.count();
}
void scramble(std::vector<std::string> &words2scramble)
{
    srand(time(0));
    for(int i = 0; i < 50000; ++i)
    {
        int random = rand()% 50000;
        std::swap(words2scramble.at(i),words2scramble.at(random));
    }
}

int main()
{
    std::ofstream readdata;
    readdata.open("data.txt");
    if(!readdata)
    {
        std::cout << "Error opening " << "data.txt" << std::endl;
        exit(0);
    }
    double sumtree = 0;
    double sumhash = 0;
    double tree;
    double hash;
    double sumtquery = 0;
    double sumhquery = 0;
    double tquery;
    double hquery;
    std::vector<std::string> wordvctr;
    fillvctr(wordvctr,"words.txt");
    for(int i = 5000; i <= 50000; i += 5000)
    {
        std::set<std::string> treeset;
        std::unordered_set<std::string> hashset;
        scramble(wordvctr);
        //std::cout << i << ' ';
        readdata << i << ' ';
        tree = tree_insert_time(i,wordvctr,treeset);
        sumtree += tree;
        readdata << tree << ' ';
        //std::cout << tree << " ms ";
        hash = hash_insert_time(i,wordvctr,hashset);
        sumhash += hash;
        readdata << hash << ' ';
        //std::cout << hash << " ms ";
        tquery = tree_query_time(i,wordvctr,treeset);
        sumtquery += tquery;
        readdata << tquery << ' ';
        //std::cout << tquery << " ms ";
        hquery = hash_query_time(i,wordvctr,hashset);
        sumhquery += hquery;
        readdata << hquery << '\n';
        //std::cout << hquery << " ms\n";
       
    }
    // for(int i = 0; i < 25; ++i)
    // {
    //     std::cout << wordvctr.at(i) << ' ';
    // }
    // std::cout << std::endl;
   
}

