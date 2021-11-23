#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int part(int arr[],int s,int e)
{
    int pivot = arr[e];
    int pindex = s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[pindex++],arr[i]);
        }
    }
    swap(arr[e],arr[pindex]);

    return pindex;
}
void Q(int arr[],int s,int e)
{
    if(s<e) {
        int p = part(arr,s,e);
        Q(arr,s,p-1);
        Q(arr,p+1,e);
    }
}
int main()
{

    int arr[6] = {4,2,8,1,7,9};
    Q(arr,0,5);
    for(int i =0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
