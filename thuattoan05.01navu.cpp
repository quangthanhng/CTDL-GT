/*
Yêu cầu: Cho 1 dãy gồm n số nguyên dương đã được sắp xếp tăng dần. Tìm tất cả các số

nguyên tố trong dãy|
Input: Dòng đầu tiên là n, dòng thứ 2 là dãy n các số nguyên dương, ngăn cách nhau bởi 1
khoảng trắng
Output: Các số nguyên tố trong dãy
Ví dụ:
Input                                                       Outfput

10                                                          11 13 29

11 13 15 16 20 21 29 30 32 50

15                                                          19 37 53 61 101 113

19 20 34 35 36 37 52 53 60 61 99 100 101 102 113
*/

#include<iostream>
using namespace std;
#define MAX 100

bool isPrime(int n) {
    if (n <= 1) return false;             // Số nhỏ hơn hoặc bằng 1 không phải là số nguyên tố
    for (int i = 2; i * i <= n; i++) {    // Kiểm tra từ 2 đến √n
        if (n % i == 0) return false;     // Nếu n chia hết cho i thì không phải số nguyên tố
    }
    return true;
}

int binary_search(int a[], int start, int end){
    int mid = (start+end)/2;
    if(isPrime(a[mid])){
        return a[mid];
    }
    cout << endl;
    binary_search(a, start, mid - 1);
    binary_search(a, mid + 1, end);
    return 0;
}

int main(){
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int start = 0;
    int end = n - 1;
    cout << binary_search(a, start, end);
}