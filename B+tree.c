#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BPTreeNode
{
    int *data;
    struct BPTreeNode **child_ptr;
    bool leaf;
    int n;
} *root = NULL, *np = NULL, *x = NULL;

struct BPTreeNode *init()
{
    int i;
    np = (struct BPTreeNode *)malloc(sizeof(struct BPTreeNode));
    np->data = (int *)malloc(sizeof(int) * 5);
    np->child_ptr = (struct BPTreeNode **)malloc(sizeof(struct BPTreeNode *) * 6);
    np->leaf = true;
    np->n = 0;

    for (i = 0; i < 6; i++)
        np->child_ptr[i] = NULL;

    return np;
}

void traverse(struct BPTreeNode *ptr)
{
    int i;
    for (i = 0; i < ptr->n; i++)
    {
        if (ptr->leaf == false)
            traverse(ptr->child_ptr[i]);

        printf("%d ", ptr->data[i]);
    }

    if (ptr->leaf == false)
        traverse(ptr->child_ptr[i]);
}

void sort(int *ptr, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (ptr[i] > ptr[j])
            {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }
}

int split_child(struct BPTreeNode *x, int i)
{
    int j, mid;
    struct BPTreeNode *np1, *np3, *y;

    np3 = init();
    np3->leaf = true;

    if (i == -1)
    {
        mid = x->data[2];
        x->data[2] = 0;
        x->n--;

        np1 = init();
        np1->leaf = false;
        x->leaf = true;

        for (j = 3; j < 5; j++)
        {
            np3->data[j - 3] = x->data[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->data[j] = 0;
            x->n--;
        }

        for (j = 0; j < 6; j++)
            x->child_ptr[j] = NULL;

        np1->data[0] = mid;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = x->child_ptr[i];
        mid = y->data[2];
        y->data[2] = 0;
        y->n--;

        for (j = 3; j < 5; j++)
        {
            np3->data[j - 3] = y->data[j];
            np3->n++;
            y->data[j] = 0;
            y->n--;
        }

        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3;
    }

    return mid;
}

void insert(int a)
{
    int i, temp;
    x = root;

    if (x == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->leaf == true && x->n == 5)
        {
            temp = split_child(x, -1);
            x = root;

            for (i = 0; i < (x->n); i++)
            {
                if ((a > x->data[i]) && (a < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < x->data[0])
                    break;
                else
                    continue;
            }
            x = x->child_ptr[i];
        }
        else
        {
            while (x->leaf == false)
            {
                for (i = 0; i < (x->n); i++)
                {
                    if ((a > x->data[i]) && (a < x->data[i + 1]))
                    {
                        i++;
                        break;
                    }
                    else if (a < x->data[0])
                        break;
                    else
                        continue;
                }

                if ((x->child_ptr[i])->n == 5)
                {
                    temp = split_child(x, i);
                    x->data[x->n] = temp;
                    x->n++;
                    continue;
                }
                else
                    x = x->child_ptr[i];
            }
        }
    }

    x->data[x->n] = a;
    sort(x->data, x->n);
    x->n++;
}

int main(void)
{
    int i, num, item;

    printf("B+ Trees Implementation...!\n");
    printf("Enter the no of elements to be inserted: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter the element:\n");
        scanf("%d", &item);
        insert(item);
    }

    printf("Traversal of constructed B+ tree:\n");
    traverse(root);

    return 0;
}