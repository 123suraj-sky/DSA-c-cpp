#include <stdio.h>
#include <stdlib.h> // for malloc

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    //* Method 1
    // If we use while loop in this place then the execution will not start as initially ptr = head, so that's why we have to manually start the traversal

    // printf("Element: %d\n", ptr->data);
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     printf("Element: %d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    //* Method 2
    // To overcome this situation we can also use do-while loop which is more convient

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
};

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
    third->data = 6;
    third->next = fourth;

    // Link fourth and first nodes
    fourth->data = 1;
    fourth->next = head;

    printf("Circular linked list before insertion\n");
    CircularLinkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("\nCircular linked list after insertion\n");
    CircularLinkedListTraversal(head);
    return 0;
}