#include <iostream>
using namespace std;
#define M 9999999;

class Tbtnode
{
public:
    int data;
    Tbtnode *left, *right;
    bool leftThread, rightThread;
};
class Tbt
{
private:
    Tbtnode *root;
public:
    Tbt();
    void insert(int data);
    void printT();
    void Clear();
    void Inorder(Tbtnode *root);
    void Preorder(Tbtnode *root);
    Tbtnode* GetRoot();
};
Tbt ::Tbt()
{
    root = new Tbtnode();
    root->right = root->left = root;
    root->leftThread = true;
    root->data = M;
}
void Tbt ::Clear()
{
    root = new Tbtnode();
    root->right = root->left = root;
    root->leftThread = true;
    root->data = M;
}
Tbtnode* Tbt ::GetRoot(){
    return root;
}
//45 60 35 32 18 100 
void Tbt ::insert(int data)
{
    Tbtnode *new1 = new Tbtnode;
    Tbtnode *current = root->left;
    new1->data = data;
    bool gotoleft;
    bool gotoright;
    if ((root->right == root) & (root->left == root))
    {
        new1->left = root;
        root->left = new1;
        new1->leftThread = root->leftThread;
        root->leftThread = true;
        new1->right = root;
    }
    else
    {
        while (true)
        {
            if (current->data > data)
            {
                if (current->leftThread == false)
                {
                    gotoleft = true;
                    gotoright = false;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->rightThread == false)
                {
                    gotoright = true;
                    gotoleft = false;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
        if (gotoleft)
        {
            current->left = new1;
            new1->right = current;
            new1->left = current->left;
            new1->leftThread = current->leftThread;
            current->leftThread = true;
        }
        else if (gotoright)
        {
            current->right = new1;
            new1->left = current;
            new1->right = current->right;
            new1->rightThread = current->rightThread;
            current->rightThread = true;
        }
    }
}

int main()
{
    Tbt t;
    int choice = 0;
    int data;

    do
    {
        cout << "\n===============================================" << endl;
        cout << "\n** THREADED BINARY TREE (TBT) **\n";
        cout << "0. Exit " << endl;
        cout << "1. Insert Element " << endl;
        cout << "2. Inorder" << endl;
        cout << "3. Preorder" << endl;
        cout << "4. Clear Tree" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << "===============================================\n"
             << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter Data : ";
            cin >> data;
            t.insert(data);
            cout << data << " inserted " << endl;
            break;
        case 2:
            cout<<"Inorder : ";
            
            break;
        case 3:
            cout<<"Preorder : ";

            break;
        case 4:
            t.Clear();
            cout << "\nTree Cleared\n";
            break;
        default:
            if (choice != 0)
                cout << "Invalid....!!! ";
            else
                cout << "Exiting....!!! ";
            break;
        }
    } while (choice != 0);
    return 0;
}
