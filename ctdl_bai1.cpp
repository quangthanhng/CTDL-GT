#include <iostream>

using namespace std;
//6 29 -91 47 88 44 5

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {};
};

void add(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void print_Node(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    int index;
    cin >> index;
    if (index == 0)
    {
        cout << "Danh sach rong.";
    }
    else
    {
        while (index != 0)
        {
            add(head, index);
            cin >> index;
        }
        cout << "Danh sach vua nhap la: "; 
        print_Node(head);
    }
}