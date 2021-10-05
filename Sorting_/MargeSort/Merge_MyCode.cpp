
#include <iostream>
using namespace std;

void Merge(int *a, int *l, int nl, int *r, int nr)
{

    int i, j, k;   //i->l[]
    i =0,j=0,k=0; //j->r[]
                   //k->a[]

    while (i < nl && j < nr)
    {
        (l[i] <= r[j])? a[k++] = l[i++] :a[k++] = r[j++] ;
    }

    while (i < nl) a[k++] = l[i++];
  
    while (j < nr) a[k++] = r[j++];
    
    // while(i<nl && j< nr) {
	// 	if(l[i]  < r[j]) a[k++] = l[i++];
	// 	else a[k++] = r[j++];
	// }
	// while(i < nl) a[k++] = l[i++];
	// while(j < nr) a[k++] = r[j++];
       
}

void MergeSort(int *a, int n)
{ 
    int mid,*l,*r;
    if(n<2){return;};

    mid = n/2;

    l = new int[mid];
    r = new int[n-mid];
 
    for (int i = 0; i < mid ; i++) l[i]=a[i]; 
    
    for (int i = mid; i < n ; i++) r[i-mid]=a[i];
       
    MergeSort(l,mid);
    MergeSort(r,n-mid);
    Merge(a,l,mid,r,n-mid);
    delete (l);
    delete (r);

}

int main()
{
    int a[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17}; // creating an array of integers.
    int n;
    n = sizeof(a) / sizeof(a[0]);
    MergeSort(a, n);

    for (int atom : a)
    {
        cout << atom << " ";
    }
    return 0;
}