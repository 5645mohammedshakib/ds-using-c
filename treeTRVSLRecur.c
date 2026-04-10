// Tree Traversals on Binary Trees - Recursive approach
#include <stdio.h>
#include <stdlib.h>
// Definition of a node in a binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// Defining root of the tree
struct node *root = NULL;
// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// recursive function to perform preorder traversal
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// recursive function to perform inorder traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// recursive function to perform postorder traversal
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// Driver code
int main(void)
{
    // Constructing a binary tree
     // 1
    // / \
    // 2  3
    // /\
    // 4 5
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Recursive Implementation of Tree Traversal\n");

    // Pre-Order Traversals
    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    // In-Order Traversals
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");
    // Post-Order Traversals
    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");
    return 0;
}