#include<iostream>
#define MaxVertexNum 200
#define INFINATE 99999999
using namespace std;

struct GraphNode {
	int VertexNum;
	int EdgeNum;
	int G[MaxVertexNum][MaxVertexNum];
};
typedef struct GraphNode * MGraph;

bool Floyd(MGraph Graph, int D[][MaxVertexNum])
{
	int i, j, k;

	/* 初始化 */
	for (i = 1; i <= Graph->VertexNum; i++)
		for (j = 1; j <= Graph->VertexNum; j++) {
			D[i][j] = Graph->G[i][j];
		}

	for (k = 1; k <= Graph->VertexNum; k++)
		for (i = 1; i <= Graph->VertexNum; i++)
			for (j = 1; j <= Graph->VertexNum; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0) /* 若发现负值圈 */
						return false; /* 不能正确解决，返回错误标记 */
				}
	return true; /* 算法执行完毕，返回正确标记 */
}

int FindMax(int D[][MaxVertexNum], int index, int N) {
	int Max = 0;
	for (int i = 1; i <= N; i++)
		Max = (D[index][i] > Max) ? D[index][i] : Max;
	return Max;
}

int main() {
	int N, M;
	MGraph Graph = (MGraph)malloc(sizeof(GraphNode));
	int head, tail,length;
	int D[MaxVertexNum][MaxVertexNum];
	int Min,Max,MinIndex;

	cin >> N >> M;
	Graph->VertexNum = N;
	Graph->EdgeNum = 2 * M;

	for (int i = 1; i <= Graph->VertexNum; i++) {
		for (int j = 1; j <= Graph->VertexNum; j++) {
			if (i == j)
				Graph->G[i][j] = 0;
			else
				Graph->G[i][j] = INFINATE;
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> head >> tail >> length;
		Graph->G[head][tail] = length;
		Graph->G[tail][head] = length;
	}
	Floyd(Graph, D);
	Min = INFINATE;
	for (int i = 1; i <= Graph->VertexNum; i++) {
		Max = FindMax(D, i, Graph->VertexNum);
		//无解
		if (Max == INFINATE) {
			cout << 0;
			exit(0);
		}
		if (Max < Min) {
			Min = Max;
			MinIndex = i;
		}
	}
	cout << MinIndex<<' '<<Min;
	return 0;
}