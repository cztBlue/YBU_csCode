#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct Node
{
    int data;
    struct Node *next;

} Node, *LinkList;

// 初始化链表
void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// 尾插法建表
void CreateFromTai(LinkList L, int *data, int len)
{
    Node *r, *s;
    int pos = 0;
    r = L;
    while (pos + 1 <= len)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = data[pos];
        r->next = s;
        r = s;
        pos++;
    }
    r->next = NULL;
}

// 将链表顺序取反
void ReverseList(LinkList L)
{
    Node *m, *b, *a;
    Node *begin; // 去环
    b = L;
    a = m = begin = L->next;
    while (a != NULL)
    {
        a = m->next;
        m->next = b;
        if (a == NULL)
        {
            L->next = m;
            begin->next = NULL;
            break;
        }
        b = m;
        m = a;
    }
}

//降序相加
LinkList ReverseAddList(LinkList A, LinkList B)
{
    Node *a, *b, *c;
    a = A->next;
    b = B->next;

    if (A->next == NULL)
    {
        ReverseList(B);
        return B;
    }
    else if (B->next == NULL)
    {
        ReverseList(A);
        return A;
    }

    if (a->data >= b->data)
    {
        c = b;
        b = b->next;
    }
    else
    {
        c = a;
        a = a->next;
    }
    A->next = c;
    free(B);

    while (1)
    {
        // 跳出
        if (b == NULL)
        {
            c->next = a;
            break;
        }
        else if (a == NULL)
        {
            c->next = b;
            break;
        }

        // 选取逻辑
        if (a->data >= b->data)
        {
            c->next = b;
            b = b->next;
            c = c->next;
        }
        else
        {
            c->next = a;
            a = a->next;
            c = c->next;
        }
    }
    ReverseList(A);
    return A;
}

void PrintList(LinkList L)
{
    Node *m = L->next;
    while (m != NULL)
    {
        printf("%d ", m->data);
        m = m->next;
    }
}

int main()
{
    // Init
    LinkList A, B;
    InitList(&A);
    InitList(&B);

    // GiveValue
    int data_a[6] = {89, 100, 142, 150, 197, 200};
    int data_b[7] = {41, 53, 63, 111, 150, 170, 189};
    CreateFromTai(A, data_a, 5);
    CreateFromTai(B, data_b, 7);

    // Test
    printf("链表A:");
    PrintList(A);
    printf("\n");
    printf("链表B:");
    PrintList(B);
    LinkList L = ReverseAddList(A, B);
    printf("\n");
    printf("降序合并链表L:");
    PrintList(L);

    return 0;
}