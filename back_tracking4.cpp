#include <iostream>
#include <string>
using namespace std;

#define MAX 100
int n;
int x[MAX];

bool mark[MAX];

void print_result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void resolve(int i)
{
    for (int v = 1; v <= n; v++)
    {
        if (mark[v] == false)
        {
            x[i] = v;
            mark[v] = true;
            if (i == n)
            {
                print_result();
            }
            else
            {
                resolve(i + 1);
            }
            mark[v] = false;
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
    for(int i = 1; i <= n; i++){
        mark[i] = false;
    }
    solution();
}