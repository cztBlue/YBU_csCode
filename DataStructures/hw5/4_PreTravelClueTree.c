#include<stdio.h>
#include<stdlib.h>

typedef enum
{
    Link,
    Thread
} PointTag;

typedef struct BinaryTreeNode
{
    char _data;
    struct BinaryTreeNode *pLeft, *pRight;
    PointTag Ltag, Rtag;
} BiTreeNode;

void _PreOrder(BiTreeNode *Root)
{
    if (Root == NULL)
    {
        return;
    }
    BiTreeNode *pCur = Root;
    while (pCur != NULL)
    {
        while (pCur->pLeft != NULL && pCur->Ltag == Link) // 找到最左边的节点,标记
        {
            printf("%c", pCur->_data);
            pCur = pCur->pLeft;
        }
        printf("%c", pCur->_data);

        if (pCur->Ltag == Thread) // 遇到线索,向右
        {
            pCur = pCur->pRight;
        }
        while (pCur != NULL) // 循环右节点
        {
            if (pCur->pLeft != NULL && pCur->Ltag == Link) // 遇到左节点存在,访问
            {
                break;
            }
            printf("%c", pCur->_data);
            pCur = pCur->pRight;
        }
    }
}