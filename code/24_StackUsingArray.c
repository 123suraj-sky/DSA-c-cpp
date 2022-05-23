#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// condition to check if stack is empty or full
int isEmpty(struct stack *ptr)
{
    // if stack is empty --> top = -1
    if (ptr->top == -1)
        return 1;
    else // no need of else required, we only place it here just for more readibility
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1) // as index starts from 0
        return 1;
    else // no need of else required, we only place it here just for more readibility
        return 0;
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));
    //! making stack pointer instead of stack so that it will easily be passed to functions via call by reference
    struct stack *s; // it becomes structure of poiners
    // s->size = 2;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // manually Pushing an element manually --> in next video we push via other method
    s->arr[0] = 7;
    s->top++;
    s->arr[1] = 7;
    s->top++;
    s->arr[2] = 7;
    s->top++;

    // Check if stack is empty
    if (isEmpty(s))
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");

    return 0;
}

