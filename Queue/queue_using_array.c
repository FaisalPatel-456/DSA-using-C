#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if(q->rear == q->size-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}

int isEmpty(struct queue *q)
{
    if(q->rear == q->front)
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
    
}

void dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued %d from queue\n", q->arr[q->front+1]);
        q->front++;
    }
    
}

void printQueue(struct queue *q)
{
    printf("Queue:\n");
    for(int i = q->front+1; i <= q->rear; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));

    int ch, ele;

    do
    {
        printf("1:Enqueue\n2:Dequeue\n3:print queue\n4:exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to enqueue\n");
            scanf("%d", &ele);
            enqueue(&q, ele);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            printQueue(&q);
            break;

        case 4:
            printf("Program ended\n");
            break;
        
        default:
            break;
        }
    } while (ch!= 4);

    return 0;
}