#include<bits/stdc++.h>
using namespace std;
class node{
    int data;
    node *left;
    node *right;
    public:
    node(int);
    friend class BT;
};
node::node(int k = 0){
    this->data = k;
    this->left = this->right = nullptr;
}
class BT{
    public:
    node *root=nullptr;
    void create();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void levelorder(node *);
    int height(node *);
    void swap(node *);
};
void BT::swap(node *root){
    if(!root){
        return;
    }
    node *p = root->left;
    root->left = root->right;
    root->right = p;
    swap(root->left);
    swap(root->right);
}
void BT::create(){
    queue<node*> q;
    cout<<"Enter elements,enter -1 for null:\n";
    int k;
    cin>>k;
    if(k == -1){
        cout<<"Empty tree created\n";
        return;
    }
    else{
        this->root=new node(k);
        q.push(root);
    }
    while(!q.empty()){
        node *temp = q.front();
        cout<<"Enter left of "<<temp->data<<'\n';
        cin>>k;
        if(k !=-1){
        temp->left = new node(k);
        q.push(temp->left);
        }
        cout<<"Enter right of "<<temp->data<<'\n';
        cin>>k;
        if(k != -1){
        temp->right = new node(k);
        q.push(temp->right);
        } 
        q.pop(); 
    }
}
int main(){
    BT tree;
    tree.create();
    cout<<"Before swapping:\n";
    tree.inorder(tree.root);
    cout<<'\n';
    // cout<<tree.height(tree.root)-1<<'\n';
    tree.swap(tree.root);
    cout<<"After swapping:\n";
    tree.inorder(tree.root);
    cout<<'\n';
    return 0;
}

void BT::inorder(node *root)
{
    if(root){
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
    return;
}
void BT::preorder(node *root)
{
    if(root){
        cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void BT::postorder(node *root)
{
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<' ';
    }
    return;
}

int BT::height(node *root)
{
    if(!root){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
