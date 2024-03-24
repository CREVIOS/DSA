#include <bits/stdc++.h>
using namespace std;

struct ll
{
    struct node
    {
        int data;
        node *next;
    };
    node *head = NULL;
    node *tail = NULL;

    node *create_node(node *next, int data)
    {
        node *n = new node;
        n->data = data;
        n->next = next;
        return n;
    }

    void add_front(int data)
    {
        node *n = create_node(head, data);
        head = n;
        if (tail == NULL)
        {
            tail = head;
        }
    }

    void add_back(int data)
    {
        node *n = create_node(NULL, data); // Corrected to NULL
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    void delete_front()
    {
        if (head == NULL)
            return;
        node *temp = head;
        head = head->next;
        delete temp; // Corrected to delete
        if (head == NULL)
            tail = NULL;
    }

    void delete_back()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            delete head; // Corrected to delete
            head = tail = NULL;
            return;
        }
        node *tr = head;
        while (tr->next != tail)
        {
            tr = tr->next;
        }
        delete tail; // Corrected to delete
        tail = tr;
        tail->next = NULL;
    }

    void delete_at_position_x(int x)
{
    if (head == NULL || x < 0) return; // Check for empty list or invalid position

    if (x == 0) // Special case for head
    {
        node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) // If the list became empty
            tail = NULL;
        return;
    }

    node *tr = head;
    for (int cnt = 0; tr != NULL && cnt < x - 1 ; cnt++)
    {
        tr = tr->next;
    }

    // If position is out of bounds or we're at the last node without a next node
    if (tr == NULL || tr->next == NULL) return;

    node *temp = tr->next;
    tr->next = temp->next;
    if (tr->next == NULL) // If deleting the last node, update tail
        tail = tr;

    delete temp;
}


    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        node *tr = head;
        while (tr != NULL)
        {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout<<endl;
    }

    ~ll() // Destructor to clean up the list
    {
        while (head != NULL)
        {
            delete_front();
        }
    }
};

int main()
{
    ll work;
    work.add_front(5);
    work.add_front(6);
    work.print(); // Expected: 6 5
    work.delete_back();
    work.add_back(7);
    work.add_front(15);
    work.add_front(16);
    work.add_back(17);
    work.print(); // Expected: 6 5 7
    work.delete_back();
    work.print();
    work.delete_front();
    work.print();
    work.delete_at_position_x(1);
    work.print();
    return 0;
}


