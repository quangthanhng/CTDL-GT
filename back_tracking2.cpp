#include<iostream>
#include<string>
using namespace std;

#define MAX 100
int k, n;
int x[MAX];

void print_result(){
    for(int i = 1; i <= k; i++){
        cout << x[i];
    }
    cout << endl;
}

void resolve(int i){
    for(int v = x[i-1] + 1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k){
            print_result();
        }
        else {
            resolve(i + 1);
        }
    }
}

void solution(){
    resolve(1);
}

int main(){
    cin >> n >> k;
    solution();
}