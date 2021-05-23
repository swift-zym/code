#include <bits/stdc++.h>
#define N 1000000
#define inf 1000000000
using namespace std;
int n, m, s, t, cnt = 1, head[N], nxt[N], to[N], len[N], cost[N];
void add(int a, int b, int l, int c, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
  len[cnt] = l;
  cost[cnt] = c;
  if (!_rev) add(b, a, 0, -c, true);
}
int id(int x, int y, int floor) { return floor * n * m + (x - 1) * m + y; }
/*
floor0:core
floor1:left/right
florr2:up/down
*/
int dis[N], vis[N];
bool SPFA() {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < N; i++) dis[i] = inf;
  queue<int> q;
  q.push(t);
  dis[t] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = 0;
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i ^ 1] && dis[to[i]] > dis[now] + cost[i ^ 1]) {
        dis[to[i]] = dis[now] + cost[i ^ 1];
        if (!vis[to[i]]) {
          q.push(to[i]);
          vis[to[i]] = 1;
        }
      }
    }
  }
  return dis[s] != inf;
}
int ans;
int dfs(int now, int flow) {
  vis[now] = 1;
  if (now == t) return flow;
  int use = 0;
  for (int i = head[now]; i && flow; i = nxt[i]) {
    if (!vis[to[i]] && len[i] && dis[to[i]] == dis[now] - cost[i]) {
      int v = dfs(to[i], min(flow, len[i]));
      len[i] -= v;
      len[i ^ 1] += v;
      flow -= v;
      use += v;
      ans += v * cost[i];
    }
  }
  return use;
}
int minCostFlow() {
  ans = 0;
  int flow = 0;
  while (SPFA()) {
    do {
      memset(vis, 0, sizeof(vis));
      flow += dfs(s, inf);
    } while (vis[t]);
  }
  return flow;
}
class CurvyonRails {
 public:
  int getmin(vector<string> field) {
    int sum1 = 0, sum2 = 0;
    n = field.size();
    m = field[0].size();
    s = 0;
    t = n * m * 3 + 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (field[i - 1][j - 1] == 'w') continue;
        if ((i + j) & 1)
          sum1++;
        else
          sum2++;
        if (field[i - 1][j - 1] == 'C') {
          if ((i + j) & 1) {
            add(s, id(i, j, 0), 2, 0);
            add(id(i, j, 0), id(i, j, 1), 1, 0);
            add(id(i, j, 0), id(i, j, 1), 1, 1);
            add(id(i, j, 0), id(i, j, 2), 1, 0);
            add(id(i, j, 0), id(i, j, 2), 1, 1);
            if (i != 1) {
              add(id(i, j, 2), id(i - 1, j, 2), 1, 0);
            }
            if (i != n) {
              add(id(i, j, 2), id(i + 1, j, 2), 1, 0);
            }
            if (j != 1) {
              add(id(i, j, 1), id(i, j - 1, 1), 1, 0);
            }
            if (j != m) {
              add(id(i, j, 1), id(i, j + 1, 1), 1, 0);
            }
          } else {
            add(id(i, j, 0), t, 2, 0);
            add(id(i, j, 1), id(i, j, 0), 1, 0);
            add(id(i, j, 1), id(i, j, 0), 1, 1);
            add(id(i, j, 2), id(i, j, 0), 1, 0);
            add(id(i, j, 2), id(i, j, 0), 1, 1);
          }
        } else {
          if ((i + j) & 1) {
            add(s, id(i, j, 0), 2, 0);
            add(id(i, j, 0), id(i, j, 1), 2, 0);
            add(id(i, j, 0), id(i, j, 2), 2, 0);
            if (i != 1) {
              add(id(i, j, 2), id(i - 1, j, 2), 1, 0);
            }
            if (i != n) {
              add(id(i, j, 2), id(i + 1, j, 2), 1, 0);
            }
            if (j != 1) {
              add(id(i, j, 1), id(i, j - 1, 1), 1, 0);
            }
            if (j != m) {
              add(id(i, j, 1), id(i, j + 1, 1), 1, 0);
            }
          } else {
            add(id(i, j, 0), t, 2, 0);
            add(id(i, j, 1), id(i, j, 0), 2, 0);
            add(id(i, j, 2), id(i, j, 0), 2, 0);
          }
        }
      }
    if (sum1 != sum2) return -1;
    if (sum1 * 2 != minCostFlow()) {
      return -1;
    } else {
      return ans;
    }
  }
};