#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
struct stack {
	Node* head;
};
void makestack(stack& l) {
	l.head = NULL;
}
Node* makeNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void addNode(stack& list, int x) {
	Node* p = makeNode(x);
	if (list.head == NULL)
		list.head = p;
	else {
		p->next = list.head;
		list.head = p;
	}
}
void show(stack list) {
	Node* p = list.head;
	while (p != NULL) {
		cout << p->data << " ";
		p= p->next;
	}
 }
void xapxep(stack& list) {
	Node* p = list.head;
	Node* p2 = list.head;
	while (p != NULL) {
		p2 = p->next;
		while (p2 != NULL) {
			if (p->data > p2->data) {
				int tmp = p->data;
				p->data = p2->data;
				p2->data = tmp;
			}
			p2 = p2->next;
		}
		
		p = p->next;

	}
}
int main() {
	stack list;
	stack list3;
	makestack(list3);
	makestack(list);
	int x;
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		addNode(list, x);
		addNode(list3, x);
	}
	stack list2;
	makestack(list2);
	int y;
	while (true) {
		cin >> y;
		if (y == 0)
			break;
		addNode(list2, y);
		addNode(list3, y);
	}
	xapxep(list3);
	show(list);
	cout << endl;
	show(list2);
	cout << endl;
	show(list3);
}
