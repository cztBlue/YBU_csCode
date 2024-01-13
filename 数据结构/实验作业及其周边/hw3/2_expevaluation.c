#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack_int.h" //int类型的栈
#define Stack_Size 50  /*设栈中元素个数为50*/
// 3.1.3 2_表达式求值
// stack_int.h 见源码附录

typedef struct
{
    char elem[Stack_Size];
    int top;
} Stack; // char栈

void InitStack(Stack *S)
{
    S->top = -1;
}

int Push(Stack *S, char x)
{
    if (S->top == Stack_Size - 1)
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

char GetTop(Stack *S)
{
    char x;
    if (S->top == -1)
        return 0;
    else
    {
        x = S->elem[S->top];
        return x;
    }
}

int IsEmpty(Stack *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}

int SGetNumber(char a)
{
    int i = (int)a - 48;
    return i;
}

int In(char ch, char *OPSet)
{
    //   #=-*/^ 5个
    for (int i = 0; i < 6; i++)
    {
        if (OPSet[i] == ch)
        {
            return 1;
        }
    }
    return 0;
}

// 比较操作符优先级 op1?op2
char Compare(char op1, char op2)
{
    int pos1, pos2;
    char OPSet[6] = {'#', '+', '-', '*', '/', '^'};
    for (int i = 0; i < 6; i++)
    {
        if (OPSet[i] == op1)
            pos1 = i;
        if (OPSet[i] == op2)
            pos2 = i;
    }
    int dalt = pos1 - pos2;
    if (dalt == 0)
        return '=';
    else
    {
        if (dalt > 0)
        {
            if (dalt >= 2)
                return '>';
            if (dalt == 1 && (pos1 == 0 || pos1 == 2 || pos1 == 4))
                return '=';
            else
                return '>';
        }
        else
        {
            if (dalt <= -2)
                return '<';
            if (dalt == -1 && (pos1 == 1 || pos1 == 3 || pos1 == 5))
                return '=';
            else
                return '<';
        }
    }
}

// 对输入操作符匹配后执行运算
int Execute(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return (int)pow((double)a, (double)b);
    case '#':
        return b;
    }
}

//为了方便数值测试,这里不采用getch获取表达式
int ExpEvaluation(char *exp)
{
    Stack OPTR;
    Stack_int OVS;
    char OPSet[6] = {'#', '+', '-', '*', '/', '^'};
    char op;
    int a, b;
    int v = 0;
    InitStack(&OPTR);
    InitStack_int(&OVS);
    Push(&OPTR, '#');
    // printf("\n\nPlease input an expression(Ending with #):");
    // char ch = getchar();
    int i = 0;
    int exp_len = strlen(exp);
    char ch = exp[i];
    while (ch != '#' || GetTop(&OPTR))
    {
        if (!In(ch, OPSet))
        {
            int n = SGetNumber(ch);
            Push_int(&OVS, n);
            // ch = getchar();
        }
        else
        {
            switch (Compare(ch, GetTop(&OPTR)))
            {
            case '>':
                Push(&OPTR, ch);
                // ch = getchar();
                break;
            case '=':
            case '<':
                Pop(&OPTR, &op);
                Pop_int(&OVS, &b);
                Pop_int(&OVS, &a);
                v = (int)Execute(a, op, b);
                Push_int(&OVS, v);
                i = i - 1;
                break;
            }
        }

        if (i + 1 < exp_len)
        {
            i++;
            ch = exp[i];
        }
    }
    v = GetTop_int(&OVS);
    return v;
}

int main()
{
    char *exp = "1*3+2*5/2#";
    printf("作业3.1.3_2\n");
    printf("表达式 %s 的值是: %d",exp,ExpEvaluation(exp));
    return 0;
}