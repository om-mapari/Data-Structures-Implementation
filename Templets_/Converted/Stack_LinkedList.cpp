#include <iostream>
using namespace std;
template <class t>

class node  {
    public:
    t data;
    node<t>* next;
};
template <class t>
class stack {
    node<t> *top;
    public:
    stack(){
        top = NULL;
    }
    void push(t x);
    void pop();
    bool isempty();
    t Top();
    void print();
    
};

template <class t>
bool stack<t> :: isempty(){
    return top == NULL;
}

template <class t>
void stack<t> :: push(t x){
    node<t>* temp = new node<t>();
    temp->data = x;
    temp->next = top;
    top = temp;
}

template <class t>
void stack<t> :: pop(){
    if (isempty())
    {
        cout<<"list is empty"<<endl;
        return;
    }
    
    node<t>* temp = top;
    top = top->next;
    delete(temp);
    temp = NULL;
}
template <class t>
void stack<t> :: print(){
    node<t>* temp = top;
    if (isempty())
    {
        cout<<"list is empty"<<endl;
        return;
    }
    cout<<"the list is ";
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<""<<endl;
}
template <class t>
t stack<t> ::Top (){
    return top->data;
}
int main(){
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.pop();
    // s.pop();
    // s.pop();
    cout<<"top "<<endl;
    cout<<s.Top()<<endl;
    s.print();
    return 0;
}