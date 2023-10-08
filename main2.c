#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int n)
{
    node *p, *q, *r;
    p = (node *)malloc(sizeof(node));

    if (!p)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    scanf("%d", &(p->data));
    p->next = NULL;
    q = p;

    for (int i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(node));

        if (!r)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        scanf("%d", &(r->data));
        r->next = NULL;
        q->next = r;
        q = r;
    }

    return p;
}

void traverse(node *p)
{
    node *t = p;
    while (t != NULL)
    {
        printf("%d", t->data);
        printf("->");
        t = t->next;
    }
    t = p ;
}
void insertlist(node **p, int i, node *t)
{
    node *q,*x;
    if(i == 0){
        t->next = *p;
        *p = t;
    }else{
        q = *p;
        for(int j = 0 ; (j<i)&&(q!=NULL);j++){
            x = q;
            q = q->next;
        }
        t->next = x->next;
        x->next = t;
    }
}

int main(void)
{
    int n;
    printf("Enter Size Of Linkedlist: ");
    scanf("%d", &n);
    node *head = create(n);
    traverse(head);
    node *newNode = (node *)malloc(sizeof(node));
    printf("\nEnter the data for the new node: ");
    scanf("%d", &(newNode->data));
    insertlist(&head,0,newNode);
    traverse(head);


    return 0;
}
