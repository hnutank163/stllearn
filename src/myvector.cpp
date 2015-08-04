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
    operator=(vec);
}

template <class object>
const myvector<object> myvector<object>::operator=(const myvector & vec)
{
    if( this != vec ) //not itself
    {
        delete [] objects;
        this->theSize = vec.theSize;
        theCapacity = vec.theCapacity;
        objects = new object[theCapacity];

        for (int i = 0; i < theSize; ++i) {
            objects[i] = vec[i];
        }
    }

    return *this;
}

template <class object>
void myvector<object>::resize(int newSize)
{
    if( newSize > theCapacity ) //when need more space
        reserve( newSize * 2 + 1 );

    theSize = newSize;
}

template <class object>
void myvector<object>::reserve(int newCapacity)
{
     if( newCapacity < theCapacity )
         return;

     object * oldObj = objects;
     objects = new object[newCapacity];

     for (int i = 0; i < size(); ++i) {
         objects[i] = oldObj[i];
     }

     theCapacity = newCapacity;

     delete [] oldObj;
}

template <class object>
object & myvector<object>::operator[](int index )
{
    return objects[index];
}

template<class object>
void myvector<object>::push_back(const object &obj)
{
    if(theSize >= theCapacity )
        reserve(2*theCapacity + 1);

    objects[theSize ++ ] = obj;
}

template <class object>
void myvector<object>::pop_back()
{
    --theSize;
}


