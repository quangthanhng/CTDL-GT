#include <iostream>
#include<string>
#include<math.h>
using namespace std;

class Node {
public:
    char value;
    Node* next;
    Node(char val) : value(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int icount1;
    int icount2;
public:
    Stack() {
        top = NULL;
        icount1 = 0;
        icount2 = 0;
    }

    void push(char val) {
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
    
    int count(){
        for(Node* p = top; p != NULL; p = p->next){
            if(p->value == '['){
                icount1++;
            }else if(p->value == ']'){
                icount2++;
            }
        }
        return abs(icount1 - icount2) * 2;
    }
};


int main() {
    Stack s;
    string name;
    cin >> name;
    for(int i = 0; i < name.length(); i++){
        s.push(name[i]);
    }
    s.print_stack();
    cout << s.count();
    return 0;
}