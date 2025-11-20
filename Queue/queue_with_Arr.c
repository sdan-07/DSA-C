#include <stdio.h>
#include <stdlib.h>
#define max 4

typedef struct MyQ
{
    int front;
    int rear;
    int Q[max];
} *queue;
static queue q = NULL;

queue create_queue()
{
    if (q == NULL)
    {
        q = malloc(sizeof(struct MyQ));
        if (!q)
            exit(1);
        q->front = q->rear = -1;
    }
    return q;
}

queue enqueue(int E, queue q)
{
    q = create_queue();

    if ((q->rear + 1) % max == q->front)
    {
        printf("Queue is full\n");
        return q;
    }

    if (q->front == -1)
        q->front = q->rear = 0;
        
    else
        q->rear = (q->rear + 1) % max;

    q->Q[q->rear] = E;

    return q;
}

queue dequeue(queue q)
{
    q = create_queue();

    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return q;
    }

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
    {
        printf("\nDequeued Element: %d\n", q->Q[q->front]);
        q->front = (q->front + 1) % max;
    }

    return q;
}

void print()
{
    int t = q->front;
    printf("Queue elements:\n");

    while (t <= q->rear)
    {
        printf("%d ", q->Q[t]);

        if (t == q->rear)
            break;

        t = (t + 1) % max;
    }
}

int size()
{
    return ((q->rear - q->front) + 1);
}

int main()
{
    q = enqueue(90, q);
    q = enqueue(12, q);
    q = enqueue(43, q);
    q = enqueue(23, q);

    q = dequeue(q);

    print();
    printf("\nSize: %d ", size());

    return 0;
}