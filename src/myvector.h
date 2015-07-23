#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#define SPACE_CAPACITY 128


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

private:
    int theSize;
    int theCapacity;
    object *objects;
};

#endif
