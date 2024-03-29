#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& s)
{
    stack<int> tempStack;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        // Move elements from tempStack to s where they are smaller than current
        while (!tempStack.empty() && tempStack.top() > current) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        // Push current to tempStack
        tempStack.push(current);
    }

    // Copy elements back to original stack to get them in ascending order
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Utility function to print contents of stack
void printStack(stack<int> s)
{
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

// Driver code
int main()
{
    stack<int> s;

    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Stack elements before sorting:\n";
    printStack(s);

    sortStack(s);
    cout << "\n";

    cout << "Stack elements after sorting:\n";
    printStack(s);

    return 0;
}
