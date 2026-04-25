#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <string>
using namespace std;

typedef string Elem; // element type

class CNode
{
private:
    Elem elem;
    CNode *next;

    friend class CircleList;
};

class CircleList
{
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem &front() const;
    const Elem &back() const;
    void advance();
    void add(const Elem &e);
    void remove();

private:
    CNode *cursor;
};

// Implementation
inline CircleList::CircleList() : cursor(NULL) {}

inline CircleList::~CircleList()
{
    while (!empty())
    {
        remove();
    }
}

inline bool CircleList::empty() const
{
    return cursor == NULL;
}

// Element at cursor
inline const Elem &CircleList::back() const
{
    return cursor->elem;
}

// Elemment following curor
inline const Elem &CircleList::front() const
{
    return cursor->next->elem;
}

// Advance cursor
inline void CircleList::advance()
{
    cursor = cursor->next;
}

// Add after cursor
inline void CircleList::add(const Elem &e)
{
    CNode *v = new CNode;
    v->elem = e;
    if (cursor == NULL)
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }
}

// Remove the Node after cursor
inline void CircleList::remove()
{
    if (cursor == NULL)
    {
        return;
    }
    CNode *old = cursor->next;
    if (old == cursor)
    {
        cursor = NULL;
    }
    else
    {
        cursor->next = old->next;
    }
    delete old;
}

#endif