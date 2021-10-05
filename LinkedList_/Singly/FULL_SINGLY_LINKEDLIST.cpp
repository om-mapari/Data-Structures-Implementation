#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;
    friend class linkedlist;
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
    void atend(int n);
    void insertatposition(int p, int n);

    void delet_at_begin();
    void delete_at_end();
    void deletatposition(int p);
    void delete_list();

    void print();
    void reverse();
    int input();
    int count();
    int input_Position();
    bool isempty() { return (head == NULL); };
};
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
int linkedlist::input()
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
void linkedlist ::atbigin(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
}
void linkedlist ::atend(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    } //why
    node *end = head;
    while (end->next != NULL) //because
    {
        end = end->next;
    }
    end->next = temp;
}
void linkedlist ::delet_at_begin()
{
    if (isempty())
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head;
    head = temp->next;
    delete (temp);
}
void linkedlist ::delete_at_end()
{
    if (isempty())
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp1 = head;
    node *temp2; //MUST required Second last
    if (temp1->next == NULL)
    {
        head = NULL;
        delete (temp1);
        return;
    } //Must conditionm for only one element
    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    delete (temp1);
}
void linkedlist ::print()
{
    node *temp = head;
    cout << "the list is ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; //temp become NULL means temp ka prev is last node
                           //i.e temp.data is nothing & temp.next is also nothing
    }
    cout << endl;
}
int linkedlist ::count()
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
void linkedlist ::insertatposition(int p, int n)
{
    if (p <= 0)
    {
        return;
    }
    if (p > count() + 1)
    {
        cout << "Position Not Exist " << endl;
        return;
    }

    node *temp1 = new node();
    temp1->data = n;
    temp1->next = NULL;
    if (p == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    node *temp2 = head;
    for (int i = 0; i < p - 2; i++)
    {
        temp2 = temp2->next;
    } //now temp2 is pointing to n-1 th node
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void linkedlist ::reverse()
{

    node *current = head;
    node *next, *prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void linkedlist ::delete_list()
{
    node *current = head;
    node *prev;

    while (current != NULL)
    {
        prev = current;
        current = current->next;
        delete (prev);
    }
    head = current;
}
void linkedlist ::deletatposition(int p)
{
    if (p > count())
    {
        cout << "Position Not Exist " << endl;
        return;
    } //just extra

    node *temp1 = head;
    if (p == 1)
    {
        head = temp1->next;
        delete (temp1);
        return;
    }
    for (int i = 0; i < p - 2; i++)
    {
        temp1 = temp1->next;
    } //raach to the n-1 th node
    node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete (temp2);
}

int main()
{
    linkedlist l;
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
        cout << "PRESS 7 TO Delete at Position : " << endl;
        cout << "PRESS 8 TO Count no of Elements : " << endl;
        cout << "PRESS 9 TO Reverse the List : " << endl;
        cout << "PRESS 10 TO Delete whole List : " << endl;
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
            l.atend(l.input());
            l.print();
            break;
        case 3:
            l.insertatposition(l.input_Position(), l.input());
            l.print();
            break;
        case 4:
            l.print();
            break;
        case 5:
            l.delet_at_begin();
            l.print();
            break;
        case 6:
            l.delete_at_end();
            l.print();
            break;
        case 7:
            l.deletatposition(l.input_Position());
            l.print();
            break;
        case 8:
            cout << "No of Element in the list are " << l.count() << endl;
            break;
        case 9:
            l.reverse();
            l.print();
            break;
        case 10:
            l.delete_list();
            cout << "Now No of Element in the list are " << l.count() << endl;
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}