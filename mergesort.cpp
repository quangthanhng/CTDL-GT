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

void combine(int start, int mid, int end){
    //Xác định độ dài của 2 mảng con tách riêng ra để làm việc
    //start -> mid | mid - start + 1 (phần tử)
    int n1 = mid - start + 1;
    // mid + 1 -> end
    int n2 = end - mid;
    int L[max];
    for(int i = 0; i < n1; i++) L[i] = a[start + i];
    int R[max];
    for(int i = 0; i < n1; i++) R[i] = a[mid + 1 + i];
    // Trộn
    int j = 0, k = 0; // => L[j] và R[k]
    int i = start;
    for( ;j < n1 && k < n2; i++){
        if(L[j] <= R[k]){
            a[i] = L[j];
            j++;
        }else {
            a[i] = R[k];
            k++;
        }
    }
    // Check xem mảng con nào còn dư thì đưa nốt vào
    for( ;j < n1; j++) a[i++] = L[j];
    for( ;k < n2; k++) a[i++] = R[k];
}

void mergesort(int start, int end){
    if(start == end){
        return;
    }

    int mid = (start + end)/2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    combine(start, mid, end);
}

void solution(){
    mergesort(0, n - 1);
    print();
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solution();
}