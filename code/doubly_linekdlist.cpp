#include <bits/stdc++.h>
using namespace std;

struct ll
{
    struct node
    {
        node *next;
        node *prev; // Add a pointer to the previous node
        int data;
    };

    node *head = NULL;
    node *tail = NULL;

    node *create_node(node *next, node *prev, int x) // Update to include previous node
    {
        node *new_node = new node;
        new_node->data = x;
        new_node->next = next;
        new_node->prev = prev; // Set the previous node
        return new_node;
    }

    void Add_node_at_start(int x)
    {
        node *a = create_node(head, NULL, x); // Previous node is NULL at the start
        if (head == NULL)
        {
            head = tail = a;
        }
        else
        {
            head->prev = a; // Update previous pointer of the old head
            head = a;
        }
    }

    void Add_node_at_back(int x)
    {
        node *a = create_node(NULL, tail, x); // Next node is NULL at the end, and previous is the current tail
        if (head == NULL)
        {
            head = tail = a;
        }
        else
        {
            tail->next = a;
            tail = a;
        }
    }

    void delete_at_front()
    {
        if (head == NULL) return;
        node *temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL; // Update previous pointer of the new head
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void delete_at_last()
    {
        if (tail == NULL) return;

        node *temp = tail;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL; // Update next pointer of the new tail
        else head = NULL; // If the list is now empty
        delete temp;
    }

    void add_node_after_data_x(int x, int y)
    {
        node *tr = head;
        while (tr != NULL && tr->data != x)
        {
            tr = tr->next;
        }
        if (tr == NULL) return; // x was not found

        node *a = create_node(tr->next, tr, y);
        if (tr->next != NULL) tr->next->prev = a; // Update previous pointer of the node after new node
        tr->next = a;
        if (tr == tail) tail = a; // Update tail if needed
    }

    void delete_node_at_data_x(int x)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == x)
        {
            delete_at_front(); // Use delete_at_front to handle head deletion
            return;
        }

        node *tr = head->next; // Start from the second node
        while (tr != NULL && tr->data != x)
        {
            tr = tr->next;
        }

        if (tr == NULL)
        {
            cout << "Element not found." << endl;
            return;
        }

        tr->prev->next = tr->next;
        if (tr->next != NULL) tr->next->prev = tr->prev; // Update previous pointer of the next node
        else tail = tr->prev; // If deleting the last node, update tail

        delete tr;
    }

    void print()
    {
        node *tr = head;
        while (tr != NULL)
        {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout << endl;
    }
};

int main()
{
    ll link;
    link.Add_node_at_start(10);
    link.Add_node_at_back(15);
    link.print();
    link.add_node_after_data_x(10,19);
    link.print();
    link.delete_node_at_data_x(19);
    link.print();
}
