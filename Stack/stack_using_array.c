#include<stdio.h>
#include<stdlib.h>

struct  stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void push(struct stack *ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    
}

void pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow");
    }
    else
    {
        // int val = ptr->arr[ptr->top];
        // ptr->top--;
        // return val;
        printf("popped %d from stack\n", ptr->arr[ptr->top]);
        ptr->top--;
    }
    
}

void peek(struct stack *ptr, int i)
{
    int peekIndex = ptr->top - i + 1;
    if(peekIndex < 0)
    {
        printf("Not valid position in stack");
    } 
    else
    {
        printf("Value at %d is %d\n", i, ptr->arr[peekIndex]);
    }
    
}

void stackTop(struct stack *ptr)
{
    printf("Top element is %d", ptr->arr[ptr->top]);
}

void stackBottom(struct stack *ptr)
{
    printf("Bottom element is %d", ptr->arr[0]);
}

void printStack(struct stack *ptr)
{
    printf("Stack:\ntop->");
    for(int i = ptr->top; i >= 0; i--)
    {
        printf("\t%d\n", ptr->arr[i]);
    }
}


int main()
{
    int ch = 0, ele;
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));

    do
    {
        printf("\n1:Push\n2:Pop\n3:Peek\n4:Print Stack\n5:Top Element\n6:Bottom Element\n7:Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to push\n");
            scanf("%d", &ele);
            push(s, ele);
            break;

        case 2:
            pop(s);
            break;
        
        case 3:
            printf("Enter index to peek\n");
            scanf("%d", &ele);
            peek(s, ele);
            break;

        case 4:
            printStack(s);
            break;

        case 5:
            stackTop(s);
            break;

        case 6:
            stackBottom(s);
            break;
        
        case 7:
            printf("Program ended...");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (ch != 7);

    return 0;
}