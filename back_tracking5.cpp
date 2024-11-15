#include <iostream>
using namespace std;

int n, k;
int x[100]; // Giả sử k không vượt quá 100
int y[100]; // Giả sử k không vượt quá 100
bool mark[100] = {false}; // Đánh dấu các phần tử đã được sử dụng

void print_result(){
    for(int i = 1; i <= k; i++){
        cout << y[i];
    }
    cout << endl;
}

void resolve_permutation(int i){
    for(int v = 1; v <= k; v++){
        if(!mark[v]){
            y[i] = x[v];
            mark[v] = true;
            if(i == k){
                print_result();
            } else {
                resolve_permutation(i + 1);
            }
            mark[v] = false;
        }
    }
}

void resolve_combination(int i){
    for(int v = x[i - 1] + 1; v <= n - k + i; v++){
        x[i] = v;
        if(i == k){
            resolve_permutation(1);
        } else {
            resolve_combination(i + 1);
        }
    }
}

void solution(){
    resolve_combination(1);
}

int main(){
    cin >> n >> k;
    solution();
    return 0;
}