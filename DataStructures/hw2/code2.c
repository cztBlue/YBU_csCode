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

void PrintList(LinkList L)
{
    Node *m = L->next;
    while (m != NULL)
    {
        printf("%d ", m->data);
        m = m->next;
    }
}

//输出倒数节点
void CountBack(LinkList L, int back)
{
    //按序记录所有访问过的节点
    int store[MAXSIZE];
    int pos = 0;
    Node *a = L->next;

    while (a != NULL)
    {
        store[pos] = a->data;
        a = a->next;
        pos++;
    }
    //到表尾直接查表
    printf("%d\n",store[pos-back]);
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
    CreateFromTai(A, data_a, 6);
    CreateFromTai(B, data_b, 7);

    // Test
    printf("链表数据:");
    PrintList(A);
    printf("\n");
    printf("倒数第3个节点：");
    CountBack(A,3);
    return 0;
}