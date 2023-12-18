#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct stack
{
    int top;
    int arr[size];
} stack;

int push(stack *s, int a)
{
    if (s->top == size - 1)
    {
        return 0;
    }
    s->top += 1;
    s->arr[s->top] = a;
    return 1;
}

int pop(stack *s, int *a)
{
    if (s->top == -1)
    {
        return 0;
    }
    *a = s->arr[s->top];
    s->top -= 1;
    return 1;
}

void printStack(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]); // Corrected the printf statement
    }
    printf("\n");
}

int main(void)
{
    stack s;
    s.top = -1;
    push(&s, 10);
    push(&s, 20);
    int a = 20;
    pop(&s,&a);
    printStack(&s);
    return 0;
}
