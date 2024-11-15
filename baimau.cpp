#include<iostream>

using namespace std;

int recursion(int n){
     if(n == 1){
          return n;
     }
     return pow(n,2) + recursion(n - 1);
}

int main(){
     int n;
     cin >> n;
     int tong = recursion(n);
     cout << tong;
}