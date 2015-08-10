#include "Sort.cpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

template<class Contains>
void print_contains(Contains & con)
{
    typename Contains::iterator iter = con.begin();
    while( iter != con.end() )
    {
        cout<<*iter++<<" ";
    }
    cout<<endl;
}

void test_sort(char *num, string name)
{
    clock_t begin;
    vector<int> vi;
    int size = atoi(num);
    srand(time(NULL));
    for(int i=0 ;i<size; i++)
    {
        vi.push_back(rand()%size);
    }
    begin = clock();
    if(name=="bubble")
        bubble_sort(vi.begin(), vi.end());
    else if(name == "quick")
        quick_sort(vi.begin(),vi.end());
    else if(name=="shell")
        shell_sort(vi.begin(), vi.end());
    else if(name=="merge")
        merge_sort(vi.begin(), vi.end());
    else if(name=="insert")
        insert_sort(vi.begin(), vi.end());
    clock_t val = clock() - begin;
    cout<<val/1000<<"ms"<<endl;
}

int
main(int argc, char **argv)
{
    int a[] = {3,2,0,3,0};
    int size = sizeof(a) / sizeof(int);
    quick_sort(a, a+size);
    for(int i=0; i<size; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    test_sort(argv[1],argv[2]);
    return 0;
}
