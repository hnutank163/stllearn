#include "myvector.h"

template <class object>
myvector<object>::myvector(int initSize):theSize(initSize),theCapacity(initSize+128)
{
    this->objects = new object[theCapacity];
}

template <class object>
myvector<object>::~myvector()
{
    delete [] objects;
}

template <class object>
int myvector<object>::size() const
{
    return theSize;
}

template <class object>
int myvector<object>::capacity() const
{
    return theCapacity;
}

template <class object>
myvector<object>::myvector(const myvector & vec)
{
     if( this != vec )
     {
         delete [] this->objects;
         this->theSize = vec.theSize;
     }
}

void test()
{
    myvector <int> mv;

}
