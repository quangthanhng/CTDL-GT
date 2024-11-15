#include<iostream>
#include<math.h>

using namespace std;

void Nhap(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int Min_scp(int a[], int n){ 
    int index = 1;
    int kq;
    for(int i = 0; i < n; i++){
        if(pow(index, 2) < a[i]){
            kq = pow(index, 2);
            break;
        }else if(a[i] == pow(index, 2)){
            index += 1;
            kq = pow(index, 2);
        }
    }
    return kq;
}

int main(){
    int a[100];
    cout << "Nhap tong so luong: ";
    int n;
    cin >> n;
    Nhap(a, n);
    int kq = Min_scp(a, n);
    cout << "Ket qua so chinh phuong nho nhat khong thuoc day la: " << kq;
}