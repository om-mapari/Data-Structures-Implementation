#include <iostream>
using namespace std;
#include<stack>

class itop{
    string expression;
    string postfix;
    public:
    void getexp();
    string InfixToPostfix(string expression);
    int HasHigherPrecedence(char operator1, char operator2);
    bool IsOperand(char C);
    bool IsOperator(char C);
    int GetOperatorWeight(char op);
    int IsRightAssociative(char op);
    void ConInfixToPostfix();
};
void itop :: ConInfixToPostfix(){
    string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}
string itop :: InfixToPostfix(string expression)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(expression[i])) 
		{
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

void itop :: getexp(){
    cout<<"Enter Infix Expression \n";
	getline(cin,expression);
}
bool itop :: IsOperand(char C){
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
bool itop :: IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;
	return false;          
}
int itop :: GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
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
int itop :: HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);


	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
int itop :: IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}
int main(){
    itop i;
    i.getexp();
    i.ConInfixToPostfix();

return 0;
}