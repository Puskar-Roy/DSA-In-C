#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct queue
{
    int front,rear;
    int arr[size];
} queue;

int push(queue *q, int n)
{
    if (q->rear == size - 1)
    {
        return 0; 
    }
    q->rear += 1;
    q->arr[q->rear] = n;
    return 1; 
}


int pop(queue *q, int *n)
{
    if (q->front == q->rear)
    {
        q->rear = -1;
        q->front = -1;
        return 0; 
    }

    *n = q->arr[q->front];
    q->front += 1;

    return 1; 
}

void display(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d", q->arr[i]);
        if (i < q->rear)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main(void)
{
    queue q;
    q.front = -1;
    q.rear = -1;

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    display(&q);

    int popped_value;
    if (pop(&q, &popped_value))
    {
        printf("Popped value: %d\n", popped_value);
    }

    display(&q);

    return 0;
}
