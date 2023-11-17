#include <iostream>
using namespace std;

class Node {
public:
    string word;
    string meaning;
    Node* left;
    Node* right;

    Node(string key, string value) { word=key;
    meaning=value;
    left=nullptr;
  right=nullptr;}
};

class Dictionary {
public:
    Node* root;

    Dictionary() {
        root=nullptr; 
        
    }

    Node* addKeyword(Node* node, string word, string meaning) {
        if (node == NULL) {
            return new Node(word, meaning);
        }

        if (word < node->word) {
            node->left = addKeyword(node->left, word, meaning);
        }
        else if (word > node->word) {
            node->right = addKeyword(node->right, word, meaning);
        }
        else {
            // keyword already exists, update the meaning
            node->meaning = meaning;
        }
        return node;
    }

    Node* deleteWord(Node* node, string word) {
        if (node == nullptr) {
            return nullptr;
        }

        if (word < node->word) {
            node->left = deleteWord(node->left, word);
        }
        else if (word > node->word) {
            node->right = deleteWord(node->right, word);
        }
        else {
            // found the keyword to be deleted
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children, find the inorder successor
            Node* temp = minValue(node->right);
            // copy the inorder successor data to this node
            node->word = temp->word;
            node->meaning = temp->meaning;
            // delete the inorder successor
            node->right = deleteWord(node->right, temp->word);
        }

        return node;
    }

    Node* minValue(Node* node) {
        Node* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << "Word: " << node->word << ", Meaning: " << node->meaning << endl;
            inorderTraversal(node->right);
        }
    }

    int findMaxComparison(Node* node, string word, int comparison) {
        if (node == nullptr) {
            return comparison;
        }

        if (word == node->word) {
            // Keyword found
            return comparison + 1;
        }
        else if (word < node->word) {
            // Move to the left subtree
            return findMaxComparison(node->left, word, comparison + 1);
        }
        else {
            // Move to the right subtree
            return findMaxComparison(node->right, word, comparison + 1);
        }
    }
};

int main() {
    Dictionary dictionary;

    int choice;
    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add New Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Display Dictionary\n";
        cout << "4. Find Max Comparisons for a Keyword\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string key, value;
            cout << "Enter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin >> value;
            dictionary.root = dictionary.addKeyword(dictionary.root, key, value);
            cout << "Keyword added successfully!\n";
            break;
        }
        case 2: {
            string key;
            cout << "Enter keyword to delete: ";
            cin >> key;
            dictionary.root = dictionary.deleteWord(dictionary.root, key);
            cout << "Keyword deleted successfully!\n";
            break;
        }
        case 3: {
            cout << "Dictionary:\n";
            dictionary.inorderTraversal(dictionary.root);
            break;
        }
        case 4: {
            string key;
            cout << "Enter keyword to find max comparisons: ";
            cin >> key;
            int maxComparisons = dictionary.findMaxComparison(dictionary.root, key, 0);
            cout << "Maximum comparisons needed to find '" << key << "': " << maxComparisons << "\n";
            break;
        }
        case 5:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
