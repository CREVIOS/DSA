#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode* findMax(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

TreeNode* insertNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->value) {
        root->left = insertNode(root->left, key);
    } else if (key > root->value) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root; // Base case


    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMax(root->left);

        root->value = temp->value;

        root->left = deleteNode(root->left, temp->value);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->value << " ";
        inorder(root->right);
    }
}

// Driver program
int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    inorder(root);
    std::cout << "\n";

    insertNode(root, 8);
    inorder(root);
    std::cout << "\n";

    root = deleteNode(root, 3); // Deleting node with value 3
    inorder(root);
    std::cout << "\n";


    return 0; // Fixed: Added missing semicolon
}
