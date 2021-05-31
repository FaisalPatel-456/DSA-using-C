#include<stdio.h>
#include<stdlib.h>

struct  stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char val)
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

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}

int match(char a, char b)
{
    if(a == '{' && b == '}')
    {
        return 1;
    }

    else if (a == '[' && b == ']')
    {
        return 1;
    }

    else if (a == '(' && b == ')')
    {
        return 1;
    }

    else
    {
        return 0;
    } 
}

int parenthesisMatching(char *exp)
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(isEmpty(sp))
            {
                return 0;
            }

            ch = pop(sp);
            if(!match(ch, exp[i]))
            {
                return 0;
            }
        }
        
    }

    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

int main()
{
    char * exp = "{8*[9 -(10*5)}";
    if(parenthesisMatching(exp))
    {
        printf("The parethesis are matching\n");
    }
    else
    {
        printf("The parethesis are not matching\n");
    }

    return 0;
}