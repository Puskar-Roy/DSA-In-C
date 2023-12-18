#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int n)
{
    node *p, *q, *r;
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->next = NULL;
    q = p;
    for (int i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(node));
        scanf("%d", &(r->data));
        r->next = NULL;
        q->next = r;
        q = r;
    }
    return p;
}
void traverse(node *p)
{
    node *t;
    t = p;
    while (t != NULL)
    {
        printf("%d", t->data);
        printf(" -> ");
        t = t->next;
    }
    p = t;
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