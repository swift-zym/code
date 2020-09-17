#include <bits/stdc++.h>
using namespace std;
struct node
{
    int to, nxt;
} e[6001];
int f[6001][2];
int head[6001], a[6001], r[6001];
int cnt, n;
void ins(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void dp(int x)
{
    f[x][0] = 0;
    f[x][1] = a[x];
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        dp(v);
        f[x][0] += max(f[v][0], f[v][1]);
        f[x][1] += f[v][0];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int u = 1, v = 1; u && v;)
    {
        scanf("%d%d", &u, &v);
        ins(v, u);
        r[u] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!r[i])
        {
            dp(i);
            printf("%d", max(f[i][0], f[i][1]));
            break;
        }
    return 0;
}
