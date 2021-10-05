#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
    int n = 7;
    int a[] = {11, 12, 14,23, 55, 64, 198};
    

    for (int i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        { //n-1-i optimization no 1
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
        if(sorted) break;
    }

    for(int item : a) cout<<item<<" ";
    return 0;
}