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
    node *head, *tail;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void atbigin(int n);
    void insertatposition(int n, int p);
    void print();
    void deletatposition(int p);
    int input();
    int count();
    void atbigin();
    void atend(int n);
};
void linkedlist ::atbigin(int n)
{
    node *temp = new node();
}
void linkedlist ::atend(int n)
{
}
int linkedlist::input()
{
    int n;
    cout << "Enter Number/Position : ";
    while (!(cin >> n))
    {
        cout << "  *error 404 : ReEnter : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}
int main()
{
    linkedlist l;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO Insert at Beginning : " << endl;
        cout << "PRESS 2 TO Insert at Position : " << endl;
        cout << "PRESS 3 TO Delete at Position : " << endl;
        cout << "PRESS 4 TO Print the List : " << endl;
        cout << "PRESS 5 TO Count no of Elements : " << endl;
        cout << "PRESS 6 TO : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            l.atbigin(l.input());
            l.print();
            break;
        case 2:
            l.insertatposition(l.input(), l.input());
            l.print();
            break;
        case 3:
            l.deletatposition(l.input());
            l.print();
            break;
        case 4:
            l.print();
            break;
        case 5:
            cout << "No of Element in the list are " << l.count();
            cout << endl;
            break;
        case 6:
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}