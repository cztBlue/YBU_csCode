#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#define ERROR -1
#define OK 0
using namespace std;

typedef int STATUS;
// 定义链表节点
typedef struct Node
{
    string name;
    int score;
    struct Node *next;

} Node, *LinkList;

// 初始化链表
void InitList(LinkList *H)
{
    // 分配头指针空间
    *H = new Node;
    (*H)->next = NULL;
}

// 尾插法建表
void CreateFromTai(LinkList H, string *data_name, int *data_score, int len)
{
    Node *r, *s;
    int pos = 0;
    r = H;
    while (pos + 1 <= len)
    {
        s = new Node;
        s->name = data_name[pos];
        s->score = data_score[pos];
        r->next = s;
        r = s;
        pos++;
    }
    r->next = NULL;
}

// 插入(给值按位置插入)
STATUS LinkInsert(LinkList H, string e_name, int e_score, int i)
{
    Node *temp = H;
    i++;
    if (i <= 0)
    {
        cout << " 提示：非法插入 ";
        return ERROR;
    }

    // 找到要插入位置的上一个结点
    for (int j = 1; j < i; j++)
    {
        if (temp == NULL)
        {
            cout << "提示:插入位置无效";
            return ERROR;
        }
        temp = temp->next;
    }
    // 创建插入结点c
    Node *c = new Node;
    c->name = e_name;
    c->score = e_score;
    // 向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return OK;
}

// 删除
STATUS LinkDele(const LinkList H, string name)
{
    Node *cur;
    Node *temp = NULL;
    // temp指向被删除结点的上一个结点
    for (cur = H->next; cur != NULL && cur->name != name; cur = cur->next)
        temp = cur;

    if (cur == NULL)
    {
        cout << " 删除的节点不存在 ";
        return ERROR;
    }

    Node *del = temp->next;
    temp->next = cur->next;
    delete del;
    return OK;
}

// 按数值查找一个元素
Node *LinkFinde(const Node *H, string name)
{
    Node *ptr = H->next;
    if (ptr == NULL)
    {
        cout << "链表为空";
        return NULL;
    }

    while (ptr != NULL && ptr->name != name)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        return ptr;
    }
    else
    {
        cout << "未查到";
        return NULL;
    }

    return NULL;
}

// 查找按位置
Node *LinkFindi(LinkList H, int i)
{
    Node *ptr = H->next;
    if (ptr == NULL || i < 0)
    {
        cout << " 提示：非法访问 ";
        return NULL;
    }

    for (int j = 0; j < i && ptr != NULL; j++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
        cout << "未查到";

    return ptr;
}

// 显示
void PrintList(const LinkList L)
{
    Node *m = L->next;
    while (m != NULL)
    {
        cout << "(" << m->name << " " << m->score << ")"
             << "->";
        m = m->next;
    }
    cout << "" << endl;
    return;
}

void PrintList_c(const LinkList L)
{
    Node *m = L->next;
    while (m != NULL)
    {
        printf ("(%s %d)->",  m->name.c_str(), m->score );
        m = m->next;
    }
    printf("\n");
}

// 返回一个新表头，原有的AB表头置空
void MergeList(LinkList A, LinkList B)
{
    Node *l1 = A->next;
    Node *l2 = B->next;
    Node *curp ;
    if (l1->score < l2->score)
        A->next = l1;
    else
        A->next = l2;

    delete B;
    B = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        // 判断两个链表 较小的添加到合并链表后面，并且小链表后移
        if (l1->score < l2->score)
        {
            curp->next = l1;
            l1 = l1->next;
        }
        else
        {
            curp->next = l2;
            l2 = l2->next;
        }
        // 指针后移
        curp = curp->next;
    }
    // l1、l2不空的链表 添加到合并链表后面
    if (l1 != NULL)
    {
        curp->next = l1;
    }
    if (l2 != NULL)
    {
        curp->next = l2;
    }
    return;
}

int main()
{
    // 数据初始化
    LinkList A, B;
    InitList(&A);
    InitList(&B);
    srand(114514);

    string data_a_name[100] = {"Joseph", "Vincenzo", "Langston", "Malakai", "Kylo", "Sutton", "Ayden", "Sinclair", "Elliott", "Lowell", "Ryan", "Stefan", "Andre", "Carlos", "Holden"};
    int data_a_score[20] = {89, 100, 42, 50, 97, 20};
    string data_b_name[100] = {"Ulysses", "Moises", "Dexter", "Chris", "Toby", "Kylen", "Oral", "Edgar", "Dash", "Joseph", "Westley", "Damari", "Sinclair", "Kaysen"};
    int data_b_score[20] = {89, 100, 42, 50, 97, 20};

    int arrStdLen = 8;
    for (int i = 0; i < arrStdLen; i++)
    {
        data_a_score[i] = rand() % 101;
        data_b_score[i] = rand() % 101;
    }
    sort(data_a_score, data_a_score + arrStdLen);
    sort(data_b_score, data_b_score + arrStdLen);

    CreateFromTai(A, data_a_name, data_a_score, 6);
    CreateFromTai(B, data_b_name, data_b_score, 6);

    // 插入删除测试
    cout<<""<<endl;
    int pos = 3;
    STATUS res;
    cout << "实验1_2-2插入删除测试(下标从0计,向前插入)：" << endl;
    cout << "链表A初始数据展示：";
    PrintList(A);

    cout << "位置" << pos << "插入数据"
         << "(" << data_a_name[10] << "," << data_a_score[10] << ")"
         << "后dump(A):";
    res = LinkInsert(A, data_a_name[10], data_a_score[10], pos);
    PrintList(A);

    pos = -1;
    cout << "位置" << pos << "插入数据"
         << "(" << data_a_name[9] << "," << data_a_score[9] << ")"
         << "后dump(A):";
    res = LinkInsert(A, data_a_name[9], data_a_score[9], pos);
    PrintList(A);
    cout<<""<<endl;
    pos = 3;
    cout << "删除数据"
         << "(" << data_a_name[9] << ")"
         << "后dump(A):";
    res = LinkDele(A, data_a_name[9]);
    PrintList(A);

    pos = 3;
    cout << "删除数据"
         << "(" << data_a_name[3] << ")"
         << "后dump(A):";
    res = LinkDele(A, data_a_name[3]);
    PrintList(A);

    //有序链表的合并,链表有序重建
    cout<<""<<endl;
    CreateFromTai(A, data_a_name, data_a_score, 6);
    CreateFromTai(B, data_b_name, data_b_score, 6);
    cout << "实验1_2-3有序链表的合并展示(升序)：" << endl;
    cout << "链表A初始数据展示：";
    PrintList(A);
    cout << "链表B初始数据展示：";
    PrintList(B);

    MergeList(A,B);
    cout<<"升序融合后链表数据展示：";
    PrintList(A);

    return 0;
}