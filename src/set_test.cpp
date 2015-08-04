#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include <hashtable>
using namespace std;

void test_set()
{
    set<int> st;
    st.insert(2);
    st.insert(3);
    st.insert(1);

    for( set<int>::iterator iter = st.begin(); iter != st.end(); iter++ )
        cout<<*iter<<" ";
    cout<<endl;
}

int
main()
{
    test_set();
    return 0;
}
