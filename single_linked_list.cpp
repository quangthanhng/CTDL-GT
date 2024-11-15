#include <iostream>
using namespace std;

// Cấu trúc node
struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Cấu trúc danh sách liên kết đơn
struct Linked_list
{
    Node *pHead;
    Node *pTail;
    int length;
    Linked_list()
    {
        pHead = nullptr;
        pTail = nullptr;
        length = 0;
    }

    // Thêm phần tử vào cuối danh sách
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (pHead == nullptr)
        {
            pHead = newNode;
            pTail = newNode;
        }
        else
        {
            pTail->next = newNode;
            pTail = newNode;
        }
        length++;
    }

    // Thêm phần tử vào vị trí bất kỳ
    void insertAt(int value, int position)
    {
        if (position < 1 || position > length + 1)
        {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (position == 1)
        {
            newNode->next = pHead;
            pHead = newNode;
            if (length == 0)
                pTail = newNode;
        }
        else
        {
            Node *temp = pHead;
            for (int i = 1; i < position - 1; ++i)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == nullptr)
            {
                pTail = newNode;
            }
        }
        length++;
    }

    // Xoá phần tử ở vị trí bất kỳ
    void deleteAt(int position)
    {
        if (pHead == nullptr || position < 1 || position > length)
        {
            cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
            return;
        }

        if (position == 1)
        {
            Node *temp = pHead;
            pHead = pHead->next;
            delete temp;
            if (pHead == nullptr)
                pTail = nullptr;
        }
        else
        {
            Node *temp = pHead;
            for (int i = 1; i < position - 1; ++i)
            {
                temp = temp->next;
            }
            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            if (nodeToDelete == pTail)
                pTail = temp;
            delete nodeToDelete;
        }
        length--;
    }

    // Sửa giá trị của node ở vị trí bất kỳ
    void updateAt(int position, int newValue)
    {
        if (position < 1 || position > length)
        {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }

        Node *temp = pHead;
        for (int i = 1; i < position; ++i)
        {
            temp = temp->next;
        }
        temp->data = newValue;
    }

    // Đảo ngược danh sách liên kết
    void reverse()
    {
        if (pHead == nullptr)
            return;

        Node *prev = nullptr;
        Node *current = pHead;
        Node *next = nullptr;
        pTail = pHead;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        pHead = prev;
    }

    // Duyệt danh sách
    void iteration()
    {
        if (pHead == nullptr)
        {
            cout << "Danh sach rong." << endl;
            return;
        }

        Node *temp = pHead;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Linked_list list;
    int value;
    bool check_first = true;

    while (true)
    {
        cin >> value;
        if (value == 0 && check_first == true)
        {
            cout << "Danh sach rong.";
            return 0;
        }
        check_first = false;
        if (value == 0)
            break;
        list.insert(value);
    }

    cout << "Danh sach vua nhap la: ";
    list.iteration();
    cout << endl;
    list.reverse();
    list.iteration();
    cout << endl;
    int phantu;
    cin >> phantu;
    list.deleteAt(phantu);
    list.iteration();
    return 0;
}