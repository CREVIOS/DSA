#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
    node *left;
    node *right;
    int data;

    node(int x)
    {
        left = NULL;
        right = NULL;
        data = x;
    }
};

int height(node *node)
{
    // Base case: An empty tree has height 0
    if (!node)
        return 0;

    // Compute the height of the left and right subtrees
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // Return the maximum height plus 1
    return max(leftHeight, rightHeight) + 1;
}

bool isbalanced(node *root)
{
    // Base case: An empty tree or a leaf node is balanced
    if (!root)
        return true;

    // Check the height difference between the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the current node is balanced
    if (abs(leftHeight - rightHeight) > 1)
        return false;

    // Recursively check if left and right subtrees are balanced
    return isbalanced(root->left) && isbalanced(root->right);
}

int main()
{
    // Sample binary tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);

    if (isbalanced(root))
    {
        cout << "The binary tree is balanced." << endl;
    }
    else
    {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}





// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

/* This function traverse the skewed binary tree and
stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
	// Base case
	if (root==NULL)
		return;

	// Store nodes in Inorder (which is sorted
	// order for BST)
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
				int end)
{
	// base case
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = nodes[mid];

	/* Using index in Inorder traversal, construct
	left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid-1);
	root->right = buildTreeUtil(nodes, mid+1, end);

	return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
	// Store nodes of given BST in sorted order
	vector<Node *> nodes;
	storeBSTNodes(root, nodes);

	// Constructs BST from nodes[]
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n-1);
}

// Utility function to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

// Driver program
int main()
{
	/* Constructed skewed binary tree is
				10
			/
			8
			/
			7
		/
		6
		/
		5 */

	Node* root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(7);
	root->left->left->left = newNode(6);
	root->left->left->left->left = newNode(5);

	root = buildTree(root);

	printf("Preorder traversal of balanced "
			"BST is : \n");
	preOrder(root);

	return 0;
}


/* A program to convert Binary Tree to Binary Search Tree */
#include <iostream>
using namespace std;

/* A binary tree node structure */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* A helper function that stores inorder 
traversal of a tree rooted with node */
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
	// Base Case
	if (node == NULL)
		return;

	/* first store the left subtree */
	storeInorder(node->left, inorder, index_ptr);

	/* Copy the root's data */
	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* finally store the right subtree */
	storeInorder(node->right, inorder, index_ptr);
}

/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

/* A helper function that copies contents of arr[]
to Binary Tree. This function basically does Inorder 
traversal of Binary Tree and one by one copy arr[] 
elements to Binary Tree nodes */
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
	// Base Case
	if (root == NULL)
		return;

	/* first update the left subtree */
	arrayToBST(arr, root->left, index_ptr);

	/* Now update root's data and increment index */
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	/* finally update the right subtree */
	arrayToBST(arr, root->right, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
	// base case: tree is empty
	if (root == NULL)
		return;

	/* Count the number of nodes in Binary Tree so that
	we know the size of temporary array to be created */
	int n = countNodes(root);

	// Create a temp array arr[] and store inorder 
	// traversal of tree in arr[]
	int* arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);

	// Sort the array using library function for quick sort
	qsort(arr, n, sizeof(arr[0]), compare);

	// Copy array elements back to Binary Tree
	i = 0;
	arrayToBST(arr, root, &i);

	// delete dynamically allocated memory to 
	// avoid memory leak
	delete[] arr;
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node* temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Utility function to print inorder 
traversal of Binary Tree */
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout <<" "<< node->data;

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver function to test above functions */
int main()
{
	struct node* root = NULL;

	/* Constructing tree given in the above figure
		10
		/ \
		30 15
	/	 \
	20	 5 */
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	// convert Binary Tree to BST
	binaryTreeToBST(root);

	cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
	printInorder(root);

	return 0;
}

// This code is contributed by shivanisinghss2110


// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class LNode 
{ 
	public:
	int data; 
	LNode* next; 
}; 

/* A Binary Tree node */
class TNode 
{ 
	public:
	int data; 
	TNode* left; 
	TNode* right; 
}; 

TNode* newNode(int data); 
int countLNodes(LNode *head); 
TNode* sortedListToBSTRecur(LNode **head_ref, int n); 


/* This function counts the number of 
nodes in Linked List and then calls 
sortedListToBSTRecur() to construct BST */
TNode* sortedListToBST(LNode *head) 
{ 
	/*Count the number of nodes in Linked List */
	int n = countLNodes(head); 

	/* Construct BST */
	return sortedListToBSTRecur(&head, n); 
} 

/* The main function that constructs 
balanced BST and returns root of it. 
head_ref --> Pointer to pointer to 
head node of linked list n --> No.
of nodes in Linked List */
TNode* sortedListToBSTRecur(LNode **head_ref, int n) 
{ 
	/* Base Case */
	if (n <= 0) 
		return NULL; 

	/* Recursively construct the left subtree */
	TNode *left = sortedListToBSTRecur(head_ref, n/2); 

	/* Allocate memory for root, and 
	link the above constructed left 
	subtree with root */
	TNode *root = newNode((*head_ref)->data); 
	root->left = left; 

	/* Change head pointer of Linked List
	for parent recursive calls */
	*head_ref = (*head_ref)->next; 

	/* Recursively construct the right 
		subtree and link it with root 
		The number of nodes in right subtree
		is total nodes - nodes in 
		left subtree - 1 (for root) which is n-n/2-1*/
	root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1); 

	return root; 
} 



