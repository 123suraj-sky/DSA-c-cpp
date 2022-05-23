#include <stdio.h>
#include <stdlib.h> // for malloc

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1:
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

// Case 2:
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3:
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4:
struct Node *deleteAfterNode(struct Node *head, int value)
{

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL) // second condition to check if the value is not present in the linked list
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value) // Perform deletion only if the element is not present in linked list
    {
        p->next = q->next;
        free(q);
    }
    else
        printf("Value not found in linked list\n");
    
    return head;
}

int main()
{
    struct Node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // Case 1
    // head = deleteAtFirst(head);

    // Case 2
    // head = deleteAtIndex(head, 2);

    // Case 3
    // head = deleteAtEnd(head);

    // Case 4
    head = deleteAfterNode(head, 8);

    printf("\nLinked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}