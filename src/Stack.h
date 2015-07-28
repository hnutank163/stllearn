#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

template <class Object>
class Stack
{
private:
    struct Node
    {
        Object data;
        Node *next;
        Node(const Object &obj = Object(), Node *p=NULL):data(obj),next(p)
        {

        }
    };
public:
    Stack ():theSize(0),head(NULL){}
    virtual ~Stack (){};

    void push(const Object & obj)
    {
        head = new Node(obj, head);
        ++ theSize;
    }

    void pop()
    {
        if(empty())
            return;
         Node *old = head;
         head = head->next;
         delete old;
    }

    int size() const
    {
        return theSize;
    }

    Object & top()
    {
        return head->data;
    }

    bool  empty()
    {
         return theSize == 0;
    }

private:
    int theSize;
    Node *head;
};

#endif
