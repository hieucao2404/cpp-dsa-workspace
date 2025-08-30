#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack top: " << s.top() << endl;
    s.pop();
    cout << "After pop, new top: " << s.top() << endl;

    return 0;
}
