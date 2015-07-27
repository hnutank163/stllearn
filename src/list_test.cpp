#include <list>
#include <iostream>
#include <iterator>
#include "List.h"
using namespace std;

template <class LIST>
static void print_list(LIST &li)
{
    typename LIST::iterator iter = li.begin();
    while(iter != li.end())
    {
        cout<<" "<<*iter;
        ++iter;
    }
    cout<<endl;
}

void test_List()
{
    List<int> li;
    for (int i = 0; i < 5; ++i) {
        li.push_back(i+1);
    }
    List<int>::iterator iter = li.begin();
    ++iter;
    li.push_front(10);
    li.push_back(100);
    li.insert(iter,50);
    li.insert(iter,60);
    print_list(li);
    li.erase(iter);
    print_list(li);
}

void test()
{
    list <int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    list<int>::iterator iter = li.begin();
    ++iter;
    li.insert(iter, 10);
    li.insert(iter, 20);
    print_list(li);
}

int
main(int argc, char ** argv)
{
    test();
    test_List();
}
