/* 
ASSIGNMENT 5 : DSA:  Binary Search Tree

* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :

Implement binary search tree and perform following operations:

a) Insert (Handle insertion of duplicate entry)
b) Delete
c) Search 
d) Display tree (Traversal) --> O(n)
e) Display - Depth of tree
f) Display - Mirror image
g) Create a copy
h) Display all parent nodes with their child nodes
i) Display leaf nodes
j) Display tree level wise

*/

#include <iostream>
#include <queue>
using namespace std;
class BstNode //BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;
    friend class BineryTree;
};

class BineryTree
{
private:
    BstNode *root = NULL;

public:
    BstNode *GetNewNode(int x); //TO GET NEW NODE
    BstNode *GetRoot() { return root; } //TO GET ROOT
    void Insert(int x); //TO INSERT DATA TO BST
    // bool find(int data) //ITERATIVE
    bool find(BstNode *root, int x); //SEARCH

    BstNode *delet(BstNode *root, int data);//TO DELETE NODE IN BST
    BstNode *findMaxInLeft(BstNode *root);//TO FIND MAX FOR DELETATION OF 2 CHILD NODE
    void Delete(int x);//DELETE FUNCTON TO UPDATE ROOT

    void Triversal();//ALL TRIVERSAL IN ONE 
    void preorder(BstNode *root);//PREORDE TRIVERSAL 
    void inorder(BstNode *root);//INORDER TRIVERSAL
    void postorder(BstNode *root);//POSTORDER TRIVERSAL
    void levelorder(BstNode *root);//LEVELORDER TRIVERSAL

    int height(BstNode *root);//TO RETURN HEIGHT OF TREE
    // BstNode *MirrorBst(BstNode *root); //ITERATIVE MIRROR FUNCTION
    void Mirro(BstNode *root);//MIRROR THE TREE

    void displayParentChild(BstNode *root);//DISPLAY PARENT NODE
    void displayLeafNode(BstNode *root);//DISPLAY CHILD NODE
    BstNode *CreateCopy(BstNode *root);//CREATE COPY OF TREE
};

BstNode *BineryTree ::GetNewNode(int x)
{
    BstNode *temp = new BstNode();
    temp->data = x;
    temp->left = temp->right = NULL;//MAKE L AND R TO NULL
    return temp;
}

void BineryTree ::Insert(int x)
{
    if (root == NULL) //FOR TREE IS EMPTY
    {
        root = GetNewNode(x);
        cout << x << " Inserted" << endl;
        return;
    }
    BstNode *temp = root;
    while (true)
    {
        if (x <= temp->data)//if less then
        {
            if ( temp->left == NULL)
            {
                temp->left = GetNewNode(x);
                break;//to stop
            }
            else
                temp = temp->left;
        }
        else//if grater than 
        {
            if (temp->right == NULL)
            {
                temp->right = GetNewNode(x);
                break;//to stop
            }
            else
                temp = temp->right;
        }
    }

    cout << x << " Inserted" << endl;
}

void BineryTree ::preorder(BstNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void BineryTree ::inorder(BstNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    cout << root->data << " ";
    postorder(root->right);
}
void BineryTree ::postorder(BstNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void BineryTree ::levelorder(BstNode *root)
{ // Iterative method
    if (root == NULL)
        return;

    queue<BstNode *> q;
    q.push(root);
    while (!q.empty())
    {
        // Print front of queue and remove it from queue
        BstNode *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)//push left child
            q.push(temp->left);
        if (temp->right)// push right child
            q.push(temp->right);
    }
}

void BineryTree ::Triversal()
{
    int ch;
    while (true)
    {
        cout << "\n========Menu2========\n1) Preorder \n2) Postorder \n3) Inorder \n4) Levelorder \n5) Main meun \nEnter Choice\n=====================" << endl;
        cin >> ch;
        if (ch == 1)
        {
            preorder(root);
        }
        else if (ch == 2)
        {
            inorder(root);
        }
        else if (ch == 3)
        {
            postorder(root);
        }
        else if (ch == 4)
        {
            levelorder(root);
        }
        else if (ch == 5)
        {
            break;
        }
        else
        {
            cout << "invalid input !!! " << endl;
        }
    }
}
void BineryTree ::Delete(int x)
{
    root = delet(root, x);
}
BstNode *BineryTree ::findMaxInLeft(BstNode *root)//helper function
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// Function to search a delete a value from tree.
BstNode *BineryTree ::delet(BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = delet(root->left, data);
    else if (data > root->data)
        root->right = delet(root->right, data);//to search
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            BstNode *temp = findMaxInLeft(root->right);
            root->data = temp->data;
            root->right = delet(root->right, temp->data);
        }
    }
    return root;
}
// bool BineryTree ::find(int data)
// {
//     BstNode *temp = root;
//     bool flag = false;
//     while (temp != NULL)
//     {
//         if (data == temp->data)
//         {
//             flag = true;
//             break;
//         }
//         else
//         {
//             if (data < temp->data)
//             {
//                 temp = temp->left;
//             }
//             else
//             {
//                 temp = temp->right;
//             }
//         }
//     }
//     return flag;
// }
bool BineryTree ::find(BstNode *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    else if (root->data < x)
    {
        return find(root->right, x);
    }
    else
    {
        return find(root->left, x);
    }
}
int BineryTree ::height(BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return (max(height(root->left), height(root->right)) + 1);
}
// BstNode *BineryTree ::Mirror(BstNode *root)
// {

