#include "getStack.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

/**
 * Problem Statement
Check if a string of parentheses (), brackets [], and braces {} are properly balanced.

A string is balanced if:

Every opening bracket has a matching closing bracket
Brackets are in the correct order (no ([)] crossing)
Every closing bracket matches the most recent unmatched opening bracket
Examples:

"(())" → ✅ Valid
"()[]{}" → ✅ Valid
"([{}])" → ✅ Valid
"([)]" → ❌ Invalid (crossing)
"(((" → ❌ Invalid (unclosed)
"())" → ❌ Invalid (extra closing)

 */

using namespace std;

bool isBalanced(const string &str)
{
    Stack<char> stk;

    for (char ch : str)
    {
        // push the opening brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            stk.push(ch);
        }

        // Chech the closing bracket
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // no matching opening bracket
            if (stk.isEmpty())
            {
                return false;
            }

            char opening = stk.pop();

            if ((ch == ')' && opening != '(') ||
                (ch == ']' && opening != '[') ||
                (ch == '}' && opening != '{'))
            {
                return false;
            }
        }
    }
    return stk.isEmpty();
}

/**
 * Problem Statement
Convert mathematical expressions from infix notation to postfix notation.

Infix: 3 + 4 * 2 (standard notation we use)
Postfix: 3 4 2 * + (no parentheses needed; operators come after operands)
Why Postfix?

No parentheses needed
Easier for computers to evaluate
Directly usable with a stack
Examples:

2 + 3 → 2 3 +
2 + 3 * 4 → 2 3 4 * + (respects operator precedence)
(2 + 3) * 4 → 2 3 + 4 * (parentheses override precedence)
a / b + c * d → a b / c d * +

 */

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperand(char ch) {
    return isalnum(ch);
}
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
//Convert infix to postfix
string infixToPostfix(const string& infix) {
    Stack<char> opStack;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        //skip spaces
        if(ch == ' ') continue;

        //Operand: add directly to output
        if(isOperand(ch)){
            postfix += ch;
            postfix += ' ';
        }
        //Opening paranthesis: push to stack
        else if(ch == '('){
            opStack.push(ch);
        }
        //Closing: pop until match (
        else if(ch == ')'){
            while(!opStack.isEmpty() && opStack.topEl() != '('){
                postfix += opStack.pop();
                postfix += ' ';
            }
            if(!opStack.isEmpty()){
                opStack.pop(); //remove the '('
            }
        }
        //Operator:pop based on precendence
        else if(isOperator(ch)){
            while(!opStack.isEmpty() && opStack.topEl() != '(' && 
        getPrecedence(opStack.topEl()) >= getPrecedence(ch)){
            postfix += opStack.pop();
            postfix += ' ';
        }
        opStack.push(ch);
        }
    }

    //Pop remaining operators
    while(!opStack.isEmpty()) {
        postfix += opStack.pop();
        postfix += ' ';
    }
    return postfix;
}

/**
 * Calculate the result of a postfix (Reverse Polish Notation) expression.

Input: 2 3 + → Output: 5
Input: 2 3 4 * + → Output: 14 (because 3 * 4 = 12, then 2 + 12 = 14)
Input: 5 2 / 3 + → Output: 5.5 (5 / 2 = 2.5, then 2.5 + 3 = 5.5)
Why Postfix is Easy to Evaluate:

No precedence rules to worry about
Just use a stack: push operands, pop when you see an operator
Examples:

2 3 + → 2 3 + = 5
2 3 4 * + → 2 (3 4 *) + = 2 12 + = 14
10 5 / 2 + → (10 5 /) 2 + = 2 2 + = 4
 */

double applyOperator(double left, double right, char op) {
    switch(op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/':
            if(right == 0) throw runtime_error("Divisioon by zero ?!?");
            return left/ right;
        default: throw runtime_error("Unknown operator");
    }
}

// Evaluate postfix expression
double evaluatePostfix(const string& postfix) {
    Stack<double> numStack;
    stringstream ss(postfix);
    string token;

    while(ss >> token){
        // single charactore operand
        if(token.length() == 1 && isOperand(token[0])){
            numStack.push(stod(token));
        }

        //Multi-digit number or operator
        else if(isOperator(token[0])){
             if (numStack.isEmpty()) {
                throw runtime_error("Invalid postfix expression: not enough operands");
            }
            
            double right = numStack.pop();
            
            if (numStack.isEmpty()) {
                throw runtime_error("Invalid postfix expression: not enough operands");
            }
            double left = numStack.pop();
            double result = applyOperator(left, right, token[0]);
            numStack.push(result);
        }
        else {
            //Multi-digi numbner
            numStack.push(stod(token));
        }
    }
    if(numStack.isEmpty()) {
        throw runtime_error("Invalid postfix expression: empty");
    }
    return numStack.pop();
}


int main() {
    // Test cases
    vector<string> tests = {
        "(())",           // ✅
        "()[]{}" ,        // ✅
        "([{}])",         // ✅
        "([)]",           // ❌ crossing
        "(((",            // ❌ unclosed
        "())",            // ❌ extra closing
        "{[()]}",         // ✅
        "[({})]",         // ✅
    };
    
    for (const string& test : tests) {
        cout << "\"" << test << "\" -> " 
             << (isBalanced(test) ? "Valid" : "Invalid") << endl;
    }

    vector<string> test2 = {
        "2 + 3",
        "2 + 3 * 4",
        "(2 + 3) * 4",
        "a / b + c * d",
        "((a + b) * c - d / e) * (f + g)",
        "2 * 3 + 4",
    };
    
    cout << "Infix to Postfix Conversion:\n" << string(50, '-') << endl;
    
    for (const string& test : test2) {
        string result = infixToPostfix(test);
        cout << "Infix:   " << test << endl;
        cout << "Postfix: " << result << endl;
        cout << endl;
    }

    vector<pair<string, double>> test3 = {
        {"2 3 +", 5},
        {"2 3 4 * +", 14},
        {"10 5 / 2 +", 4},
        {"15 7 1 1 + - / 3 * 2 1 1 + + -", 5},
        {"100 50 -", 50},
        {"2 2 *", 4},
    };
    
    cout << "Evaluate Postfix Expression:\n" << string(50, '-') << endl;
    
    for (const auto& test : test3) {
        try {
            double result = evaluatePostfix(test.first);
            cout << "Postfix: " << test.first << endl;
            cout << "Result:  " << result;
            cout << "  (Expected: " << test.second << ")";
            cout << (abs(result - test.second) < 0.0001 ? " ✅" : " ❌") << endl;
            cout << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cout << endl;
        }
    }
    
    return 0;
}