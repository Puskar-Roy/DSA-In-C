#include <stdio.h>
#include <stdlib.h>
#define size 10


typedef struct stack{
    int top;
    int arr [size];
}stack;


int push(stack *s,int n){
    if(s->top == size-1){
        return 0;
    }
    s->top += 1;
    s->arr[s->top] = n;
    return 1;
}

int pop(stack *s,int *n){
    if(s->top == -1){
        return 0;
    }
    *n = s->arr[s->top];
    s->top -= 1;
    return 1;
}


void printStack(stack *s){
    if(s->top == -1){
        return 0;
    }for (int i = 0; i <= size; i++)
    {
        printf("%d",)
    }
    

}