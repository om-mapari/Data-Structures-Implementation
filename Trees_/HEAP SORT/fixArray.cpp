#include <iostream>
using namespace std;
#include <vector>
#define max 100

//delete functon check
class MaxHeap {
    int v[max];
    int N = -1;
    public : 
    void insert (int x)
    {
        N++;
        v[N] = x;
        int ptr = N;
        while (ptr>0)
        {
            int par = (ptr-1)/2;
            if (v[par] < v[ptr])
            {
                swap(v[par],v[ptr]);
                ptr = par;
            }
            else
            {
                break;
            }
        }
    }
    void display(){
        cout<<"MaxHeap = ";
        for (int i = 0; i <= N; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    int Delete()
    {
        if (N==0){int data = v[0];N=-1;return data;}
        int data = v[0];
        swap(v[0],v[N]);
        N--;
        int ptr = 0;
        while (true)
        {
            if (v[2*ptr+1]>v[ptr])
            {
                swap(v[2*ptr+1],v[ptr]);
                ptr = 2*ptr+1;
            }
            else if(v[2*ptr+2]>v[ptr])
            {
                swap(v[2*ptr+2],v[ptr]);
                ptr = 2*ptr+2;
            }
            else
            {
                break;
            }
        }
        return data;
    }
};
int main (){
    MaxHeap h;
    for (int i = 0; i < 5; i++)
    {
        int data;
        cin>>data;
        h.insert(data);
    }
    h.display();
    for (int i = 0; i < 2; i++)
    {
        cout<<"process "<<endl;
        cout<<h.Delete()<<" sort"<<endl;
        h.display();
    }
    
    // h.insert(10);
    // h.insert(20);
    // h.insert(15);
    // h.insert(30);
    // h.insert(40);
    h.display();
}
