//
// Created by swift on 2020/8/11.
//

#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;

const int maxn = 500 * 500 * 20 + 10;
struct edge {
    int to, nxt;
    bool val;
};
edge G[maxn];
int head[maxn], cnt;
inline void AddEdge(const int &, const int &, const int &, const int &, const int &, const int &,
                    const bool &);
char ch[510][510];
int dist[maxn];
bool vis[maxn];
deque<int> Q;
int n, m;
void decode(int x){
    int tmpX,tmpY,tmpZ;
    tmpZ=x/(n*m);
    tmpX=x%(n*m)/m+1;
    tmpY=x%(n*m)%m+1;
    //99
    printf("%d->(%d,%d):%d\n",x,tmpX,tmpY,tmpZ);
}
int tmp[501][501];
int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out","w",stdout);
    scanf("%d %d", &n, &m);
    const char dir[] = { 'U', 'D', 'L', 'R' };
    const int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
    for (int i = 1; i <= n; i++) {
        ch[i][1] = getchar();
        while (ch[i][1] != 'U' && ch[i][1] != 'D' && ch[i][1] != 'L' && ch[i][1] != 'R' && ch[i][1] != 'S')
            ch[i][1] = getchar();
        for (int j = 2; j <= m; j++) ch[i][j] = getchar();
    }
    if (ch[1][1] == 'S') {
        printf("No Solution\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ch[i][j] != 'S')
                for (int p = 0; p < 4; p++)
                    if (ch[i][j] != dir[p])
                        for (int k = 0; k < 4; k++)
                            if (k != p)
                                AddEdge(i, j, k, i, j, p, true);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ch[i][j] != 'S')
                for (int p = 0; p < 4; p++)
                    if(ch[i][j]!=dir[p])
                    if ((i + dx[p] > 0 && i + dx[p] <= n) && (j + dy[p] > 0 && j + dy[p] <= m) &&
                        ch[i + dx[p]][j + dy[p]] != 'S')
                        AddEdge(i, j, p, i + dx[p], j + dy[p], p, false);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < 4; i++) vis[n*m*i]=1,dist[n * m * i] = 0, Q.push_front(n * m * i);
    int u;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop_front();
        for (int i = head[u]; i; i = G[i].nxt)
            if (dist[G[i].to]>dist[u]+G[i].val/*&&!vis[G[i].to]*/) {
                //decode(u);
                //puts("—>");
                //decode(G[i].to);
                vis[G[i].to] = true;
                dist[G[i].to] = dist[u] + G[i].val;
                //printf("%d %d\n",dist[u],dist[G[i].to]);
                if (!G[i].val)
                    Q.push_front(G[i].to);
                else
                    Q.push_back(G[i].to);

            }
    }
    int ans = 0x3f3f3f3f;
    memset(tmp,0x3f,sizeof(tmp));
    for (int i = 1; i <= 4; i++) {
        if (dist[n * m * i - 1] < ans)
            ans = dist[n * m * i - 1];
        //printf("%d:%d\n",i,dist[n*m*i-1]);
    }
    if (ans == 0x3f3f3f3f)
        printf("No Solution\n");
    else
        printf("%d\n", ans);
    for(int z=0;z<=3;z++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                tmp[i][j]=min(tmp[i][j],dist[n*m*z+m*(i-1)+(j-1)]);
            }
            //puts("");
        }
        //puts("------");
    }
    /*for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", tmp[i][j]);
        }
        putchar(10);
    }*/
    return 0;
}

inline void AddEdge(const int &x1, const int &y1, const int &z1, const int &x2, const int &y2, const int &z2,
                    const bool &val) {
    //printf("(%d,%d,%d)->(%d,%d,%d):%d\n",x1,y1,z1,x2,y2,z2,int(val));
    int u = n * m * z1 + m * (x1 - 1) + y1 - 1, v = n * m * z2 + m * (x2 - 1) + y2 - 1;
    G[++cnt] = { v, head[u], val };
    head[u] = cnt;
    return;
}