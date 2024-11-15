#include <iostream>
#include <string>
using namespace std;

#define MAX 100
int n;
int x[MAX];

bool mark_cot[MAX]; // j
bool mark_cheo_chinh[MAX]; // i - j
bool mark_cheo_phu[MAX]; // i + j

void print_result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void set_mark(int i, int j, bool value){
    mark_cot[j] 
    = mark_cheo_chinh[i-j+n]
    = mark_cheo_phu[i + j]
    = value;
}

void resolve(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (mark_cot[j] == false 
        && mark_cheo_chinh[i - j + n] == false
        && mark_cheo_phu[i + j] == false)
        {
            set_mark(i, j, true);
            x[i] = j;
            if (i == n)
            {
                print_result();
            }
            else
            {
                resolve(i + 1);
            }
            set_mark(i, j, false);
        }
    }
}

void solution()
{
    resolve(1);
}

int main()
{
    cin >> n;
    solution();
}