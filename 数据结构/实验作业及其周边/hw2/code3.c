#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

typedef struct Node
{
    int data;
    struct Node *next;

} Node, *LinkList;

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// loop_pos=0就是没有环，=x就是创建尾部接正数第x个的环链表
void CreateFromTai(LinkList L, int *data, int len, int loop_pos)
{
    Node *r, *s, *loopNode;
    int pos = 0;
    r = L;
    while (pos + 1 <= len)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = data[pos];
        r->next = s;
        r = s;
        pos++;
        if (loop_pos != 0 && pos + 1 == loop_pos)
        {
            loopNode = s;
        }
    }
    if (loop_pos != 0)
        r->next = loopNode;
    else
        r->next = NULL;
}

//判断链表节点地址是否被记录过
int IsExist(Node **a, Node *data, int size)
{
    int pos = 0;
    while (pos < size)
    {
        if (a[pos] == data)
            return 1;
        else
            pos++;
    }
    return 0;
}

void IsLoop(LinkList L)
{
    Node *address[MAXSIZE];
    int pos = 0;
    Node *a = L->next;
    while (a != NULL)
    {
        //按地址
        address[pos] = a;
        if (IsExist(address, a, pos))
        {
            printf("存在环\n");
            return;
        }
        a = a->next;
        pos++;
    }
    printf("无环\n");
    return;
}

int main()
{
    // Init
    LinkList A, B;
    InitList(&A);
    InitList(&B);

    // GiveValue
    int data_a[MAXSIZE] = {1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data_b[MAXSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CreateFromTai(A, data_a, 18, 0);//无环A
    CreateFromTai(B, data_b, 7, 4);//有环B

    // Test
    printf("A:");
    IsLoop(A);
    printf("B:");
    IsLoop(B);

    return 0;
}