#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"
//习题3,实习4

// x用char防溢出
void TransToLow(int X, char *x, int tarbase)
{
    Stack_char s;

    InitStack_char(&s);
    while (X != 0)
    {
        Push_char(&s, (char)((X % tarbase) + 48));
        X = X / tarbase;
    }

    char temp, i;
    for (int i = 0; IsEmpty_char(&s) == 0; i++)
    {
        Pop_char(&s, &temp);
        x[i] = temp;
        if (IsEmpty_char(&s) == 1)
        {
            x[i + 1] = '\0';
            break;
        }
    }
}

int main()
{
    printf("习题3,实习4\n");
    char s[50];
    TransToLow(789,s,4);
    printf("(10)789->(4)%s",s);
    return 0;
}