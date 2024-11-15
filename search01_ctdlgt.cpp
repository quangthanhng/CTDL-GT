#include <iostream>
using namespace std;

int findFirstGreaterOrEqual(long long* A, int N, long long K) {
    int left = 0;
    int right = N - 1;
    int pos = N;  // giả định không tìm thấy phần tử >= K

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] >= K) {
            pos = mid;  // cập nhật vị trí và tìm thêm bên trái
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return pos;
}

int main() {
    int N, T;
    cin >> N >> T;

    long long* A = new long long[N]; // Mảng A có kích thước N
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long* K = new long long[T]; // Mảng K có kích thước T
    for (int i = 0; i < T; i++) {
        cin >> K[i];
    }

    // Đầu ra cho từng giá trị của K
    for (int i = 0; i < T; i++) {
        int pos = findFirstGreaterOrEqual(A, N, K[i]);
        cout << (N - pos) << endl;
    }

    delete[] A;
    delete[] K;

    return 0;
}
/*
Input           Output
5 3                2
1 2 3 6 6          4
6 2 8              0
*/