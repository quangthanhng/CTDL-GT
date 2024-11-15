#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int depth, vector<vector<vector<int>>>& result) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    vector<int> merged(arr.begin() + left, arr.begin() + right + 1);
    result[depth].push_back(merged);
}

void mergesort(vector<int>& arr, int left, int right, int depth, vector<vector<vector<int>>>& result) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid, depth + 1, result);
        mergesort(arr, mid + 1, right, depth + 1, result);

        merge(arr, left, mid, right, depth, result);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<vector<int>>> result(N);
    mergesort(a, 0, N - 1, 0, result);

    for (int depth = 0; depth < N; depth++) {
        if (!result[depth].empty()) {
            cout << "k=" << depth + 1 << endl;
            for (const auto& subarray : result[depth]) {
                cout << "[";
                for (size_t i = 0; i < subarray.size(); i++) {
                    if (i > 0) cout << ",";
                    cout << subarray[i];
                }
                cout << "]";
            }
            cout << endl;
        }
    }

    return 0;
}