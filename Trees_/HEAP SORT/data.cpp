
/* Assignment 9 : DSA 
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Implement Heap sort to sort given set of values using max or min heap.
*/


#include<iostream>
using namespace std;
class MaxHeap {
    private:
	int *tree;
    int size;
    int N=-1;

    public:
	MaxHeap (int size);
	void insertData(int item);
    int Delete();
    void display(){
        for (int i = 0; i <= N; i++)
        {
            cout<<tree[i]<<" ";
        }
        
    }
};

MaxHeap::MaxHeap(int s) {
	tree = new int[size];
    size = s;
}

void MaxHeap::insertData(int item){
	N+=1;
	int ptr = N;
	while(ptr > 0){
		int par = (ptr-1)/2;
		if(item <= tree[par]){
			tree[ptr] = item;
			return;
		}
		tree[ptr] = tree[par];
		ptr = par;
	}
	tree[ptr] = item;
	return;
}

int MaxHeap::Delete(){
    int item = tree[0];
    int last = tree[N-1];
    N = N-1;
    int ptr = 0;
    int left = 1;
    int right = 2;
    while (right <= N-1)
    {
        if(last >= tree[left] && last >= tree[right])
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]<=tree[left])
        {
            tree[ptr] = tree[left];
            ptr = left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left = 2*ptr + 1;
        right = left + 1;
    }
    if(left=N-1 && last<tree[left]){
        tree[ptr] = tree[left];
        ptr = left;
    }
    tree[ptr]=last;
    return item;
}

int main() {
	int size;
    cout<<"Enter Size : ";
    cin>>size;
    // MaxHeap *h = new MaxHeap(size);
    MaxHeap h(size);
    cout<<"om";
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter data at "<<i<<" : ";
        int data;
        cin>>data;
        h.insertData(data);
    }

    h.display();

    // cout<<"\nSorted data : "<<endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<h.Delete()<<" ";
    // }
    
}

