#include <iostream>
#include <iomanip>
using namespace std;
struct node
{
    int data;
    node *next;
};

class linkedlist
{
private:
    node *head,*tail;

public:
    linkedlist() {
        head=NULL;
        tail=NULL;
    }
    void insert(int n);
    void atbigin(int n);
    void insertatposition(int n,int p);
    void print();
    void deletatposition(int p);
};
void linkedlist :: insert(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL) //empty linked list
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
    }
    
}
void linkedlist :: atbigin(int n){
    node *temp = new node;
    temp->data=n;
    temp->next=head;
    head=temp;
}
void linkedlist :: print(){
    node* temp = head;
    cout<<"the list is ";
    while (temp!=NULL)
    {   
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void linkedlist :: insertatposition(int n,int p){
    node *temp1 = new node();
    temp1->data= n;
    temp1->next=NULL;
    if(p==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    node *temp2 = head;
    for (int i = 0; i < p-2; i++)
    {
        temp2=temp2->next;
    }//now temp2 is pointing to n-1 th node
    temp1->next=temp2->next;
    temp2->next=temp1;
    
}
void linkedlist :: deletatposition(int p){
    node *temp1 = head;
    if(p==1){
        head=temp1->next;
        delete(temp1);
        return;
    }
    for (int i = 0; i < p-2; i++)
    {
        temp1=temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete(temp2);
    
}

int main(){
    linkedlist a;
    int x,y;
    cout<<"how many number you want to insert : ";
    cin>>x;
    for (int i = 0; i < x; i++)
     {   cout<<"\nenter no : ";
    //     cin>>y;
        a.atbigin(i);
        a.print();
    }
    // a.insertatposition(5,3);
    // a.print();
    // a.insertatposition(3,2);
    // a.print();
    // a.insertatposition(1,1);
    // a.print();
    // a.deletatposition(3);
    // a.print();

return 0;
}