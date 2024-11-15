#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void print_stack() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void sort_odd_value() {
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;
        Node* current = top;

        while (current != nullptr) {
            if (current->value % 2 == 0) {
                if (evenHead == nullptr) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }
            } else {
                if (oddHead == nullptr) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }
            }
            current = current->next;
        }

        if (oddTail != nullptr) {
            oddTail->next = evenHead;
        }
        if (evenTail != nullptr) {
            evenTail->next = nullptr;
        }

        top = (oddHead != nullptr) ? oddHead : evenHead;
    }
};

int main() {
    Stack s;
    int n;
    bool check_first = true;
    while (true) {
        cin >> n;
        if (n == 0 && check_first == true) {
            cout << "Stack rong." << endl;
            break;
        }
        check_first = false;
        if (n == 0) {
            break;
        }
        s.push(n);
    }
    s.print_stack();
    s.sort_odd_value();
    s.print_stack();
    return 0;
}