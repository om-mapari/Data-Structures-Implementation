#include <iostream>
using namespace std;
#define max 50
class queue {
    int a[max];
    int f,r;
    public:
    queue(){
        f=r=-1;
    }
    bool empty() {return (f==-1 && r==-1);}
    bool isfull() {return (r == max-1) ;}
    void push(int x);
    void pop();
    void print();
};
void queue :: push(int x){
    if(isfull()){
        cout<<"queue is full"<<endl;
        return;
    }
    
    if(empty()){
        f=r=0;   
    }
    else
    {
        r++;
    }
    a[r] = x;
}
void queue :: pop(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }

    if(f==r){
        f=r=-1;
    }
    else{
        f++;
    }

}
void queue :: print(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"the list is ";
    for (int i = f; i <= r ; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
}
int main(){
    queue q;
    for(;;){
        cout << "\n[=== MAIN MENU ===]" << endl;
        cout << "1) push : " << endl;
        cout << "2) pop : " << endl;
        cout << "3) Print : " << endl;
        cout << "4) Exit : " << endl;
        cout << "CHOICE : ";
        int ch ;
        cin>>ch;
        if(ch==1){
            int data ;
            cout<<"Enter data : "<<endl;
            cin>>data;
            q.push(data);
            q.print();
        }
        else if(ch==2)
        {
            q.pop();
            q.print();
        }
        else if(ch==3)
        {
            q.print();
        }
        else if(ch==4)
        {
            cout<<"exiting..."<<endl;
            break;
        }
        else
        {
            cout<<"invalid input"<<endl;
        }        
        
    }
    return 0;
}