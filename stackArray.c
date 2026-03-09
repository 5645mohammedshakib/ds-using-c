// stack implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int top = -1;
int max = 5;
int stack[50];
// ADts Decleration
void push();
void pop();
bool isEmpty();
bool isFull();
void peek();
void display();
// driver vode
int main(void)
{
	printf("\nEnter maximum capacity:");
	scanf("%d", &max);
	push(); // push -10
	push(); // push -20
	push(); // push-30
	display();
	push(); // push-40
	push(); // push-50
	push(); // push-60(overflow)
	display();
	peek();
	pop(); // pop-50
	pop(); // pop-40
	pop(); // pop-30
	display();
	pop(); // pop-20
	pop(); // pop-10
	pop(); // Underflow
	display();
	return 0;
}
bool isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
bool isFull()
{
	if (top == max - 1)
		return true;
	else
		return false;
}
void peek()
{
	if (isEmpty())
		printf("\nstack is Empty....:(");
	else
		printf("\nTop of the stack:%d", stack[top]);
}
void push()
{
	int item;
	if (isFull())
		printf("\nStack overFlow....:(");
	else
	{
		printf("\nEnter the item:");
		scanf("%d", &item);
		top = top + 1;
		stack[top] = item;
		printf("\n%d successfully pushed.....:", item);
	}
}
void pop()
{
	int item;
	if (isEmpty())
		printf("\nstack UnderFlow.....:(");
	else
	{
		item=stack[top];
		top = top - 1;
		printf("\n%d successfully poped....:)", item);
	}
}
void display()
{
	int i;
	if (isEmpty())
		printf("\nstack is Empty....:(");
	else
	{
		for (i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}
