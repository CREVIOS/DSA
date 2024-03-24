#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
        cout << "Enqueued " << value << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue is empty after dequeue
        } else {
            front = (front + 1) % capacity;
        }
        return item;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[rear];
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Front element is: " << q.Front() << endl;
    cout << "Rear element is: " << q.Rear() << endl;

    q.dequeue();
    q.enqueue(6);

    cout << "After one dequeue and one enqueue:" << endl;
    cout << "Front element is: " << q.Front() << endl;
    cout << "Rear element is: " << q.Rear() << endl;

    return 0;
}
