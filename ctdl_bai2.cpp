#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Linked_list
{
    Node *tail = NULL;
    Node *head = NULL;
    int length = 0;
};

void insert(Linked_list *list, int x)
{
    list->length++;
    Node *newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void duyet(Linked_list *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
// Danh sach vua nhap la: 6 29 6 47 6 47 5
void frequency(Linked_list *list)
{
    for (Node *p = list->head; p != NULL; p = p->next)
    {
        int count = 1;
        for (Node *q = p; q->next != NULL;)
        {
            if (p->data == q->next->data)
            {
                count++;
                Node *k = q->next;
                q->next = q->next->next; // Bỏ qua node trùng lặp
                delete k;                // Giải phóng bộ nhớ node bị xóa
                list->length--;
            }
            else
            {
                q = q->next;
            }
        }
        cout << p->data << ": " << count << endl;
    }
}

int main()
{
    Linked_list list;
    int value;
    bool check_first = true;

    while (true)
    {
        cin >> value;
        if (value == 0 && check_first == true)
        {
            cout << "Danh sach rong.";
            return 0;
        }
        check_first = false;
        if (value == 0)
            break;
        insert(&list, value);
    }

    cout << "Danh sach vua nhap la: ";
    duyet(&list);
    cout << endl
         << "So lan xuat hien cua tung phan tu trong danh sach la: " << endl;
    frequency(&list);
    return 0;
}