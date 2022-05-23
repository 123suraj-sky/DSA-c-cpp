#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;    // front
    int r;    // rear
    int *arr; // for dynamic memory alloction
};

int isEmpty(struct circularQueue *q) // this condition is same for both linear and circular queue
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if (((q->r + 1) % q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This circularQueue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This circularQueue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0; // it must not be -1 as in that case condition for isFull never match (see ifFull conditon)
    q.arr = (int *)malloc(q.size * sizeof(int));

    // if (isEmpty(&q))
    //     printf("Queue is empry\n");

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 5);
    // we can now only enqueue 3 elements in this case as 1 place is reserved for front i.e. 0
    
    printf("Dequeuing elements %d\n", dequeue(&q));
    printf("Dequeuing elements %d\n", dequeue(&q));
    printf("Dequeuing elements %d\n", dequeue(&q));

    enqueue(&q, 351);
    enqueue(&q, 355);
    enqueue(&q, 35);

    if (isEmpty(&q))
        printf("Queue is empty\n");
    if (isFull(&q))
        printf("Queue is full\n");

    return 0;
}