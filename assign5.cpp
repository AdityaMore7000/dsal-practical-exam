
#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    char key;
    string value;
    Node* next;
    Node(){
        this->key = ' ';
        this->value = "-1";
        next = NULL;
    }
    Node(char key, string value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    friend class HashTable;
};

class HashTable{
    Node arr[10];
    int n;
public:
    HashTable(int n){
        this->n = n;
    }
    void Insert(char key, string value);
    void Display();

private:
    int HashFunc(Node* n1){
        int index = (int(n1->key)) % 10;
        return index;
    }
};

void HashTable::Insert(char key, string value) {
    Node* n1 = new Node(key, value);
    int index = HashFunc(n1);
    if (arr[index].value == "-1") {
        arr[index] = *n1;
    }
    else {
        Node* ptr = &(arr[index]);
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n1;
    }
}

void HashTable::Display(){
    for(int i = 0; i < n; i++){
        Node* ptr = &arr[i];
        cout << i << " -- > ";
        while(ptr != NULL){
            cout << ptr->value << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the Number Elements in list: " << endl;
    cin >> n;
    HashTable obj(n);
    while(true){
        cout << "1. Insert Element \n2. Display ELements" << endl;
        int ch;
        cin >> ch;
        char key;
        string value1;
        switch(ch){
            case 1:
                cout << "Enter key :";
                cin >> key;
                cout << "Enter value :";
                cin >> value1;
                obj.Insert(key,value1);
                break;
            case 2:
                obj.Display();
                break;
            default:
                return 0;
        }
    }
    return 0;
}