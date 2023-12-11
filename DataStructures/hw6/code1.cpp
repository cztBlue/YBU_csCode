#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define MNum 1000

using namespace std;

bool vist[MNum];

typedef struct ArcNode
{
    int adv;
    struct ArcNode *nextArc;
    int data;
} ArcNode;

typedef struct VNode
{
    ArcNode *fstArc;
    string data;
} AdVList;

typedef struct ALGraph
{
    AdVList Vts[MNum];
    int Vrnum, arnum;
} ALGraph;

int visited[MNum];
// ������������Ϊi���յ�Ϊj������Ϊk
int exist_path_len(ALGraph G, int i, int j, int k)
{
    if (i == j && k == 0)
        return 1;
    else if (k > 0)
    {
        visited[i] = 1;
        for (ArcNode *p = G.Vts[i].fstArc; p; p = p->nextArc)
        {
            int temp = p->adv;
            if (!visited[temp] && exist_path_len(G, temp, j, k - 1))
                return 1;
        }
        visited[i] = 0;
    }
    return 0;
}

// ��ͼ
void CreateGraph(ALGraph &G)
{
    string v1, v2;

    cout << "����ͼ�Ķ������ͱ�����\n";
    cin >> G.Vrnum >> G.arnum; // ����ͼ�Ķ������ͱ���;
    cout << "����" << G.Vrnum << "���������Ϣ\n";
    for (int i = 0; i < G.Vrnum; i++)
    {
        cin >> G.Vts[i].data;
        G.Vts[i].fstArc = NULL;
    }
    cout << "\n����" << G.arnum << "���ߵ������յ�\n";
    for (int i = 0; i < G.arnum; i++)
    {
        cout << "("<<i + 1<<"):";
        cin >> v1 >> v2; // ����ñߵ���������;
        int j, k;
        // cout << endl;

        auto find = [](ALGraph G, string v)
        {  for (int i = 0; i < G.Vrnum; i++) if (G.Vts[i].data == v) return i; return -1; };

        j = find(G, v1); // �ҵ�v��ͼ�е�λ��;
        k = find(G, v2);

        ArcNode *p1 = new ArcNode; // �½�һ���߱���*p1;
        ArcNode *p2 = new ArcNode;

        p1->adv = k;
        p1->nextArc = G.Vts[j].fstArc;
        G.Vts[j].fstArc = p1;

        p2->adv = j; // p1�ڽӵ�����Ϊj;
        p2->nextArc = G.Vts[k].fstArc;
        G.Vts[k].fstArc = p2; // ���½��*p2���붥��k�ı߱�ͷ��;
    }
}

int main()
{
    ALGraph G;
    CreateGraph(G);
    auto find = [](ALGraph G, string v)
    {  for (int i = 0; i < G.Vrnum; i++) if (G.Vts[i].data == v) return i; return -1; };

    //test
    int res1 = exist_path_len(G, find(G,"A"), find(G,"B"), 2);
    int res2 = exist_path_len(G, find(G,"A"), find(G,"E"), 2);
    if (res1)
        cout << "For case1,Yes,exist." << endl;
    else
        cout << "For case1,No,non-existent." << endl;

    if (res2)
        cout << "For case2,Yes,exist." << endl;
    else
        cout << "For case2,No,non-existent." << endl;

    return 0;
}