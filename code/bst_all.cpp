#include <bits/stdc++.h>
using namespace std;

struct BinaryTree
{

    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;
    BinaryTree() : root(nullptr) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            inserter(root, newNode);
        }
    }

    Node *delete_node(Node *node, int data)
    {
        if (node == nullptr)
            return nullptr;

        if (data < node->data)
        {
            node->left = delete_node(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = delete_node(node->right, data);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = delete_node(node->right, temp->data);
        }
        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void printInorder(Node *node)
    {
        if (node == nullptr)
            return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    int max_height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int hl = max_height(node->left);
        int hr = max_height(node->right);

        return 1 + max(hr, hl);
    }

    bool is_balanced(Node *node)
    {
        return dfs_height(node) != -1;
    }

    int dfs_height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int left_h = dfs_height(node->left);
        if (left_h == -1)
            return -1;
        int right_h = dfs_height(node->right);
        if (right_h == -1)
            return -1;
        if (abs(right_h - left_h) > 1)
            return -1;

        return 1 + max(left_h, right_h);
    }
    void inserter(Node *node, Node *newNode)
    {
        if (node->data > newNode->data)
        {
            if (node->left == nullptr)
                node->left = newNode;
            else
                inserter(node->left, newNode);
        }
        else
        {
            if (node->right == nullptr)
                node->right = newNode;
            else
                inserter(node->right, newNode);
        }
    }

    bool search(int data, Node *node)
    {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;
        return node->data > data ? search(data, node->left) : search(data, node->right);
    }


    int diameter(Node *node, int *height)
    {
        if (node == nullptr)
        {
            *height = 0;
            return 0; // Diameter is 0 for an empty tree
        }

        int lh = 0, rh = 0; // To store height of left and right subtree
        int ldiameter = diameter(node->left, &lh); // Get left diameter and height
        int rdiameter = diameter(node->right, &rh); // Get right diameter and height

        *height = max(lh, rh) + 1; // Height of current node is max of heights of left and right subtrees plus 1

        return max({lh + rh + 1, ldiameter, rdiameter}); // Return max of left diameter, right diameter and lh+rh+1
    }

    // Wrapper over diameter(Node*, int*)
    int diameter()
    {
        int height = 0;
        return diameter(root, &height);
    }
};

int main()
{
    BinaryTree bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);

    cout << "In-order Traversal: ";
    bt.printInorder(bt.root);
    cout << endl;

    cout << "Max Height :" << bt.max_height(bt.root) << endl;

    cout << "Search 4: " << (bt.search(4, bt.root) ? "Found" : "Not Found") << endl;
    cout << "Deleting 4." << endl;
    bt.delete_node(bt.root, 4);
    cout << "In-order Traversal After Deletion: ";
    bt.printInorder(bt.root);
    cout << endl;
    cout << "Search 4: " << (bt.search(4, bt.root) ? "Found" : "Not Found") << endl;
    cout << "Is balanced Tree : " << bt.is_balanced(bt.root) << endl;

        cout << "Tree Diameter: " << bt.diameter() << endl;

    return 0;
}
