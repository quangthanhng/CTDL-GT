#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {};
};

void add(Node *&head, Node *&tail, int data, int& count)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode; // Nếu danh sách trống, gán head là newNode
        tail = newNode; // tail cũng trỏ đến newNode
        count++;
    }
    else
    {
        tail->next = newNode; // tail đang trỏ tới node cuối, gán nó tới newNode
        tail = newNode;       // tail bây giờ là newNode
        count++;
    }
}

void print_Node(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr; // Thêm một con trỏ tail để tối ưu hoá việc thêm phần tử
    int index;
    bool hasInserted = false; // Cờ kiểm tra xem có phần tử nào được chèn vào không
    int count = 0;

    while (true)
    {
        cin >> index;
        if (index == 0)
        {
            break; // Ngừng nhập khi gặp giá trị 0
        }
        add(head, tail, index, count);
        hasInserted = true; // Đánh dấu có phần tử được thêm vào
    }

    if (!hasInserted)
    {
        cout << "Danh sach rong." << endl; // In đúng yêu cầu khi danh sách trống
    }
    // 6 29 -91 47 88 44 5
    else
    {
        cout << "Danh sach vua nhap la: ";
        print_Node(head); // In ra danh sách đã được nhập
        cout << endl << "Danh sach co " << count << " phan tu.";
    }

    return 0;
}
