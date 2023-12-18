#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct stack
{
    int top;
    int arr[size];
} stack;

int push(int a, stack *s)
{
    if (s->top == size - 1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    s->top += 1;
    s->arr[s->top] = a;
    printf("%d pushed to the stack\n", a);
    return 1;
}

int pop(stack *s, int *a)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    *a = s->arr[s->top];
    s->top -= 1;
    printf("%d popped from the stack\n", *a);
    return 1;
}

void printStack(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    stack s;
    s.top = -1;

    push(10, &s);
    push(20, &s);
    push(30, &s);
    printStack(&s);

    int popped_value;
    pop(&s, &popped_value);
    printStack(&s);

    return 0;
}
