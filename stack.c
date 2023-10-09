#include <stdio.h>
#include <stdlib.h>
#define SIZE 10;

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

int push(int a, stack *s)
{
    if (s->top == SIZE - 1)
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

int main(void)
{
    
    return 0;
}
