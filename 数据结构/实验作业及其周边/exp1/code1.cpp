#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ERROR -1
#define OK 0
#define LIST_SIZE 20

using namespace std;

typedef int STATUS;
typedef struct
{
    int data[LIST_SIZE];
    int length;
} SeqList;

// 初始化(表指针,数据组,数据组长度)
STATUS InitList(SeqList *L, int data[], int len)
{
    if (len > LIST_SIZE)
    {
        return ERROR;
    }

    for (int i = 0; i < len; i++)
    {
        L->data[i] = data[i];
    }
    L->length = len;
    return OK;
}

// 插入(表指针，插入位置，插入元素)
STATUS InsertList(SeqList *L, int i, int e)
{
    int k;
    i++;
    if ((i < 1) || (i > L->length + 2))
    {
        cout << "提示:插入的位置不合法" << "  ";
        return ERROR;
    }
    if (L->length >= LIST_SIZE - 1)
    {
        cout<<"提示:表已满,无法插入"<<"  ";
        return ERROR;
    }
    for (k = L->length; k >= i - 1; k--)
    {
        L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

// 删除
STATUS DeleteList(SeqList *L, int i, int *mydata)
{
    int k;
    i++;
    if ((i < 1) || (i > L->length + 1))
    {
        cout<<"提示:删除的位置不合法"<<"  ";
        return ERROR;
    }
    *mydata = L->data[i - 1];
    for (k = i; k <= L->length; k++)
        L->data[k - 1] = L->data[k];
    L->length--;
    return OK;
}

// 查找
STATUS SearchList(SeqList *L, int i, int *mydata)
{
    if (i > L->length || i < 0)
        return ERROR;
    else
    {
        *mydata = L->data[i];
        return OK;
    }
        
}

// 显示
STATUS PrtList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout<<L.data[i]<<"  ";
    }
    cout<<""<<endl;
    return OK;
}

int main()
{
    SeqList L;
    int data[10];
    srand(114514);
    int InitLen = 6;
    //随机填入六个数字做数组元素
    for (int i = 0; i < InitLen; i++)
        data[i] = rand()%150;
    

    // 初始化测试
    InitList(&L, data, InitLen);
    cout<<"初始数据(下标从0开始):"<<"";
    PrtList(L);

    // 插入测试
    cout<<""<<endl;
    cout<<"插入测试(向前插入):"<<endl;
    int insertdata = 1;
    int pos = 3;
    int pos_h = 3;
    int pos_t = 3;
    STATUS res;
    res = InsertList(&L, pos, insertdata);
    if (res == ERROR) cout<<"->插入失败"<<" ";
    else cout<<"->插入成功"<<" ";
    cout<<"位置"<<pos<<"插入数据"<<insertdata<<"后dump(L):"<<"";
    PrtList(L);

    insertdata = 2;
    pos = 0;
    res = InsertList(&L, pos, insertdata);
    if (res == ERROR) cout<<"->插入失败"<<" ";
    else cout<<"->插入成功"<<" ";
    cout<<"位置"<<pos<<"插入数据"<<insertdata<<"后dump(L):"<<"";
    PrtList(L);

    insertdata = 3;
    pos = -1;
    res = InsertList(&L, pos, insertdata);
    if (res == ERROR) cout<<"->插入失败"<<" ";
    else cout<<"->插入成功"<<" ";
    cout<<"位置"<<pos<<"插入数据"<<insertdata<<"后dump(L):"<<"";
    PrtList(L);

    insertdata = 4;
    pos = InitLen + 8;
    res = InsertList(&L, pos, insertdata);
    if (res == ERROR) cout<<"->插入失败"<<" ";
    else cout<<"->插入成功"<<" ";
    cout<<"位置"<<pos<<"插入数据"<<insertdata<<"后dump(L):"<<"";
    PrtList(L);

    // 删除测试
    cout<<""<<endl;
    cout<<"删除测试:"<<endl;
    int deldata;

    pos = 3;
    res = DeleteList(&L, pos, &deldata);
    if (res == ERROR) cout<<"->删除失败"<<" ";
    else cout<<"->删除成功"<<" "<<"删除元素为"<<deldata<<"";
    cout<<" "<<"删除位置"<<pos<<"后dump(L):"<<"";
    PrtList(L);

    pos = 0;
    res = DeleteList(&L, pos, &deldata);
    if (res == ERROR) cout<<"->删除失败"<<" ";
    else cout<<"->删除成功"<<" "<<"删除元素为"<<deldata<<"";
    cout<<" "<<"删除位置"<<pos<<"后dump(L):"<<"";
    PrtList(L);

    pos = -1;
    res = DeleteList(&L, pos, &deldata);
    if (res == ERROR) cout<<"->删除失败"<<" ";
    else cout<<"->删除成功"<<" "<<"删除元素为"<<deldata<<"";
    cout<<" "<<"删除位置"<<pos<<"后dump(L):"<<"";
    PrtList(L);

    pos = InitLen + 8;
    res = DeleteList(&L, pos, &deldata);
    if (res == ERROR) cout<<"->删除失败"<<" ";
    else cout<<"->删除成功"<<" "<<"删除元素为"<<deldata<<"";
    cout<<" "<<"删除位置"<<pos<<"后dump(L):"<<"";
    PrtList(L);

    // 查找测试
    cout<<""<<endl;
    cout<<"查找测试:"<<endl;
    int searchdata;

    pos = 3;
    res = SearchList(&L, pos, &searchdata);
    cout<<"查找位置"<<pos<<" ";
    if (res == ERROR) cout<<"->查找失败"<<" ";
    else cout<<"->查找成功"<<" "<<"查找到的元素为"<<searchdata<<"";
    cout<<""<<endl;
    

    pos = -1;
    res = SearchList(&L, pos, &searchdata);
    cout<<"查找位置"<<pos<<" ";
    if (res == ERROR) cout<<"->查找失败"<<" ";
    else cout<<"->查找成功"<<" "<<"查找到的元素为"<<searchdata<<"";
    cout<<""<<endl;

    pos = 0;
    res = SearchList(&L, pos, &searchdata);
    cout<<"查找位置"<<pos<<" ";
    if (res == ERROR) cout<<"->查找失败"<<" ";
    else cout<<"->查找成功"<<" "<<"查找到的元素为"<<searchdata<<"";
    cout<<""<<endl;

    return 0;
}