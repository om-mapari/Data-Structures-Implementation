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

class ItoP
{
    string expression;
    string postfix;
    string prifix;

public:
    void getexp();
    string InfixToPostfix(string expression);
    int HasHigherPrecedence(char operator1, char operator2);
    bool IsOperand(char C);
    bool IsOperator(char C);
    int GetOperatorWeight(char op);
    int IsRightAssociative(char op);
    void ConInfixToPostfix();
    string postToPre(string postfix);
};

void ItoP ::getexp()
{
    cout << "Enter Infix Expression \n";
    getline(cin, expression);
}
void ItoP ::ConInfixToPostfix()
{
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << "\n";
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
    int Weightof1 = GetOperatorWeight(op1);
    int Weightof2 = GetOperatorWeight(op2);

    if (Weightof1 == Weightof2)
    {
        if (IsRightAssociative(op1))
            return false;
        else
            return true;
    }
    return Weightof1 > Weightof2 ? true : false;
}
string ItoP ::InfixToPostfix(string expression)
{
    stack S;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++)
    {

        if (expression[i] == ' ' || expression[i] == ',')
            continue;
        else if (IsOperator(expression[i]))
        {
            while (!S.empty() && S.Top() != '(' && HasHigherPrecedence(S.Top(), expression[i]))
            {
                postfix += S.Top();
                S.pop();
            }
            S.push(expression[i]);
        }

        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }
        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }
        else if (expression[i] == ')')
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
string ItoP :: postToPre(string postfix)
{
    stack s;
    string pre = "";
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
    return pre;
}

int main()
{   string str = "ABC/-AK/L-*";
    ItoP i;
    // i.getexp();
    cout<<i.postToPre(str);
    // i.ConInfixToPostfix();
    // int choice = 0;
    // do
    // {
    //     cout << "\n***** MAIN MENU Disigned By OM MAPARI *******" << endl;
    //     cout << "PRESS 1 TO Input Infix Expression : " << endl;
    //     cout << "PRESS 2 TO Convert Infix To Postfix : " << endl;
    //     cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
    //     cout << "**ENTER CHOICE** : ";
    //     cin >> choice;
    //     cin.clear();
    //     cin.ignore(123, '\n');
    //     switch (choice)
    //     {
    //     case 1:
    //         i.getexp();
    //         break;
    //     case 2:
    //         i.ConInfixToPostfix();
    //         break;
    //     default:
    //         (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
    //         break;
    //     }

    // } while (choice != 0);
    // return 0;
}

// int main()
// {
//     stack l;
//     int choice = 0;
//     do
//     {
//         cout << "\n*****MAIN MENU*****" << endl;
//         cout << "PRESS 1 TO Push : " << endl;
//         cout << "PRESS 2 TO Pop : " << endl;
//         cout << "PRESS 3 TO Print : " << endl;
//         // cout << "PRESS 4 TO : " << endl;
//         // cout << "PRESS 5 TO : " << endl;
//         cout << "**ENTER CHOICE** : ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             l.push(l.input());
//             l.print();
//             break;
//         case 2:
//             l.pop();
//             l.print();
//             break;
//         case 3:
//             l.print();
//             break;
//         // case 4:
//         //     break;
//         // case 4:
//         //     break;
//         default:
//             (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
//             break;
//         }
//     } while (choice != 0);
//     return 0;
// }
