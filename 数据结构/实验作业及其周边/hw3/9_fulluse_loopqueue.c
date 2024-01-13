#include <stdio.h>
#define MAXSIZE 100
//习题3，第6题

typedef struct
{
    int element[MAXSIZE];
    int front;
    int rear;
    int tag;
} SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, int x)
{
    if(Q->front == Q->rear && Q->tag == 1)
        return 0;
    else
    {
        Q->element[Q->rear] = x;
        Q->rear = (Q->rear+1) % MAXSIZE;//通过求模运算实现循环
        if(Q->front == Q->rear)  //如果此时队头和队尾相等，则设置tag为1，表示队列已满
        {
            Q->tag = 1;
        }
        return 1;
    }
}


int DeleteQueue(SeqQueue *Q, int *x)
{
    if(Q->front == Q->rear && Q->tag == 0)
        return 0;
    else
    {
        *x = Q->element[Q->front];
        Q->front = (Q->front+1) % MAXSIZE;
        if(Q->front == Q->rear)   //如果此时队头和队尾相等，则设置tag为0，表示队列为空
            Q->tag = 0;
        return 1;
    }
}

int main()
{
    printf("习题3，第6题\n");
    SeqQueue Q;
    int res,code;
    InitQueue(&Q);
    EnterQueue(&Q, 10);
    EnterQueue(&Q, 9);
    code = DeleteQueue(&Q, &res);
    printf("out1:%d state code:%d\n", res,code);
    code = DeleteQueue(&Q, &res);
    printf("out2:%d state code:%d\n", res,code);
    printf("state code:%d", DeleteQueue(&Q, &res));
    return 0;
}
