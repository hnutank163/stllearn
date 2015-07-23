#ifndef STL_COMM_H
#define STL_COMM_H

template <typename Container>
void RemoveEveryOtherItem(Container &lst)
{
    typename Container::iterator  iter = lst.begin();
    while( iter != lst.end() )
    {
        iter = lst.erase(iter);
        if( iter != lst.end() )
            ++ iter;
    }
}


template <typename T>
T smax(T t1, T t2)
{
    return t1>t2? t2 : t1;
}

#endif
