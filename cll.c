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
// function declaration
void insertAtBeginning(int item);
void insertAtEnd(int item);
void deleteFromBeginning();
void deleteFromEnd();
void display();
void search(int item);
// Driver Code
int main(void)
{
    // inserting nodes into the CLL
    insertAtBeginning(34);
    insertAtBeginning(16);
    insertAtBeginning(8);
    insertAtEnd(72);
    insertAtEnd(43);
    // display the CLL
    display();
    // search the item
    search(72);
    // delete the items from CLL
    deleteFromBeginning();
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromEnd();
    // display the CLL
    display();
}
// function definition
void insertAtBeginning(int item)
{
    struct node *newNode;
    struct node *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        newNode->data = item;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        printf("\n%d inserted successfully at the beginning of CLL...:)", item);
    }
}
void insertAtEnd(int item)
{
    struct node *newNode;
    struct node *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        newNode->data = item;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        printf("\n%d inserted successfully at the end of CLL...:)", item);
    }
}
void deleteFromBeginning()
{
    struct node *temp;
    int item;
    if (head == NULL)
        printf("\nUnderflow...:(");
    else if (head->next == head)
    {
        head = NULL;
        item = head->data;
        free(head);
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        item = head->data;
        free(head);
        head = temp->next;
    }
    printf("\n%d deleted successfully from beginning of CLL...:)", item);
}
void deleteFromEnd()
{
    struct node *temp1;
    struct node *temp2;
    int item;
    if (head == NULL)
        printf("\nUnderflow...:(");
    else if (head->next == head)
    {
        head = NULL;
        item = head->data;
        free(head);
    }
    else
    {
        temp1 = head;
        while (temp1->next != head)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        item = temp1->data;
        free(temp1);
    }
    printf("\n%d deleted successfully from the end of CLL...:)", item);
}
void search(int item)
{
    struct node *temp;
    int i = 0, flag = 1;
    temp = head;
    if (temp == NULL)
        printf("\nCLL is Empty...:(");
    else
    {
        if (head->data == item)
            flag = 0;
        else
        {
            while (temp->next != head)
            {
                if (temp->data == item)
                {
                    flag = 0;
                    break;
                }
                else
                    flag = 1;
                i++;
                temp = temp->next;
            }
        }
        if (flag == 0)
            printf("%d found at location %d in CLL...:)", item, i);
        else
            printf("%d not found in CLL...:(", item);
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
        printf("\nCLL is Empty...:(");
    else
    {
        printf("\nCLL items are:\n");
        while (temp->next != head)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}