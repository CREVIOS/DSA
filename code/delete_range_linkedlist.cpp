#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    struct Node {
        int data;
        Node *next;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    void add_back(int data) {
        Node *n = new Node{data, nullptr};
        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void delete_range(int lower, int upper) {
        Node dummy{0, head};
        Node *current = &dummy;
        while (current && current->next) {
            if (current->next->data >= lower && current->next->data <= upper) {
                Node *toDelete = current->next;
                current->next = current->next->next;
                if (toDelete == tail) {
                    tail = current;
                }
                delete toDelete;
            } else {
                current = current->next;
            }
        }
        head = dummy.next;
    }

    void print() {
        Node *tr = head;
        while (tr != nullptr) {
            cout << tr->data << endl;
            tr = tr->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int n, value, lower, upper;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.add_back(value);
    }
    
    cin >> lower >> upper;
    list.delete_range(lower, upper);
    list.print();
    
    return 0;
}
