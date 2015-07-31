#include <ext/hash_map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
#include <tr1/unordered_map>
#include <ctime>

using namespace std::tr1;
using namespace std;
using namespace __gnu_cxx;

template< class Func>
void timer(Func func);

class person
{
public:
    person(int age=18, char *name=NULL): age(age), name(name){}

    friend ostream & operator<< (ostream & os, const person & per)
    {
        os<<per.name<<" age "<<per.age;
        return os;
    }

    bool operator==(const person &obj) const
        {
            return (this->age==obj.age) &&( 0== strcmp(this->name, obj.name) );
    }

    bool operator< (const person &obj)
    {
        return hash() < obj.hash();
    }

    int hash() const
    {
        return age;
    }
private:
    int age;
    char *name;
    friend class MyHash;
};

class MyHash
{
public:
    size_t operator()(const person &x) const
    {
        return x.age;
    }
};

void test_hash_map()
{
    unordered_map <person, const char *, MyHash> um;
    char name1[] = "dhy";
    char name2[] = "tx";
    char name3[] = "fyw";
    person dhy = person(28, name1);
    person tx = person(24, name2);
    person fyw = person(46, name3);

    um.insert(make_pair(dhy, "tomato"));
    um.insert(make_pair(tx, "potato"));
    um.insert(make_pair(fyw, "carrot"));

    cout<<fyw<<" like eat "<<um[fyw]<<endl;
}

int
main()
{
    test_hash_map();
}
