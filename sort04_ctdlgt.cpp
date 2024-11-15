#include <bits/stdc++.h>
using namespace std;

void heapify(vector <long long> &a, long long n, long long i, string &swaps, bool recordSwaps)
{
    long long smallest = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;
    
    if (l < n && a[l] < a[smallest]){
        smallest = l;
    }
    if (r < n && a[r] < a[smallest]){
        smallest = r;
    }
    if (smallest != i){
        swap(a[i], a[smallest]);
        if (recordSwaps){
            swaps += to_string(i) + " " + to_string(smallest) + "\n";
        }
       
        heapify(a, n, smallest, swaps, recordSwaps);
    }
}

void heapSort(vector<long long> &a, string &swaps){
    long long n = a.size();
    for(long long i = n/2-1; i>=0; --i){
        heapify(a,n,i,swaps, true);
    }
    for (long long i = n - 1; i > 0; --i){
        swap(a[0], a[i]);
        //swaps += to_string(0) + " " + to_string(i) + "\n";
        heapify(a,i,0, swaps, false);
    }
}

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << "Day truoc khi sap xep: ";
    for (long long x : a) cout << x << " ";
    string swaps = "";
    heapSort(a, swaps);
    cout << "\nDay sau khi sap xep: ";
    for (long long x : a) cout << x << " ";
    cout << "\nCac hoan vi duoc thuc hien trong heap:" << endl;
    cout << swaps; 

    
}