#include <bits/stdc++.h>
using namespace std;

struct ll
{
    struct node
    {
        node *next;
        int data;
    };

    node *head = NULL;
    node *tail = NULL;

    node *create_node(node *next, int x)
    {
        node *new_node = new node; // Use new for C++ instead of malloc
        new_node->data = x;
        new_node->next = next;
        return new_node; // Return the newly created node
    }
    void Add_node_at_start(int x)
    {
        node *a = create_node(head, x);
        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            head = a;
        }
    }
    void Add_node_at_back(int x)
    {
        node *a = create_node(NULL, x);
        if (head == NULL) // Check if the list is empty
        {
            head = a;
            tail = a;
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
        delete temp; // Correctly free the old head
        if (head == NULL) tail = NULL; // If the list becomes empty
    }
    void delete_at_last()
    {
        if (head == NULL) return;

        if (head == tail) // If there's only one element
        {
            delete head;
            head = tail = NULL;
            return;
        }

        node *tr = head;
        while (tr->next != tail)
        {
            tr = tr->next;
        }

        delete tail;
        tail = tr;
        tail->next = NULL;
    }
    void add_node_after_data_x(int x, int y)
    {
        if (head == NULL) return;
        node *tr = head;
        while (tr != NULL && tr->data != x)
        {
            tr = tr->next;
        }
        if (tr == NULL) return; // x was not found
        node *a = create_node(tr->next, y);
        tr->next = a;
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
            node *temp = head;
            head = head->next;
            delete temp;
            if (head == NULL) tail = NULL;
            return;
        }
        node *tr = head;
        while (tr->next != NULL && tr->next->data != x)
        {
            tr = tr->next;
        }
        if (tr->next == NULL)
        {
            cout << "Element not found." << endl;
            return;
        }
        node *temp = tr->next;
        tr->next = temp->next;
        if (tr->next == NULL) tail = tr; // Adjust tail if needed
        delete temp;
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
