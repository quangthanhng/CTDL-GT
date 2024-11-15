#include <iostream>
using namespace std;
void quicksort(long long a[], long long  left, long long right, string &swaps) {
    if (left >= right){
        return;
    }
    long long mid = left + (right - left) / 2;
    long long pivot = a[mid];
    long long i = left;
    long long j = right;
    while (i <= j){
        while (a[i] > pivot) i++;
        while (a[j] < pivot) j--;
        if (i <= j) {
            if(i<j){
            swaps += to_string(i+1) + " " + to_string(j+1) + "\n";
            swap(a[i], a[j]);
            }
            i++;
            j--;
        }
    }
    quicksort(a, left, j, swaps);
    quicksort(a, i, right, swaps);
}
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "Mang rong." << endl;
        return 0;
    }
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Day truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    string swaps = "";
    quicksort(a, 0, n - 1, swaps);
    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Cac hoan vi duoc thuc hien trong Quick Sort:" << endl;
    cout << swaps;
}