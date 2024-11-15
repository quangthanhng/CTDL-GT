#include <iostream>
using namespace std;

const int MAX_N = 20;
int n;
int money[MAX_N];
int x[MAX_N + 1];
int total_ways = 0;

void print_result() {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            cout << "A ";
        } else {
            cout << "B ";
        }
    }
    cout << endl;
}

void resolve(int i, int sumA, int sumB) {
    if (i > n) {
        if (sumA == sumB) {
            print_result();
            total_ways++;
        }
        return;
    }

    x[i] = 0; // Assign to A
    resolve(i + 1, sumA + money[i - 1], sumB);

    x[i] = 1; // Assign to B
    resolve(i + 1, sumA, sumB + money[i - 1]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }

    resolve(1, 0, 0);

    cout << total_ways << endl;

    return 0;
}