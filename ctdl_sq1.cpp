#include <iostream>
using namespace std;

struct Node {
public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

struct Stack {
public:
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(int value) {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack rong." << endl;
            return;
        }
        cout << "Cac gia tri co trong stack la: ";
        Node *current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int x;
    cin >> x;

    while (true) {
        int a;
        cin >> a;
        if (a == 0) break;
        if (a == x) {
            s.pop();
        } else {
            s.push(a);
        }
    }

    s.printStack();
    for (Node* temp = s.top; temp != NULL && temp->next != NULL; ) {
    if (temp->next->data == 4) {
        Node* p = temp->next;
        temp->next = temp->next->next;
        delete p;
    } else {
        temp = temp->next;  // Move to the next node only if no deletion happens
    }
}
    if(s.isEmpty()){
        cout << "Stack rong." << endl;
    } else {
        s.printStack();
    }
    return 0;
}