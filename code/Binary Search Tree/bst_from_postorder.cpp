#include <iostream>
#include <vector>
#include <limits>

// Define the structure for the BST node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTUtil(const std::vector<int>& postorder, int& currentIndex, int min, int max) {
    if (currentIndex < 0) {
        return nullptr;
    }

    int value = postorder[currentIndex];

    if (value < min || value > max) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(value);
    currentIndex--;

    node->right = buildBSTUtil(postorder, currentIndex, value, max);
    node->left = buildBSTUtil(postorder, currentIndex, min, value);

    return node;
}

TreeNode* buildBSTFromPostorder(const std::vector<int>& postorder) {
    int currentIndex = postorder.size() - 1;
    return buildBSTUtil(postorder, currentIndex, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

void inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->value << " ";
    inorderTraversal(node->right);
}

int main() {
    std::vector<int> postorder = {1, 7, 5, 12, 10, 8};
    TreeNode* root = buildBSTFromPostorder(postorder);

    inorderTraversal(root); // Should print the numbers in sorted order
    std::cout << std::endl;

    
    return 0;
}
