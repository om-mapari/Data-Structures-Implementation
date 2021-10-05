#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
/*
   stack - 
   push 
   pop
   isempty
   top
*/
void push_attop(node* &top,int x)
{
    node* temp = new node();
    temp->data = x;

    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next= top;
        top = temp;
    }
    
}
bool isempty(node* top)
{
    return top == NULL;
}
void pop_attop(node* &top)
{
    if(isempty(top)) return;

    node* temp = top;
    top = top->next;
    delete temp;
}
int Top(node* top)
{
    return top->data;
}

void print (node* top)
{
    while (top != NULL)
    {
        cout<<top->data<<"->";
        top = top->next;;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    //push 5 element 
    node* top = NULL;
    push_attop(top,1);
    push_attop(top,2);
    push_attop(top,3);
    push_attop(top,4);
    push_attop(top,5);
    print(top);

    //pop 2 element 
    pop_attop(top);
    pop_attop(top);
    print(top);

    //isempty
    if(isempty(top)) cout<<"is empty"<<endl;
    else
    {
        cout<<"not empty"<<endl;
    }
    
    //top
    cout<<Top(top)<<endl;

    //print stack whole
    print(top);

    //check where top pointing
    cout<<top->data<<endl;

    return 0;
}