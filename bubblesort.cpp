#include <iostream>

using namespace std;

#define MAX 100

void swap(int &m, int &n)
{
    int temp = m;
    m = n;
    n = temp;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void solution(int a[], int n)
{
    bool check = true;
    while (check == true)
    {
        check = false;
        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                check = true;
            }
        }
    }
    print(a, n);
}

int main()
{
    int a[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solution(a, n);
}