#include <iostream>
#include <string.h>
using namespace std;
struct node{
    int data; 
    node *pNext;
};

struct stack{
    node *pHead;
};

void init_stack(stack &s){
    s.pHead = NULL;
}

node *khoi_tao_node(int x)
{
    node *p = new node;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void push(stack &s, int x)
{
    node *p = khoi_tao_node(x);
    if(s.pHead == NULL){
        s.pHead = p;
    }
    else{
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

void pop(stack &s)
{
    if(s.pHead == NULL) return;
    else{
        node *tam = s.pHead;
        s.pHead = s.pHead->pNext;
        delete tam;
    }
}

int top (stack s)
{
    return s.pHead->data;
}

bool isEmpty(stack s)
{
    return s.pHead == NULL;
}

void multiply(stack &s, string a, int b)
{
    int nho = 0;
    string result = "";  // Dùng để lưu kết quả thay vì in ngay lập tức.
    
    // Nhân từng chữ số của chuỗi với số b
    for (int i = a.size() - 1; i >= 0; --i ){
        int so = a[i] - '0';
        int kq = so * b + nho;
        result = char(kq % 10 + '0') + result;  // Lưu kết quả vào chuỗi.
        nho = kq / 10;
    }

    // Xử lý số dư còn lại
    while (nho > 0)
    {
        result = char(nho % 10 + '0') + result;
        nho = nho / 10;
    }

    // Loại bỏ các chữ số 0 ở đầu (nếu cần)
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        ++start;
    }

    if (start == result.size()) {
        cout << "0";  // Trường hợp nhân với 0.
    } else {
        cout << result.substr(start);  // In kết quả từ vị trí không có 0.
    }

    cout << endl;
}

int main(){
    stack s;
    init_stack(s);
    string a; 
    cin >> a;
    int b; 
    cin >> b;
    multiply(s, a, b);
    
    return 0;
}