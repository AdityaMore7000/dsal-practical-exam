#include <iostream>
using namespace std;
class node
{
    int data;
    node *left, *right;
    bool lt, rt;

public:
    node(int);
    friend class TBT;
};
node ::node(int k = 0)
{
    this->data = k;
    this->left = this->right = nullptr;
    this->lt = this->rt = true;
}
class TBT
{
public:
    node *root;
    TBT() { root = nullptr; }
    void insert(int);
    void inorder(node *root);
    void preorder(node *root);
    void *pop(node *root, int);
};
void TBT::insert(int key)
{
    if(!root){
        root = new node(key);
        return;
    }
    node *temp = new node(key);
    node *p = this->root;
    while(1){
        if(key<p->data){
            if(!p->lt) p = p->left;
            else{
                temp->left = p->left;
                temp->right = p;
                p->left = temp;
                p->lt = false;
                break;
            }
        }
        else if(key>p->data){
            if(!p->rt) p = p->right;
            else{
                temp->right = p->right;
                temp->left = p;
                p->right = temp;
                p->rt = false;
                break;
            }
        }
    }
}
void TBT::inorder(node *root)
{
    if (!root)
    {
        cout << "Tree is empty!\n";
    }
    node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    while (temp)
    {
        cout << temp->data << ' ';
        temp = temp->right;
    }
    cout<<'\n';
}
int main()
{
    TBT tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(60);
    tree.insert(30);
    tree.insert(40);
    tree.insert(10);
    tree.inorder(tree.root);
    return 0;
}