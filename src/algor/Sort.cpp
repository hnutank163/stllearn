#include "Sort.h"
#include <iostream>
using namespace std;

template<class T>
inline static void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b= tmp;
}

template<class Iterator>
void insert_sort(Iterator begin, Iterator end)
{
    Iterator out, in, tmp;
    for( out=begin+1; out != end; ++out )
    {
        tmp = out;
        for( in=tmp; in > begin && *tmp < *(in-1); --in) //same like can't store value of *out..?
        {
            Swap(*tmp, *(in-1));            //not sure the value's type, so swap it and assign tmp to in-1
            tmp = in-1;
        }
    }
}

template<class Iterator>
void bubble_sort(Iterator begin, Iterator end)
{
    for(Iterator out=end; out != begin; --out)
    {
        for( Iterator in=begin; in < out-1; ++in )
        {
            if( *in > *(in+1) )
                Swap(*in, *(in+1));
        }
    }
}

template<class Iterator>
void quick_sort(Iterator begin, Iterator end)
{
    Iterator first = begin+1, last = end-1;
    Iterator tmp = begin;
    while( first<=last )
    {
        while( *first < *tmp )
            ++first;

        while( *last > *tmp )
            --last;
        if( first < last && first < end && last > begin )
        {
            Swap(*first, *last);
        }
    }

    Swap(*begin, *last);
    if( begin < last-1)
        quick_sort(begin, last);
    if( last+1 < end )
        quick_sort(last+1, end);
}

template<class Iterator>
void merge_sort(Iterator begin, Iterator end)
{

}

template<class Iterator>
void _merge_sort(Iterator begin, Iterator mid, Iterator end)
{
    Iterator i = begin;
    Iterator j = mid;

    while( i<mid && j<end )
    {

    }
}
