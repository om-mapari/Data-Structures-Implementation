#include <iostream>
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
    // void insert(int n);
    void atbigin();
    void insertatposition();
    void print();
    void deletatposition();
    int input();
    int inputp();
};
// void linkedlist :: insert(){
//     node *temp = new node;
//     temp->data = n;
//     temp->next = NULL;
//     if(head == NULL) //empty linked list
//     {
//         head=temp;
//         tail=temp;
//     }
//     else
//     {
//         tail->next=temp;
//         tail=tail->next;
//     }
    
// }
void linkedlist :: atbigin(){
    node *temp = new node;
    temp->data=input();
    temp->next=head;
    head=temp;
}
int input(){
    int n;
    cout<<"Enter Number : ";
    while(!(cin>>n))
    {
        cout<<"  *error 404 : ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return n;
}
int inputp(){
    int n;
    cout<<"Enter Position : ";
    while(!(cin>>n))
    {
        cout<<"  *error 404 : ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return n;
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
void linkedlist :: insertatposition(){
    node *temp1 = new node();
    temp1->data= input();
    temp1->next=NULL;
    int p=inputp();
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
void linkedlist :: deletatposition(){
    node *temp1 = head;
    int p=inputp();
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
    // int x,y;
    // cout<<"how many number you want to insert : ";
    // cin>>x;
    // for (int i = 0; i < x; i++)
    // {   cout<<"\nenter no : ";
    //     cin>>y;
    //     a.atbigin(y);
    //     a.print();
    // }
    // a.insertatposition(5,3);
    // a.print();
    // a.insertatposition(3,2);
    // a.print();
    // a.insertatposition(1,1);
    // a.print();
    // a.deletatposition(3);
    // a.print();
    int c =0;
    do
    {   cout<<"Enter choice :";
        cin>>c;
        switch(c)
        {   
            case 1:
            a.atbigin();
            a.print();
            break;
            case 2:
            a.insertatposition();
            a.print();
            break;
            case 3:
            a.deletatposition();
            a.print();
            case 4:
            a.print();
            break;
            default:
            cout<<"error";
            break;
        }

    } while (c!=0);
    

return 0;
}