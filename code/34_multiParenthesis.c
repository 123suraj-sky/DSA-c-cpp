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

int match(char a, char b)
{
    if (a == '{' && b == '}')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
} // Above code for match can also be written in 1 if condition using "or"

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100; // or whatever size of stack is given
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poppedCh;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            poppedCh = pop(sp);
            if (!match(poppedCh, exp[i])) // if any parenthesis is not matched it will exit the loop
            {
                return 0;
            }
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
    char *exp = "((8)({}[*--$$9))";

    // Check if parenthesis is matching
    if (parenthesisMatch(exp))
        printf("The parenthesis is balanced\n");
    else
        printf("The parenthesis is not balanced\n");

    return 0;
}
