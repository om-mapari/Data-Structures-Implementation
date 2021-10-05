#include <iostream>
#include "stackhello.h"
#include <iostream>
using namespace std;

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