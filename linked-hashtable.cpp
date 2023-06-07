#include <iostream>
#include <cstring>

const int TABLE_SIZE = 10;

class HashNode {
public:
    std::string key;
    int value;
    HashNode* next;

    HashNode(const std::string& key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashTable {
private:
    HashNode** table;

public:
    HashTable() {
        table = new HashNode*[TABLE_SIZE];
        memset(table, 0, sizeof(HashNode*) * TABLE_SIZE);
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode* node = table[i];
            while (node) {
                HashNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
        delete[] table;
    }

    int hashFunction(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

    void insert(const std::string& key, int value) {
        int hashValue = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);

        if (!table[hashValue]) {
            table[hashValue] = newNode;
        } else {
            HashNode* node = table[hashValue];
            while (node->next) {
                node = node->next;
            }
            node->next = newNode;
        }
    }

    int search(const std::string& key) {
        int hashValue = hashFunction(key);
        HashNode* node = table[hashValue];

        while (node) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }

        return -1; // Key not found
    }

    void remove(const std::string& key) {
        int hashValue = hashFunction(key);
        HashNode* node = table[hashValue];
        HashNode* prev = nullptr;

        while (node) {
            if (node->key == key) {
                if (prev) {
                    prev->next = node->next;
                } else {
                    table[hashValue] = node->next;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
};

int main() {
    HashTable hashtable;

    hashtable.insert("John", 25);
    hashtable.insert("Jane", 30);
    hashtable.insert("Alice", 35);
    hashtable.insert("Bob", 40);

    std::cout << "John: " << hashtable.search("John") << std::endl;
    std::cout << "Jane: " << hashtable.search("Jane") << std::endl;
    std::cout << "Alice: " << hashtable.search("Alice") << std::endl;
    std::cout << "Bob: " << hashtable.search("Bob") << std::endl;

    hashtable.remove("Jane");
    std::cout << "Jane: " << hashtable.search("Jane") << std::endl;

    return 0;
}
