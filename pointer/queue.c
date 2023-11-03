#include <stdio.h>
#include <stdlib.h>

struct Queue
{

    struct Node
    {
        int data;
        struct Node *next;
    };
    Node *front;
    Node *rear;

    void init()
    {
        front = rear = NULL;
    }
    int isEmpty()
    {
        return front == NULL;
    }
    void enqueue(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            fprintf(stderr, "Error: Queue is empty\n");
            exit(EXIT_FAILURE);
        }
        Node *temp = front;
        int value = temp->data;
        front = temp->next;
        free(temp);
        return value;
    }

    int front_element()
    {
        if (isEmpty())
        {
            fprintf(stderr, "Error: Queue is empty\n");
            exit(EXIT_FAILURE);
        }
        return front->data;
    }

    void freeQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue myQueue;
    myQueue.init();

    myQueue.enqueue(10);
    myQueue.enqueue(20);

    myQueue.enqueue(30);

    myQueue.enqueue(40);

    printf("Front element: %d\n", myQueue.front_element());
    myQueue.dequeue();
    printf("After dequing Front element: %d\n", myQueue.front_element());

    while (!myQueue.isEmpty())
    {
        printf("%d ", myQueue.dequeue());
    }

    myQueue.freeQueue();

    return 0;
}
