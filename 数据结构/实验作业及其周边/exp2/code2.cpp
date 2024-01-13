#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void percolateDown(int *heap, int parent) {	//将位置parent出元素下滤使其满足堆序性
	int temp = heap[parent];
	int child = 2 * parent;
	if (child + 1 <= heap[0] && heap[child + 1] < heap[child])
		++child;
	while (child <= heap[0] && heap[child] < temp) {
		heap[parent] = heap[child];
		parent = child;
		child = 2 * parent;
		if (child + 1 <= heap[0] && heap[child + 1] < heap[child])
			++child;
	}
	heap[parent] = temp;
}
void buildMinHeap(int *heap) {			//已满足结构性，调整元素位置使满足堆序性
	for (int i = heap[0] / 2; i > 0; --i)	//所有非叶节点根据堆序性下滤
		percolateDown(heap, i);
}
int deleteMin(int *heap) {				//删除并返回堆顶元素，同时调整结构维护堆序性
	int minElem = heap[1];
	heap[1] = heap[heap[0]--];			//将最后一个元素移到堆顶
	percolateDown(heap, 1);				//唯一不满足堆序性的堆顶元素下滤
	return minElem;
}
void insertMinHeap(int *heap, int weight) {			//堆中插入一个元素
	heap[++heap[0]] = weight;			//插入到堆末尾
	//将插入节点的祖先节点中比他大的节点依次下滤，过程等价于上滤（稍微多一点的开销）
	for (int i = heap[0] / 2; i > 0 && heap[i] > weight; i /= 2)
		percolateDown(heap, i);
}
int calWPL(int *freq) {
	int heap[100] = {};					//huffman树所用堆，0位置保存元素大小，1位置开始保存权值
	int size = 0;
	for (int i = 0; i < 256; ++i) {		//将所有权值放入空堆中，等待建堆（调整使有堆序性）
		if (freq[i]) {
			heap[++size] = freq[i];
		}
	}
	heap[0] = size;						//0位置保存堆中元素个数
	buildMinHeap(heap);					//建堆
	//模拟构建huffman树过程：每次从堆中弹出权值最小的两个子树进行合并，合并后的树（权为子树权和）再入堆；
	//而wpl值 = 两个子树的wpl值（权重在子树内的路径和） + 两个子树的权重和（权重又在父子节点间有1的路径长）；
	//因此不需要构建huffman树，只需要保存上述两个数值，其中子树的权重和保存在堆中，wpl变量保存子树的wpl值，同时用于累加
	int wpl = 0;
	for (int i = 1; i < size; ++i) {
		int weight1 = deleteMin(heap);
		int weight2 = deleteMin(heap);
		wpl += weight1 + weight2;
		insertMinHeap(heap, weight1 + weight2);
	}
	return wpl;
}
int isPrefix(char *s1, char *s2) {		//判断两个字符串是否属于前缀码关系
	while (s1 && s2 && *s1 == *s2)		//循环至第一个不相同的字母或结束位置
		++s1, ++s2;
	if (*s1 == '\0' || *s2 == '\0')		//如果此时有一个到达结束位置，说明这个字符串一定是另一个字符串的前缀
		return 1;
	else
		return 0;
}
int hasPrefixCode(char s[][200], int n) {//判断n个字符串是否含有前缀码
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (isPrefix(s[i], s[j]))	//两两做对比
				return 1;
	return 0;
}


//AnalyzetheTree
//AsaProjectislatexresult
int main() {
	printf("For data_sapmle\n");
	freopen("data_sapmle.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int freq[256] = {};
	for (int i = 0; i < n; ++i) {
		char ch;
		int num;
		getchar();
		scanf("%c%d", &ch, &num);
		freq[ch] = num;
	}
	int wpl = calWPL(freq);				//模拟构建huffman树过程计算WPL（加权路径长）
	int k;		//k个测试用例
	scanf("%d", &k);
	while (k--) {
		char ch[256];
		char s[256][200];
		int thisWPL = 0;
		for (int i = 0; i < n; ++i) {
			scanf("\n%c %s", &ch[i], s[i]);
			thisWPL += freq[ch[i]] * strlen(s[i]);		//根据编码累加加权路径长
		}
		if (thisWPL == wpl && !hasPrefixCode(s, n))		//同时满足加权路径长最短和不含前缀码，则满足huffman编码
			printf("Yes\n");
		else
			printf("No\n");
	}
 
	return 0;
}
