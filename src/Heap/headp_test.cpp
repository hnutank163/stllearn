#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template< class Contains>
void print_contains(Contains c)
{
    typename Contains::iterator iter = c.begin();
    while( iter != c.end() )
        cout<<*iter++<<" ";
    cout<<endl;
}

void test_heap()
{
    vector<int> vi;

    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(4);

    print_contains(vi);
    make_heap(vi.begin(), vi.end());
    cout<<vi.front()<<endl;
    pop_heap(vi.begin(), vi.end());
    vi.pop_back();
    cout<<vi.front()<<endl;
    pop_heap(vi.begin(), vi.end());
    vi.pop_back();
    cout<<vi.front()<<endl;
    pop_heap(vi.begin(), vi.end());
}

int
main()
{
    test_heap();
    return 0;
}
