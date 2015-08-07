#ifndef _BINARY_HEAP
#define _BINARY_HEAP

#include <vector>
#include <iostream>
using namespace std;

template <class Object>
class BinaryHeap
{
public:
    BinaryHeap (int capacity=100);
    BinaryHeap(const vector<Object> & items);
    virtual ~BinaryHeap ();
    bool isempty() const {return array.size() == 0;}
    const Object &findMin() const;

    void insert(const Object & obj);
    void deleteMin();
    void deleteMin(Object & itenMin);
    void makeEmpty();

private:
    int theSize;
    vector<Object> array;
};


template<class Object>
void BinaryHeap<Object>::insert(const Object &obj)
{
     if( theSize == this->array.size()-1 )
         array.resize(array.size() * 2);

     int loc = theSize;

     for(; loc>1 && array[loc/2] > obj; loc /= 2)
         array[loc] = array[loc/2];
    array[loc] = obj;
}

template<class Object>
void BinaryHeap<Object>::deleteMin()
{
    if( isempty() )
        return;

    Object item = array[theSize - 1];
    int loc = 0;
    for(; loc < theSize-1 && array[loc*2+1] < item; loc = loc*2+1 )
        array[loc] = array[loc*2+1];

    array[loc] = item;
}

#endif
