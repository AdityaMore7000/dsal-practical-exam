#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int);
};

node::node(int k = 0)
{
    this->data = k;
    this->left = this->right = nullptr;
}

class bst
{
    node *root = nullptr;

public:
    void swap(node *);
    void create();
    node *insert(node *, int);
    node *getRoot();
    void inOrder(node *);
    void preOrder(node *);
    void postOrder(node *);
    int getMax();
    int getMin();
    void levelOrder(node *);
    bool search(node *, int);
};
void bst::swap(node *root)
{
    if (root)
    {
        node *p;
        p = root->left;
        root->left = root->right;
        root->right = p;
        swap(root->left);
        swap(root->right);
    }
}
node *bst::insert(node *root, int val)
{
    if (!root)
        return root = new node(val);
    if (val <= root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

node *bst::getRoot()
{
    return this->root;
}

void bst::inOrder(node *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

void bst::preOrder(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void bst::postOrder(node *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

int bst::getMax()
{
    node *p = root;
    while (p->right)
        p = p->right;
    return p->data;
}

int bst::getMin()
{
    node *p = root;
    while (p->left)
        p = p->left;
    return p->data;
}

void bst::levelOrder(node *root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* p = q.front();
        q.pop();
        cout<<p->data<<' ';
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}

bool bst::search(node *root, int key)
{
    if (key == root->data)
    {
        return 1;
    }
    else if (key < root->data && root->left)
    {
        return search(root->left, key);
    }
    else if (key > root->data && root->right)
    {
        return search(root->right, key);
    }
    return 0;
}

void bst::create()
{
    int n;
    int k = 0;
    cout << "Enter number of elements : \n";
    ;
    cin >> n;
    cout << "Enter " << n << " elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        root = insert(root, k);
    }
}
int main()
{
    bst tree;
    cout << "Press 1 to create a binary search tree\n";
    cout << "Press 2 to insert a node\n";
    cout << "Press 3 to search for a node\n";
    cout << "Press 4 to get maximum element\n";
    cout << "Press 5 to get minimum element\n";
    cout << "Press 6 for pre order traversal\n";
    cout << "Press 7 for in order traversal\n";
    cout << "Press 8 for post order traversal\n";
    cout << "Press 9 to flip the tree vertically\n";
    cout << "Press 10 for level order traversal\n";
    cout << "Press 0 to exit:\n";
    bool flag = 1;
    int n = 0;
    int k = 0;
    while (flag)
    {
        cout << "Enter your choice:\n";
        cin >> n;
        switch (n)
        {
        case 0:
            cout << "Thank you!\n";
            flag = 0;
            break;
        case 1:
            tree.create();
            break;
        case 2:
        {
            cout << "Enter the value to be inserted:\n";
            cin >> k;
            tree.insert(tree.getRoot(), k);
            break;
        }
        case 3:
        {
            cout << "Enter key:\n";
            cin >> k;
            (tree.search(tree.getRoot(), k)) ? cout << "Found\n" : cout << "Not found\n";
            break;
        }
        case 4:
        {
            cout << "Maximum element of tree is:\n"
                 << tree.getMax();
            cout << '\n';
            break;
        }
        case 5:
        {
            cout << "Minimum element of tree is:\n"
                 << tree.getMin();
            cout << '\n';
            break;
        }
        case 6:
        {
            tree.preOrder(tree.getRoot());
            cout << '\n';
            break;
        }
        case 7:
        {
            tree.inOrder(tree.getRoot());
            cout << '\n';
            break;
        }
        case 8:
        {
            tree.postOrder(tree.getRoot());
            cout << '\n';
            break;
        }
        case 9:
        {
            tree.swap(tree.getRoot());
            break;
        }
        case 10:
        {
            tree.levelOrder(tree.getRoot());
            cout<<'\n';
            break;
        }
        default:
        {
            cout << "Invalid input !!\n";
            cout << "Try again:\n";
            cout << "Press 0 to quit : ";
        }
        }
    }
    return 0;
}