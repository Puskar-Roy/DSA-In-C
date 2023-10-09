#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct dnode
{
    int data;
    struct dnode *left,*right;
} dnode;

node *createlist(int n)
{
    node *p, *q, *x;
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->next = NULL;
    q = p;
    for (int i = 0; i < n - 1; i++)
    {
        x = (node *)malloc(sizeof(node));
        scanf("%d", &(x->data));
        x->next = NULL;
        q->next = x;
        q = x;
    }
    return p;
}

dnode* createdlist(int n){
    dnode *p,*q,*r;
    p = (node* )malloc(sizeof(dnode));
    scanf("%d",&(p->data));
    p->left = NULL;
    p->right = NULL;
    q = p;
    for (int j = 0; j < n-1; j++)
    {
        r = (node *)malloc(sizeof(dnode));
        scanf("%d", &(r->data));
        r->right = NULL;
        r->left = q;
        q->right= r;
        q = r;
    }
    return p;
}

void dtraverse(dnode *p)
{
    dnode *t;
    t = p;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->right;
    }
}


void traverse(node *p)
{
    node *t;
    t = p;
    while (p != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    p = t;
}

void insertlist(node **p, int i, node *t)
{
   node *q,*x;
   if(i == 0){
    t->next = *p;
    *p = t;
   }else{
    q =*p;
    for (int j = 0;(j<i)&&(q!=NULL); j++){
        x = q;
        q =  q->next;
    }
    t->next = x->next;
    x->next = t;
   }
}


int main(void)
{
    int n, i;
    // printf("Enter Size Of Linked List - ");
    // scanf("%d", &n);
    // node *head = createlist(n);
    // node *newNode;
    // printf("Enter The Data Of New Node - ");
    // scanf("%d", &(newNode->data));
    // printf("Enter The Insert Index - ");
    // scanf("%d", &i);
    // insertlist(&head,i,newNode);
    // printf("Linked List After Insertion - ");
    // traverse(head);

   printf("Enter Size Of Linked List - ");
   scanf("%d", &n);
   dnode *head = createdlist(n);
   
    dtraverse(head);


   return 0;
}
