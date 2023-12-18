#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *left;
} node;

node *createNode(int n)
{
    node *p, *q, *r;
    p = (node *)malloc(sizeof(n));
    scanf("%d", &(p->data));
    p->right = NULL;
    p->left = NULL;
    q = p;
    for (int i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(n));
        scanf("%d", &(r->data));
        r->right = NULL;
        r->left = q;
        q->right = r;
        q = r;
    }
    return p;
}

void traverse(node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        printf(" -> ");
        p = p->right;
    }
}

int main(void)
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    node *head = createNode(n);

    printf("Linked list elements: ");
    traverse(head);

    return 0;
}