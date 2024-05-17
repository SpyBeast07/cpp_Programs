#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for left of " << data << " node: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << " node: " << endl;
    root->right = buildTree(root->right);

    return root;
}

// void levelOrderTraversal(Node* root) {
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* temp = q.front();
//         q.pop();
//         cout << temp->data << " ";

//         if (temp->left) {
//             q.push(temp->left);
//         }
//         if (temp->right) {
//             q.push(temp->right);
//         }
//     }
// }

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    // * So that we know when the level ends
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // * if statement for getting in next line after a level is completed
        // After complete traversal of old level
        if (temp == NULL) {
            cout << endl;
            // Queue still have some child nodes
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            // Print data only when the temp != NULL
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        } 
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);
    // * 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Level Order Traversal
    cout << "\nLevel Order Traversal: \n";
    levelOrderTraversal(root);
    cout << endl;

    // InOrder Traversal
    cout << "\nInOrder Traversal: \n";
    inorderTraversal(root);
    cout << endl;

    // PreOrder Traversal
    cout << "\nPreOrder Traversal: \n";
    preorderTraversal(root);
    cout << endl;

    // PostOrder Traversal
    cout << "\nPostOrder Traversal: \n";
    postorderTraversal(root);
    cout << endl;

    return 0;
}