//     if (root == NULL)
//         return root;
//     else
//     {
//         BstNode *temp;

//         /* do the subtrees */
//         root = Mirror(root->left);
//         root = Mirror(root->right);

//         /* swap the pointers in this root */
//         temp     = root->left;
//         root->left = root->right;
//         root->right = temp;
//     }

//     return root;
// }
void BineryTree ::Mirro(BstNode *root)
{
    BstNode *temp = root;
    if (temp == NULL)
        return;

    queue<BstNode *> q;
    q.push(temp);
    while (!q.empty())
    {
        BstNode *curr = q.front();
        q.pop();

        swap(curr->left, curr->right);

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    levelorder(temp);
    cout << endl;
}
void BineryTree ::displayParentChild(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        return;
    }
    cout << "Parent : " << root->data << " -> ";

    if (root->left)
    {
        cout << "Left Child : " << root->left->data;
    }
    else
    {
        cout << "Left Child : NULL";
    }

    if (root->right)
    {
        cout << " && Right Child : " << root->right->data << endl;
    }
    else
    {
        cout << " && Right Child : NULL " << endl;
    }

    displayParentChild(root->left);
    displayParentChild(root->right);
}
void BineryTree ::displayLeafNode(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << "Leaf Node : " << root->data << endl;
        return;
    }
    displayLeafNode(root->left);
    displayLeafNode(root->right);
}
BstNode *BineryTree :: CreateCopy(BstNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    BstNode *newNode = GetNewNode(root->data);
    newNode->left = CreateCopy(root->left);
    newNode->right = CreateCopy(root->right);
    return newNode;
}


int main()
{
    BineryTree b;
    // b.Insert(15);
    // b.Insert(5);
    // b.Insert(70);
    // b.Insert(10);
    // b.Insert(80);
    // b.Insert(28);
    // b.Insert(20);
    // b.Insert(22);
    // b.Insert(34);
    // b.Insert(67);
    int data;
    BstNode *CopyRoot = NULL;
    int choice = 0;
    do
    {

        cout << "\n============================MAIN MENU============================" << endl;
        cout << "\nUpdated BST = ";
        b.levelorder(b.GetRoot());
        cout << "\n"
             << endl;
        cout << "PRESS 1 TO Insert : " << endl;
        cout << "PRESS 2 TO Delete : " << endl;
        cout << "PRESS 3 TO Search : " << endl;
        cout << "PRESS 4 TO tree (Traversal) : " << endl;
        cout << "PRESS 5 TO Display Height / Max Depth of tree : " << endl;
        cout << "PRESS 6 TO Display - Mirror Image : " << endl;
        cout << "PRESS 7 TO Create a Copy : " << endl;
        cout << "PRESS 8 TO Display all parent nodes with their child nodes : " << endl;
        cout << "PRESS 9 TO Display leaf nodes : " << endl;
        cout << "PRESS 10 TO Display tree level wise: " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        cout << "\n=================================================================" << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter element to Insert : ";
            cin >> data;
            b.Insert(data);
            break;
        case 2:
            cout << "Enter element you wants to delete : ";
            cin >> data;
            if (b.find(b.GetRoot(), data))
            {
                b.Delete(data);
                cout << data << " Deleted" << endl;
            }
            else
            {
                cout << "Element Not Found " << endl;
            }
            break;
        case 3:
            cout << "Enter element to search : ";
            cin >> data;
            if (b.find(b.GetRoot(), data))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case 4:
            b.Triversal();
            break;
        case 5:
            cout << "Height of BST : " << b.height(b.GetRoot()) << endl;
            cout << "No of Node in longest Path : " << (b.height(b.GetRoot()) + 1) << endl;
            break;
        case 6:
            cout << "\nBST Mirrored = ";
            b.Mirro(b.GetRoot());

            break;
        case 7:
            if (CopyRoot != NULL)
            {
                cout << "Last Copied BST : ";
                b.levelorder(CopyRoot);
            }
            CopyRoot = b.CreateCopy(b.GetRoot());
            cout << "\nNew Copy of BST Created " << endl;
            cout << "Just Copied BST : ";
            b.levelorder(CopyRoot);
            break;
        case 8:
            b.displayParentChild(b.GetRoot());
            break;
        case 9:
            b.displayLeafNode(b.GetRoot());
            break;
        case 10:
            b.levelorder(b.GetRoot());
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}