#ifndef _LIST_H
#define _LIST_H


#include <iostream>

template <class Object>
class List
{
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;

        Node ( const Object &obj = Object() , Node *p = NULL, Node *n = NULL )
            :data(obj),prev(p),next(n){}
    };
public:
    class const_iterator
    {
        public:
            const_iterator():cur(NULL){}
            const_iterator(Node *p):cur(p){}

            const_iterator & operator++ ()
            {
                cur = cur->next;
                return *this;
            }       //front ++

            const_iterator & operator++ (int)
            {
                const_iterator old = *this;
                ++(*this);
                return old;
            }   //back ++

            bool operator==( const const_iterator & iter ) const
            {
                 return (cur == iter.cur);
            }

            bool operator!=(const const_iterator & iter) const
            {
                return (cur != iter.cur);
            }

            const Object & operator*() const
            {
                 return cur->data;
            }

        public:
            Node * cur;
            friend class List<Object>;
    };

    class iterator:public const_iterator
    {
        public:
            iterator(){}
            iterator(Node * p):const_iterator(p){}
            Object & operator*(){ return this->cur->data;}
            iterator & operator++()
            {
                 this->cur = this->cur->next;
                 return *this;
            }

            iterator & operator++(int )
            {
                iterator old = *this;
                ++(*this);
                return old;
            }
            friend class List<Object>;
    };

public:
    List ()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    virtual ~List ()
    {

    }
    int size() const{ return this->theSize; }
    bool  empty() const{ return theSize == 0; };
    iterator begin()
    {
         return iterator(head->next);  //head ptr not store dat:w
    }

    iterator end()
    {
        return iterator(tail);
    }

    const_iterator end() const
    {
        return const_iterator(tail);
    }
    Object & front()
    {
        return *begin();
    }

    Object & back()
    {
         return *tail();
    }

    iterator insert(iterator  iter, const Object & obj) //don't use iterator & iter, because non-const reference can't bind temporary objects
    {
         Node *p = iter.cur;
         Node *tmp =new Node(obj, p->prev, p);
         p->prev->next = tmp;
         p->prev = tmp;
         ++ theSize;
         return iter;
    }

    iterator erase(const iterator &iter)
    {
        Node *p = iter.cur;
        iterator rval(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        -- theSize;
        return rval;
    }

    void push_front(const Object & obj)
    {
         insert(begin(), obj);
    }

    void push_back(const Object & obj)
    {
        insert(end(), obj);
    }

    void pop_front()
    {
         erase(begin());
    }

    void pop_back()
    {
        erase(end());
    }


private:
    Node *head;
    Node *tail;
    int theSize;
};

#endif
