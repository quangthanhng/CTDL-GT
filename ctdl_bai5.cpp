
#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};
 
void CreateList(List &l);
void NhapList(List &l);
int DemSoPhanTu(List l);
void Split(List l, List &l1, List &l2);
void XuatList(List l);

int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	NhapList(l);
	if(DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		XuatList(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		XuatList(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		XuatList(l2);
		cout << endl;
	}
	return 0;
}

void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

int DemSoPhanTu(List l)
{
	return (l.pHead == NULL) ? 0 : 1;
}

void frequency(List *list)
{
	for (Node *p = list->pHead; p != NULL; p = p->pNext)
	{
		for (Node *q = p; q->pNext != NULL;)
		{
			if (p->info == q->pNext->info)
			{
				Node *k = q->pNext;
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

void Split(List l, List &l1, List &l2)
{
	frequency(&l); // Remove duplicates before splitting

	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		Node *newNode = new Node();
		newNode->info = p->info;
		newNode->pNext = NULL;

		if (p->info % 2 == 0)
		{
			if (l1.pHead == NULL)
			{
				l1.pHead = newNode;
				l1.pTail = newNode;
			}
			else
			{
				l1.pTail->pNext = newNode;
				l1.pTail = newNode;
			}
		}
		else
		{
			if (l2.pHead == NULL)
			{
				l2.pHead = newNode;
				l2.pTail = newNode;
			}
			else
			{
				l2.pTail->pNext = newNode;
				l2.pTail = newNode;
			}
		}
	}

	// Terminate both lists to avoid circular references
	if (l1.pTail != NULL)
		l1.pTail->pNext = NULL;
	if (l2.pTail != NULL)
		l2.pTail->pNext = NULL;
}

void insert(List *list, int value)
{
	Node *p = new Node();
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

void NhapList(List &l)
{
	int value;
	bool check_first = true;

	while (true)
	{
		cin >> value;
		if (value == 0 && check_first == true)
		{
			break;
		}
		check_first = false;
		if (value == 0)
			break;
		insert(&l, value);
	}
}

void XuatList(List list)
{
	for (Node *p = list.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << " ";
	}
}