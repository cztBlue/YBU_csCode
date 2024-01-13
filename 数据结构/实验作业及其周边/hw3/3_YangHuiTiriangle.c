#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_int.h"
#define MAXSIZE 100
#define N 6
//3.2.3_3 ,杨辉三角

void YangHuiTriangle()
{
    SeqQueue Q;
    InitQueue(&Q);
    EnterQueue(&Q, 1);
    int temp = 0;
    int x = 0;
    for (int n = 2; n <= N; n++)
    {
        EnterQueue(&Q, 1);
        for (int i = 0; i < N+1-n; i++)
        {
            printf(" ");
        }

        for (int i = 1; i <= n - 2; i++)
        {
            DeleteQueue(&Q, &temp);
            printf("%d ", temp);
            GetHead(Q, &x);
            temp = temp + x;
            EnterQueue(&Q, temp);
        }
        DeleteQueue(&Q, &x);
        printf("%d ", x);
        EnterQueue(&Q, 1);
        printf("\n");
    }
    while (!IsEmpty(Q))
    {
        DeleteQueue(&Q, &x);
        printf("%d ", x);
    }
}

int main()
{
    printf("作业3.2.3_3 ,本例规模为6\n");
    YangHuiTriangle();
    return 0;
}