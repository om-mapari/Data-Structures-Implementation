#include<iostream>
using namespace std;
class TbtNode
{
public:
    int data;
    TbtNode *left;
    TbtNode *right;
    bool lb;
    bool rb;
    friend class BineryTree;
};
class ThreadedBinaryTree {
    TbtNode* root;
    public:
    ThreadedBinaryTree(){
        root->left = NULL;
        root->right = NULL;
        root->lb = 0;
        root->rb = 0;
        
    }
    void insert(int x);
    void deleteN(int x);

};