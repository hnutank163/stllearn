#include "Sort.cpp"
#include <iostream>
#include <vector>
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

void test_bubble_sort()
{
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(2);
    vi.push_back(1);
    vi.push_back(5);
    vi.push_back(20);
    vi.push_back(11);
    quick_sort(vi.begin(), vi.end());
   // bubble_sort(vi.begin(), vi.end());
    print_contains(vi);
}

int
main()
{
    int a[] = {2,1,3,4,6};

    quick_sort(a, a+5);
    for(int i=0; i<5; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    test_bubble_sort();
    return 0;
}
