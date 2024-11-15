#include <iostream>
using namespace std;

int n;
int x[100]; // Giả sử n không vượt quá 100

void print_result(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void resolve(int i){
    for(int v : {0, 1}){
        x[i] = v;
        if(i == n){
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
    cin >> n;
    solution();
    return 0;
}