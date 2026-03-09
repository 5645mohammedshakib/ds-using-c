#include <stdio.h>
#include <stdlib.h>
// node Declaration
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
// head Declaration
struct node *head;
// Function Declarations
void insertAtBeginning(int item);
void insertAtEnd(int item);
void insertRandom(int loc, int item);
void deleteFromBeginning();
void deleteFromEnd();
void deleteRandom(int val);
void display();
void search();
// Driver Code
int main(void)
{
    // inserting nodes into the DLL
    insertAtBeginning(12);
    insertAtBeginning(24);
    insertAtEnd(32);
    insertAtEnd(49);
    insertRandom(77, 0);
    insertRandom(55, 2);
    // NULL <-> 24 <-> 77 <-> 12 <-> 55 <-> 32 <-> 49 <-> NULL
    // Display the items in DLL
    display();
    // Searching for value 55 & 92 in the DLL
    search(55);
    search(92);
    // Deleting items from DLL
    deleteFromBeginning();
    deleteFromEnd();
    deleteRandom(12);
    // NULL <-> 77 <-> 12 <-> 32 <-> NULL
    // Display the items in DLL
    display();
}
void insertAtBeginning(int item)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        newNode->data = item;
        if (head == NULL)
        {
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printf("\n%d inserted at the begining of DLL Successfully...:)", item);
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
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    }
    printf("\n%d inserted at the end of the DLL Successfully...:)", item);
}
void insertRandom(int item, int loc)
{
    struct node *newNode;
    struct node *temp;
    int i;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("\nMemory Overflow...:(");
    else
    {
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nThere are less than %d elements", loc);
                return;
            }
        }
        newNode->prev = temp;
        newNode->data = item;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("\n%d inserted after location %d in DLL Successfully...:)", item, loc);
    }
}
void deleteFromBeginning()
{
    int item;
    struct node *temp;
    if (head == NULL)
    {
        printf("\nUnderflow...:(");
        return;
    }
    if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        item = temp->data;
        free(temp);
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        item = temp->data;
        free(temp);
    }
    printf("\n%d deleted from begining of DLL Successfully...:)", item);
}
void deleteFromEnd()
{
    int item;
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\nUnderflow...:(");
        return;
    }
    // If there is only one node in the DLL
    if (head->next == NULL)
    {
        head = NULL;
        item = temp->data;
        free(temp);
    }
    // If there are morethan one node in the DLL
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        item = temp->data;
        free(temp);
    }
    printf("\n%d deleted from end of DLL Successfully...:)", temp->data);
}
void deleteRandom(int val)
{
    struct node *temp1;
    struct node *temp2;
    temp1 = head;
    while (temp1->data != val)
        temp1 = temp1->next;
    if (temp1->next == NULL)
        printf("\nCan't delete...:(");
    else if (temp1->next->next == NULL)
        temp1->next = NULL;
    else
    {
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
    }
    printf("\nnode after %d value deleted\n", val);
}
void display()
{
    struct node *temp;
    if (head == NULL)
        printf("\nDLL is Empty...:(");
    else
    {
        printf("\nDLL items are:\n");
        temp = head;
        printf("NULL <->");
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            if (temp->next != NULL)
                printf("<->");
            else
                printf("<-> NULL");
            temp = temp->next;
        }
    }
}
void search(int item)
{
    struct node *temp = head;
    int i = 0, flag;
    if (temp == NULL)
        printf("\nDLL is Empty...:(");
    else
    {
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                printf("\n%d found at location %d ", item, i);
                flag = 0;
                break;
            }
            else
                flag = 1;
            i++;
            temp = temp->next;
        }
        if (flag == 1)
            printf("\n%d not found\n", item);
    }
}
