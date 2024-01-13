#define Stack_Size 50 /*设栈中元素个数为50*/

typedef struct
{
    char elem[Stack_Size];
    int top;
} Stack_char;

void InitStack_char(Stack_char *S)
{
    S->top = -1;
}

int Push_char(Stack_char *S, char x)
{
    if (S->top == Stack_Size - 1)
        return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

int Pop_char(Stack_char *S, char *x)
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

char GetTop_char(Stack_char *S)
{
    char x;
    if (S->top == -1)
        return -1;
    else
    {
        x = S->elem[S->top];
        return x;
    }
}

int IsEmpty_char(Stack_char *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}