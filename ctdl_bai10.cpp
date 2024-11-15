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

// Hàm xóa tất cả phần tử có giá trị value
void frequency(List *list, int value)
{
    if (list->pHead == NULL)
    {
        cout << "Danh sach rong." << endl;
        return;
    }

    bool found = false;

    // Xóa tất cả phần tử đầu có giá trị bằng value
    while (list->pHead != NULL && list->pHead->info == value)
    {
        node *temp = list->pHead;
        list->pHead = list->pHead->pNext;
        delete temp;
        found = true;
    }

    // Duyệt và xóa các phần tử có giá trị value trong danh sách
    node *p = list->pHead;
    while (p != NULL && p->pNext != NULL)
    {
        if (p->pNext->info == value)
        {
            node *temp = p->pNext;
            p->pNext = p->pNext->pNext;
            delete temp;
            found = true;
        }
        else
        {
            p = p->pNext;
        }
    }

    // Cập nhật con trỏ pTail nếu danh sách rỗng hoặc xóa phần tử cuối cùng
    if (list->pHead == NULL)
    {
        list->pTail = NULL;
        cout << "Danh sach rong." << endl;
    }
    else if (list->pTail->info == value)
    {
        list->pTail = p; // Cập nhật lại tail nếu phần tử cuối cùng bị xóa
    }

    if (!found)
    {
        cout << "Khong tim thay " << value << " trong danh sach:" << endl;
    }
}

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
// 85 36 85 35 20 20 61 36 76 15 20 16 36 5 0 36

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
        frequency(&l, value); // Xóa tất cả các phần tử có giá trị value
        if (l.pHead != NULL)
        {
            ReverseList(l);
            xuat(l); // Xuất danh sách nếu không rỗng sau khi xóa
        }
    }

    return 0;
}
