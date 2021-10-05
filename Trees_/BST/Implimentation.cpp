#include <iostream>
using namespace std;
class BstNode
{
    public:
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root , int data) {
    if(root == NULL )
    {
        root = GetNewNode(data); 
        return root;
    }
    if(data<=root->data)
    {
        root->left = Insert(root->left,data);
    }
    else //for greater
    {
        root->right = Insert(root->right,data);
    }
    return root ;
}
int findmin(BstNode* root){
    if(root== NULL){cout<<"Tree is Empty ";return -1;}

    while(root->left != NULL){//doing root.left because root is local variable  
        root = root->left;   //if globle then root value is over written 
    }
    return root->data;
}
int findmax(BstNode* root){
    if(root == NULL){cout<<"Tree is Empty ";return -1;}

    while(root->right != NULL){
        root=root->right;
    }
    return root->data;
}
BstNode* FindminNode(BstNode* root){
	while(root->left != NULL) root = root->left;
	return root;
}    
//using recursion
int Findmin(BstNode* root){
    if(root== NULL){cout<<"Tree is Empty ";return -1;}
    else if (root->left==NULL)
    {
        return root->data;
    }
    return Findmin(root->left);
}
int findheight(BstNode* root){
    if(root == NULL) return -1;
    return max(findheight(root->left),findheight(root->right))+1;
}
void levelorder(BstNode* root){
    
}
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
void preorder(BstNode *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
    BstNode *root;
    root = NULL;
    root = Insert(root,15);
    root = Insert(root,5);
    root = Insert(root,70);
    root = Insert(root,10);
    root = Insert(root,80);
    root = Insert(root,28);
    root = Insert(root,20);
    root = Insert(root,22);
    root = Insert(root,34);
    root = Insert(root,67);
    preorder(root);
    // cout<<findmin(root)<<endl;
    // cout<<Findmin(root)<<endl;
    // cout<<findmax(root)<<endl;
    // cout<<findheight(root)<<endl;

return 0;
}























// class tree{

//     public:
//     node* root1;
//     tree(){
//         root1 = NULL;
//     }
//     node* GetNewNode(int x);
//     node* insert(node* root ,int x);
// };
// node* tree :: GetNewNode(int x)
// {
//     node* newNode = new node();
//     newNode->data = x;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }
// node* tree :: insert(node* root , int x)
// {
//     if(root==NULL){root = GetNewNode(x);return root;}

//     if(x <= root->data){
//         root->left = insert(root->left, x);8
//     }
//     else
//     {
//         root->right = insert(root->right,x);
//     }
//     return root ;

// }

// int main(){
//     tree t;
//     t.root1 = t.insert(t.root1,3);

// return 0;
// }