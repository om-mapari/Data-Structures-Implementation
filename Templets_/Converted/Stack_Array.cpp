#include <iostream>
#define max 5
using namespace std;
template <class t>
class stack
{
private:
    t a[max];
    t top;

public:
    stack()
    {
        top = -1;
    }
    void push(t x);
    void pop();
    bool isempty(){return (top==-1);}
    bool isfull(){return (top==max-1);}

    t Top();
    
};

template <class t>
void stack<t>  :: push(t x){
    if(isfull()){cout<<"Stack OverFlow..."<<endl;return;}

    top++;
    a[top]=x;
}

template <class t>
void stack<t>  :: pop(){
    if(isempty()){cout<<"List is Empty"<<endl;return;}

    top--;
}

template <class t>
t stack<t>  :: Top(){
    return a[top];
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(5);
    s.push(9);
    s.pop();
    s.pop();
    s.Top();
    cout<<"hell";
}
