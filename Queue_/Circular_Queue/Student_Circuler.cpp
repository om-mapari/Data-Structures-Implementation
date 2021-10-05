/* Assignment 2 : DSA - QUEUE
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :

Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (enqueue)
b) Deletion (dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)
*/


#include <iostream>
#include <iomanip>
using namespace std;
#define size 4 // define size of array student

// Creating a class named student
class student
{
    string name;
    int rollno;
    int marks;
    friend class queue;
};
// Creating a class named Queue.
class queue
{
    student s[size];
    int f, r;

public:
// Constructor - set front and rear as -1. 
// We are assuming that for an empty Queue, both front and rear will be -1.
    queue()
    {
        f = r = -1;
    }
    // To check wheter Queue is empty or not
    bool isempty() { return (f == -1 && r == -1); };
    // To check whether Queue is full or not
    bool isfull() { return ((r + 1) % size == f); };
    // Inserts an element in queue at rear end
    void enqueue();
    // Removes an element in Queue from front end.
    void dequeue();
    // Printing student list
    void print();
};
void queue ::enqueue()
{
    if (isfull())
    {
        cout << "OverFlow... " << endl;
        return;
    }
    else if (isempty())
    {
        f = r = 0;
    }
    else
    {
        r = (r + 1) % size;
    }

    cout << "Enter Name : ";
    cin >> s[r].name;
    cout << "Enter rollno : ";
    cin >> s[r].rollno;
    cout << "Enter totel marks : ";
    cin >> s[r].marks;
}
void queue ::dequeue()
{
    if (isempty())
    {
        cout << "Queue is Empty ";
        return;
    }
    else if (r == f)
    {
        r = f = -1;
    }
    else
    {
        f = (f + 1) % size;
    }
    cout<<"deleted";
}
void queue ::print()
{
    if (isempty())
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        int count = (r + size - f) % size + 1;
        cout << setw(12)
             << "Roll No"
             << setw(12)
             << "Name" << setw(12)
             << "SGPA" << '\n';
        for (int i = 0; i < count; i++)
        {
            int index = (f + i) % size;

            cout << setw(12)
                 << s[index].rollno
                 << setw(12)
                 << s[index].name << setw(12)
                 << s[index].marks << '\n';
        }
    }
}
int main()
{
    queue o;
    int choice = 0;
    while (choice != 4)
    {
        cout << "\n=========================================" << endl;
        cout << "* MENU Disigned By OM MAPARI * \n ";
        cout << "1. Press 1 to Insert Student data  \n";
        cout << " 2. Press 2 to Delete Data  \n";
        cout << " 3. Press 3 to Display Data  \n";
        cout << " 4. Press 4 for Exit \n";
        cout << " Enter Choice : ";
        cin >> choice;
        cout << "=========================================\n"
             << endl;
        switch (choice)
        {
        case 1:
            o.enqueue();
            break;
        case 2:
            o.dequeue();
            break;
        case 3:
            o.print();
            break;
        default:
            cout<<"invalid choice"<<endl;
            break;
        }
    }
    return 0;
}