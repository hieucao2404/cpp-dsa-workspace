template<typename E>
class SNode {
    private: 
        E elem; //linked list element value
        SNode<E>* next;// next item in the list
        friend class SLinkedList<E>; //provide SLinkedList access
};


template<typename E>
class SLinkedList {
    public:
        SLinkedList();
        ~SLinkedList();
        bool empty() const;
        const E& front() const;
        void addFront(const E& e);
        void removeFront();
    private:
        SNode<E>* head; //head of the lsit
};

//constructor
template<typename E>
SLinkedList<E>::SLinkedList() : head(NULL) { }

//is list empty
template<typename E>
bool SLinkedList<E>::empty() const{
    return head == NULL;
}

//return front element
template<typename E>
const E& SLinkedList<E>::front()  const{
    return head->elem; //return front element
}

// destructor
template <typename E>
SLinkedList<E>::~SLinkedList(){
    while(!empty*() removeFront());
}

// Add to front of list
template<typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNone<E>* v = new SNode<E>; // create new node
    v->elem = e; // store data
    v->next = head; // head now follow the new node
    head = v; // v is now the head
}

template<typename E>
void SLinkedList<E>::removeFront(){
    SNode<E>* old = head;
    head = old->next;
    delete old;
}