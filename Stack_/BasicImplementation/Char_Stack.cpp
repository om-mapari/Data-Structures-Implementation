#include <iostream>
using namespace std;
class node
{
    char data;
    node *next;
    friend class stack;
};
class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
        {
            return;
        }
        node *temp;
        temp = top;
        top = top->next;
        delete (temp);
        temp = NULL; //check
    }
    void print()
    {
        node *temp = top;
        cout << "the list is ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    char input()
    {
        char n;
        cout << "Enter Data : ";
        cin >> n;
        return n;
    }
    char Top() 

	{   node *temp = top;
        return temp->data;
	}
};

int main()
{
    stack l;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO Push : " << endl;
        cout << "PRESS 2 TO Pop : " << endl;
        cout << "PRESS 3 TO Print : " << endl;
        cout << "PRESS 4 TO Print Top: " << endl;
        // cout << "PRESS 5 TO : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            l.push(l.input());
            l.print();
            break;
        case 2:
            l.pop();
            l.print();
            break;
        case 3:
            l.print();
            break;
        case 4:
            cout<<"top is "<<l.Top();
            break;
        // case 4:
        //     break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
 
}