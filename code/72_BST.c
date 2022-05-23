// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h> --> included in stdlib.h

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

int isBST(struct node *root) // check if the binary tree is BST or not
{
    static struct node *previous = NULL; // node whose children we are checking
    // initially it is NULL b/c previous of 1st root is NULL
    // it is static b/c 1st node is alwasy root
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (previous != NULL && root->data <= previous->data)
        {
            return 0;
        }

        previous = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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

    if (isBST(p))
        printf("It is a BST\n");
    else
        printf("It is not a BST\n");
    
    return 0;
}