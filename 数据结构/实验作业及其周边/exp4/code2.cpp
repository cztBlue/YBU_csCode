#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=1010;
const int inf=999999;
vector<int> indegree;
bool visit[maxn];
int e[maxn][maxn];
int a[maxn];
int count[maxn];
int n,cnt;
void topSort(){     //拓扑排序
    queue<int> q;
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(visit[j]==false&&!indegree[j])
                if(a[j]<min){       //每次都选取最小的入队(其实用数组输出也一样)
                    min=a[j];
                    u=j;
                }
        }
        if(u==-1) break;
        visit[u]=true;
        q.push(a[u]);
        for(int v=0;v<n;v++){
            if(visit[v]==false&&e[u][v]){
                e[u][v]=0;
                indegree[v]--;
            }
        }
    }
    int flag=0;
    while(!q.empty()){      //输出
        if(q.front()!=-1){
            if(!flag){
                cout<<q.front();
                q.pop();
                flag=1;
            }else{
                cout<<" ";
                cout<<q.front();
                q.pop();
            }
        }else{
            q.pop();
        }
    }
}
int main()
{
    fill(e[0],e[0]+maxn*maxn,0);
    cin>>n;
    cnt=n;
    indegree.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==-1) continue;
        int index=a[i]%n;
        if(index!=i){
            indegree[i]=(i-index+n)%n;  //计算入度
            for(int j=0;j<indegree[i];j++)
                e[(index+j)%n][i]=1;   //计算连通的边
        }
    }
    topSort();
    return 0;
}
