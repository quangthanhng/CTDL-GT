
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
void ReverseList(List &l);

void ReverseList(List &l)
{
    for (node *p = l.pHead; p != NULL; p = p->pNext)
    {
        for (node *q = p->pNext; q != NULL; q = q->pNext)
        {
            int k = p->info;
            p->info = q->info;
            q->info = k;
        }
    }
}
//6 29 8 47 6 47 5
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
void nhap(List &l)
{
    int value;
    bool check_dau = true;
    while (true)
    {
        cin >> value;
        if (value == 0 && check_dau == true)
        {
            break;
        }
        check_dau = false;
        if (value == 0)
            break;
        insert(&l, value);
    }
}

void xuat(List l)
{
    for (node *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << " ";
    }
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        ReverseList(l);
        cout << endl
             << "Danh sach sau khi dao nguoc la: ";
        xuat(l);
    }
    return 0;
}