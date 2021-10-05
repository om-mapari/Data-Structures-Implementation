/* DSA ASSIGNMENT 2 - STACK 

* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT NO 20 :
Implement stack as an abstract data type using singly linked list and use this ADT for conversion of
infix expression to postfix, prefix and evaluation of postfix and prefix expression.

*/
#include <iostream>
#include <algorithm>

using namespace std;
template <class t> // template  generic class of stack
class node
{ //node class
public:
    t data;
    node<t> *next;
};
template <class t> //t data type
class stack
{
    node<t> *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(t x); //push
    void pop();     // Pop operation to remove an element from top of stack.
    bool isempty(); //check empty
    t Top();        // Top operation to return element at top of stack.
    void print();
    void add_bottom(t x);
};

template <class t>
bool stack<t>::isempty()
{
    return top == NULL;
}

template <class t>
void stack<t>::push(t x)
{
    node<t> *temp = new node<t>();
    temp->data = x;
    temp->next = top;
    top = temp;
}

template <class t>
void stack<t>::pop()
{ // Pop operation to remove an element from top of stack.

    if (isempty())
    {
        cout << "list is empty" << endl;
        return;
    }

    node<t> *temp = top;
    top = top->next;
    delete (temp);
    temp = NULL;
}
template <class t>
void stack<t>::add_bottom(t x)
{
    node<t> *temp = new node<t>();
    temp->data = x;
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
        return;
    }
    node<t> *end = top;
    while (end->next != NULL)
    {
        end = end->next;
    }
    end->next = temp;
}
template <class t>
void stack<t>::print()
{ //to print
    node<t> *temp = top;
    if (isempty())
    {
        cout << "list is empty" << endl;
        return;
    }
    cout << "The value is ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "" << endl;
}
template <class t>
t stack<t>::Top()
{ // Top operation to return element at top of stack.
    return top->data;
}
#include <cmath>
class Convertor
{
    string infix;
    string PrefixExp;
    string postfixExp;

public:
    void InfixtoPrefix(string infix);
    void getexp();
    void ConInfixToPrefix();
    // Function to convert Infix expression to Prefix
    string InfixToPrefix(string infix);
    // Function to convert Infix expression to postfix
    string InfixToPostfix(string infix);
    void ConInfixToPostfix();

    //supportive functions

    // Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
    bool IsOperand(char C);
    // Function to verify whether a character is operator symbol or not.
    bool IsOperator(char C);
    // Function to verify whether an operator has higher precedence over other
    int Precedence(char c);
};
int Convertor ::Precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
bool Convertor ::IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
        return true;

    return false;
}
void Convertor ::getexp()
{
    cout << "Enter Infix Expression : ";
    getline(cin, infix);
}
void Convertor ::ConInfixToPrefix()
{
    PrefixExp = InfixToPrefix(infix);
    cout << "Prefix output = " << PrefixExp << "\n";
}
void Convertor ::ConInfixToPostfix()
{
    postfixExp = InfixToPostfix(infix);
    cout << "Postfix Output = " << postfixExp << "\n";
}
bool Convertor ::IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    if (C >= 'a' && C <= 'z')
        return true;
    if (C >= 'A' && C <= 'Z')
        return true;
    return false;
}

