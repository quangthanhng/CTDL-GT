
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

void frequency(List *list)
{
	for (node *p = list->pHead; p != NULL; p = p->pNext)
	{
		for (node *q = p; q->pNext != NULL;)
		{
			if (p->info == q->pNext->info)
			{
				node *k = q->pNext;
				q->pNext = q->pNext->pNext; // Bỏ qua node trùng lặp
				delete k;					// Giải phóng bộ nhớ node bị xóa
			}
			else
			{
				q = q->pNext;
			}
		}
	}
}

//85 36 85 35 20 20 61 36 76 15 20 16 36 5 0
//5 36 16 20 15 76 36 61 20 20 35 85 36 85
//5 36 16 20 15 76 61 35 85
int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL)
        cout << "Danh sach rong.";
    else
    {
        ReverseList(l);
        xuat(l);
        frequency(&l);
        cout << endl;
        xuat(l);
    }
    return 0;
}