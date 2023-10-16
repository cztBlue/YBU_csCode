#define MAXSIZE 100

typedef struct
{
    int element[MAXSIZE];
    int front;
    int rear;
} SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int EnterQueue(SeqQueue *Q, int x)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return 0;
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int DeleteQueue(SeqQueue *Q, int *x)
{
    if (Q->front == Q->rear)
        return 0;
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int GetHead(SeqQueue Q, int *x)
{
    if (Q.front == Q.rear)
        return 0;
    *x = Q.element[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return 1;
}

int IsEmpty(SeqQueue Q)
{
    if (Q.front == Q.rear)
        return 1;
    else
        return 0;
    // if (Q.front == (Q.rear + 1) % MAXSIZE)
}