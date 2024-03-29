#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Existing functions: insertNode, minValueNode, deleteNode, deleteSpecific, inorderTraversal...

// Function to insert a node as left or right child of a given node
void insertChild(TreeNode*& root, int parentValue, int childValue, char childPosition) {
    if (!root) return;

    std::queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        TreeNode* currentNode = nodesQueue.front();
        nodesQueue.pop();

        if (currentNode->value == parentValue) {
            if (childPosition == 'l' && !currentNode->left) {
                currentNode->left = new TreeNode(childValue);
            } else if (childPosition == 'r' && !currentNode->right) {
                currentNode->right = new TreeNode(childValue);
            }
            return;
        }

        if (currentNode->left) nodesQueue.push(currentNode->left);
        if (currentNode->right) nodesQueue.push(currentNode->right);
    }
}

// Function to insert a new parent for a given node (Simplified and not maintaining BST properties)
void insertParent(TreeNode*& root, int nodeValue, int parentValue) {
    if (!root) return;

    if (root->value == nodeValue) {
        TreeNode* newParent = new TreeNode(parentValue);
        newParent->left = root;
        root = newParent;
        return;
    }

    std::queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        TreeNode* currentNode = nodesQueue.front();
        nodesQueue.pop();

        if (currentNode->left && currentNode->left->value == nodeValue) {
            TreeNode* newParent = new TreeNode(parentValue);
            newParent->left = currentNode->left;
            currentNode->left = newParent;
            return;
        } else if (currentNode->right && currentNode->right->value == nodeValue) {
            TreeNode* newParent = new TreeNode(parentValue);
            newParent->left = currentNode->right; // Assuming new parent takes place as left child
            currentNode->right = newParent;
            return;
        }

        if (currentNode->left) nodesQueue.push(currentNode->left);
        if (currentNode->right) nodesQueue.push(currentNode->right);
    }
}

TreeNode* insertNode(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);

    return node;
}

// Utility function to find the minimum value node in the given BST
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}


int main() {
    TreeNode* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    std::cout << "Original BST (inorder): ";
    inorderTraversal(root);
    std::cout << "\n";

    // Insert new nodes as specified
    insertChild(root, 50, 55, 'r'); // Insert as right child of 50
    std::cout << "After inserting 55 as right child of 50 (inorder): ";
    inorderTraversal(root);
    std::cout << "\n";

    insertParent(root, 55, 52); // Insert 52 as new parent of 55
    std::cout << "After inserting 52 as new parent of 55 (inorder): ";
    inorderTraversal(root);
    std::cout << "\n";

    // Remember to handle memory deallocation
    return 0;
}
