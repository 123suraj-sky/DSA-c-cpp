#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL, *r = NULL; // f - front & r - rear

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val) // no need to pass f & r b/c they are global variables
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) //* checking isFull condition
    {
        printf("Queue if full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue() // no need to pass f & r b/c they are global variables
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL) //* checking isEmpty condition
    {
        printf("Queue if Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue()); // it returns -1 as queue is empty
    enqueue(34);
    enqueue(3);
    enqueue(4);
    enqueue(17 - 1);
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);

    return 0;
}