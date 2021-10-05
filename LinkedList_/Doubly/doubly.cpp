#include <iostream>
using namespace std;
class node
{
    int data;
    node* next;
    node* prev;
    friend class doubly;
};
class doubly{
    node *head,*tail;
    public:
    doubly(){
        head=tail=NULL;
    }
    void insert_begin();
    void insert_end();
    void delete_begin();
    void delete_end();
    node *get_new_node();
    void print();
    void reverse_print();
    int input();
    int count();
};
void doubly :: delete_begin(){
    node* temp = head;
    head=temp->next; //or head = head->next; //hesd shift
    head->prev=NULL;
    free(temp);
}
void doubly :: delete_end(){
    node* temp=head;
    while (temp->next!=NULL)
    {
        /* code */
    }
    

}
void doubly :: insert_end(){
    node *newnode = get_new_node();
    if(head==NULL){head=newnode ;return;}
    node *temp = head ;
    while (temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    
}
void doubly :: insert_begin()
{
    node *newnode = get_new_node();
    if(head==NULL){head=newnode;return;}

    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
node *doubly :: get_new_node(){
    node *newnode = new node();
    newnode->data=input();
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}   
void doubly :: print(){
    node *temp = head;
    cout<<"The List is ";
    while (temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
void doubly :: reverse_print(){
    node *temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }//temp pointing to last pointer
    cout<<"The Reverse List is ";
    while (temp!=NULL)
    {
        cout<<" "<<temp->data;
        temp = temp->prev;
    }
    cout<<endl;
    
}
int doubly::input()
{
    int n;
    cout << "Enter Data : ";
    while (!(cin >> n))
    {
        cout << "  *error 404 : ReEnter : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}
int doubly ::count()
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next; 
    }
    return count;
}
int main(){
    doubly d;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO Insert at Beginning : " << endl;
        cout << "PRESS 2 TO Insert at End : " << endl;
        cout << "PRESS 3 TO Insert at Position : " << endl;
        cout << "PRESS 4 TO Print List : " << endl;
        cout << "PRESS 5 TO Delete at Beginning : " << endl;
        cout << "PRESS 6 TO Delete at End : " << endl;
        // cout << "PRESS 7 TO Delete at Position : " << endl;
        // cout << "PRESS 8 TO Count no of Elements : " << endl;
        cout << "PRESS 9 TO Reverse the List : " << endl;
        // cout << "PRESS 10 TO Delete whole List : " << endl;
        // cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            d.insert_begin();
            d.print();
            break;
        case 2:
            d.insert_end();
            d.print();
            break;
        case 3:
              
            break;
        case 4:
            d.print();
            break;
        // case 5:
        //     d.delete_begin();
        //     d.print();
        //     break;
        // case 6:
        //     d.delete_end();
        //     d.print();
        //     break;
        case 7:
            
            break;
        case 8:
            cout << "No of Element in the list are " << d.count()<<endl;
            break;
        case 9:
            d.reverse_print();
            break;            
        case 10:
            
            break;                    
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;

return 0;
}