#include <iostream>
using namespace std;
//best case = O(n)
//worst case = O(n^2)
//avarage case = O(n^2)
void InsersionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int h = i;
        while (h > 0 && a[h - 1] > v)
        {
            a[h] = a[h - 1];
            h--;
        }
        a[h] = v;
    }
}

int main()
{
    int k[] = {7, 2, 4, 1, 5, 3};
    int n = 6;
    InsersionSort(k, n);

    for (int atom : k)
    {
        cout << atom << " ";
    }
    return 0;
}