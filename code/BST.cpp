#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

node *searchinBST(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        searchinBST(root->left, key);
    }
    else
    {
        searchinBST(root->right, key);
    }
}

node *inordersucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteInBST(node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->left, temp->data);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 100);
    insertBST(root, 3);
    insertBST(root, 2);
    insertBST(root, 77);
    insertBST(root, 1);
    inorder(root);
    cout << endl;
    if (searchinBST(root, 5) != NULL)
    {
        cout << "got the key" << endl;
    }
    else
    {
        cout << "Not got the key" << endl;
    }
    root = deleteInBST(root, 2);
    inorder(root);
    cout << endl;
}