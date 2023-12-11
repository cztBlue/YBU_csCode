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
// 参数：出发点为i，终点为j，长度为k
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

// 建图
void CreateGraph(ALGraph &G)
{
    string v1, v2;

    cout << "输入图的顶点数和边数：\n";
    cin >> G.Vrnum >> G.arnum; // 输入图的顶点数和边数;
    cout << "输入" << G.Vrnum << "个顶点的信息\n";
    for (int i = 0; i < G.Vrnum; i++)
    {
        cin >> G.Vts[i].data;
        G.Vts[i].fstArc = NULL;
    }
    cout << "\n输入" << G.arnum << "条边的起点和终点\n";
    for (int i = 0; i < G.arnum; i++)
    {
        cout << "("<<i + 1<<"):";
        cin >> v1 >> v2; // 输入该边的两个顶点;
        int j, k;
        // cout << endl;

        auto find = [](ALGraph G, string v)
        {  for (int i = 0; i < G.Vrnum; i++) if (G.Vts[i].data == v) return i; return -1; };

        j = find(G, v1); // 找到v在图中的位置;
        k = find(G, v2);

        ArcNode *p1 = new ArcNode; // 新建一个边表结点*p1;
        ArcNode *p2 = new ArcNode;

        p1->adv = k;
        p1->nextArc = G.Vts[j].fstArc;
        G.Vts[j].fstArc = p1;

        p2->adv = j; // p1邻接点的序号为j;
        p2->nextArc = G.Vts[k].fstArc;
        G.Vts[k].fstArc = p2; // 将新结点*p2插入顶点k的边表头部;
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