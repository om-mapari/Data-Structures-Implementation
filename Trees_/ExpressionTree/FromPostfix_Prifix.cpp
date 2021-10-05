/* Assignment 4 : DSA 
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Construct an Expression Tree from postfix and prefix expression. 
Perform recursive and nonrecursive In-order, pre-order and post-order traversals.
*/

using namespace std;
#include <iostream>
#include "stack.h"
#include "stack.cpp"

class TreeNode  //tree node 
{
public:
	char data;
	TreeNode *left;
	TreeNode *right;
};
void PostorderIterative(TreeNode *root)
{
	// empty stack and add root node
	Stack<TreeNode *> s;
	s.add(root);

	// another stack to store post-order traversal
	Stack<char> out;

	// loop till stack is empty
	while (!s.isEmpty())
	{
		// we pop a node from the stack and push the data to output stack
		TreeNode *temp = s.top();
		s.pop();

		out.add(temp->data);

		// push left and right child of popped node to the stack
		if (temp->left)
			s.add(temp->left);

		if (temp->right)
			s.add(temp->right);
	}

	// print post-order traversal
	while (!out.isEmpty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
void InorderIterative(TreeNode *root)
{
	// an empty stack
	Stack<TreeNode *> stack;

	// start from root node 
	TreeNode *curr = root;


	while (!stack.isEmpty() || curr != nullptr)
	{
		// if current node is not null, push it to the stack 
		// and move to its left child
		if (curr != nullptr)
		{
			stack.add(curr);
			curr = curr->left;
		}
		else
		{
			// else if current node is null, we pop an element from stack,

			curr = stack.top();
			stack.pop();
			cout << curr->data << " ";

			curr = curr->right;
		}
	}
}
void PreorderIterative(TreeNode *root)
{
	if (root == NULL)
		return;

	Stack<TreeNode *> s;
	s.add(root);

	while (!s.isEmpty())
	{
		// Pop the top item from stack and print it
		TreeNode *temp = s.top();
		cout << temp->data << " ";
		s.pop();

		if (temp->right)
			s.add(temp->right);
		if (temp->left)
			s.add(temp->left);
	}
}

void preorder(TreeNode *root)
{
	if (root == NULL)
		return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(TreeNode *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}
void postorder(TreeNode *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}

TreeNode *postfix(string expression)
{
	Stack<TreeNode *> stack;
	for (char i : expression)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		{
			TreeNode *a = new TreeNode();
			a->data = i;
			stack.add(a);
		}
		else
		{
			TreeNode *a = stack.top();
			stack.pop();
			TreeNode *b = stack.top();
			stack.pop();
			TreeNode *temp = new TreeNode();
			temp->data = i;
			temp->right = a;
			temp->left = b;
			stack.add(temp);
		}
	}
	return stack.top();
}

string reverseExpression(string s)
{
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == ')')
		{
			reverse += '(';
		}
		else if (s[i] == '(')
		{
			reverse += ')';
		}
		else
		{
			reverse += s[i];
		}
	}
	return reverse;
}

TreeNode *prefix(string expression)
{
	expression = reverseExpression(expression);
	Stack<TreeNode *> stack;
	for (char i : expression)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		{
			TreeNode *a = new TreeNode();
			a->data = i;
			stack.add(a);
		}
		else
		{
			TreeNode *a = stack.top();
			stack.pop();
			TreeNode *b = stack.top();
			stack.pop();
			TreeNode *temp = new TreeNode();
			temp->data = i;
			temp->left = a;
			temp->right = b;
			stack.add(temp);
		}
	}
	return stack.top();
}

int main()
{
	int choice = 0;
	while (true)
	{
		cout << "\n===============================================" << endl;
		cout << "\n***** MAIN MENU Disigned By OM MAPARI *******" << endl;
		cout << "1) Expression Tree From Postfix & All traversals recursive and non recursive : " << endl;
		cout << "2) Expression Tree From Prifix  & All traversals recursive and non recursive : " << endl;
		cout << "3) Exit" << endl;
		cout << "**ENTER CHOICE** : ";
		cin >> choice;
		cout << "===============================================\n"
			 << endl;

		if (choice == 1)
		{
			cout << "Enter Postfix Expression : ";
			string expression;
			cin >> expression;
			cout << "preorder ";
			preorder(postfix(expression));
			cout << endl;
			cout << "Inorder ";
			inorder(postfix(expression));
			cout << endl;
			cout << "postorder ";
			postorder(postfix(expression));
			cout << endl;
			cout << "PreorderIterative ";
			PreorderIterative(postfix(expression));
			cout << endl;
			cout << "InorderIterative ";
			InorderIterative(postfix(expression));
			cout << endl;
			cout << "PostorderIterative ";
			PostorderIterative(postfix(expression));
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << "\nEnter Prifix Expression : ";
			string expression2;
			cin >> expression2;
			cout << "preorder ";
			preorder(prefix(expression2));
			cout << endl;
			cout << "Inorder ";
			inorder(prefix(expression2));
			cout << endl;
			cout << "Postorder ";
			postorder(prefix(expression2));
			cout << endl;
			cout << "PreorderIterative ";
			PreorderIterative(prefix(expression2));
			cout << endl;
			cout << "InorderIterative ";
			InorderIterative(prefix(expression2));
			cout << endl;
			cout << "PostorderIterative ";
			PostorderIterative(prefix(expression2));
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			cout << "invalid input" << endl;
		}
	}
	return 0;
	// cout<<"Enter Postfix Expression : ";
	// string expression;
	// cin >> expression;
	// postfix(expression);

	// cout<<"\nEnter Prifix Expression : ";
	// string expression2;
	// cin >> expression2;
	// prefix(expression2);

	// ++A*BCD pri
	// ABC*+D+ post
	// A+B*C+D in
}
