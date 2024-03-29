#include <bits/stdc++.h>
using namespace std;

bool found = true ;
struct node
{
    node *left;
    node *right;
    int data;

    node(int x) : left(nullptr), right(nullptr), data(x) {}

    void insert_left(int x)
    {
        if (left == nullptr)
            left = new node(x);
        else
            left->insert_left(x);
    }

    void insert_right(int x)
    {
        if (right == nullptr)
            right = new node(x);
        else
            right->insert_right(x);
    }

    int height(node *root)
    {
        if (root == nullptr)
            return 0;

        int lheight = height(root->left);
        int rheight = height(root->right);

        return 1 + max(lheight, rheight);
    }

    void inorder(node *root, string &first)
    {
        if (!root)
            return;

        inorder(root->left, first);
        first += to_string(root->data); // Convert int to string and append
        inorder(root->right, first);
    }
    void preorder(node* root)
    {
        if(!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node* root)
    {
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

void check_identical(node *root1, node *root2)
{
    string first = "", second = "";
    
    root1->inorder(root1, first);
    root2->inorder(root2, second);

    if (first == second)
    {
        cout << "identical";
    }
    else
        cout << "NOPE";
}

int Max(node* root)
{
    if(!root) return 0;
    int l = Max(root->left);
    int r = Max(root->right);

    int val = 0;

    val = max(l,r);
    val = max(val,root->data); 


    return val;
}
int Min(node* root)
{
    if(!root) return INT_MAX;
    int l = Min(root->left);
    int r = Min(root->right);

    int val = 0;
    
    val = min(l,r);
    val = max(val,root->data); 

    return val;
}
bool checkBST(node* root)
{
    if(!root) return true;

    if(root->left && Max(root->left) > root->data) return false; // karon left e choto hobe

    else if(root->right && Min(root->right) < root->data)return false;  // right e boro howar kotha

    if(!checkBST(root->left) || !checkBST(root->right)) return false;


    return true;

}

int main()
{
    node *tree = new node(10);
    node *tree2 = new node(11);

    tree->insert_left(12);
    tree->insert_right(31);
    tree->left->insert_left(221);
    tree->left->insert_right(111);

    tree2->insert_left(12);
    tree2->insert_right(31);
    tree2->left->insert_left(221);
    tree2->left->insert_right(111);

    if(checkBST(tree)) cout <<"UES";else cout << "NO";

    return 0;
}
