#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
        printf("Stack Overflow!! Cannot push %d to the stack\n", val);
    // return; --> not required as it already return as there is nothing but only if-else
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! Cannot pop from the stack\n");
        return -1; // assuming "-1" is never present in the stack
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *sp, int i)
{
    int arrayInd = sp->top - i + 1; // array index
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int stackTop(struct Stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct Stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    push(sp, 46);
    push(sp, 565);
    push(sp, 78);
    push(sp, 756);
    push(sp, 586);
    push(sp, 569);
    push(sp, 65);
    push(sp, 566);
    push(sp, 51);
    push(sp, 516);
    push(sp, 90);

    printf("The top most value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));

    return 0;
}