#include <stdio.h>
#include<conio.h>
#include "queue_int.h"
//terminal of Vscode that defulat encoding by system code
//so use GB2312,not utf8
//3.3.2_6 ����ģ�⿴��

void SeeDoctor()
{
    SeqQueue Q;
    InitQueue(&Q);
    int flag = 1;
    int n;
    while (flag)
    {
        printf("\n���������");
        char ch = getch();
        switch (ch)
        {
        case 'a':
            printf("\n�����ţ�");
            scanf("%d", &n);
            EnterQueue(&Q, n);
            break;
        case 'n':
            if (!IsEmpty(Q))
            {
                DeleteQueue(&Q, &n);
                printf("\n������Ϊ%d���˾���", n);
            }
            else
            {
                printf("\n�޲��˾���");
            }

            break;
        case 'q':
            printf("����ֹͣ�Һţ����в������ξ��");
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
    printf("��ҵ3.3.2_6\n");
    SeeDoctor();
    return 0;
}