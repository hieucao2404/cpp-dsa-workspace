#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

//Funciton to applu operator
int applyOp(int a, int b, char op){
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;//assume b != 0
    }
    return 0;
}

//Evaluate postfiix expression
int evaluatePostfix(string expr){
    stack<int> st;
    stringstream  ss(expr);
    string token;

    while(ss >> token){
        //If number
        if(isdigit(token[0]) || (token[0] == '-' && token.size() > 1)){
            st.push(stoi(token));
        }
        //if operator
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int result = applyOp(a, b, token[0]);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string expr;

    cout << "Enter postfix expression (space separated): ";
    getline(cin, expr);

    int result = evaluatePostfix(expr);

    cout << "Result = " << result << endl;

    return 0;
}