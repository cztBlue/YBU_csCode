#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"queue_char.h"
//terminal of Vscode that defulat encoding by system code
//so use GB2312,not utf8
//3.2.3_4 ，键盘缓冲区

int main()
{
    printf("作业3.2.3_4\n");
    char ch1,ch2;
    SeqQueue Q;
    int f;
    InitQueue(&Q);
    for (;;)
    {
        for (;;)
        {
            printf("A");
            if(kbhit()){
                ch1 = getch();
                if(ch1 == ';'||ch1==',') break;
                f = EnterQueue(&Q,ch1);
                if (f ==0)
                {
                    printf("循环队列已满\n");
                    break;
                } 
            }
            //实际做测试的时候闪的太快了看不清，这里停.3秒
            Sleep(300);
        }
        while (!IsEmpty(Q))
        {
            DeleteQueue(&Q,&ch2);
            putchar(ch2);
        }
        if (ch1==';') break;
    };
    return 0;
}
