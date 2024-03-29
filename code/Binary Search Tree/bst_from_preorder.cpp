#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTFromPreorder(const std::vector<int>& preorder) {
    if (preorder.empty()) return nullptr;

    std::stack<TreeNode*> stack;
    TreeNode* root = new TreeNode(preorder[0]);
    stack.push(root);

    for (size_t i = 1; i < preorder.size(); ++i) {
        TreeNode* node = new TreeNode(preorder[i]);
        if (preorder[i] < stack.top()->value) {
            stack.top()->left = node;
        } else {
            TreeNode* parent = nullptr;
            while (!stack.empty() && preorder[i] > stack.top()->value) {
                parent = stack.top();
                stack.pop();
            }
            parent->right = node;
        }
        stack.push(node);
    }

    return root;
}

// Helper function for inorder traversal to verify the tree
void inorderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->value << " ";
    inorderTraversal(node->right);
}

int main() {
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = buildBSTFromPreorder(preorder);

    inorderTraversal(root); // Should print the numbers in sorted order
    std::cout << std::endl;

   

    return 0;
}
