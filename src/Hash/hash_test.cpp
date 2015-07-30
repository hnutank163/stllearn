#include <ext/hash_map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <tr1/unordered_map>
#include <ctime>
using namespace std::tr1;
using namespace std;
using namespace __gnu_cxx;

template< class Func>
void timer(Func func);

template<class TMap>
void insert_test(int size)
{
    TMap map;
    clock_t begin, tval;
    begin = clock();
    for(int i=0; i<size; i++)
        map.insert(make_pair(i,i));
    tval = clock() - begin;
    cout<<tval/1000000<<"s "<<(tval%1000000)/1000<<" ms"<<endl;

    begin = clock();
    typename TMap::iterator iter = map.find(234567);
    if( iter != map.end())
        cout<<"find it"<<endl;
    tval = clock() - begin;
    cout<<tval/1000000<<"s "<<(tval%1000000)/1000<<" ms"<<endl;
}

void test_hash_map()
{
    int size = 1024*3000;
    unordered_map<int, int> um;
    hash_map<int, int> hm;
    insert_test<hash_map<int,int> >(size);
    insert_test< unordered_map<int ,int> >(size);
}

int
main()
{
    test_hash_map();
}
