#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string str) {
    // create a stack
    stack<char> s;

    //push all char into that stack
    for (char c : str) {
        s.push(c);
    }

    //compare with original
    for(char c : str) {
        if(c != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string str = "mfdfadg";

    if (isPalindrome(str))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}