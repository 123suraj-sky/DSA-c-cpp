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
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

// Case 2:
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Case 3:
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4:
struct Node *insertAfterNode(struct Node *head, struct Node *previousNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = previousNode->next;
    previousNode->next = ptr;
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
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 66;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 41;
    fourth->next = NULL;

    linkedListTraversal(head);

    // Case 1
    // head = insertAtFirst(head, 56);
    // printf("After Insertion at first(Case 1):\n");
    // linkedListTraversal(head);

    // Case 2
    // head = insertAtIndex(head, 56, 1); // since it is insert in between so it will not work for index 0 for that use case 1
    // printf("After Insertion at index(Case 2):\n");
    // linkedListTraversal(head);

    // Case 3
    // head = insertAtEnd(head, 56);
    // printf("After Insertion at end(Case 3):\n");
    // linkedListTraversal(head);

    // Case 4
    head = insertAfterNode(head, second, 56);
    printf("After Insertion after a node(Case 4):\n");
    linkedListTraversal(head);

    return 0;
}