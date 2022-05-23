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

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56156);
    push(sp, 56);
    push(sp, 516); // Pushed 10 values
    push(sp, 90); // Stack Overflow since the size of the stack is 10
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // LIFO - Last In First Out

    return 0;
}