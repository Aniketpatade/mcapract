#include <iostream>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert nodes in the binary tree
Node* createNode(int data) {
    return new Node(data);
}

// Calculate the height of the tree
int findHeight(Node* root) {
    if (!root) return 0;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

// Print leaf nodes of the tree
void printLeafNodes(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Generate the mirror image of the tree
void mirrorTree(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Print tree level-wise
void printLevelWise(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

// Driver code
int main() {
    // Create a binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Print original tree level-wise
    cout << "Original Tree (Level-wise): ";
    printLevelWise(root);

    // Find height of the tree
    cout << "Height of Tree: " << findHeight(root) << endl;

    // Print leaf nodes
    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    // Create mirror image
    mirrorTree(root);

    // Print mirror tree level-wise
    cout << "Mirror Tree (Level-wise): ";
    printLevelWise(root);

    return 0;
}