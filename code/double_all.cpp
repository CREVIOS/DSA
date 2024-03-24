#include <bits/stdc++.h>
using namespace std;

struct dll // Doubly linked list
{
    struct node
    {
        node *next;
        node *prev; // Previous pointer
        int data;
    };

    node *head = NULL;
    node *tail = NULL;

    // Function to create a new node
    node *create_node(int x)
    {
        node *new_node = new node;
        new_node->data = x;
        new_node->next = NULL;
        new_node->prev = NULL; // Initialize prev to NULL
        return new_node;
    }

    // Function to add a node at the start
    void Add_node_at_start(int x)
    {
        node *a = create_node(x);
        if (head == NULL)
        {
            head = tail = a;
        }
        else
        {
            a->next = head;
            head->prev = a; // Set previous of old head to new node
            head = a;
        }
    }

    // Function to add a node at the back
    void Add_node_at_back(int x)
    {
        node *a = create_node(x);
        if (head == NULL)
        {
            head = tail = a;
        }
        else
        {
            tail->next = a;
            a->prev = tail; // Set previous of new node to old tail
            tail = a;
        }
    }

    // Function to delete a node from the front
    void delete_at_front()
    {
        if (head == NULL) return;
        node *temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL; // Set previous of new head to NULL
        delete temp;
        if (head == NULL) tail = NULL; // Adjust tail if list becomes empty
    }

    // Function to delete a node from the back
    void delete_at_last()
    {
        if (head == NULL) return;
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    // Function to add a node after a node containing data x
    void add_node_after_data_x(int x, int y)
    {
        node *tr = head;
        while (tr != NULL && tr->data != x)
        {
            tr = tr->next;
        }
        if (tr == NULL) return; // x was not found

        node *a = create_node(y);
        a->next = tr->next;
        if (tr->next != NULL) tr->next->prev = a; // Adjust previous of the node after new node
        tr->next = a;
        a->prev = tr; // Set previous of new node to tr

        if (tr == tail) tail = a; // Adjust tail if needed
    }

    // Function to delete a node containing data x
    void delete_node_at_data_x(int x)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == x)
        {
            delete_at_front();
            return;
        }

        node *tr = head;
        while (tr != NULL && tr->data != x)
        {
            tr = tr->next;
        }
        if (tr == NULL)
        {
            cout << "Element not found." << endl;
            return;
        }

        if (tr->next != NULL) tr->next->prev = tr->prev; // Adjust previous of the node after tr
        if (tr->prev != NULL) tr->prev->next = tr->next; // Adjust next of the node before tr

        if (tr == tail) tail = tr->prev; // Adjust tail if needed
        delete tr;
    }

    void delete_node_at_kth_position(int k) {
    if (head == NULL || k < 1) {
        cout << "Invalid position or list is empty." << endl;
        return;
    }

    if (k == 1) {
        delete_at_front();
        return;
    }

    node *tr = head;
    int count = 1;

    // Traverse the list to find the kth node
    while (tr != NULL && count < k) {
        tr = tr->next;
        count++;
    }

    if (tr == NULL) {
        cout << "Position exceeds the size of the list." << endl;
        return;
    }

    // If deleting the last node
    if (tr->next == NULL) {
        delete_at_last();
        return;
    }

    // Adjust the pointers to bypass the kth node
    if (tr->prev != NULL) tr->prev->next = tr->next;
    if (tr->next != NULL) tr->next->prev = tr->prev;

    delete tr; // Free the memory of the kth node
}



    // Function to print the list
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
    dll link;
    link.Add_node_at_start(10);
    link.Add_node_at_back(15);
    link.print();
    link.add_node_after_data_x(10,19);
    link.print();
    link.delete_node_at_data_x(19);
    link.print();
    link.Add_node_at_start(10);
    link.Add_node_at_back(15);
    link.Add_node_at_back(20);
    link.Add_node_at_back(25);
    link.print();
    link.delete_node_at_kth_position(2);
    link.print(); // Prints: 10 20 25

    link.delete_node_at_kth_position(3);
    link.print(); // Prints: 10 20

}
