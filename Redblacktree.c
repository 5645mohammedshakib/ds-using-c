#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
    int color;
};

struct RedBlackTree
{
    struct node *root;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->color = 1;
    return newNode;
}

struct RedBlackTree *createRedBlackTree()
{
    struct RedBlackTree *newTree = (struct RedBlackTree *)malloc(sizeof(struct RedBlackTree));
    if (newTree == NULL)
    {
        printf("Memory Allocation Error\n");
        exit(1);
    }
    newTree->root = NULL;
    return newTree;
}

void leftRotate(struct RedBlackTree *tree, struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(struct RedBlackTree *tree, struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        tree->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void insertFixup(struct RedBlackTree *tree, struct node *z)
{
    while (z->parent != NULL && z->parent->color == 1)
    {
        if (z->parent == z->parent->parent->left)
        {
            struct node *y = z->parent->parent->right;
            if (y != NULL && y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(tree, z->parent->parent);
            }
        }
        else
        {
            struct node *y = z->parent->parent->left;
            if (y != NULL && y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = 0;
}

void insert(struct RedBlackTree *tree, int data)
{
    struct node *z = createNode(data);
    struct node *y = NULL;
    struct node *x = tree->root;
    while (x != NULL)
    {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        tree->root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
    insertFixup(tree, z);
}

struct node *findMinValueNode(struct node *ptr)
{
    struct node *current = ptr;
    while (current->left != NULL)
        current = current->left;
    return current;
}

void deleteFixup(struct RedBlackTree *tree, struct node *x)
{
    while (x != tree->root && x->color == 0)
    {
        if (x == x->parent->left)
        {
            struct node *w = x->parent->right;
            if (w->color == 1)
            {
                w->color = 0;
                x->parent->color = 1;
                leftRotate(tree, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == 0 && w->right->color == 0)
            {
                w->color = 1;
                x = x->parent;
            }
            else
            {
                if (w->right->color == 0)
                {
                    w->left->color = 0;
                    w->color = 1;
                    rightRotate(tree, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->right->color = 0;
                leftRotate(tree, x->parent);
                x = tree->root;
            }
        }
        else
        {
            struct node *w = x->parent->left;
            if (w->color == 1)
            {
                w->color = 0;
                x->parent->color = 1;
                rightRotate(tree, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == 0 && w->left->color == 0)
            {
                w->color = 1;
                x = x->parent;
            }
            else
            {
                if (w->left->color == 0)
                {
                    w->right->color = 0;
                    w->color = 1;
                    leftRotate(tree, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                w->left->color = 0;
                rightRotate(tree, x->parent);
                x = tree->root;
            }
        }
    }
    x->color = 0;
}

void transplant(struct RedBlackTree *tree, struct node *u, struct node *v)
{
    if (u->parent == NULL)
        tree->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

void delete(struct RedBlackTree *tree, int data)
{
    struct node *z = tree->root;
    while (z != NULL && z->data != data)
    {
        if (data < z->data)
            z = z->left;
        else
            z = z->right;
    }
    if (z == NULL)
    {
        printf("Node not found in the tree\n");
        return;
    }
    struct node *y = z;
    struct node *x;
    int yOriginalColor = y->color;
    if (z->left == NULL)
    {
        x = z->right;
        transplant(tree, z, z->right);
    }
    else if (z->right == NULL)
    {
        x = z->left;
        transplant(tree, z, z->left);
    }
    else
    {
        y = findMinValueNode(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else
        {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(tree, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);
    if (yOriginalColor == 0)
        deleteFixup(tree, x);
}

void inOrderTraversal(struct node *root)
{
    char c[2][6] = {"BLACK", "RED"};
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d,%s -> ", root->data, c[root->color]);
        inOrderTraversal(root->right);
    }
}

void freeMemory(struct node *root)
{
    if (root == NULL)
        return;
    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}

int main(void)
{
    int choice, value;
    struct RedBlackTree *tree = createRedBlackTree();
    printf("Red Black Tree Implementation...!");
    do
    {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            insert(tree, value);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            delete(tree, value);
            break;
        case 3:
            inOrderTraversal(tree->root);
            break;
        case 4:
            freeMemory(tree->root);
            break;
        default:
            printf("\nWrong selection!!! Try again!!!");
        }
    } while (choice != 4);
    return (0);
}