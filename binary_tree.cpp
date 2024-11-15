#include<iostream>

using namespace std;
#define MAX 100

int n, x;
int a[MAX];
int solution(){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = (start + end)/2;
        if(a[mid] == x){
            return mid;
        }

        if(x > a[mid]){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

    }
    return -1;
}



int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    cout << solution();
}