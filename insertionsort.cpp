#include<iostream>

using namespace std;
#define max 100
int n;
int a[max];

void print(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert(int value, int j){
    for( ; j > 0; j--){
        if(value > a[j - 1]){
            break;
        }
        a[j] = a[j - 1];
    }
    a[j] = value;
}

void solution(){
    for(int i = 1; i < n; i++){
        insert(a[i], i);
        // chèn giá trị a[i] vào mảng con
        // từ 0 đến i
    }
    print();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solution();
}