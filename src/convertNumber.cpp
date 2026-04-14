#include <iostream>
#include <stack>
using namespace std;

// Function to convert decimal to base (2-27)
string convertBase(int number, int base)
{
    if (base < 2 || base > 27)
    {
        return "Invalid base";
    }

    stack<char> s;
    while (number > 0) {
        int remainder = number % base;

        //convert remainder to correct character
        if(remainder < 10) {
            s.push('0' + remainder);
        }
        else {
            s.push('A' + (remainder - 10));
        }

        number /= base;
    }

    //build result string
    string result = "";
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    int number, base;
    cout << "Enter decimal number: ";
    cin >> number;

    cout << "Enter base (2-27): ";
    cin >> base;
    
    cout << "Converted: " << convertBase(number, base) << endl;

    return 0;
}
