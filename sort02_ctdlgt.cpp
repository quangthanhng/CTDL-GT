#include <iostream>
using namespace std;

int n;
int a[100];

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int insert(int value, int j) {
    int pos = j;
    for (; j > 0; j--) {
        if (value > a[j - 1]) {  // Đổi điều kiện để sắp xếp giảm dần
            a[j] = a[j - 1];
            pos = j - 1;  // Cập nhật vị trí chèn
        } else {
            break;
        }
    }
    a[pos] = value;
    return pos; // Trả về vị trí đã chèn
}

void solution() {
    for (int i = 1; i < n; i++) {
        int pos = insert(a[i], i);
        cout << "Vi tri chen cua a[" << i << "] la " << pos << endl;
        print();
    }
    cout << "Mang sau khi sap xep la: ";
    print();
}

int main() {
    cin >> n;
    if (n == 0) {
        cout << "Mang rong." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Mang truoc khi sap xep la: ";
        print();
        solution();
    }
    return 0;
}
