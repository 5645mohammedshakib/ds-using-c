// Tree Traversals on Binary Trees - Non Recursive approach
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
int top = -1;
struct node *s[40];
// push into stack
int push(struct node *x)
{
    s[++top] = x;
}
// pop from stack
struct node *pop()
{
    struct node *x = s[top--];
    return (x);
}
// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// non-recursive function to perform preorder traversal
void preOrder(struct node *root)
{
    struct node *ptr;
    ptr = root;
    if (root == NULL)
        printf("\nTree is empty");
    else
    {
        push(root);
        while (top != -1)
        {
            ptr = pop();
            if (ptr != NULL)
            {
                printf("%d ", ptr->data);
                push(ptr->right);
                push(ptr->left);
            }
        }
    }
}
// non-recursive function to perform inorder traversal
void inOrder(struct node *root)
{
    struct node *ptr;
    ptr = root;
    if (root == NULL)
        printf("\nTree is empty");
    else
    {
        while (top != -1 || ptr != NULL)
        {
            if (ptr != NULL)
            {
                push(ptr);
                ptr = ptr->left;
            }
            else
            {
                ptr = pop();
                printf("%d ", ptr->data);
                ptr = ptr->right;
            }
        }
    }
}
// non-recursive function to perform postorder traversal
void postOrder(struct node *root)
{
    struct node *ptr;
    struct node *temp;
    ptr = root;
    temp = NULL;
    if (root == NULL)
        printf("\nTree is empty");
    else
    {
        while (ptr->left != NULL)
        {
            push(ptr);
            ptr = ptr->left;
        }
        while (ptr != NULL)
        {
            if (ptr->right == NULL || ptr->right == temp)
            {
                printf("%d ", ptr->data);
                temp = ptr;
                ptr = pop();
            }
            else
            {
                push(ptr);
                ptr = ptr->right;
                while (ptr->left != NULL)
                {
                    push(ptr);
                    ptr = ptr->left;
                }
            }
        }
    }
}
// Driver code
int main(void)
{
    // Constructing a binary tree
      // 1
     // / \
     // 2 3
    // / \
    // 4 5
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Non-Recursive Implementation of Tree Traversal\n");

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