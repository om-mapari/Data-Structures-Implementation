#include <iostream>
using namespace std;
#include <vector>

class MaxHeap {
    vector <int> v;
    int N = -1;
    public : 
    void insert (int x)
    {
        N++;
        v.push_back(x);
        int ptr;
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
    void display (){
        for (int i = 0; i <= N; i++)
        {
            cout<<v[i]<<" ";
        }
    }
};
int main (){
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.display();
}
