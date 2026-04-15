#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3
#define MIN_KEYS 1
#define MAX_CHILDREN (MAX_KEYS + 1)

struct BTreeNode
{
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_CHILDREN];
    int numKeys;
    int isLeaf;
};

struct BTreeNode *createNode(int isLeaf)
{
    int i;
    struct BTreeNode *node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;

    for (i = 0; i < MAX_CHILDREN; i++)
        node->children[i] = NULL;

    return node;
}

void splitChild(struct BTreeNode *parent, int index, struct BTreeNode *child)
{
    int i;
    struct BTreeNode *newChild = createNode(child->isLeaf);
    newChild->numKeys = MIN_KEYS;

    for (i = 0; i < MIN_KEYS; i++)
        newChild->keys[i] = child->keys[i + MIN_KEYS + 1];

    if (!child->isLeaf)
    {
        for (i = 0; i < MIN_KEYS + 1; i++)
            newChild->children[i] = child->children[i + MIN_KEYS + 1];
    }

    child->numKeys = MIN_KEYS;

    for (i = parent->numKeys; i >= index + 1; i--)
        parent->children[i + 1] = parent->children[i];

    parent->children[index + 1] = newChild;

    for (i = parent->numKeys - 1; i >= index; i--)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = child->keys[MIN_KEYS];
    parent->numKeys++;
}

void insertNonFull(struct BTreeNode *node, int key)
{
    int i = node->numKeys - 1;

    if (node->isLeaf)
    {
        while (i >= 0 && node->keys[i] > key)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->numKeys++;
    }
    else
    {
        while (i >= 0 && node->keys[i] > key)
            i--;

        if (node->children[i + 1]->numKeys == MAX_KEYS)
        {
            splitChild(node, i + 1, node->children[i + 1]);

            if (key > node->keys[i + 1])
                i++;
        }

        insertNonFull(node->children[i + 1], key);
    }
}

void insert(struct BTreeNode **root, int key)
{
    struct BTreeNode *r = *root;

    if (r->numKeys == MAX_KEYS)
    {
        struct BTreeNode *newRoot = createNode(0);
        newRoot->children[0] = r;

        splitChild(newRoot, 0, r);

        int i = 0;
        if (newRoot->keys[0] < key)
            i++;

        insertNonFull(newRoot->children[i], key);
        *root = newRoot;
    }
    else
    {
        insertNonFull(r, key);
    }
}

void traverse(struct BTreeNode *root)
{
    if (root == NULL)
        return;

    int i;
    for (i = 0; i < root->numKeys; i++)
    {
        if (!root->isLeaf)
            traverse(root->children[i]);

        printf("%d ", root->keys[i]);
    }

    if (!root->isLeaf)
        traverse(root->children[i]);
}

int main(void)
{
    struct BTreeNode *root = createNode(1);

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);

    printf("Traversal of the constructed B-tree is:\n");
    traverse(root);

    return 0;
}