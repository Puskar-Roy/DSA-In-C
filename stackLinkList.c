#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    struct node *top;
} stack;

int push(stack *s, int n)
{
    node *x;
    x = (node *)malloc(sizeof(node));
    x->data = n;
    x->next = s->top;
    s->top = x;
    return 1;
}

int pop(stack *s, int *a)
{
    node *t;
    if (s->top == NULL)
    {
        return 0;
    }
    *a = s->top->data;
    t = s->top;
    s->top = s->top->next;
    free(t);
    return 1;
}

void display(stack *s)
{
    if (s->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    node *current = s->top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d", current->data);
        printf("\n");
        current = current->next;
    }
}

int main(void)
{
    stack s;
    s.top = NULL;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    int data;
    pop(&s,&data);
    display(&s);


    return 0;
}