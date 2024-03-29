#include <iostream>
#include <queue>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new node with the given value in BST
TreeNode* insertNode(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);

    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }

    return node;
}

// Utility function for inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

// Utility function to delete a subtree rooted at 'node'
void deleteSubtree(TreeNode*& node) {
    if (node == nullptr) return;
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
    node = nullptr; // Important to avoid dangling pointer
}

// Function to delete a subtree starting from a given value in the BST
void deleteSubtreeFromValue(TreeNode*& root, int value) {
    if (root == nullptr) return;

    if (root->value == value) {
        deleteSubtree(root);
        return;
    }

    std::queue<TreeNode**> nodesQueue; // Store pointers to node pointers
    nodesQueue.push(&root);

    while (!nodesQueue.empty()) {
        TreeNode** currentNodePtr = nodesQueue.front();
        TreeNode* currentNode = *currentNodePtr;
        nodesQueue.pop();

        if (currentNode->value == value) {
            deleteSubtree(currentNode);
            *currentNodePtr = nullptr; // Reset the parent's pointer to nullptr
            return;
        }

        if (currentNode->left) nodesQueue.push(&(currentNode->left));
        if (currentNode->right) nodesQueue.push(&(currentNode->right));
    }

    std::cout << "Value not found." << std::endl;
}

// Main function demonstrating BST operations
int main() {
    TreeNode* root = nullptr;
    
    // Insert nodes to form a basic BST
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 13);
    insertNode(root, 17);

    std::cout << "Original BST (inorder): ";
    inorderTraversal(root);
    std::cout << "\n";

    // Delete subtree rooted at node 5
    deleteSubtreeFromValue(root, 5);

    std::cout << "BST after deleting subtree rooted at 5 (inorder): ";
    inorderTraversal(root);
    std::cout << "\n";

    return 0;
}
