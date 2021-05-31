#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if(((q->rear+1) % q->size) == q->front)
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}

int isEmpty(struct circularQueue *q)
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

void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = val;
    }
    
}

void dequeue(struct circularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued %d from queue\n", q->arr[q->front+1]);
        q->front = (q->front+1) % q->size;
    }
    
}

// void printQueue(struct circularQueue *q)
// {
//     printf("Queue:\n");
//     for(int i = q->front+1; i <= q->rear; i++)
//     {
//         printf("%d\n", q->arr[i]);
//     }

// }

void printQueue(struct circularQueue *q)
{
    int i;
    if(isEmpty(q))
        printf("\nQueue empty\n");
    else
    {
        printf("\nContents of queue are\n");
        if(q->front < q->rear)
        {
            for(i = q->front+1;i <= q->rear;i++)
            {
                printf("%d\n",q->arr[i]);
            }
            printf("\n");
        }
        else
        {
            for(i = q->front+1; i < 5; i++)
            {
                printf("%d\n",q->arr[i]);
            }
            for(i = 0; i <= q->rear;i++)
            {
                printf("%d\n",q->arr[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    struct circularQueue q;
    q.size = 5;
    q.front = q.rear = 0;
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
