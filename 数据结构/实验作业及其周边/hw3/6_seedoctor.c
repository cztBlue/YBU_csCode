#include <stdio.h>
#include<conio.h>
#include "queue_int.h"
//terminal of Vscode that defulat encoding by system code
//so use GB2312,not utf8
//3.3.2_6 队列模拟看病

void SeeDoctor()
{
    SeqQueue Q;
    InitQueue(&Q);
    int flag = 1;
    int n;
    while (flag)
    {
        printf("\n请输入命令：");
        char ch = getch();
        switch (ch)
        {
        case 'a':
            printf("\n病历号：");
            scanf("%d", &n);
            EnterQueue(&Q, n);
            break;
        case 'n':
            if (!IsEmpty(Q))
            {
                DeleteQueue(&Q, &n);
                printf("\n病历号为%d的人就诊", n);
            }
            else
            {
                printf("\n无病人就诊");
            }

            break;
        case 'q':
            printf("今天停止挂号，下列病人依次就诊：");
            while (!IsEmpty(Q))
            {
                DeleteQueue(&Q, &n);
                printf("%d", n);
            }
            flag = 0;
            break;
        }
    }
}

int main()
{
    printf("作业3.3.2_6\n");
    SeeDoctor();
    return 0;
}