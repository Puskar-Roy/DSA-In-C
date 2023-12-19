#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    struct node *front;
    struct node *rear;
} queue;

int push(queue *q, int n)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    if (t == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 0; // Indicate failure
    }

    t->data = n;
    t->next = NULL;

    if (q->front == NULL)
    {
        q->front = t;
        q->rear = t;
    }
    else
    {
        q->rear->next = t;
        q->rear = t;
    }

    return 1; 
}

int pop(queue *q, int *value)
{
    if (q->front == NULL)
    {
        fprintf(stderr, "Queue is empty\n");
        return 0; 
    }

    node *temp = q->front;
    *value = temp->data;

    q->front = temp->next;
    
    free(temp);

    if (q->front == NULL)
    {
        q->rear = NULL; 
    }

    return 1; 
}

void display(queue q)
{
    if (q.front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *current = q.front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{

    queue myQueue = {NULL, NULL};


    push(&myQueue, 10);
    push(&myQueue, 20);
    push(&myQueue, 30);


    printf("Queue elements: ");
    display(myQueue);

    
    int deletedValue;
    if (pop(&myQueue, &deletedValue))
    {
        printf("Deleted value: %d\n", deletedValue);
    }

    
    printf("Queue elements after deletion: ");
    display(myQueue);

    return 0;
}