/* UTILITY FUNCTIONS */

/* A utility function that returns 
count of nodes in a given Linked List */
int countLNodes(LNode *head) 
{ 
	int count = 0; 
	LNode *temp = head; 
	while(temp) 
	{ 
		temp = temp->next; 
		count++; 
	} 
	return count; 
} 

/* Function to insert a node 
at the beginning of the linked list */
void push(LNode** head_ref, int new_data) 
{ 
	/* allocate node */
	LNode* new_node = new LNode();
	
	/* put in the data */
	new_node->data = new_data; 

	/* link the old list of the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in a given linked list */
void printList(LNode *node) 
{ 
	while(node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
TNode* newNode(int data) 
{ 
	TNode* node = new TNode();
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return node; 
} 

/* A utility function to 
print preorder traversal of BST */
void preOrder(TNode* node) 
{ 
	if (node == NULL) 
		return; 
	cout<<node->data<<" "; 
	preOrder(node->left); 
	preOrder(node->right); 
} 

/* Driver code*/
int main() 
{ 
	/* Start with the empty list */
	LNode* head = NULL; 

	/* Let us create a sorted linked list to test the functions 
	Created linked list will be 1->2->3->4->5->6->7 */
	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	cout<<"Given Linked List "; 
	printList(head); 

	/* Convert List to BST */
	TNode *root = sortedListToBST(head); 
	cout<<"\nPreOrder Traversal of constructed BST "; 
	preOrder(root); 

	return 0; 
} 

// This code is contributed by rathbhupendra



// C++ code to find the largest value smaller
// than or equal to N
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

// To create new BST Node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// To insert a new node in BST
Node* insert(Node* node, int key)
{
	// if tree is empty return new node
	if (node == NULL)
		return newNode(key);

	// if key is less than or greater than
	// node value then recur down the tree
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	// return the (unchanged) node pointer
	return node;
}

// function to find max value less than N
int findMaxforN(Node* root, int N)
{
	// Base cases
	if (root == NULL)
		return -1;
	if (root->key == N)
		return N;

	// If root's value is smaller, try in right
	// subtree
	else if (root->key < N) {
		int k = findMaxforN(root->right, N);
		if (k == -1)
			return root->key;
		else
			return k;
	}

	// If root's key is greater, return value
	// from left subtree.
	else if (root->key > N) 
		return findMaxforN(root->left, N); 
}

// Driver code
int main()
{
	int N = 4;

	// creating following BST
	/*
				5
			/ \ 
			2	 12
		/ \ / \ 
		1 3 9 21
					/ \ 
					19 25 */
	Node* root = insert(root, 25);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 12);
	insert(root, 9);
	insert(root, 21);
	insert(root, 19);
	insert(root, 25);

	printf("%d", findMaxforN(root, N));

	return 0;
}


// C++ program to delete leaf Node from
// binary search tree.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Create a newNode in binary search tree.
struct Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Insert a Node in binary search tree.
struct Node* insert(struct Node* root, int data)
{
	if (root == NULL)
		return newNode(data);
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;
}

// Function for inorder traversal in a BST.
void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

// Delete leaf nodes from binary search tree.
struct Node* leafDelete(struct Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL) {
		free(root);
		return NULL;
	}

	// Else recursively delete in left and right
	// subtrees.
	root->left = leafDelete(root->left);
	root->right = leafDelete(root->right);

	return root;
}

// Driver code
int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	cout << "Inorder before Deleting the leaf Node." << endl;
	inorder(root);
	cout << endl;
	leafDelete(root);
	cout << "INorder after Deleting the leaf Node." << endl;
	inorder(root);
	return 0;
}

#include <iostream>
using namespace std;

/* A binary tree node has data, 
the pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node* minValue(struct node* node);

struct node* inOrderSuccessor(
	struct node* root,
	struct node* n)
{
	// step 1 of the above algorithm
	if (n->right != NULL)
		return minValue(n->right);

	// step 2 of the above algorithm
	struct node* p = n->parent;
	while (p != NULL && n == p->right) {
		n = p;
		p = p->parent;
	}
	return p;
}

/* Given a non-empty binary search tree, 
	return the minimum data 
	value found in that tree. Note that 
	the entire tree does not need
	to be searched. */
struct node* minValue(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

/* Helper function that allocates a new 
	node with the given data and 
	NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(
			struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return (node);
}

/* Give a binary search tree and 
a number, inserts a new node with 
	the given number in the correct 
	place in the tree. Returns the new
	root pointer which the caller should
	then use (the standard trick to 
	avoid using reference parameters). */
struct node* insert(struct node* node,
					int data)
{
	/* 1. If the tree is empty, return a new,
	single node */
	if (node == NULL)
		return (newNode(data));
	else {
		struct node* temp;

		/* 2. Otherwise, recur down the tree */
		if (data <= node->data) {
			temp = insert(node->left, data);
			node->left = temp;
			temp->parent = node;
		}
		else {
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}

		/* return the (unchanged) node pointer */
		return node;
	}
}

/* Driver program to test above functions*/
int main()
{
	struct node *root = NULL, *temp, *succ, *min;

	// creating the tree given in the above diagram
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);
	temp = root->left->right->right;

	succ = inOrderSuccessor(root, temp);
	if (succ != NULL)
		cout << "\n Inorder Successor of " << temp->data<< " is "<< succ->data;
	else
		cout <<"\n Inorder Successor doesn't exit";

	getchar();
	return 0;
}

// this code is contributed by shivanisinghss2110

