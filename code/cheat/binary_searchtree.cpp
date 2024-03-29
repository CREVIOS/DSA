#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

node *child(int x)
{
    return new node(x);
}

bool search(int data, node *root)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return search(data, root->left);
    }
    else
    {
        return search(data, root->right);
    }
}

node *insert(int x, node *root)
{
    if (root == nullptr)
    {
        return child(x);
    }

    if (x < root->data)
    {
        root->left = insert(x, root->left);
    }
    else if (x > root->data)
    {
        root->right = insert(x, root->right);
    }

    return root;
}
void Delete(int x, node *&root)
{
    if (!root)
    {
        cout << "Not present" << endl;
        return;
    }

    if (x < root->data)
    {
        Delete(x, root->left);
    }
    else if (x > root->data)
    {
        Delete(x, root->right);
    }
    else
    {
        // Case 1: No child or one child
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            // Case 2: Two children
            // Find the inorder successor (smallest node in the right subtree)
            node *temp = root->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            // Copy the inorder successor's data to this node
            root->data = temp->data;
            // Delete the inorder successor
            //Delete(temp->data, root->right);
            free(temp);
        }
        cout << "The node of value " << x << " has been deleted" << endl;
    }
}


void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void print_all_leaf(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " ";
    }
    else
    {
        print_all_leaf(root->left);
        print_all_leaf(root->right);
    }
}

int main()
{
    node *root = nullptr; // Initialize an empty tree

    // Insert elements (example usage)
    root = insert(50, root);
    insert(30, root);
    insert(20, root);
    insert(40, root);
    insert(70, root);
    insert(60, root);
    insert(80, root);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Leaf nodes: ";
    print_all_leaf(root);
    cout << endl;

    // Search for an element (example usage)
    int element_to_find = 60;
    if (search(element_to_find, root))
    {
        cout << element_to_find << " found in the tree" << endl;
    }
    else
    {
        cout << element_to_find << " not found in the tree" << endl;
    }

    Delete(50,root);
    Delete(1111,root);

    inorder(root);

    return 0;
}
