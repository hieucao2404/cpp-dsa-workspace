#include <iostream>
#include "intSLLst.hpp"

IntSLList::~IntSLList()
{
    for (IntNode *p; !isEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}
/** Add to head
 *  1/ An empty node is created. It is empty in the senset that program performing insertion does not assign any values to the data membsers of the node.
    2/ The node's info member ins initialized to a particular integer.
    3/ Because the node is being included at the front of the list, the next member becomes a pointer to the first node on the list, that is, the current value of head.
    4/ The enw precedes all the nodes onthe list, but this fact has to be reflected in the value of head; otherwise, the new ndoe is not accessible. Therefore, head is updated to become the pointer to the new node. */

void IntSLList::addToHead(int el)
{
    head = new IntNode(el, head);
    if (tail == 0)
        tail = head;
}

/** Add to tail
 *  1/ An empty node is created
    2/ The node's infopr member is initialize to an integer el
    3/ Because the ndoe is being included at the end of the list, the next member is set to null
    4/ The node is now included in the list by making the nexst member of the last node of the list a pointer to the newly created node
    5/ The new node follows all the nodes of the list, but this fact has to be reflected in the value of tail, which now becomse the pointer to the new node
 */

void IntSLList::addToTail(int el)
{
    if (tail != 0)
    {                                 // if list is not empty
        tail->next = new IntNode(el); // set tail to new ndoe
        tail = tail->next;            // move tail to the tail/null
    }
    else
        head = tail = new IntNode(el);
}

int IntSLList::deleteFromHead()
{
    int el = head->info;
    IntNode *tmp = head;
    if (head == tail) // if only one ndoe in the list
        head = tail = 0; // set head and tail to null
    else
        head = head->next; // move head to the 2nd element
    delete tmp;
    return el;
}

int IntSLList::deleteFromTail()
{
    int el = tail->info;
    if (head == tail)
    { // if only one node in the list
        delete head;
        head = tail = 0;
    }
    else
    // the predecessor has to be searched and found from the beginning of the list since node cant move backward
    {
        IntNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            ;
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el)
{
    if (head != 0)
        if (head == tail && el == head->info)
        { // if only one ndoe in the list
            delete head;
            head = tail = 0;
        }
        else if (el == head->info)
        { // if more than one node in the list
            IntNode *tmp = head->next;
            head = head->next;
            delete tmp;
        }
        else
        {
            IntNode *pred, *tmp;
            for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next)
                ;
            if (tmp != 0)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
}

bool IntSLList::isInList(int el) const
{
    IntNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
        ;
    return tmp != 0;
}
