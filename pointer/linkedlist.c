#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *init(int value)
{
    struct Node *newnode = NULL;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    // Initialize the data and next pointer
    newnode->data = value;
    newnode->link = NULL;
    return newnode;
}

void insert(struct Node **head, int value)
{
    struct Node *newnode = init(value);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct Node *temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
}
void delete_it(struct Node **head, int value)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;
    // the deleted node is head, change head node
    if (temp->data == value && temp != NULL)
    {
        *head = temp->link;
        free(temp);
        return;
    }
    // Search for the node to be deleted, keeping track of the previous node
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Element is not in the list\n");
        return;
    }

    // Unlink the node from the linked list
    prev->link = temp->link;
    free(temp);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(struct Node *head)
{
    int swapped;
    struct Node *ptr;
    struct Node *lptr = NULL;
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->link != lptr)
        {
            if (ptr->data > ptr->link->data)
            {
                swap(&(ptr->data), &(ptr->link->data));
                swapped = 1;
            }
            ptr = ptr->link;
        }
        lptr = ptr;
    } while (swapped);

    return;
}
void printlist(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
void freelist(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}
int main()
{
    struct Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    printlist(head);
    delete_it(&head, 20);
    printlist(head);
    freelist(head);
    head = NULL;
    insert(&head, 18);
    insert(&head, 99);
    insert(&head, 16);
    insert(&head, 26);
    printlist(head);
    sort(head);
    printlist(head);
}
