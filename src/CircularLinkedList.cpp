#include <iostream>
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

CircleList::CircleList() : cursor(NULL)
{
}

CircleList::~CircleList()
{
    while (!empty())
        remove();
}

bool CircleList::empty() const
{
    return cursor == NULL;
}

// Element at cursor
const Elem &CircleList::back() const
{
    return cursor->elem;
}
// element following curosr
const Elem &CircleList::front() const
{
    return cursor->next->elem;
}

// Advance cursor
void CircleList::advance()
{
    cursor = cursor->next;
}

// Add after cursor
void CircleList::add(const Elem &e)
{
    CNode *v = new CNode; // crate a new node
    v->elem = e;
    if (cursor == NULL) // is list empty?
    {
        v->next = v; // v points to itself
        cursor = v;  // curosr points to v
    }
    else
    {
        v->next = cursor->next; // list is nonempty
        cursor->next = v;       // Link in v after cursor
    }
}

// Remove the Node after cursor
void CircleList::remove()
{
    CNode *old = cursor->next;
    if (old == cursor)
    {                  // is this the only node?
        cursor = NULL; // removing the only node, List is now empty
    }
    else
    {
        cursor->next = old->next; // link out the old node
    }
    delete old;
}

int main()
{
    CircleList playList;

    cout << "Create playlist\n";
    cout << "Playlist is empty: yes\n\n";

    cout << "Add: Stayin Alive\n";
    playList.add("Stayin Alive");
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Add: Le Freak\n";
    playList.add("Le Freak");
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Add: Jive Talkin\n";
    playList.add("Jive Talkin");
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Advance cursor once\n";
    playList.advance();
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Advance cursor again\n";
    playList.advance();
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Remove node after cursor\n";
    playList.remove();
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Add: Disco Inferno\n";
    playList.add("Disco Inferno");
    cout << "Front: " << playList.front() << "\n";
    cout << "Back: " << playList.back() << "\n\n";

    cout << "Done\n";
    return EXIT_SUCCESS;
}