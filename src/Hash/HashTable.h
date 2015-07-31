#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<class HashObject>
class HashTable
{
public:
    explicit HashTable(int size=100){}
    virtual ~HashTable();
    HashTable(const HashTable &rhs);
    bool contains(const HashObject & obj) const

private:
    vector< list<HashObject> > lists;
    int currentSize;
};

#endif
