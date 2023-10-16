#include <stdio.h>
#define Stack_Size 50 /*设栈中元素个数为50*/
//3.1.3 1_括号匹配算法

typedef struct
{
    char elem[Stack_Size];
    int top;
} Stack;

void InitStack(Stack *S)
{
    S->top = -1;
}

int Push(Stack *S, char x)
{
    if (S->top ==Stack_Size -1)
        return 0;
    S->top++;
    S->elem[S->top] = x;
    return 1;
}

int Pop(Stack *S, char *x)
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

int GetTop(Stack *S, char *x)
{
    if (S->top == -1)
        return 0;
    else
    {
        *x = S->elem[S->top];
        return 1;
    }
}
int IsEmpty(Stack *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}

//是否左右匹配
int Match(char ch1, char ch2)
{
    switch (ch1)
    {
    case '(':
        if (ch2 == ')')
            return 1;

    case '[':
        if (ch2 == ']')
            return 1;
    case '{':
        if (ch2 == '}')
            return 1;
    case ')':
        if (ch2 == '(')
            return 1;
    case ']':
        if (ch2 == '[')
            return 1;
    case '}':
        if (ch2 == '{')
            return 1;
    }
    return 0;
}

//左括号入栈，左右匹配弹栈
void BracketMatch(char *str)
{
    Stack S;
    int i;
    char ch;
    InitStack(&S);
    for (i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            Push(&S, str[i]);
            break;
        case ')':
        case ']':
        case '}':
            if (IsEmpty(&S))
            {
                printf("\n 右括号多余!");
                return;
            }
            else
            {
                GetTop(&S, &ch);
                if (Match(ch, str[i]))
                    Pop(&S, &ch);
                else
                {
                    GetTop(&S, &ch);
                    if (Match(ch, str[i]))
                        Pop(&S, &ch);
                    else
                    {
                        printf("\n 对应的左右括号不同类!");
                        return;
                    }
                }
            }
        }
    }
    if (IsEmpty(&S))
        printf("\n括号匹配");
    else
        printf("\n左括号多余！");
}

int main()
{
    printf("作业3.1.3_1\n");
    char s[] = "{[]})}";
    printf("示例：%s",s);
    BracketMatch(s);

    char b[] = "{[]}";
    printf("\n示例：%s",b);
    BracketMatch(b);

    return 0;
}
