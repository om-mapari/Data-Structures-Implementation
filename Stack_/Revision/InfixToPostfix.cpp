#include <iostream>
using namespace std;
template <class t>
//a+b*(c^d-e)^(f+g*h)-i
class node  {
    public:
    t data;
    node<t>* next;
};
template <class t>
class stack {
    node<t> *top;
    public:
    stack(){
        top = NULL;
    }
    void push(t x);
    void pop();
    bool isempty();
    t Top();
    void print();

    
};

template <class t>
bool stack<t> :: isempty(){
    return top == NULL;
}

template <class t>
void stack<t> :: push(t x){
    node<t>* temp = new node<t>();
    temp->data = x;
    temp->next = top;
    top = temp;
}

template <class t>
void stack<t> :: pop(){
    if (isempty())
    {
        cout<<"list is empty"<<endl;
        return;
    }
    
    node<t>* temp = top;
    top = top->next;
    delete(temp);
    temp = NULL;
}
template <class t>
void stack<t> :: print(){
    node<t>* temp = top;
    if (isempty())
    {
        cout<<"list is empty"<<endl;
        return;
    }
    cout<<"the list is ";
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<""<<endl;
}
template <class t>
t stack<t> ::Top (){
    return top->data;
}


class Convertor
{
    string infix;
    string postfixExp;

public:
    void InfixtoPostfix(string infix);
    void getexp();
    void ConInfixToPostfix();
    string InfixToPostfix(string infix);

    //supportive function
    bool IsOperand(char C);
    bool IsOperator(char C);
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
    stack<char> s;
    string postfix; //local variable
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ' || infix[i] == ',')
            continue;

        if (IsOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.Top() != '(') && (!s.isempty()))
            {
                char temp = s.Top();
                postfix += temp;
                s.pop();
            }
            if (s.Top() == '(')
            {
                s.pop();
            }
        }
        else if (IsOperator(infix[i]))
        {
            if (s.isempty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (Precedence(infix[i]) > Precedence(s.Top()))
                {
                    s.push(infix[i]);
                }
                else if ((Precedence(infix[i]) == Precedence(s.Top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
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
int evaluatePostfix(char* exp)  
{  
    // Create a stack of capacity equal to expression size  
    stack<int> s;
    int i;  
  
    // See if stack was created successfully    
  
    // Scan all characters one by one  
    for (i = 0; exp[i]; ++i)  
    {  
        //if the character is blank space then continue  
        if(exp[i] == ' ')continue;  
          
        // If the scanned character is an  
        // operand (number here),extract the full number  
        // Push it to the stack.  
        else if (isdigit(exp[i]))  
        {  
            int num=0;  
              
            //extract full number  
            while(isdigit(exp[i]))  
            {  
                num = num * 10 + (int)(exp[i] - '0');  
                i++;  
            }  
            i--;  
              
            //push the element in the stack  
            s.push(num);  
        }  
          
        // If the scanned character is an operator, pop two  
        // elements from stack apply the operator  
        else
        {  
            int val1 = s.Top();
            s.pop();
            int val2 = s.Top();
            s.pop();
              
            switch (exp[i])  
            {  
            case '+': s.push( val2 + val1); break;  
            case '-': s.push( val2 - val1); break;  
            case '*': s.push(val2 * val1); break;  
            case '/': s.push( val2 / val1); break;  
              
            }  
        }  
    }  
    return s.Top();  
}  
int main()
{
    Convertor c;
    c.getexp();
    c.ConInfixToPostfix();
}