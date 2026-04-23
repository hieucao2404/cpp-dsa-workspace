#include <iostream>
using namespace std;

class TwoColorStack{
    private:
        int *arr;
        int redTop;
        int blueTop;
        int capacity;
    
    public: 
        TwoColorStack(int n){
            capacity = n;
            arr = new int[n];
            redTop = -1;
            blueTop = n;
        }

        bool isFull() {
            return redTop + 1 ==  blueTop;
        }

        //Push Red
        void pushRed(int x) {
            if(isFull()){
                cout << "overflow\n";
                return;
            }
            arr[++redTop] = x;
        }

        void pushBlue(int x){
            if(isFull()){
                cout  << "Overflow!\n";
                return;
            }
            arr[--blueTop] = x;
        }

        //Pop Red 
        int popRed() {
            if(redTop == -1) {
                cout << "Red stack underflow\n";
                return  -1;
            }
            return arr[redTop--];
        }

        //Pop Blue
        int popBlue() {
            if(blueTop == capacity){
                cout << "Blue stack underflow\n";
                return -1;
            }
            return arr[blueTop++];
        }

        int topRed(){
            if(redTop == -1) return -1;
            return arr[redTop];
        }

        int topBlue(){
            if(blueTop == capacity) return -1;
            return arr[blueTop];
        }
};

int main() {
    TwoColorStack s(6);

    s.pushRed(10);
    s.pushRed(20);

    s.pushBlue(100);
    s.pushBlue(200);

    cout << "Top Red: " << s.topRed() << endl;   // 20
    cout << "Top Blue: " << s.topBlue() << endl; // 200

    cout << "Pop Red: " << s.popRed() << endl;
    cout << "Pop Blue: " << s.popBlue() << endl;

    return 0;
}