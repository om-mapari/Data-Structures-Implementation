#include <iostream>
#include <iomanip>
using namespace std;
class student
{
    int rollno;
    string name;
    float sgpa;
    friend class doubly;
public:
    void input_student()
    {
        cout << "Enter name of the student : ";
        cin >> name; 
        cout << "Enter rollno : ";
        // cin >> rollno; //in case if we input string here program infinite chalto
        rollno = intinput();
        cout << "Enter sgpa : ";
        // cin >> sgpa;
        sgpa = intinput();
    }
    int intinput(){
    int n;
    while(!(cin>>n))
    {
        cout<<"INVALID INPUT :: ReEnter : ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return n;
}

};
class node
{ 
    student data;
    node *next;
    node *prev;
    friend class doubly;
};

class doubly
{
private:
    node *head,*tail;
public:
    doubly() {
        head=NULL;
        tail=NULL;
    }
    void atbigin();
    void atend();
    void  at_position();
    void print();
    void ReversePrint();
    int noofstudent();

    // void delete_at_position();
    // void delet_at_begin();
    // void delet_at_end();

    node *get_new_node();
    int input_Position();  
};
void doubly :: atend(){
    node *temp = head;
    node *newnode= get_new_node();
    if (head==NULL){head=newnode ; return;}

    while (temp->next!=NULL)
    {
        temp = temp->next;
    }//last pointing
    temp->next=newnode;
    newnode->prev=temp;
}
void doubly :: atbigin(){
    node *temp = get_new_node();
    temp->next= head;
    head=temp;
}
node *doubly :: get_new_node(){
    student s;
    s.input_student();
    node *newnode = new node();
    newnode->data=s;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}   

void doubly:: at_position(){
    int p = input_Position();
    if(p>1+noofstudent()){cout<<"Position not exist"<<endl;return;}

    node *newnode = get_new_node();
    
    if(p==1){
        newnode->next= head;
        head=newnode;
        return;
    }
    node *prevnode = head;
    node *nextnode;
    for (int i = 0; i < p-2; i++)
    {
        prevnode=prevnode->next;
    }//now prevnode is pointing to p-1 th node
    nextnode=prevnode->next;
    newnode->next=nextnode;
    newnode->prev=prevnode;
    prevnode->next=newnode;
    nextnode->prev=newnode;
}

void doubly :: print(){
    node* temp =head;
    cout<<endl;
    cout << "** CLASS SE10 STUDENT LIST **\n";
        cout<< setw(12) << "Position :" << setw(12) << "Name"
         << setw(12)
         << "Roll No" << setw(12)
         << "SGPA" << '\n';
    int count=1;     
    while (temp!=NULL)
    {
        cout<< setw(12) << count << setw(12) << temp->data.name << setw(12) <<temp->data.rollno << setw(12) << temp->data.sgpa<< "\n";
        temp=temp->next;
        count++;
    }
    cout<<endl;
}
void doubly ::  ReversePrint() {//error
    node *temp = head;
    if (temp==NULL){cout<<"Nummber of Student are "<<noofstudent()<<endl;return;}
   
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    cout << "** CLASS SE10 REVERSE STUDENT LIST **\n";
        cout<< setw(12) << "Position :" << setw(12) << "Name"
         << setw(12)
         << "Roll No" << setw(12)
         << "SGPA" << '\n';
    int count=1;      
    while (temp!=NULL)
    {
        cout<< setw(12) << count << setw(12) << temp->data.name << setw(12) <<temp->data.rollno << setw(12) << temp->data.sgpa<< "\n";
        temp= temp->prev;
    }
    cout<<endl;
}
int doubly :: noofstudent(){
    int count =0;
    node* temp = head;
    while (temp!=NULL)
    {   
        count++;
        temp = temp->next;
    }
    return count;
}
int doubly::input_Position()
{
    int n;
    cout << "Enter Position : ";
    while (!(cin >> n))
    {
        cout << "  *error 404 : ReEnter : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}
int main()
{   doubly a;
    int choice = 0;
    do
    {
        cout << "\n***** MAIN MENU *****" << endl;
  
        cout << "PRESS 1 TO Insert at Beginning : " << endl;
        cout << "PRESS 2 TO Insert at End : " << endl;
        cout << "PRESS 3 TO Insert at Position : " << endl;
        cout << "PRESS 4 TO Print List : " << endl;
        cout << "PRESS 5 TO Delete at Beginning : " << endl;
        cout << "PRESS 6 TO Delete at End : " << endl;
        cout << "PRESS 7 TO Delete at Position : " << endl;
        cout << "PRESS 8 TO Count no of Elements : " << endl;
        cout << "PRESS 9 TO Reverse the List : " << endl;
        cout << "PRESS 10 TO Delete whole List : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            a.atbigin();
            a.print();
            break;
        case 2:
            a.atend();
            a.print();
            break;
        case 3:
            a.at_position();
            a.print();
            break;
        case 4:
            a.print();
            break;
        case 6:
            // a.delet_at_begin();
            break;
        case 7:
            // a.delet_at_end();
            break;
        case 8:
            cout<<"Nummber of Student are "<<a.noofstudent()<<endl;
            break;
        case 9:
            a.ReversePrint();
             break;    
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
