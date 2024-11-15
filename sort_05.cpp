#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
typedef vector<long long> ll;
vector<vector<ll>> level_arr;
long long size_arr;
void Split_until_1_element(vector<ll> &v1) {
    vector<ll> restore; 
    for (auto &x : v1) {
        long long l = 0, r = x.size() - 1;
        long long mid = (l + r) / 2;
        vector<long long> tmp; 

        if (l == r) {
            restore.push_back(x);
        } else {
            while (l <= mid) {
                tmp.push_back(x[l]);
                l++;
            }
            restore.push_back(tmp);
            tmp.clear();
            mid++;
            while (mid <= r) {
                tmp.push_back(x[mid]);
                mid++;
            }
            restore.push_back(tmp);
        }
    }
    v1 = move(restore);
}

void printLevel(long long k, const vector<vector<long long>>& arr) {
    stringstream output;
    output << "k=" << k << endl;
    output << "[";
    for (long long i = 0; i < arr.size(); i++) {
        output << "[";
        for (long long j = 0; j < arr[i].size(); j++) {
            output << arr[i][j];
            if (j < arr[i].size() - 1) output << ",";
        }
        output << "]";
        if (i < arr.size() - 1) output << ",";
    }
    output << "]" << endl;
    cout << output.str();
}

void merge(long long k, vector<ll>& v) {
    for (auto& vec : v) {
        if (vec.size() > 1) {
            sort(vec.begin(), vec.end(), greater<long long>());
        }
    }
    printLevel(k, v);
}

int main() {
    long long n; 
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> arr;
    long long k = 1;

    if (n == 1) {
        cout << "k=" << k << endl;
        cout << '[' << a[0] << ']' << endl;
    } else {
        arr.push_back(a);
        size_arr = arr[0].size();

        while (arr.size() < size_arr) {
            Split_until_1_element(arr);

            stringstream output;
            output << "k=" << k << endl;
            output << '[';
            vector<ll> super_tmp;
            for (long long i = 0; i < arr.size(); i++) {
                vector<long long> tmp;
                output << '[';
                for (long long j = 0; j < arr[i].size(); j++) {
                    if (j != arr[i].size() - 1) {
                        output << arr[i][j] << ',';
                        tmp.push_back(arr[i][j]);
                    } else {
                        output << arr[i][j] << ']';
                        tmp.push_back(arr[i][j]);
                        super_tmp.push_back(tmp);
                    }
                }
                if (i != arr.size() - 1) output << ',';
            }
            output << ']' << endl;
            cout << output.str();
            level_arr.push_back(super_tmp);
            k++;
        }
        level_arr.pop_back();

        for (int i = level_arr.size() - 1; i >= 0; i--) {
            merge(k, level_arr[i]);
            k++;
        }

        vector<ll> last_level;
        sort(a.begin(), a.end(), greater<long long>());
        last_level.push_back(a);
        
        printLevel(k, last_level);
    }
}