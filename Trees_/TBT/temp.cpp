#include <iostream>
using namespace std;
#define MAX_VALUE 9999999;

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
    void GetNode(int x);
    void makeEmpty();
    void insert(int data);
    bool search(int data);
    void printTree();
    void Delete(int data);
};
Tbt ::Tbt()
{
    root = new Tbtnode();
    root->right = root->left = root;
    root->leftThread = true;
    root->data = MAX_VALUE;
}
void Tbt ::makeEmpty()
{
    root = new Tbtnode();
    root->right = root->left = root;
    root->leftThread = true;
    root->data = MAX_VALUE;
}
void Tbt ::insert(int data)
{
    Tbtnode *p = root;
    while (true)
    {
        if (p->data < data)
        {
            if (p->rightThread)
                break;
            p = p->right;
        }
        else if (p->data > data)
        {
            if (p->leftThread)
                break;
            p = p->left;
        }
        else
        {

            return;
        }
    }
    Tbtnode *tmp = new Tbtnode();
    tmp->data = data;
    tmp->rightThread = tmp->leftThread = true;
    if (p->data < data)
    {
        //  insert to right side
        tmp->right = p->right;
        tmp->left = p;
        p->right = tmp;
        p->rightThread = false;
    }
    else
    {
        tmp->right = p;
        tmp->left = p->left;
        p->left = tmp;
        p->leftThread = false;
    }
}

bool Tbt ::search(int data)
{
    Tbtnode *tmp = root->left;
    while (true)
    {
        if (tmp->data < data)
        {
            if (tmp->rightThread)
                return false;
            tmp = tmp->right;
        }
        else if (tmp->data > data)
        {
            if (tmp->leftThread)
                return false;
            tmp = tmp->left;
        }
        else
        {
            return true;
        }
    }
}

/* Fuction to delete an element */
void Tbt ::Delete(int data)
{
    Tbtnode *temp = root->left, *p = root;
    for (;;)
    {
        if (temp->data < data)
        {
            /* not found */
            if (temp->rightThread)
                return;
            p = temp;
            temp = temp->right;
        }
        else if (temp->data > data)
        {
            /* not found */
            if (temp->leftThread)
                return;
            p = temp;
            temp = temp->left;
        }
        else
        {
            /* found */
            break;
        }
    }
    Tbtnode *target = temp;
    if (!temp->rightThread && !temp->leftThread)
    {
        /* temp has two children*/
        p = temp;
        /* find largest Tbtnode at left child */
        target = temp->left;
        while (!target->rightThread)
        {
            p = target;
            target = target->right;
        }
        /* using replace mode*/
        temp->data = target->data;
    }
    if (p->data >= target->data)
    {
        if (target->rightThread && target->leftThread)
        {
            p->left = target->left;
            p->leftThread = true;
        }
        else if (target->rightThread)
        {
            Tbtnode *largest = target->left;
            while (!largest->rightThread)
            {
                largest = largest->right;
            }
            largest->right = p;
            p->left = target->left;
        }
        else
        {
            Tbtnode *smallest = target->right;
            while (!smallest->leftThread)
            {
                smallest = smallest->left;
            }
            smallest->left = target->left;
            p->left = target->right;
        }
    }
    else
    {
        if (target->rightThread && target->leftThread)
        {
            p->right = target->right;
            p->rightThread = true;
        }
        else if (target->rightThread)
        {
            Tbtnode *largest = target->left;
            while (!largest->rightThread)
            {
                largest = largest->right;
            }
            largest->right = target->right;
            p->right = target->left;
        }
        else
        {
            Tbtnode *smallest = target->right;
            while (!smallest->leftThread)
            {
                smallest = smallest->left;
            }
            smallest->left = p;
            p->right = target->right;
        }
    }
}

void Tbt ::printTree()
{
    Tbtnode *tmp = root, *p;
    while (true)
    {
        p = tmp;
        tmp = tmp->right;
        if (!p->rightThread)
        {
            while (!tmp->leftThread)
            {
                tmp = tmp->left;
            }
        }
        if (tmp == root)
            break;
        cout << tmp->data << "   ";
    }
    cout << endl;
}

int main()
{
    Tbt tbst;
    int choice = 0;
    int val;

    do
    {
        cout << "\n===============================================" << endl;
        cout << "\n** THREADED BINARY TREE (TBT) **\n";
        cout << "0. Exit " << endl;
        cout << "1. Insert Element " << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Print Tree" << endl;
        cout << "5. Clear Tree" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << "===============================================\n"
             << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter integer element to insert: ";
            cin >> val;
            tbst.insert(val);
            cout << val << " inserted " << endl;
            break;
        case 2:
            cout << "Enter integer element to delete: ";
            cin >> val;
            if (tbst.search(val))
                tbst.Delete(val);
            else
                cout << "Element Not Found " << endl;
            break;
        case 3:
            cout << "Enter integer element to search: ";
            cin >> val;
            if (tbst.search(val))
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
            break;
        case 5:
            cout << "\nTree Cleared\n";
            tbst.makeEmpty();
            break;
        case 4:
            cout << "\nTBT = ";
            tbst.printTree();
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