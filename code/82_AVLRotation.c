#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height; // for calculating mod balance factor of AVL Tree
};

// gives height at every node
int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // as node is inserted at leaf, so every leaf node will give height = 1 to its parent node

    return n;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

// see 81 PDF for function details
struct node *rightRotate(struct node *y) // where 'y' is root node
{
    // Initialization
    struct node *x = y->left;
    struct node *T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // Updating new heights
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x; // returing 'x' as it become a root node
}

struct node *leftRotate(struct node *x) // where 'y' is root node
{
    // Initialization
    struct node *y = x->right;
    struct node *T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // Updating new heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y; // returing 'y' as it become a root node
}

struct node *insert(struct node *n, int key)
{
    if (n == NULL)
    {
        return createNode(key);
    }

    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
    }

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;

    int balanceFactor = getBalanceFactor(n);

    // Left Left Case
    if (balanceFactor > 1 && key < n->left->key)
    {
        return rightRotate(n);
    }

    // Right Right Case
    if (balanceFactor < -1 && key > n->right->key)
    {
        return leftRotate(n);
    }

    // Left Right Case
    if (balanceFactor > 1 && key > n->left->key)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    // Right Left Case
    if (balanceFactor < -1 && key < n->right->key)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    printf("\n");

    return 0;
}