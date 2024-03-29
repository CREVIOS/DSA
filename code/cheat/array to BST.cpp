#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;

    node(int x) : data(x), left(nullptr), right(nullptr) {}
};

node *makeBST(int ara[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    node *root = new node(ara[mid]);

    root->left = makeBST(ara, start, mid - 1);
    root->right = makeBST(ara, mid + 1, end);

    return root;
}

void postorder(node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void max_value(node *root, int ara[], int start)
{
    if (!root)
        return;

    ara[start] = max(ara[start], root->data);

    max_value(root->left, ara, start + 1);
    max_value(root->right, ara, start + 1);
}

int main()
{
    int n;
    cin >> n;
    int ara[n];

    // Initialize ans array with large negative numbers
    int ans[n];
    fill(ans, ans + n, INT_MIN);

    for (int i = 0; i < n; i++)
        cin >> ara[i];

    sort(ara, ara + n);

    node *tree = makeBST(ara, 0, n - 1);

    // Find and store the maximum values at each depth level
    max_value(tree, ans, 0);

    // Print the postorder traversal of the BST
    postorder(tree);
    cout << endl;

    // Print the maximum values at each depth level
    for (int i = 0; i < n; i++)
    {
        if (ans[i] != INT_MIN)
        {
            cout << "Maximum value at depth " << i << ": " << ans[i] << endl;
        }
    }

    return 0;
}
