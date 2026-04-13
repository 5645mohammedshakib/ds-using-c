#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d -> ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->key);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
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
    int value, n, i;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n\nEnter value to delete: ");
    scanf("%d", &value);
    root = deleteNode(root, value);

    printf("\nAfter Deletion (Inorder): ");
    inorder(root);

    freeMemory(root);
    return 0;
}