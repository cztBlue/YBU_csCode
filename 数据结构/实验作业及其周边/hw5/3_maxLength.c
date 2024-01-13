#include "queue_int.h"
#include <stdio.h>
#define MAXLEN 1000

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} BiTNode, *BiTree;

// 求二叉树最大宽度
int BiTreeWidth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        SeqQueue Q;
        InitQueue(&Q);
        int max = 0; // 记录最大宽度
        EnQueue(&Q, T);
        while (!QueueEmpty(Q))
        { // 层序遍历
            int point = QueueLength(Q);
            max = max > point ? max : point;
            while (point)
            {
                BiTree tmp = Q.element[Q.front];
                DeQueue(&Q);

                if (tmp->lchild != NULL)
                {
                    EnQueue(&Q, tmp->lchild); // 左孩子入队
                }

                if (tmp->rchild != NULL)
                {
                    EnQueue(&Q, tmp->rchild); // 右孩子入队
                }
            }
        }
        return max;
    }
}
