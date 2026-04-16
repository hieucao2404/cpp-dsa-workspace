#include <string>

class StringNode
{
private:
    std::string elem;
    StringNode* next;

    friend class StringLinkedList;
};


class StringLinkedList{
    public:
        StringLinkedList();
        ~StringLinkedList();
        bool empty() const;
        const std::string& front() const;
        void addFront(const std::string& e);
        void removeFront();
    private:
        StringNode* head;
};


//Constructor
StringLinkedList::StringLinkedList() : head(NULL) {}

//Destructor 
StringLinkedList::~StringLinkedList(){
    while (!empty()) removeFront();
}

//is list empty
bool StringLinkedList::empty() const {
    return head == NULL;
}

// get front element
const std::string& StringLinkedList::front() const {
    return head->elem;
}

/** CREATE NEW NODE
 * 1. Create a new node, and set its elem value to the desired string and set its next link to point to the current head of the list
 * 2. The set head to point to th new node
 *  
*/
void StringLinkedList::addFront(const std::string& e) {
    // Add to front of list
    //create new node
    StringNode* v = new StringNode;
    //store data
    v->elem = e;
    //head now follows v
    v->next = head;
    head = v; // v is now the head
}

/** DELETE NODE
 * 1. Save a pointer to the old head node and advance the head pointer to the next node in the list
 * 2. Delete the old head node
 */
void StringLinkedList::removeFront() {
    StringNode* old = head; //save current head
    head = old->next;  //skip over old head
    delete old; // delete the old head
}

