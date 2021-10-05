#include <iostream>
#include <algorithm>
using namespace std;

template <class t>
class node
{
    t data;
    node<t> *next;
    friend class stackh<t>;
};

template <class t>
class stackh
{
    node<t> *top;

public:
    stackh()
    {
        top = NULL;
    }
    void push(t x)
    {
        node<t> *temp = new node<t>;
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
        node<t> *temp;
        temp = top;
        top = top->next;
        delete (temp);
        temp = NULL; //check
    }
 
    char input()
    {
        t n;
        cout << "Enter Data : ";
        cin >> n;
        return n;
    }
    char Top()
    {
        node<t> *temp = top;
        return temp->data;
    }
    bool empty() { return top == NULL; };
};

class ItoP
{
    string infix;
    string postfix;
    string prifix;

public:
    void getexp();
    string InfixToPostfix(string infix);
    int HasHigherPrecedence(char operator1, char operator2);
    bool IsOperand(char C);
    bool IsOperator(char C);
    int GetOperatorWeight(char op);
    int IsRightAssociative(char op);
    void ConInfixToPostfix();
    string InfixtoPrefix(string infix);
    void ConInfixtoPrefix();
};

void ItoP  ::getexp()
{
    cout << "Enter Infix Expression \n";
    getline(cin, infix);
}

void ItoP ::ConInfixToPostfix()
{
    string postfix = InfixToPostfix(infix);
    cout << "Output = " << postfix << "\n";
}

void ItoP ::ConInfixtoPrefix()
{
    string prefix = InfixtoPrefix(infix);
    cout << "Output = " << prefix << "\n";
}

bool ItoP ::IsOperand(char C)
{
    if (C >= '0' && C <= '9')
        return true;
    if (C >= 'a' && C <= 'z')
        return true;
    if (C >= 'A' && C <= 'Z')
        return true;
    return false;
}

bool ItoP ::IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
        return true;

    return false;
}

int ItoP ::GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
    case '+':
    case '-':
        weight = 1;
        return weight;
    case '*':
    case '/':
        weight = 2;
        return weight;
    case '$':
        weight = 3;
    }
    return weight;
}

int ItoP ::IsRightAssociative(char op)
{
    if (op == '$')
        return true;
    return false;
}

int ItoP ::HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    if (op1Weight == op2Weight)
    {
        if (IsRightAssociative(op1))
            return false;
        else
            return true;
    }
    return op1Weight > op2Weight ? true : false;
}

string ItoP ::InfixToPostfix(string infix)
{
    stackh <char> S;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {

        if (infix[i] == ' ' || infix[i] == ',')
            continue;
        else if (IsOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (IsOperator(infix[i]))
        {
            while (!S.empty() && S.Top() != '(' && HasHigherPrecedence(S.Top(), infix[i]))
            {
                postfix += S.Top();
                S.pop();
            }
            S.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            S.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!S.empty() && S.Top() != '(')
            {
                postfix += S.Top();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.empty())
    {
        postfix += S.Top();
        S.pop();
    }

    return postfix;
}

string ItoP ::InfixtoPrefix(string infix)
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
    stackh <char> s;

    for (int i = 0; i < infix.length(); i++)
    {
        if (IsOperand(infix[i]))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s.Top() != '(' && !s.empty())
            {
                prefix += s.Top();
                s.pop();
            }
            if (s.Top() == '(')
            {
                s.pop();
            }
        }
        else if (IsOperator(infix[i]))
        {  
            if (GetOperatorWeight(infix[i]) > GetOperatorWeight(s.Top()))
            {
                s.push(infix[i]);
            }
            else if ((GetOperatorWeight(infix[i]) == GetOperatorWeight(s.Top())) && (infix[i] == '$'))
            {
                while ((GetOperatorWeight(infix[i]) == GetOperatorWeight(s.Top())) && (infix[i] == '$'))
                {
                    prefix += s.Top();
                    s.pop();
                }
                s.push(infix[i]);
            }
            else if (GetOperatorWeight(infix[i]) == GetOperatorWeight(s.Top()))
            {
                s.push(infix[i]);
            }
            else
            {
                while ((!s.empty()) && (GetOperatorWeight(infix[i]) < GetOperatorWeight(s.Top())))
                {
                    prefix += s.Top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    while (!s.empty())
    {
        prefix += s.Top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    ItoP  i;
    // ItoP  <int>p;
    // i.getexp();
    // i.ConInfixToPostfix();
    // i.ConInfixtoPrefix();
    int choice = 0;
    do
    {
        cout << "\n***** MAIN MENU Disigned By OM MAPARI *****" << endl;
        cout << "PRESS 1 TO Input Infix  : " << endl;
        cout << "PRESS 2 TO Convert Infix To Postfix : " << endl;
        cout << "PRESS 3 TO Convert Infix To Prifix : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        cin.clear();
        cin.ignore(123, '\n');
        switch (choice)
        {
        case 1:
            i.getexp();
            break;
        case 2:
            i.ConInfixToPostfix();
            break;
        case 3:
            i.ConInfixtoPrefix();
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}