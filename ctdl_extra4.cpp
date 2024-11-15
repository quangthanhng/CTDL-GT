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
void addNode(stack& l, int x) {
	Node* p = makeNode(x);
	if (l.head == NULL)
		l.head = p;
	else {
		p->next = l.head;
		l.head = p;
	}
}
bool check(stack l, stack l2, int n) {
	
	Node* tmp = l.head;
	Node* tmp2 = l2.head;
	while (tmp != NULL) {
		tmp2 = l2.head;
		while (tmp2 != NULL) {
			int i = 0;
			if (tmp->data == tmp2->data) {
		        while(tmp->next!=NULL && tmp2->next!=NULL) {
					if (tmp->next->data != tmp2->next->data)
						break;
					tmp = tmp->next;
					tmp2 = tmp2->next;
					i++;
					if (i == n - 1)
						return true;
				}
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return false;
}
int main() {
	stack list;
	stack list2;
	makestack(list);
	makestack(list2);
	int x;
	while (true) {
		cin >> x;
		if (x == 0)
			break;
		addNode(list, x);
	}
	int y;
	while (true) {
		cin >> y;
		if (y == 0)
			break;
		addNode(list2, y);
	}
	int n;
	cin >> n;
	if (check(list, list2, n))
		cout << "yes";
	else
		cout << " no";
}
