#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createlistdouble(int n)
{
    node *p, *q, *r;
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->left = NULL;
    p->right = NULL;
    q = p;
    for (int j = 0; j < n - 1; j++)
    {
        r = (node *)malloc(sizeof(node));
        scanf("%d", &(r->data));
        r->right = NULL;
        r->left = q;
        q->right = r;
        q =r ;
    }
    return p;
}

void traverse(node *p)
{
    node *t;
    t = p;
    while (p != NULL)
    {
        printf("%d ", t->data);
        t = t->right;
    }
}

void insertDoubleList(node **p, int position, int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    if (position == 0)
    {
        n->right = *p;
        *p= n; 
    }
    else
    {
        node *q = *p;
        int i;
        for (i = 0; i < (position - 1) && (q != NULL); i++)
        {
            q = q->right;
        }
        n->right = q->right;
        if (q->right != NULL)
        {
            q->right->left = n;
        }
        q->right = n;
        n->left = q;
    }
}

void insertList(node **p,int i,node *t){
    node *q,*x;
    if( i == 0){
        t->right = *p;
        *p = t;
    }else{
        q = *p;
        for (int j = 0; j < (q!=NULL)&&(i-1); j++)
        {
            q = q->right;
        }
        t->right = q->right;
        if (q->right != NULL)
        {
            q->right->left = n;
        }
        q->right= t;
        t->left = q; 
    }

}





int main(int argc, char const *argv[])
{
    int n,i;
    printf("Enter Size Of This Double Linked List - ");
    scanf("%d", &n);
    node *head = createlistdouble(n);
    // traverse(head);
    printf("Enter Index - ");
    scanf("%d", &i);
    insertDoubleList(&head , i, 0);
    traverse(head);
    
    return 0;
}
