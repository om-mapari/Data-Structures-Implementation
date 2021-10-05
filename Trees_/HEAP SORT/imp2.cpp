#include <iostream>
using namespace std;

class Tree {
	int * tree;
	int MaxSize;
	int index;
public:
	Tree(int MaxSize);
	void insertData(int item);
	void display();
};

Tree::Tree(int MaxSize) {
	this->MaxSize = MaxSize;
	index = -1;
	this->tree = new int[MaxSize];
}

void Tree::insertData(int item){
	index+=1;
	int ptr = index;
	while(ptr > 0){
		int par = (ptr-1)/2;
		if(item <= tree[index]){
			tree[ptr] = item;
			return;
		}
		tree[ptr] = tree[par];
		ptr = par;
	}
	tree[ptr] = item;
	return;
}

void Tree::display(){
	for(int i = 0 ; i < index+1 ; i++){
		cout << tree[i] << endl;
	}
}
int main(){
    Tree t(10);
    int x;
    for (size_t i = 0; i < 5; i++)
    {
        cout<<"enter : ";
        cin>>x;
        t.insertData(x);
    }
    t.display();
    return 0;

}