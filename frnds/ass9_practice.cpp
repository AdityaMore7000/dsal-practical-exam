#include <iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
public:
    Node(int d=0){
        data = d;
        left = NULL;
        right = NULL;
      }

friend class AVL;

};

class AVL{
    
public:
    Node* root;

    AVL(){root=NULL;}
    int height(Node*);
    int difference(Node*);
    Node* ll_rotat(Node*);
    Node* lr_rotat(Node*);
    Node* rr_rotat(Node*);
    Node* rl_rotat(Node*);

    Node* balance(Node*);
    Node* insert(Node*, int);

    void inorder(Node*);

    Node* getRoot(){return root;}
};

int AVL::height(Node* temp){
    if(temp!=NULL){
        int x = height(temp->left);
        int y = height(temp->right);
        int h = max(x,y);
        return h+1;
    }
}

int AVL::difference(Node* temp){
    if(temp!=NULL){
        int x = height(temp->left);
        int y = height(temp->right);
        return x-y;
     }
}

Node* AVL::ll_rotat(Node* parent){
    if(parent!=NULL){
        Node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

}

Node* AVL::rr_rotat(Node* parent){
    if(parent!=NULL){
        Node* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }
}

Node* AVL::lr_rotat(Node* parent){
    if(parent!=NULL){
        Node* temp = parent->left;
        temp = rr_rotat(temp);
        return ll_rotat(parent);
    }
} 

Node* AVL::rl_rotat(Node* parent){
    if(parent!=NULL){
        Node* temp = parent->right;
        temp = ll_rotat(temp);
        return rr_rotat(parent);
    }
} 

Node* AVL::balance(Node* t){
    int b_factor = difference(t);

    if(b_factor > 1){
        Node* temp = t->left;
        if(difference(temp) > 0){
            t = ll_rotat(t);
        }
        else{
            t = lr_rotat(t);
        }
    }
    else if(b_factor < -1){
        Node* temp = t->right;
        if(difference(temp) > 0){
            t = rl_rotat(t);
        }
        else{
            t = rr_rotat(t);
        }
    }

    return t;
}

Node* AVL::insert(Node* r, int d){
    if(r==NULL){
        r = new Node(d);
    }
    else if(d > r->data){
        r->right = insert(r->right, d);
        r = balance(r);
    }
    else if(d < r->data){
        r->left = insert(r->left, d);
        r = balance(r);
    }
    return r;
}

void AVL::inorder(Node* temp){
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}


int main(){

AVL a1;

a1.root = a1.insert(a1.root,13);
a1.root = a1.insert(a1.root,10);
a1.root = a1.insert(a1.root,15);
a1.root = a1.insert(a1.root,5);
a1.root = a1.insert(a1.root,11);

a1.root = a1.insert(a1.root,4);
a1.root = a1.insert(a1.root,8);
a1.root = a1.insert(a1.root,16);

a1.inorder(a1.getRoot());




    return 0;
}



