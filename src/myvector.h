#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#define SPACE_CAPACITY 128
#include <iterator>

template <class object>
class myvector
{
public:
    myvector (int initSize = 0);
    virtual ~myvector ();

    int size() const;
    int capacity() const;
    bool empty() const;

    myvector (const myvector &vec);
    const myvector operator= (const myvector & vec);
    void resize(int newSize);
    void reserve(int newCapacity);

    object &operator[](int index);

    void push_back(const object & obj);
    void pop_back();

typedef object * iterator;
typedef const object * const_iterator;

    iterator erase(iterator iter)
    {
        if( iter >= end() )
            return end();
        iterator olditer = iter + 1;
        iterator endptr = end();
        while( olditer < endptr )
        {
            *(olditer-1) = *olditer;
            olditer ++;
        }
        -- theSize;
        return iter;
    }

    iterator begin()
    {
        return &objects[0];
    }
    const_iterator begin() const
    {
        return &objects[0];
    }
    iterator end()
    {
         return &objects[theSize];
    }
    const_iterator end() const
    {
        return &objects[theSize];
    }


private:
    int theSize;
    int theCapacity;
    object *objects;
};

#endif
