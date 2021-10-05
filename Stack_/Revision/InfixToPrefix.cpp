#include <iostream>
#include <algorithm>
using namespace std;
template <class t>
//a+b*(c^d-e)^(f+g*h)-i
//(a-b/c)*(a/k-l) = *-a/bc-/akl
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
    string PrefixExp;

public:
    void InfixtoPrefix(string infix);
    void getexp();
    void ConInfixToPrefix();
    string InfixToPrefix(string infix);

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
void Convertor ::ConInfixToPrefix()
{
    PrefixExp = InfixToPrefix(infix);
    cout << "Prefix output = " << PrefixExp << "\n";
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
string Convertor ::InfixToPrefix(string infix)
{
    stack<char> s;
    string prefix;
    reverse(infix.begin(), infix.end());
 
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    //now infix to postfix algo
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.Top() != '(') && (!s.isempty())) {
                prefix += s.Top();
                s.pop();
            }
 
            if (s.Top() == '(') {
                s.pop();
            }
        }
        else if (IsOperator(infix[i])) {
            if (s.isempty()) {
                s.push(infix[i]);
            }
            else {
                if (Precedence(infix[i]) > Precedence(s.Top())) {
                    s.push(infix[i]);
                }
                else if ((Precedence(infix[i]) == Precedence(s.Top()))
                    && (infix[i] == '^')) {
                    while ((Precedence(infix[i]) == Precedence(s.Top()))
                        && (infix[i] == '^')) {
                        prefix += s.Top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (Precedence(infix[i]) == Precedence(s.Top())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.isempty()) && (Precedence(infix[i]) < Precedence(s.Top()))) {
                        prefix += s.Top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
 
    while (!s.isempty()) {
        prefix += s.Top();
        s.pop();
    }
 
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    Convertor c;
    c.getexp();
    c.ConInfixToPrefix();
}