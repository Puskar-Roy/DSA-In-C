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


void insertList(node **p,int i,node *t){
    node *q,*x;
    if( i == 0){
        t->right = *p;
        *p = t;
    }else{
        q = *p;
        for (int j = 0; j < (i - 1) && (q != NULL); j++)
        {
            q = q->right;
        }
        t->right = q->right;
        if (q->right != NULL)
        {
            q->right->left = t;
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
    // printf("Enter Index - ");
    // scanf("%d", &i);
    node *newNode;
    printf("Enter The Data Of New Node - ");
    scanf("%d", &(newNode->data));
    printf("Enter The Insert Index - ");
    scanf("%d", &i);
    insertList(&head , i , newNode);
    traverse(head);
    
    return 0;
}
