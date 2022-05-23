#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// function for creating node
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

struct node *searchIterative(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left; // new root is left side branch of previous root
        }
        else
        {
            root = root->right; // new root is right side branch of previous root
        }
    }
    return NULL; // in case if root is NULL
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node  with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node *n = searchIterative(p, 4);
    if (n != NULL)
    {
        printf("Found: %d\n", n->data);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}