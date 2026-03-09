#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
// global decleration
int front = -1, rear = -1, max, choice = 0;
int queue[30];
// function declerations
bool isEmpty();
bool isFull();
void enQueue();
void deQueue();
void peekFront();
void peekRear();
void display();

// driver code
int main(void)
{
    printf("Enter the max limit:");
    scanf("%d", &max);
    enQueue();
    enQueue();
    display();
    deQueue();
    display();
    peekFront();
    display();
    peekRear();
    display();
}

// finction definition
// Fixed: Changed NULL to -1 because front is an integer, not a pointer
// NULL is for pointers, -1 is the initial value of front
bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}
bool isFull()
{
    if (rear == max - 1)
        return true;
    else
        return false;
}
void enQueue()
{
    int item;
    if (isFull())
        printf("\nOverFlow...:(\n)");
    else
    {
        printf("\nEnter value:");
        scanf("%d", &item);
        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear = rear + 1;
        queue[rear] = item;
        printf("\n%d is successfully enQueued....:)", item);
    }
}
void deQueue()
{
    int item;
    if (isEmpty())
        printf("\nunderFlow....:(\n)");
    else
    {
        item = queue[front];
        printf("\n%d is successfully deQueued...:)", item);
        if (front == rear)
            front = rear = -1;
        else
            front = front + 1;
    }
}
void peekFront()
{
    if (isEmpty())
        printf("\nQueue is Empty...:(\n)");
    else
        printf("\n%d is at the front of the queue", queue[front]);
}
void peekRear()
{
    if (isEmpty())
        printf("\nQueue is Empty...:(\n)");
    else
        printf("\n%d is at the rear of the queue", queue[rear]);
}
void display()
{
    int i;
    if (isEmpty())
        printf("\nQueue is Empty...:(\n)");
    else
    {
        printf("\nQueue Elements Are:\n");
        for (i = front; i <= rear; i++)
            printf("\n%d", queue[i]);
    }
}
