#include <stdio.h>
#include <stdlib.h>

// node declaration
struct node
{
    int data;
    struct node *next;
};

// head declaration
struct node *head;

// function declarations
void insertAtBeginning();
void insertAtEnd();
void insertRandom();
void deleteAtBeginning();
void deleteAtEnd();
void deleteRandom();
void display();
void search();

// Driver code
int main(void)
{
    insertAtBeginning();
    insertAtBeginning();
    insertAtBeginning();
    display();
    insertAtEnd();
    display();
    insertRandom();
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteRandom();
    display();
    search();
}
// Inserting node at the begining
void insertAtBeginning()
{
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        printf("\n%d Node Inserted at the begining Successfully...:)", item);
    }
}

// Inserting node at the end
void insertAtEnd()
{
    struct node *newNode;
    struct node *temp;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;

        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
            printf("\n%d Node Inserted at the end Successfully...:)", item);
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = NULL;
            printf("\n%d Node Inserted at the end Successfully...:)", item);
        }
    }
}

// Insert at random location
void insertRandom()
{
    int i, loc, item;
    struct node *newNode;
    struct node *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nCan't be inserted (Select different location)\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\n%d Node Inserted after %d Successfully...:)", item, loc);
    }
}

// Delete from beginning
void deleteAtBeginning()
{
    struct node *temp;
    if (head == NULL)
        printf("\nList is empty...:(");
    else
    {
        temp = head;
        head = temp->next;
        printf("\n%d Node deleted from the begining ...\n", temp->data);
        free(temp);
    }
}

// Delete from end
void deleteAtEnd()
{
    struct node *temp1;
    struct node *temp2;

    if (head == NULL)
        printf("\nList is empty...:(\n");

    else if (head->next == NULL)
    {
        printf("\n%d Only node of the list deleted ...\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp1 = head;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        printf("\n%d Node deleted from the end of the list...\n", temp1->data);
        free(temp1);
    }
}

// Delete random
void deleteRandom()
{
    struct node *temp1;
    struct node *temp2;
    int loc, i;
    if (head == NULL)
        printf("\nList is empty...:(");
    else
    {
        printf("\nEnter the location of the node after which to perform deletion: ");
        scanf("%d", &loc);
        temp1 = head;
        for (i = 1; i <= loc; i++)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            if (temp1 == NULL)
            {
                printf("\nCan't be deleted (Select different location)");
                return;
            }
        }
        temp2->next = temp1->next;
        printf("\n%d Node deleted from location %d", temp1->data, loc + 1);
        free(temp1);
    }
}

// Search
void search()
{
    struct node *temp;
    int item, i = 0, flag;
    temp = head;
    if (temp == NULL)
        printf("\nList is Empty...:(");
    else
    {
        printf("\nEnter item which you want to search: ");
        scanf("%d", &item);
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                printf("Item found at location %d ", i);
                flag = 0;
                break;
            }
            else
                flag = 1;
            i++;
            temp = temp->next;
        }
        if (flag == 1)
            printf("Item not found\n");
    }
}

// Displa sy
void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
        printf("\nList is Empty...:(");
    else
    {
        printf("\nSingly Linked List(SLL) is:\n");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
                printf(" -> ");
            else
                printf(" -> NULL ");
        }
    }
}
