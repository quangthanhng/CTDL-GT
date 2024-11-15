#include<iostream>
#include<string>
using namespace std;

#define MAX 100
int k, n;
int x[MAX];
int y[MAX];

void print_result(){
    for(int i = 1; i <= k + n; i++){
        if(y[x[i]] == 0){
            cout << "C ";
        }else {
            cout << "O ";
        }
    }
    cout << endl;
}

void resolve(int i, int a, int b){
    for(int v = 1; v <= k + n; v++){
        x[i] = v;
        if(i > k + n){
            print_result();
        }
        else {
            resolve(i + 1, a + 1, b + 1);
        }
    }
}

void solution(){
    resolve(1, 0, 0);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        y[i] = 0;
    }
    for(int i = n; i < n + k; i++){
        y[i] = 1;
    }
    solution();
}