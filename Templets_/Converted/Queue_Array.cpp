#include <iostream>
using namespace std;
#define s 101
template <class t>
class queue {
    t f,r;
    t a[s];

    public:
    queue (){
        f=-1;
        r=-1;
    }
    bool ise(){return(f==-1 && r==-1);};
    bool isf(){return(r==s-1);};
    void enq(t x);
    void deq();
    void print();

};
template <class t>
void queue<t> :: enq (t x){
    if(isf()){
        cout<<"OverFlow"<<endl;
        return;
    }
    else if(ise()){
        r=0;
        f=0;
    }
    else{
        r++;
    }
    a[r]=x;
}
template <class t>
void queue<t> :: deq(){
    if(ise()){
        cout<<"Is Empty"<<endl;
        return;
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
}
template <class t>
void queue<t>:: print(){
    if(ise())
    {
        cout<<"Empty queue";
    }
    else
    {
     for (t i = f; i <= r ; i++)
        {
        cout<<" "<<a[i];
        }
    }
    cout<<endl;
    
}

int main(){
    cout<<"hello";
    return 0;
}