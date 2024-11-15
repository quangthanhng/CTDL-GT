#include <iostream>
using namespace std;

struct node
{
    int info;
    node *pNext;
};

struct List
{
    node *pHead;
    node *pTail;
};

void CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm xóa phần tử đầu tiên có giá trị value
void frequency(List *list, int value)
{
    if (list->pHead == NULL)
    {
        cout << "Danh sach rong." << endl;
        return;
    }

    // Xóa phần tử đầu tiên nếu giá trị bằng value
    if (list->pHead->info == value)
    {
        node *temp = list->pHead;
        list->pHead = list->pHead->pNext;
        delete temp;

        if (list->pHead == NULL)
            cout << "Danh sach rong." << endl;
        return;
    }

    // Tìm và xóa phần tử có giá trị value
    bool found = false;
    for (node *p = list->pHead; p->pNext != NULL; p = p->pNext)
    {
        if (p->pNext->info == value)
        {
            node *key = p->pNext;
            p->pNext = p->pNext->pNext;
            delete key;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay " << value << " trong danh sach:" << endl;
    }
}

// Hàm đảo ngược danh sách liên kết
void ReverseList(List &l)
{
    node *prev = NULL;
    node *current = l.pHead;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    l.pHead = prev;
}

// Hàm chèn phần tử vào cuối danh sách
void insert(List *list, int value)
{
    node *p = new node();
    p->info = value;
    p->pNext = NULL;

    if (list->pHead == NULL)
    {
        list->pHead = p;
        list->pTail = p;
    }
    else
    {
        list->pTail->pNext = p;
        list->pTail = p;
    }
}

// Hàm nhập dữ liệu đầu vào
void nhap(List &l, int &index)
{
    int value;
    while (true)
    {
        cin >> value;
        if (value == 0)
            break;
        insert(&l, value);
    }
    cin >> index;
}

// Hàm xuất danh sách
void xuat(List l)
{
    for (node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
    cout << endl;
}

int main()
{
    List l;
    CreateList(l);
    int value;
    nhap(l, value);

    if (l.pHead == NULL)
    {
        cout << "Danh sach rong." << endl;
    }
    else
    {
        ReverseList(l); // Đảo ngược danh sách sau khi xóa
        frequency(&l, value);
        if (l.pHead != NULL)
        {
            xuat(l);
        }
    }
//85 36 85 35 20 20 61 36 76 15 20 16 36 5 0 17
//85 36 85 35 20 20 61 36 76 15 20 16 36 5 0 36
//5 16 20 15 76 36 61 20 20 35 85 36 85
    return 0;
}
