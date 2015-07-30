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
    HashTable();
    virtual ~HashTable();
    HashTable(const HashTable &rhs);

private:
    vector< list<HashObject> > lists;
    int currentSize;
};

#endif
