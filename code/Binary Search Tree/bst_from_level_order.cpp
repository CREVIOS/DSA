#include <iostream>
#include <queue>
#include <climits>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// A utility function to create a new BST node
TreeNode* newNode(int item) {
    TreeNode* temp = new TreeNode(item);
    return temp;
}

// Function to construct BST from its level order traversal
TreeNode* constructBSTFromLevelOrder(int levelOrder[], int n) {
    if (n == 0) return nullptr;

    // The first element of level order traversal is root
    int i = 0;
    TreeNode* root = newNode(levelOrder[i++]);

    std::queue<std::pair<TreeNode*, std::pair<int, int>>> q;
    // Enqueue root and its range values
    q.push({root, {INT_MIN, INT_MAX}});

    while (i < n) {
        auto front = q.front();
        q.pop();

        TreeNode* temp = front.first;
        int leftRange = front.second.first;
        int rightRange = front.second.second;

        // Insert left child
        if (i < n && levelOrder[i] > leftRange && levelOrder[i] < temp->value) {
            temp->left = newNode(levelOrder[i++]);
            q.push({temp->left, {leftRange, temp->value}});
        }

        // Insert right child
        if (i < n && levelOrder[i] > temp->value && levelOrder[i] < rightRange) {
            temp->right = newNode(levelOrder[i++]);
            q.push({temp->right, {temp->value, rightRange}});
        }
    }

    return root;
}

// Utility function to do inorder traversal
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->value << " ";
        inorder(root->right);
    }
}

int main() {
    int levelOrder[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(levelOrder)/sizeof(levelOrder[0]);
    
    TreeNode* root = constructBSTFromLevelOrder(levelOrder, n);

    inorder(root);
    std::cout << std::endl;

    return 0;
}
