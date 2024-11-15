#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Định nghĩa cấu trúc Stack sử dụng danh sách liên kết
class Stack {
private:
    Node* topNode;  // Con trỏ đến node đỉnh của stack

public:
    Stack() {
        topNode = nullptr;  // Khởi tạo stack rỗng
    }

    // Kiểm tra stack có rỗng không
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Thêm phần tử vào stack
    void push(int value) {
        Node* newNode = new Node(); // Tạo node mới
        newNode->data = value;      // Gán dữ liệu cho node
        newNode->next = topNode;    // Liên kết node mới với node trước nó
        topNode = newNode;          // Cập nhật node đỉnh
        cout << "Phan tu " << value << " duoc them vao stack." << endl;
    }

    // Xóa phần tử khỏi stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack rong! Khong the xoa phan tu." << endl;
        } else {
            Node* temp = topNode;   // Lưu lại node đỉnh để xóa
            cout << "Phan tu " << topNode->data << " duoc xoa khoi stack." << endl;
            topNode = topNode->next; // Cập nhật node đỉnh mới
            delete temp;            // Xóa node cũ
        }
    }

    // Lấy phần tử đầu trên stack mà không xóa
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1; // Trả về -1 nếu stack rỗng
        }
        return topNode->data; // Trả về giá trị của phần tử đỉnh
    }

    // Sửa phần tử tại vị trí cụ thể trong stack
    void update(int index, int newValue) {
        Node* temp = topNode;
        int count = 0;

        // Duyệt qua các node đến khi tìm thấy vị trí cần sửa
        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Chi so khong hop le!" << endl;
        } else {
            cout << "Phan tu " << temp->data << " duoc sua thanh " << newValue << endl;
            temp->data = newValue; // Sửa giá trị của node tại vị trí index
        }
    }

    // Đảo ngược stack
    void reverse() {
        if (isEmpty()) {
            cout << "Stack rong! Khong the dao nguoc." << endl;
            return;
        }

        Node* prev = nullptr;
        Node* current = topNode;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // Lưu lại node tiếp theo
            current->next = prev;  // Đảo ngược liên kết
            prev = current;        // Cập nhật node trước
            current = next;        // Chuyển đến node tiếp theo
        }

        topNode = prev; // Cập nhật node đỉnh mới
        cout << "Stack da duoc dao nguoc." << endl;
    }

    // Hiển thị các phần tử trong stack
    void display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }

        cout << "Cac phan tu trong stack: ";
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;

    // Thêm phần tử vào stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.display(); // Hiển thị stack

    // Xóa phần tử khỏi stack
    myStack.pop();
    myStack.display(); // Hiển thị stack sau khi xóa

    // Sửa phần tử tại vị trí cụ thể (ví dụ sửa phần tử ở vị trí 1)
    myStack.update(1, 50);
    myStack.display(); // Hiển thị stack sau khi sửa

    // Đảo ngược stack
    myStack.reverse();
    myStack.display(); // Hiển thị stack sau khi đảo ngược

    return 0;
}
