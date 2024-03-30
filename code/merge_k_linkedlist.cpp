#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertAtHead(Node** head, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

void insertAtTail(Node** head, int data) {
    Node* new_node = newNode(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new_node;
}

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKSortedLists(Node* arr[], int K) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (int i = 0; i < K; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

    if (pq.empty())
        return NULL;

    Node *dummy = newNode(0);
    Node *last = dummy;

    while (!pq.empty()) {
        Node* curr = pq.top();
        pq.pop();
        last->next = curr;
        last = last->next;
        if (curr->next != NULL)
            pq.push(curr->next);
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int N = 3;

    Node* arr[N];

    arr[0] = NULL;
    insertAtTail(&arr[0], 1);
    insertAtTail(&arr[0], 3);
    insertAtTail(&arr[0], 5);
    insertAtTail(&arr[0], 7);

    arr[1] = NULL;
    insertAtHead(&arr[1], 8);
    insertAtHead(&arr[1], 6);
    insertAtHead(&arr[1], 4);
    insertAtHead(&arr[1], 2);

    arr[2] = NULL;
    insertAtTail(&arr[2], 0);
    insertAtTail(&arr[2], 9);
    insertAtTail(&arr[2], 10);
    insertAtTail(&arr[2], 11);

    Node* head = mergeKSortedLists(arr, N);
    printList(head);

    return 0;
}
