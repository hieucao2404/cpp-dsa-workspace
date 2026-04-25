#include <string>
#include <queue>
#include <iostream>
#include "CircularLinkedList.hpp"
#include "QueueEmpty.hpp"

typedef string Elem;
class LinkedQueue{
    public:
        LinkedQueue();
        int size() const;
        bool empty() const;
        const Elem& front() const;
        void enqueue(const Elem& e);
        void dequeue();
    private:
        CircleList C;
        int n;
};

//Constructor
LinkedQueue::LinkedQueue() :  C(), n(0) {};


int LinkedQueue::size() const {
    return n;
}

bool LinkedQueue::empty() const {
    return n == 0;
}

const Elem& LinkedQueue::front() const{
    if(empty()){
        throw QueueEmpty("front of empty queue");
    }
    return C.front();
}

void LinkedQueue::enqueue(const Elem& e){
    C.add(e);
    C.advance();
    n++;
}

void LinkedQueue::dequeue(){
    if(empty()){
        throw QueueEmpty("dequeue of empty queue");
    }
    C.remove();
    n--;
}


int main() {
    LinkedQueue q;

    std::cout << std::boolalpha;
    std::cout << "Initially empty: " << q.empty() << '\n';

    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");

    std::cout << "Size after 3 enqueues: " << q.size() << '\n';
    std::cout << "Front: " << q.front() << '\n';

    q.dequeue();
    std::cout << "Front after 1 dequeue: " << q.front() << '\n';
    std::cout << "Size now: " << q.size() << '\n';

    q.dequeue();
    q.dequeue();

    std::cout << "Empty after removing all: " << q.empty() << '\n';

    try {
        q.dequeue();
    } catch (const QueueEmpty& e) {
        std::cout << "Caught expected exception: " << e.what() << '\n';
    }

    return 0;
}