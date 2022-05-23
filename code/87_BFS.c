// Breadth First Search

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
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        // printf("This queue is empty\n");
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
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;                               // node to be dequeued
    int i = 0;                              // starting with node 0
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // visited matrix for tracked notes
    int a[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}}; // adjacent matrix --> to fill matrix see notes of 87 where graph is given

    printf("%d\t", i);
    visited[i] = 1; // after visiting node mark it to 1
    enqueue(&q, i); // Enqueue for exploration

    while (!isEmpty(&q))
    {
        node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0) /*
            First condition checks if the node is connected
            And, second condition checks if the node is not visited*/
            {
                printf("%d\t", j);
                visited[j] = 1; // after visiting node mark it to 1
                enqueue(&q, j);
            }
        }
    }
    printf("\n");

    return 0;
}