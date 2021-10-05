#include <iostream>
using namespace std;
template <class t>
struct node
{
    char data;
    node<T> *next;
    
};
template <class t>
class stack
{
    node<t> *top;

public:
    stack()
    {
        top<t> = NULL;
    }

    void push(t x)
    {
        node<t> *temp = new node<t>;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top == NULL)
        {
            return;
        }
        node *temp;
        temp<t> = top;
        top = top->next;
        delete (temp);
        temp = NULL;
    }

    t Top() 
	{   
        node *temp = top;
        return temp->data;
	}
};
template <class t>
t stack<t> :: Top()
{
    node *temp = top;
    return temp->data;
}

int main(){
    stack<int> s;
    s.push(10);
    return 0;
}
//for single data type 
//for multiple data type

//assignment 
//array of stack
//q using array and linkedlist

