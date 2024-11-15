#include <iostream>
using namespace std;

struct Node
{
    long numerator;
    long denominator;
    Node *next;
    Node(long n, long d)
    {
        numerator = n;
        denominator = d;
        next = nullptr;
    }
};

struct LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(long numerator, long denominator)
    {
        Node *newNode = new Node(numerator, denominator);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        if (!head)
        {
            cout << "Danh sach rong." << endl;
            return;
        }
        cout << "Danh sach vua nhap la: ";
        Node *temp = head;
        while (temp)
        {
            cout << temp->numerator << "/" << temp->denominator << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printEqualRationals(long xNumerator, long xDenominator)
    {
        if (!xDenominator)
        {
            cout << "Khong co phan so nao bang " << xNumerator << "/" << xDenominator << " trong danh sach." << endl;
            return;
        }
        bool found = false;
        Node *temp = head;
        while (temp)
        {
            if (temp->numerator * xDenominator == temp->denominator * xNumerator)
            {
                if (!found)
                {
                    cout << "Cac phan so bang " << xNumerator << "/" << xDenominator << " co trong danh sach la: ";
                    found = true;
                }
                cout << temp->numerator << "/" << temp->denominator << " ";
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Khong co phan so nao bang " << xNumerator << "/" << xDenominator << " trong danh sach." << endl;
        }
        else
        {
            cout << endl;
        }
    }

    Node *head;
    Node *tail;
};

int main()
{
    LinkedList list;
    long numerator, denominator;

    while (true)
    {
        cin >> numerator >> denominator;
        if (denominator == 0)
            break;
        list.insert(numerator, denominator);
    }

    list.printList();
    if (!list.head)
        return 0;
    cin >> numerator >> denominator;
    list.printEqualRationals(numerator, denominator);

    return 0;
}