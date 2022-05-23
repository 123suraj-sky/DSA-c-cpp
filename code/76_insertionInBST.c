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

void insert(struct node *root, int key)
{
    struct node *previous = NULL; // pointer that points to previous node
    while (root != NULL)
    {
        previous = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < previous->data)
    {
        previous->left = new;
    }
    else
    {
        previous->right = new;
    }
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

    insert(p, 7);
    printf("%d\n", p->right->right->data);

    return 0;
}