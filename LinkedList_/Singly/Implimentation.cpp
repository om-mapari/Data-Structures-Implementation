#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node* newN(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertatfrunt(node* &head, int data)
{
    node* temp = newN(data);
    if (head == NULL)
    {
        head = temp;
    }    
    else
    {
        temp->next = head;
        head = temp;
    }
    
}
void insertatend(node* &head,int data)
{
    if(head == NULL)
    {
        head = newN(data);
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = newN(data);
    }
}

void print (node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
void printR (node* head)
{
    if(head == NULL){  return ;}
    cout<<head->data<<"->";
    printR(head->next);
}
void printRev (node* head)
{
    if(head == NULL){  return ;}
    printRev(head->next);
    cout<<head->data<<"->";
}
void Reverse(node* &head)
{
    node* curr = head;
    node* prev = nex =NULL;
    while (curr != NULL)
    {
       
    }
    head = prev;
}
int main()
{
    node *head = NULL;
    insertatend(head, 1);
    insertatend(head, 2);
    insertatend(head, 3);
    insertatend(head, 4);
    insertatend(head, 5);
    insertatend(head, 6);
    // printR(head);
    // cout<<endl;
    // printRev(head);
    Reverse(head);
    print(head);

    cout<<endl<<head->data<<endl;
    return 0;
}
