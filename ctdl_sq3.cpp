#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List st;
	CreateList(st);
	long long x;
	cin >> x;
while (x > 0)
    {
        enstack(st, x % 2);
        x /= 2;
    }

    // Print binary representation
    while (!isEmpty(st))
    {
        cout << st.pHead->info;
        destack(st);
    }

    return 0;
}
node* CreateNode(int x)
{
    node* p = new node;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddHead(List& l, node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void enstack(List& l, int x)
{
    node* p = CreateNode(x);
    AddHead(l, p);
}
void destack(List& l)
{
    if (l.pHead != NULL)
    {
        node* p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}
bool isEmpty(List l)
{
    return l.pHead == NULL;
}