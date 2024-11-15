#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "Mang rong." << endl;
        return 0;
    }
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // In mảng trước khi sắp xếp
    cout << "Mang truoc khi sap xep la:";
    for (int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    
    // Selection Sort để sắp xếp mảng giảm dần
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        
        // In phần tử lớn nhất hiện tại
        cout << "i=" << i << ":\n";
        cout << "Max = a[" << maxIdx << "] = " << a[maxIdx] << endl;
        
        // Đổi chỗ phần tử lớn nhất với phần tử đầu tiên chưa được sắp xếp
        if (maxIdx != i) {
            int temp = a[i];
            a[i] = a[maxIdx];
            a[maxIdx] = temp;
        }
        
        // In mảng sau khi sắp xếp i+1 phần tử đầu tiên
        cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la:";
        for (int k = 0; k < n; k++) {
            cout << " " << a[k];
        }
        cout << endl;
    }
    
    // In mảng sau khi sắp xếp hoàn toàn
    cout << "Mang sau khi sap xep la:";
    for (int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}
