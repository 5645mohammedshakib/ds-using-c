// stack linked list implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

// node decleration
struct node
{
    int data;
    struct node *next;
};

// global declerations
struct node *top = NULL;

// function declerations
bool isEmpty();
void push();
void pop();
void peek();
void display();

// driver code
int main(void)
{
    push();
    push();
    display();

    peek();

    pop();
    display();
    return 0;
}
bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void push()
{
    int item;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory overflow....:(");
    else
    {
        printf("\nEnter item value:");
        scanf("%d", &item);
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        printf("\n%d pushed successfully.....:", item);
    }
}
void pop()
{
    if (isEmpty())
        printf("\nUnderflow.....:(");
    else
    {
        struct node *temp = top;
        top = top->next;
        printf("\n%d is poped successfully.....", temp->data);
        free(temp);
    }
}
void peek()
{
    if (isEmpty())
        printf("\nstack is Empty....:(");
    else
        printf("\n%d is at top of the stack", top->data);
}
void display()
{
    if (isEmpty())
        printf("\nstack is Empty....:(");
    else
    {
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        if (temp == NULL)
            printf("NULL");
    }
}
