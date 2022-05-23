#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;    // front
    int r;    // rear
    int *arr; // for dynamic memory alloction
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 2;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // if (isEmpty(&q))
    //     printf("Queue is empry\n");

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    printf("Dequeuing elements %d\n", dequeue(&q));
    printf("Dequeuing elements %d\n", dequeue(&q));
    // enqueue(&q, 35); // it shows queue if full as exceeds its max size
    if (isEmpty(&q))
        printf("Queue is empty\n");
    if (isFull(&q))
        printf("Queue is full\n");

    return 0;
}