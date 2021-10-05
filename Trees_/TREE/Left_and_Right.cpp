#include <iostream>
using namespace std;
#include <queue>
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(){
        left = right = NULL;
    }
    // friend class tree;
    // friend void Inorder(node* root);
    // friend void Preorder(node* root);
    // friend void Postorder(node* root);
    // friend bool Search(node root,int data);
};
class tree
{
    public:
    node *root;
public:
    tree()
    {
        root = NULL;
    }
    void insert();
    node* Getnewnode(int data);
    void findmin();
    void levelorder();
};
node* tree ::Getnewnode(int data)
{
    node *Newnode = new node();
    Newnode->data = data;
    Newnode->left = Newnode->right = NULL;
    return Newnode;
}
void tree ::insert()
{
    cout << "\nEnter data : ";
    int data;
    cin >> data;
    if (root == NULL)
    {
        root = Getnewnode(data);
        cout<<"Node Inserted as a root node"<<endl;
        return;
    }

    node *temp2 = root;
    int level = 0;
    while (true)
    {

        cout<<"\nyou are on level "<<level<<endl;
        level++;
        cout << "Where you want to Insert l or r" << endl;
        char ch;
        cin >> ch;
        if (ch == 'l')
        {
            if(temp2->left == NULL ){
                temp2->left = Getnewnode(data);
                cout<<"Node Inserted on level "<<level<<endl;
                break;
            }
            else
            {
                cout<<"position is occupied"<<endl;
                temp2 = temp2->left;
            }
            
        }
        else if(ch == 'r')
        {
            if(temp2->right == NULL)
            {
                temp2->right = Getnewnode(data);
                cout<<"Node Inserted on level "<<level<<endl;
                break;
            }
            else
            {
                cout<<"position is occupied"<<endl;
                temp2 = temp2->right;
            }
            
        }
        else
        {
            cout<<"invalid input"<<endl;
            level--;
        }
        
    }
}
void tree :: levelorder(){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);

}
void Inorder(node *root){
 	if(root == NULL) return;

 	Inorder(root->left);       //Visit left subtree
 	cout << root->data << " "; //Print data
 	Inorder(root->right);      // Visit right subtree
}
void Preorder(node* root)
{
    if(root == NULL) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node* root){
    if(root == NULL) return;

    Preorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
bool Search(node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else {
		return Search(root->left,data);
        return Search(root->right,data);
	}

}
int main()
{
    tree t;
    int choice = 0;
    do
    {
        cout << "\n\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO Insert data : " << endl;
        cout << "PRESS 2 TO Preorder : " << endl;
        cout << "PRESS 3 TO Inorder : " << endl;
        cout << "PRESS 4 TO Postorder : " << endl;
        cout << "PRESS 5 TO Search Element: " << endl;
        // cout << "PRESS 6 TO : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            t.insert();
            cout<<"Inorder Treversal ";
            Inorder(t.root);
            break;
        case 2:
            Preorder(t.root);
            break;
        case 3:
            Inorder(t.root);
            break;
        case 4:
            Postorder(t.root);
            break;
        case 5:
            cout<<"Enter element to search : ";
            int data;
            cin>>data;
            if(Search(t.root,data) == true) cout<<"Found\n";
	        else cout<<"Not Found\n";
            break;
        // case 6:
          
        //     break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}