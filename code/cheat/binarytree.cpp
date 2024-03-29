#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node *root = NULL;

node *child(int x)
{
    node *c = new node(x);
    c->left = NULL;
    c->right = NULL;

    return c;
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = child(1);

    root->left = child(2);
    root->right = child(3);
    root->left->left = child(4);
    root->left->right = child(5);
    root->right->left = child(6);
    root->right->right = child(7);

    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    preorder(root);

    return 0;
}
