#include <stdio.h>
#include <malloc.h> // for making root node

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// function for creating node
struct node *createNode(int data)
{
    struct node *n; // nodes
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n; // returning created node
}

int main()
{
    
    /*
    Here we see lines are repeating itself so we created a function for it
    // Creating Root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Creating Second node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Creating third node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */

    struct node *p = createNode(2); // constructing root node
    struct node *p1 = createNode(1); // construting second node
    struct node *p2 = createNode(4); // constructing third node

    // Linking the root node  with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}