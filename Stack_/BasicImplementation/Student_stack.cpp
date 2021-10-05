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
        rollno = intinput();
        cout << "Enter sgpa : ";
        sgpa = intinput();
    }
    void output_student(){
        cout << setw(12) << name << setw(12) << rollno << setw(12) << sgpa << "\n";
    }
    int intinput()
    {
        int n;
        while (!(cin >> n))
        {
            cout << "INVALID INPUT :: ReEnter : ";
            cin.clear();
            cin.ignore(123, '\n');
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
    node *top;

public:
    linkedlist()
    {
        top = NULL;
    }
    void push();
    void print();
    void pop();
    int noofstudent();
    void Top();
};

void linkedlist ::push()
{
    student s;
    s.input_student();
    node *temp = new node;
    temp->data = s;
    temp->next = top;
    top = temp;
}
void linkedlist ::pop()
{
    if (top == NULL)
    {
        return;
    }
    node *temp = top;
    top = temp->next;
    delete (temp);
    temp = NULL;
}
void linkedlist ::Top()
{
    node *temp = top;
    cout << setw(12) 
         << "Roll No" << setw(12)
         << "SGPA" << '\n';
    temp->data.output_student();
}
void linkedlist ::print()
{
    node *temp = top;
    cout << endl;
    cout << "** CLASS SE10 STUDENT LIST **\n";
    cout << setw(12) << "Name"
         << setw(12)
         << "Roll No" << setw(12)
         << "SGPA" << '\n';
    int count = 1;
    while (temp != NULL)
    {
        temp->data.output_student() ;
        temp = temp->next;
        count++;
    }
    cout << endl;
}
int linkedlist ::noofstudent()
{
    int count = 0;
    node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    linkedlist a;
    int choice = 0;
    do
    {
        cout << "\n***** MAIN MENU *****" << endl;

        cout << "PRESS 1 TO PUSH : " << endl;
        cout << "PRESS 2 TO POP : " << endl;
        cout << "PRESS 3 TO PRINT " << endl;
        cout << "PRESS 4 TO PRINT TOP " << endl;
        cout << "PRESS 5 TO NO OF STUDENT " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "** ENTER CHOICE ** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.push();
            a.print();
            break;
        case 2:
            a.pop();
            a.print();
            break;
        case 3:
            a.print();
            break;
        case 4:
            a.Top();
            break;
        case 5:
            cout << "Nummber of Student are " << a.noofstudent() << endl;
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
