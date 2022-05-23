// notes--> This code doesn't tell about the validity of expression it only tells about the validity of expression

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char val)
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

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! Cannot pop from the stack\n");
        return -1; // assuming "-1" is never present in the stack
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100; // or whatever size of stack is given
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    // For following condition we can also use
    // return isEmpty(sp);
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "8*(9)";

    // Check if parenthesis is matching
    if (parenthesisMatch(exp))
        printf("The parenthesis is matching\n");
    else
        printf("The parenthesis is not matching\n");

    return 0;
}
