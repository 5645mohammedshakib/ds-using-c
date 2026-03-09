#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// node declaration
struct node
{
    int data;
    struct node *next;
};
// Global declarations
struct node *front = NULL;
struct node *rear = NULL;
int choice = 0;
// function declarations
bool isEmpty();
void enQueue();
void deQueue();
void peekFront();
void peekRear();
void display();
// Driver Code
int main(void)
{
    enQueue();
    enQueue();
    enQueue();

    display();

    deQueue();
    deQueue();
    display();

    peekFront();
    peekRear();
}
// function defintion
bool isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}
void enQueue()
{
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(\n");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;
        if (isEmpty())
        {

             front = rear = newNode;
            rear->next = NULL;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = NULL;
        }
        printf("\n%d successfully enQueued...:)", item);
    }
}
void deQueue()
{
    struct node *temp;
    if (isEmpty())
        printf("\nUnderflow...:(");
    else
    {
        temp = front;
        front = front->next;
        printf("\n%d successfully deQueued...:)", temp->data);
        free(temp);
    }
}
void peekFront()
{
    if (isEmpty())
        printf("\nQueue is Empty...:(");
    else
        printf("\n%d is at the front of the Queue", front->data);
}
void peekRear()
{
    if (isEmpty())
        printf("\nQueue is Empty...:(");
    else
        printf("\n%d is at the rear of the Queue", rear->data);
}
void display()
{
    struct node *temp = front;
    if (isEmpty())
        printf("\nQueue is Empty...:(");
    else
    {
        printf("\nQueue Elements are: \n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
}   }   