#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

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

int precedence(char ch)
{
    // case in which expression only contain +, -, *, /
    if (ch == '*' || ch == '/')
        return 3; // lets say for our code highest precedence is 3
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)

{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix1 = "a-b+t/6";
    printf("postfix1 is %s\n", infixToPostfix(infix1));
    char *infix2 = "x-y/z-k*d";
    printf("postfix2 is %s\n", infixToPostfix(infix2));

    return 0;
}
