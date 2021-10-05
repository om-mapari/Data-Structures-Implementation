#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int t ;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        int min,max;
        min = max = a[0];
        for(int i =0;i<n;i++)
        {
            if(a[i]>max)
            {
                max = a[i];
            }
            if(a[i]<min)
            {
                min = a[i];
            }
        }
        cout<<max<<min<<endl;
        
    }
	return 0;
}