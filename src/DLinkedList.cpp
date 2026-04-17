#include <string>

typedef std::string Elem; //list element type
class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};


class DLinkedList {
    public:
        DLinkedList();
        ~DLinkedList();

        bool empty() const;
        const Elem& front() const;
        const Elem& back() const;
        void addFront(const Elem& e);
        void addBack(const Elem& e);
        void removeFront();
        void removeBack();
    
    private:
        DNode* header;
        DNode* trailer;
    protected:  
        void add(DNode* v, const Elem& e);
        void remove(DNode* v);
};

DLinkedList::DLinkedList() {
    header = new DNode; //create sentinels
    trailer = new DNode; 
    header-> next = trailer;
    trailer-> prev = header;
}
DLinkedList::~DLinkedList(){
    while(!empty()) removeFront();
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const{
    return (header->next == trailer);
}

const Elem& DLinkedList::front() const{
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

//Insert new node before v
void DLinkedList::add(DNode* v, const Elem&e) {
    DNode* u = new DNode;
    u->elem = e; // create a new node
    u->next = v; //link u in bettween v
    u->prev = v->prev; //and v.prev
    v->prev->next = v->prev = u;
}

//Add to front of the list
void DLinkedList::addFront(const Elem& e){
    add(header->next, e);
}

void DLinkedList::addBack(const Elem& e){
    add(trailer, e);
}

//Remove a node V
void DLinkedList::remove(DNode* v){
    DNode* u = v->prev;
    DNode* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

//Remove from front
void DLinkedList::removeFront(){
    remove(header->next);
}

//Remove from the back
void DLinkedList::removeBack() {
    remove(trailer->prev);
}
