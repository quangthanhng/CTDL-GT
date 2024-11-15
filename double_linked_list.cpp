#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DoubleLinkedList
{
    Node *pHead;
    Node *pTail;
    int length;
    DoubleLinkedList()
    {
        pHead = nullptr;
        pTail = nullptr;
        length = 0;
    }
    void insert_atHead(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = pHead;
        newNode->prev = nullptr;
        if (pHead != nullptr)
        {
            pHead->prev = newNode;
        }
        pHead = newNode;
        if (pTail == nullptr)
        {
            pTail = newNode;
        }
        length++;
    }
    void insert_atTail(int value)
    {
        Node *newNode = new Node(value);
        newNode->data = value;
        newNode->prev = pTail;
        newNode->next = nullptr;
        if (pTail != nullptr)
        {
            pTail->next = newNode;
        }
        pTail = newNode;
        if (pHead == nullptr)
        {
            pHead = newNode;
        }
        length++;
    }
    void displayForward() {
        Node* temp = pHead;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = pTail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{

}