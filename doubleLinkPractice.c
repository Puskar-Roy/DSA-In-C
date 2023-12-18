#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *left,*right;
}node;

node *createLink(int n){
    node *p,*q,*r;
    p = (node *)malloc(sizeof(n));
    scanf("%d",&(p->data));
    p->left = NULL;
    p->right = NULL;
    q = p;
    for (int i = 0; i < n-1; i++)
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

void traverse(node *p){
    while (p != NULL)
    {
        printf("%d",p->data);
        p = p->right;
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    node *head = createLink(n);
    traverse(head);

    return 0;
}