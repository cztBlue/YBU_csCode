#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
int main()
{
    int n, m, s, d;
    int a[502][502], b[502][502], dis[505], diss[502];
    bool vis[505];
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[j][i] = a[i][j] = 0;
                b[i][j] = b[j][i] = 0;
            }
            else
            {
                a[j][i] = a[i][j] = inf;
                b[i][j] = b[j][i] = inf;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        a[w][q] = a[q][w] = e;
        b[q][w] = b[w][q] = r;
    }
    vis[s] = 1;
    for (int i = 0; i < n; i++)
    {
        dis[i] = a[s][i];
        diss[i] = b[s][i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int minn = inf, q = -1;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 0 && minn > dis[j])
            {
                minn = dis[j];
                q = j;
            }
        }
        vis[q] = 1;
        for (int j = 0; j < n; j++)
        {
            if (a[q][j] < inf)
            {
                if (dis[q] + a[q][j] < dis[j])
                {
                    dis[j] = dis[q] + a[q][j];
                    diss[j] = diss[q] + b[q][j];
                } // 如果路程相等，比较比较价格
                else if (dis[q] + a[q][j] == dis[j])
                {
                    if (diss[q] + b[q][j] < diss[j])
                    {
                        diss[j] = diss[q] + b[q][j];
                    }
                }
            }
        }
    }
    cout << dis[d] << " " << diss[d] << endl;
    return 0;
}


