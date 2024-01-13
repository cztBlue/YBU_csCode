#include <stdio.h>
#include <stdlib.h>
#define INFINITE 2147483647 

typedef struct Node
{
    int data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;

// 先序建树
int CreateBiTree(BiTree *bt, int dataset[], int pos, int len)
{
    if (pos >= len)
    {
        *bt = NULL;
    }
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        (*bt)->data = dataset[pos];
        pos++;
        pos = CreateBiTree(&((*bt)->LChild), dataset, pos, len);
        pos++;
        pos = CreateBiTree(&((*bt)->RChild), dataset, pos, len);
    }
    return pos;
}
// void CreateBiTree(BiTree *bt)
// {
//     char ch;
//     ch = getchar();

//     if (ch == '.')
//     {
//         *bt = NULL;
//     }
//     else
//     {
//         *bt = (BiTree)malloc(sizeof(BiTNode));
//         (*bt)->data = ch;
//         CreateBiTree(&((*bt)->LChild));
//         CreateBiTree(&((*bt)->RChild));
//     }
// }

void PreOrder(BiTree root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

int PostTreeDepth(BiTree bt)
{
    int hl, hr, max;
    if (bt != NULL)
    {
        hl = PostTreeDepth(bt->LChild);
        hr = PostTreeDepth(bt->RChild);
        max = hl > hr ? hl : hr;
        return (max + 1);
    }
    else return 0;
}

int main()
{
    BiTree *bt;
    int dataset[6] = {1, 2, 3, 4, 5, 6};
    int pos = 0, len = 6;
    CreateBiTree(bt, dataset, pos, len);
    PreOrder(*bt);
    printf("\n深度：%d", PostTreeDepth(*bt));
    return 0;
}