#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include "stl_comm.h"
#include "myvector.cpp"
using namespace std;

static void test_erase_time(int n)
{
    myvector<int> mvi;
    vector <int> vi;
    list <int> li;
    clock_t begin, tval;
    for (int i = 0; i < n; ++i) {
        vi.push_back(i);
        li.push_back(i);
        mvi.push_back(i);
    }

    begin = clock();
    RemoveEveryOtherItem(vi);
    tval = clock() - begin;
    cout<<n<<" items vector erase time is "<<tval/1000000<<" s "<<tval%1000<<" ms"<<endl;
    begin = clock();
    RemoveEveryOtherItem(li);
    tval = clock() - begin;
    cout<<n<<" items list erase time is "<<tval/1000000<<" s "<<tval%1000<<" ms"<<endl;
    begin = clock();
    RemoveEveryOtherItem(mvi);
    tval = clock() - begin;
    cout<<n<<" items myvector erase time is "<<tval/1000000<<" s "<<tval%1000<<" ms"<<endl;
}

int
main(int argc, char ** argv)
{
    test_erase_time(atoi(argv[1]));
}
