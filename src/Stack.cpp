#include "getStack.hpp"
#include <string>
#include <iostream>

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
    return ch = '+' || ch == '-' || ch == '*' || ch == '/';
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
    
    return 0;
}