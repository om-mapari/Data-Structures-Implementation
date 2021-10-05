#include <iostream>
using namespace std;

class node
{
   int data;
   node *next;
   friend class queue;
};
class queue
{
    node* frunt;
    node* rear;
    public :
    queue(){
        frunt = rear = NULL;
    }
    void push(int data);
    void pop();
    void print();
    bool empty(){return (frunt == NULL && rear == NULL);}
    node* GetNewNode(int data);
    void test(){cout<<"p"<<frunt->data;}
};
node* queue :: GetNewNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void queue :: push(int data){
    node* temp = GetNewNode(data);

    if(empty()){
        frunt = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp; //or rear = rear->next;
}
void queue :: pop(){
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    
    node* temp = frunt;
    if(frunt==rear){
        frunt = rear = NULL;
    }
    else
    {
        frunt = frunt->next;
    }
    delete(temp);
    temp = NULL;
}
void queue :: print(){
    node* temp = frunt;
    cout<<"the list is ";
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
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
            q.test();
            // q.print();
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