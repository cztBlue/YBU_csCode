#include <stdio.h>
#include <stdlib.h>
// 习题3，第5题

// 结点结构
typedef struct QNode
{
	int data;
	struct QNode *next;
} QNode, *QueuePtr;

// 队列的链表结构
typedef struct
{
	QueuePtr rear;
} LinkQueue;

void InitQueue(LinkQueue *Q)
{
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->rear->next = Q->rear;
}

// 进队列
void EnQueue(LinkQueue *Q, int e)
{
	QueuePtr front = Q->rear->next;
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	s->data = e;
	// 新节点的后继指向队头指针
	s->next = front;
	Q->rear->next = s;
	// 把当前的s设置为队尾结点，rear指向s
	Q->rear = s;
}

// 出队列
int DeQueue(LinkQueue *Q, int *e)
{
	QueuePtr front = Q->rear->next;
	QueuePtr p;
	if (front == Q->rear)
		return 0;
	// 将欲删除的队头结点暂存给p
	p = front->next;
	*e = p->data;
	// 将p->next赋值给队头结点后继
	front->next = p->next;
	if (Q->rear == p)
		// 若队头就是队尾，则删除后将rear指向头结点
		Q->rear = front;
	free(p);
	return 1;
}

//历遍队列
void QueueTraverse(LinkQueue Q)
{
	QueuePtr front = Q.rear->next;
	QueuePtr p;
	p = front->next;
	printf("队头到队尾元素依次是 ：");
	while (p != front)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	printf("习题3，第5题\n");
	LinkQueue Q;
	int a;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	DeQueue(&Q, &a);
	EnQueue(&Q, 3);
	QueueTraverse(Q);
	return 0;
}
