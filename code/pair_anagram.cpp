#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class Stack {
public:
    Node<T>* top;

    Stack() : top(nullptr) {}

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (top != nullptr) {
            newNode->next = top;
        }
        top = newNode;
    }

    void pop() {
        if (top != nullptr) {
            Node<T>* toDelete = top;
            top = top->next;
            delete toDelete;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    // Since this is a generic stack, toString() is removed. Handling string conversion 
    // should be done externally if the type T supports it.

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// This function needs to be adjusted since toString() is removed.
// The demonstration below assumes T is char for simplicity, but it won't directly work for generic types.
template<typename T>
void generateWords(const vector<T>& elements, int max_length, Stack<T>& stack, vector<vector<T>>& sequences, vector<T>& currentSequence) {
    if(currentSequence.size() == max_length) {
        sequences.push_back(currentSequence);
        return;
    }

    for(T element : elements) {
        currentSequence.push_back(element);
        stack.push(element);
        generateWords(elements, max_length, stack, sequences, currentSequence);
        stack.pop();
        currentSequence.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> chars;
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        chars.push_back(ch);
    }
    int max_length;
    cin >> max_length;
    Stack<char> stack;
    vector<vector<char>> sequences; // Changed from vector<string> to vector<vector<char>> for generality
    vector<char> currentSequence;

    generateWords(chars, max_length, stack, sequences, currentSequence);

    for(const auto& sequence : sequences) {
        for(char ch : sequence) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
