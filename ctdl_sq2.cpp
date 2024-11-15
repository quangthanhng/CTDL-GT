#include <iostream>  // For input/output
#include <stack>     // For stack operations
#include <string>    // For string operations
#include <cctype>    // For isdigit() function
using namespace std;

// Function to determine precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;  // Lowest precedence
    if (c == '*' || c == '/')
        return 2;  // Higher precedence
    return 0;  // For other characters like parentheses
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix to postfix with step-by-step output
string infixToPostfix(string infix) {
    stack<char> st;  // Stack to hold operators and parentheses
    string postfix = "";  // Resultant postfix expression

    cout << "Step-by-step process of Infix to Postfix:\n";
    cout << "--------------------------------\n";

    // Loop through each character in the infix expression
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        cout << "Processing '" << c << "'...\n";

        // If the character is an operand (e.g., number), add it to the postfix string
        if (isdigit(c)) {  // Use isdigit for numbers
            postfix += c;
            cout << "Operand detected. Adding '" << c << "' to postfix expression.\n";
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            st.push(c);
            cout << "Opening parenthesis detected. Pushing '(' to the stack.\n";
        }
        // If the character is ')', pop and add to the postfix until '(' is found
        else if (c == ')') {
            cout << "Closing parenthesis detected. Popping from the stack until '(' is found.\n";
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                cout << "Popping '" << st.top() << "' from the stack and adding to postfix expression.\n";
                st.pop();
            }
            st.pop();  // Pop '(' from the stack
            cout << "Popped the '(' from the stack.\n";
        }
        // If the character is an operator
        else if (isOperator(c)) {
            cout << "Operator '" << c << "' detected. Checking precedence.\n";
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                cout << "Popping '" << st.top() << "' from the stack and adding to postfix expression (higher precedence).\n";
                st.pop();
            }
            st.push(c);  // Push the current operator to the stack
            cout << "Pushing '" << c << "' to the stack.\n";
        }

        // Display current postfix and stack status
        cout << "Current Postfix: " << postfix << "\n";
        cout << "Stack: ";
        stack<char> tempStack = st;  // Make a copy of the stack to print
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << "\n";
        cout << "--------------------------------\n";
    }

    // Pop all remaining operators from the stack
    cout << "Popping remaining operators from the stack.\n";
    while (!st.empty()) {
        postfix += st.top();
        cout << "Popping '" << st.top() << "' from the stack and adding to postfix expression.\n";
        st.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;  // Stack to hold operands

    cout << "\nStep-by-step process of Postfix Evaluation:\n";
    cout << "--------------------------------\n";

    // Loop through the postfix expression
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is an operand (number), push it to the stack
        if (isdigit(c)) {
            st.push(c - '0');  // Convert char to int by subtracting '0'
            cout << "Operand '" << c << "' detected. Pushing to the stack.\n";
        }
        // If the character is an operator, pop two operands and apply the operator
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result;

            if (c == '+') result = val1 + val2;
            else if (c == '-') result = val1 - val2;
            else if (c == '*') result = val1 * val2;
            else if (c == '/') result = val1 / val2;

            cout << "Operator '" << c << "' detected. Applying operation: "
                << val1 << " " << c << " " << val2 << " = " << result << "\n";
            st.push(result);  // Push the result back to the stack
        }

        // Display current stack status
        cout << "Stack: ";
        stack<int> tempStack = st;  // Make a copy of the stack to print
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << "\n--------------------------------\n";
    }

    // The final result is the only element remaining in the stack
    return st.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;  // Input the infix expression

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "\nFinal Postfix Expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "\nFinal Result: " << result << endl;

    return 0;
}