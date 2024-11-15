#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
struct stack {
	Node* head;
};
void makestack(stack& list) {
	list.head = NULL;
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
bool check(stack l, stack l2) {
	while (l.head != NULL && l2.head != NULL) {
		if (l.head->data != l2.head->data)
			return false;
		l.head = l.head->next;
		l2.head = l2.head->next;
	}
	return true;

}
int main() {
	stack list;
	stack list2;
	makestack(list);
	makestack(list2);
	int n;
	cin >> n;
	int tmp = n;
	int dem = 0;
	while (tmp != 0) {
		tmp = tmp / 10;
		dem++;
	}
	if (dem % 2 != 0) {
		cout << "0";
		return 0;
	}
	tmp = n;
	while (tmp != 0) {
		int x = tmp % 10;
		addNode(list, x);
		tmp = tmp / 10;
	}
	int dem2 = 1;
	Node* p = list.head;
	while (dem2 <= dem / 2) {
		addNode(list2, p->data);
		dem2++;
		p = p->next;
	}
	list.head = p;
	if (check(list, list2))
		cout << "1";
	else cout << "0";
}
