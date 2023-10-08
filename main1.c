#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Name[30];
    int Rollnumber;
    char Department[10];
    int Phone;
} Students;

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int n)
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

    // Use a temporary pointer to traverse
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    p = t;
}

void insertlist(node **p, int i, node *t)
{
    node *q, *x;
    int j;
    if (i == 0)
    {
        t->next = *p;
        *p = t;
    }
    else
    {
        q = *p;
        for (j = 0; (j < i) && (q != NULL); j++)
        {
            x = q;
            q = q->next;
        }
        if (j == i)
        {
            t->next = x->next;
            x->next = t;
        }
        else
        {
            printf("Invalid index for insertion.\n");
        }
    }
}

int main(void)
{
    // ______________Structures , Pointers , Arrow Operetors____________________
    // Students a;
    // strcpy(a.Name,"Puskar Roy");
    // a.Rollnumber = 20221013;
    // a.Phone = 77592456;
    // strcpy(a.Department,"CSE");
    // printf("Student a Is - %s ,Branch - %s ,Roll - %d ,Phone No - %d", a.Name, a.Department, a.Rollnumber, a.Phone);

    // Students *b;
    // b = &a;
    // b->Department = 23;
    // strcpy(b->Name,"Tumam");

    // printf("Hello %d",a.Rollnumber);
    // printf("\nHello %s", a.Name);

    // Students *c;
    // c = malloc(sizeof(Students));
    // c->Rollnumber = 10;
    // printf("\nHello %d", c->Rollnumber);
    // ___________________________________________________________________________________

    //________________________________Linkedlists_________________________________________

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    node *head = createnode(n);

    printf("Linked list elements: ");
    traverse(head);

    node *newNode = (node *)malloc(sizeof(node));
    printf("\nEnter the data for the new node: ");
    scanf("%d", &(newNode->data));
    int position;
    printf("Enter the position to insert (0 for beginning, %d for end): ", n);
    scanf("%d", &position);
    insertlist(&head, position, newNode);
    printf("Linked list elements after insertion: ");
    traverse(head);

    return 0;
}
