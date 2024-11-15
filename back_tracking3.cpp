#include<iostream>
#include<string>
#include<string>
using namespace std;

#define MAX 100
int k, n;
int x[MAX];
string dict[MAX];

void print_result(){
    for(int i = 1; i <= n; i++){
        int id = x[i];
        cout << dict[id];
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
    for(int i = 0; i <= n; i++){
        cin >> dict[i];
    }
    solution();
}