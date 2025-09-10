#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntNode {
    public:
    int info;
    IntNode *next;
    IntNode(int el, IntNode *ptr = 0) {
        info = el; next = ptr;
    }
};

class IntSLList {
    public:
    IntSLList() {
        head = tail =  0;
    }
    ~IntSLList();
    int isEmpty() {
        return head == 0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead(); //delet the head and return its infor
    int deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    private:
    IntNode *head, *tail;
};

#endif