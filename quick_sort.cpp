#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân đoạn (partition) mảng
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn phần tử chốt (pivot)
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp các phần tử trước và sau phần tử chốt
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << "Mảng ban đầu: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    printArray(arr);

    return 0;
}