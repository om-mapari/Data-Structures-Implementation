/* ASSIGNMENT 6 : DSA : Threaded Binary Tree
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Implement In-order Threaded Binary Tree and traverse it in In-order and Pre-order

*/
#include <iostream>
using namespace std;

class TbtNode//TBTNODE
{
public:
    int data;
    TbtNode *left, *right;
    bool leftThread, rightThread;
};
class TBT
{
private:
    TbtNode *root;

public:
    TBT();
    TbtNode *GetTbtNode(int x);// TO GET NEW NODE 
    void Insert();// TO INSERT DATA
    void Inorder();// INORDER TRIVERSAL
    void Preorder();// PREORDER TRIVERSAL

};
TbtNode *TBT ::GetTbtNode(int x)
{
    //creating a node with given data
    TbtNode *p = new TbtNode();
    p->data = x;
    p->left = p->right = NULL; //setting left and right as null
    p->leftThread = 0;         //setting both as false
    p->rightThread = 0;
    return p; //returning node
}
TBT ::TBT()
{
    root = GetTbtNode(0);
    root->left = root->right = root;
    root->leftThread = 1;
    root->rightThread = 1;
}
void TBT ::Insert()
{
    TbtNode *temp1, *temp2;
    int x, choice;
    bool flag = 1;
    cout << "ENTER VALUE : "; //value for node
    cin >> x;

    if (root->left == root)
    {
        temp1 = GetTbtNode(x);
        temp1->left = root;
        temp1->leftThread = 1;
        temp1->rightThread = 1;
        temp1->right = root;
        root->left = temp1;
        root->leftThread = 0;
    }
    else
    {
        //if root node is already present
        temp1 = root->left;
        do
        {
            //keep repeating unitl insertion takes place
            cout << "ROOT NODE : " << temp1->data << endl;
            cout << "INSERT TO \n1.LEFT  \n2.RIGHT " << endl;
            cin >> choice;

            if (choice == 1)
            {
                if (temp1->leftThread)
                {
                    //check if left subtree is present
                    //if not then it will be executed
                    temp2 = GetTbtNode(x);
                    temp2->left = temp1->left;
                    temp2->right = temp1;
                    temp2->rightThread = temp2->leftThread = 1;
                    temp1->left = temp2;
                    temp1->leftThread = 0;
                    flag = 0;
                }
                else
                {
                    //if not null go ahead till u find insertion point
                    temp1 = temp1->left;
                }
            }
            else
            {
                //for right link insertion
                if (temp1->rightThread)
                {
                    //check if right subtree is present
                    temp2 = GetTbtNode(x);
                    temp2->right = temp1->right;                //points to succesor
                    temp2->left = temp1;                        //points to predecessor
                    temp2->leftThread = temp2->rightThread = 1; //set both as 1
                    temp1->right = temp2;                       //link parent to child
                    temp1->rightThread = 0;
                    flag = 0;
                }
                else
                {
                    temp1 = temp1->right;
                    //if not null go ahead till u find insertion point
                }
            }
        } while (flag != 0);
    }

    cout << x << " INSERTED" << endl;
}
void TBT ::Preorder()
{
    TbtNode *temp = root->left;
    if (temp == root)
    {
        //if head is null print empty tree
        cout << "Empty tree" << endl;
        return;
    }
    while (temp != root)
    {
        //if head is not null
        cout << " " << temp->data; //print the data
        if (!(temp->leftThread))
        {
            //if left child is present
            temp = temp->left;
            //point temp to left child and iterate loop
            continue;
        }
        else
        {
            //if no left child go to right subtree
            while (temp->rightThread && temp != root)
            {
                //if no subchild
                temp = temp->right;
                //point to successor
            }
        }
        if (!(temp->rightThread) && (temp != root))
        {
            //if right child is present
            temp = temp->right;
            //point to the next node
        }
    }
}
void TBT ::Inorder()
{
    TbtNode *p = root->left;
    while (!(p->leftThread))
    {
        //traverse till you get the last left node
        p = p->left;
    }
    while (p != root)
    {
        cout << "  " << p->data; //print the data of node
        if (p->rightThread)
        { 
            //if no right child to succesor
            p = p->right;
        }
        else
        {
            //if right child present
            p = p->right;
            while (!(p->leftThread) && (p != root))
            {
                //if right child has further subtree traverse it
                p = p->left;
            }
        }
    }
}
int main()
{
    TBT t;
    int choice;

    do
    {
        cout << "\n============================MAIN MENU============================" << endl;
        cout << "PRESS 1 TO Insert : " << endl;
        cout << "PRESS 2 Inorder : " << endl;
        cout << "PRESS 3 Preorder : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        cout << "\n=================================================================" << endl;
        switch (choice)
        {
        case 1:
            t.Insert();
            break;
        case 2:
            cout<<"Inorder : ";
            t.Inorder();
            break;
        case 3:
            cout<<"Preorder : ";
            t.Preorder();
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
