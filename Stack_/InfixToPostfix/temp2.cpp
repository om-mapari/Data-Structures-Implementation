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
    void push(char x)
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
    {
        node *temp = top;
        return temp->data;
    }
    bool empty() { return top == NULL; };
};
bool IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    if (C >= 'a' && C <= 'z')
        return true;
    if (C >= 'A' && C <= 'Z')
        return true;
    return false;
}
int main(){
    stack s;
    string pre ;
    string postfix = "ABC/-AK/L-*";
    for (int i = 0; i < postfix.length(); i++)
    {
        if (IsOperand(postfix[i]))
        {
            s.push(postfix[i]);
        }
        else
        {
            char op1 = s.Top();
            s.pop();
            char op2 = s.Top();
            s.pop();

            pre += postfix[i] + op2 + op1;
        }
    }
    cout<<"Output "<<pre;
    
return 0;
}