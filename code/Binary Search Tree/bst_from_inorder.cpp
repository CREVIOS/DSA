#include <iostream>
#include <vector>

// Define the structure for the BST node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Function to build the BST from the sorted array
TreeNode* sortedArrayToBST(const std::vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr; // Base case
    }

    int mid = start + (end - start) / 2; // Avoid overflow
    TreeNode* root = new TreeNode(nums[mid]); // Create a node with the middle element

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// Helper function to print the tree in inorder traversal
void inorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << node->value << " ";
    inorderTraversal(node->right);
}

// Main function
int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9}; // Example sorted array
    TreeNode* root = sortedArrayToBST(nums, 0, nums.size() - 1);

    inorderTraversal(root);
    std::cout << std::endl;


    return 0;
}
