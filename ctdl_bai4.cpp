#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Linked_list {
    Node* tail = NULL;
    Node* head = NULL;
    int length = 0;
};

void insert(Linked_list* list, int x) {
    list->length++;
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;

    if (list->head == NULL) {
        list->head = newnode;
        list->tail = newnode;
    }
    else {
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

//void frequency(Linked_list* list) {
//    unordered_map<int, int> freq_map;
//    vector<int> order;  
//
//    
//    for (Node* p = list->head; p != NULL; p = p->next) {
//        if (freq_map[p->data] == 0) {
//            order.push_back(p->data);  
//        }
//        freq_map[p->data]++;
//    }
//
//   
//    for (int val : order) {
//        cout << val << ": " << freq_map[val] << endl;
//    }
//}

void duyet(Linked_list* list) {
    Node* p = list->head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
bool check_prime(int value) {
    if (value <= 1)return false;
    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}
int primenumber(Linked_list* list) {
    int count = 0;
    int check_chan_le = 1;
    Node* p = list->head;
    while (p != NULL) {
        if (check_prime(p->data)&&check_chan_le%2!=0)count++;
        p = p->next;
        check_chan_le++;
    }
    return count;
}
int main() {
    Linked_list list;
    int value;
    bool check_first = true;

    while (true) {
        cin >> value;
        if (value == 0 && check_first == true) {
            cout << "Danh sach rong.";
            return 0;
        }
        check_first = false;
        if (value == 0) break;
        insert(&list, value);
    }

    cout << "Danh sach vua nhap la: ";
    duyet(&list);
    //cout << endl << "So lan xuat hien cua tung phan tu trong danh sach la: " << endl;
   // frequency(&list);
    //cout << endl << "Danh sach co " << list.length << " phan tu.";
    cout << endl << "Danh sach co " << primenumber(&list) << " so nguyen to o vi tri le.";

    return 0;
}