#include <iostream>
using namespace std;


void selectionsort (int a[],int n){
    for (int i = 0; i < n-1 ; i++){ 
        //step 1 --> temperory set
        int imin = i; // ith position
        //step 2 --> finding imin
        for (int j = i+1 ; j < n ; j++){
            if (a[j]<a[imin])
            {
                imin=j;
            }
        }
        //step 3 --> swaping 
        swap(a[i],a[imin]);
    }

}
void sort(int *a){
    int n = 6;
    for (int i = 0; i < n-2 ; i++){
        int min = i ;
        for (int j = i+1; j < n ; j++){
            if (a[j]<a[min])
            {
                min=j;
            }
            
        }
    }
}

int main(){
    int k[]= {4,9,10,5,2};
    int n =5;
    selectionsort(k,n);
    // for (int i = 0; i < 5 ; i++){
    //     cout<<k[i]<<" ";
    // }

    // int s[]={9,5,2,6,7,6};
    // sort(s);

return 0;
}