string Convertor ::InfixToPostfix(string infix)
{
    // Declaring a Stack

    stack<char> s;
    string postfix; //local variable

    // Scanning each character from left.
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ' || infix[i] == ',')
            continue;

        // if character is an operand
        if (IsOperand(infix[i]))
        {
            postfix += infix[i];
        }
        // if opening brackets arrive push
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        // if closing bracket arrive
        else if (infix[i] == ')')
        {
            while ((s.Top() != '(') && (!s.isempty()))
            {
                postfix += s.Top();
                s.pop();
            }
            if (s.Top() == '(')
            {
                s.pop();
            }
        }
        // if operator arrive
        else if (IsOperator(infix[i])) //can use only else
        {
            if (s.isempty()) //is empty
            {
                s.push(infix[i]);
            }
            else //not empty
            {
                if (Precedence(infix[i]) > Precedence(s.Top()))
                {
                    s.push(infix[i]);
                }
                else if ((Precedence(infix[i]) == Precedence(s.Top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]); //special case
                }
                else // Precedence(infix[i]) <= Precedence(s.Top())
                {
                    while ((!s.isempty()) && (Precedence(infix[i]) <= Precedence(s.Top())))
                    {
                        postfix += s.Top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.isempty())
    {
        postfix += s.Top();
        s.pop();
    }

    return postfix;
}
string Convertor ::InfixToPrefix(string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    //now infix to postfix algo
    prefix = InfixToPostfix(infix); //wrong aahe -> use new logic
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
void evaluatePostfix()
{
    string expression;
    int valueInt;
    stack<char> expression_stack;
    stack<int> values;
    cin >> expression;

    for (char i : expression)
    {
        cout << i << endl;
        expression_stack.add_bottom(i);
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        {
            cout << "Enter the value of " << i << endl;
            cin >> valueInt;

            values.add_bottom(valueInt);
        }
    }

    stack<int> value;
    while (!expression_stack.isempty()) // Scan all characters one by one in stack
    {
        char i = expression_stack.Top(); //oprend push
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        {
            value.push(values.Top());
            values.pop();
            expression_stack.pop();
            continue;
        }
        else
        {
            int B = value.Top(); //Pop two and apply operation
            value.pop();         //then again push
            int A = value.Top();
            value.pop();
            switch (i)
            {
            case ('+'):
            {
                value.push(A + B);
                break;
            }
            case ('-'):
            {
                value.push(A - B);
                break;
            }
            case ('*'):
            {
                value.push(A * B);
                break;
            }
            case ('/'):
            {
                value.push(A / B);
                break;
            }
            case ('^'):
            {
                value.push(pow(A, B));
                break;
            }
            }
            expression_stack.pop();
        }
    }
    cout << "\n"
         << endl;
    value.print();
    cout << endl;
}
void evaluatePrefix()
{
    string expression;
    int valueInt;
    stack<char> expression_stack;
    stack<int> values;
    cin >> expression;

    reverse(expression.begin(), expression.end());
    for (char i : expression)
    {
        cout << i << endl;
        expression_stack.add_bottom(i);
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        {
            cout << "Enter the value of " << i << endl;
            cin >> valueInt;

            values.add_bottom(valueInt);
        }
    }

    stack<int> value;
    while (!expression_stack.isempty()) // Scan all characters one by one in stack
    {
        char i = expression_stack.Top(); //oprend push
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
        {
            value.push(values.Top());
            values.pop();
            expression_stack.pop();
            continue;
        }
        else
        {
            int B = value.Top(); //Pop two and apply operation
            value.pop();         //then again push
            int A = value.Top();
            value.pop();
            switch (i)
            {
            case ('+'):
            {
                value.push(A + B);
                break;
            }
            case ('-'):
            {
                value.push(A - B);
                break;
            }
            case ('*'):
            {
                value.push(A * B);
                break;
            }
            case ('/'):
            {
                value.push(A / B);
                break;
            }
            case ('^'):
            {
                value.push(pow(A, B));
                break;
            }
            }
            expression_stack.pop();
        }
    }
    cout << "\n"
         << endl;
    value.print();
    cout << endl;
}

int main()
{
    Convertor c;

    int choice = 0;
    do
    {
        cout << "\n===============================================" << endl;
        cout << "\n***** MAIN MENU Disigned By OM MAPARI *******" << endl;
        cout << "PRESS 1 TO input Infix Expression : " << endl;
        cout << "PRESS 2 TO Convert Infix To Postfix : " << endl;
        cout << "PRESS 3 TO Convert Infix To Prifix : " << endl;
        cout << "PRESS 4 TO Postfix Evaluation :" << endl;
        cout << "PRESS 5 TO Prifix Evaluation :" << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        cout << "===============================================\n"
             << endl;
        cin.clear();
        cin.ignore(123, '\n');
        switch (choice)
        {
        case 1:
            c.getexp();
            break;
        case 2:
            c.ConInfixToPostfix();
            break;
        case 3:
            c.ConInfixToPrefix();
            break;
        case 4:
            evaluatePostfix();
            break;
        case 5:
            evaluatePrefix();
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
//b*(c^d)^(g*h)-i
//((a+b-c)*d^e^f)/g
// INFIX EXPRESSION: ((a+b-c)*d^e^f)/g

// PREFIX EXPRESSION: /*-+abc^d^efg