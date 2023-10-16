#define Stack_Size 50 /*设栈中元素个数为50*/

typedef struct
{
    int elem[Stack_Size];
    int top;
} Stack_int;

void InitStack_int(Stack_int *S)
{
    S->top = -1;
}

int Push_int(Stack_int *S, int x)
{
    if (S->top == Stack_Size - 1)
        return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

int Pop_int(Stack_int *S, int *x)
{
    if (S->top == -1)
        return 0;
    else
    {
        *x = S->elem[S->top];
        S->top--;
        return 1;
    }
}

int GetTop_int(Stack_int *S)
{
    int x;
    if (S->top == -1)
        return 0;
    else
    {
        x = S->elem[S->top];
        return x;
    }
}

int IsEmpty_int(Stack_int *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}