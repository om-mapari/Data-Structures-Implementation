#include <iostream>
using namespace std;
#include <vector>
#define max 100
class maxHeap
{
    private:
    int *tree;
    int N = -1;
    public:
    void set(int s);
    void insert(int x);
    void display();
};
void maxHeap :: set(int s)
{
    tree = new int[s];
    for (int i = 0; i < s; i++)
    {
        cout<<"Enter data : ";
        int data;
        cin>>data;
        insert(data);
    }
    
}
void maxHeap :: display()
{
    for (int i = 0; i <= N; i++)
    {
        cout<<tree[i]<<" ";
    }
    
}
void maxHeap :: insert(int x)
{
    N+=1;
    int ptr = N;
    while (ptr<0)
    {
        int par = (ptr-1)/2;
        if(x <= tree[par])
        {
            tree[ptr]=x;
            return;
        }
        tree[ptr]=tree[par];
        ptr = par;
    }
    tree[ptr]=x;
    return;
}
int main()
{
    maxHeap h;
    cout<<"Enter no : ";
    int s;
    cin>>s;
    h.set(s);
    h.display();
}