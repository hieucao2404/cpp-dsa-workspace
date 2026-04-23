/**
 * Give an implementation of the deque ADT using an array, so that each of
the update functions run in O(1) time.
 */

#include <iostream>

class Dequeue{
    private:
        int *arr;
        int front, rear, size, capacity;
    
    public:
        Dequeue(int cap) {
            capacity = cap;
            arr = new int[cap];
            front = -1;
            rear = -1;
            size = 0;
        }

        bool isFull() {
            return size == capacity;
        }

        bool isEmpty() {
            return size == 0;
        }

        //Insert at front
        void pushFront(int x){
            if(isFull()){
                std::cout << "Dequeue is full\n";
                return;
            }

            if(isEmpty()){
                front = rear = 0;
            } else {
                front = ( front - 1 + capacity) % capacity;
            }

            arr[front] = x;
            size++;
        }

        //Insert at rear
        void pushBack(int x) {
            if(isFull()){
                std::cout << "Dequeue is full\n";
                return;
            }

            if(isEmpty()){
                front = rear = 0;
            }else {
                rear = (rear + 1) % capacity;
            }

            arr[rear] = x;
            size++;
        }

        // Remove from front
    void popFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    // Remove from rear
    void popBack() {
        if (isEmpty()) {
            std::cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

};
using namespace std;
int main() {
    Dequeue dq(5);  // capacity = 5

    cout << "Push back 10, 20, 30\n";
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);

    cout << "Front: " << dq.getFront() << endl; // 10
    cout << "Rear: " << dq.getRear() << endl;   // 30

    cout << "\nPush front 5\n";
    dq.pushFront(5);

    cout << "Front: " << dq.getFront() << endl; // 5
    cout << "Rear: " << dq.getRear() << endl;   // 30

    cout << "\nPush back 40\n";
    dq.pushBack(40);

    cout << "Try pushing 50 (should be full):\n";
    dq.pushBack(50); // should trigger "full"

    cout << "\nPop front\n";
    dq.popFront();

    cout << "Front: " << dq.getFront() << endl;

    cout << "\nPop back\n";
    dq.popBack();

    cout << "Rear: " << dq.getRear() << endl;

    cout << "\nPop all elements:\n";
    dq.popFront();
    dq.popFront();
    dq.popFront();

    cout << "Try popping from empty deque:\n";
    dq.popFront(); // should trigger "empty"

    return 0;
}