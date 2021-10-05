#include <iostream>
#include <iomanip>
using namespace std;
class student
{
    int rollno;
    string name;
    float sgpa;
    friend class linkedlist;
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
    friend class linkedlist;
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
    void atbigin();
    void print();
    void  at_position();
    int noofstudent();
    void delet_at_position();
    void delet_at_begin();

    int input_Position();  
};

void linkedlist :: atbigin(){
    student s;
    s.input_student();
    node *temp = new node;
    temp->data= s;
    temp->next= head;
    head=temp;
}


void linkedlist:: at_position(){
    int p = input_Position();
    if(p>1+noofstudent()){cout<<"Position not exist"<<endl;return;}

    student s; 
    s.input_student();
    node *temp1 = new node();
    temp1->data = s;

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

int linkedlist::input_Position()
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

void linkedlist :: print(){
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
int linkedlist :: noofstudent(){
    int count =0;
    node* temp = head;
    while (temp!=NULL)
    {   
        count++;
        temp = temp->next;
    }
    return count;
}
void linkedlist :: delet_at_position(){
    int p=input_Position();
    if(p>noofstudent()){cout<<"Position not exist"<<endl;return;} 

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
int main()
{   linkedlist a;
    int choice = 0;
    do
    {
        cout << "\n***** MAIN MENU *****" << endl;
  
        cout << "PRESS 1 TO Insert at begin : " << endl;
        cout << "PRESS 2 TO Insert at Position : " << endl;
        cout << "PRESS 3 TO Delete at Position : " << endl;
        cout << "PRESS 4 TO Print list " << endl;
        cout << "PRESS 5 TO Print no of Studeent " << endl;
        cout << "PRESS 6 TO "<<endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "** ENTER CHOICE ** : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            a.atbigin();
            a.print();
            break;
        case 2:
            a.at_position();
            break;
        case 3:
            a.delet_at_position();
            break;
        case 4:
            a.print();
            break;
        case 5:
            cout<<"Nummber of Student are "<<a.noofstudent()<<endl;
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
