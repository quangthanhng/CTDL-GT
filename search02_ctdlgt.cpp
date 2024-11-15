#include <iostream>
using namespace std;

int findFirstOccurrence(long long* A, int N, long long K) {
    int left = 0;
    int right = N - 1;
    int first = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == K) {
            first = mid;
            right = mid - 1; // Move left to find earlier occurrence
        } else if (A[mid] < K) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return first;
}

int findLastOccurrence(long long* A, int N, long long K) {
    int left = 0;
    int right = N - 1;
    int last = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == K) {
            last = mid;
            left = mid + 1; // Move right to find later occurrence
        } else if (A[mid] < K) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return last;
}

void findFirstGreaterOrEqual(long long* A, int N, long long K) {
    int first = findFirstOccurrence(A, N, K);
    int last = findLastOccurrence(A, N, K);

    if (first == -1) {
        cout << "-1" << endl;
    } else {
        int count = last - first + 1;
        cout << count << " " << (first + 1) << " " << (last + 1) << endl; // 1-based indexing
    }
}

int main() {
    int N, T;
    cin >> N >> T;

    long long* A = new long long[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long* K = new long long[T];
    for (int i = 0; i < T; i++) {
        cin >> K[i];
    }

    for (int i = 0; i < T; i++) {
        findFirstGreaterOrEqual(A, N, K[i]);
    }

    delete[] A;
    delete[] K;

    return 0;
}
