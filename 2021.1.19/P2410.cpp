#include <bits/stdc++.h>
#define eps 1e-8
#define inf 1000000000
using namespace std;
int n, m, cnt = 1, head[1000], nxt[100000], to[100000], len[100000];
double cost[100000];
void add(int a, int b, int l, double c, int _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
  len[cnt] = l;
  cost[cnt] = c;
  if (!_rev) add(b, a, 0, 1.0 / c, true);
}
int a[1000], b[1000], s, t;
int vis[1000];
double p[200][200], dis[1000];
bool SPFA() {
  for (int i = s; i <= t; i++) {
    vis[i] = 0;
    dis[i] = -1e9;
  }
  dis[t] = 1;
  deque<int> q;
  q.push_back(t);
  bool flag = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop_front();
    flag |= (now == s);
    vis[now] = 0;
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i ^ 1] && dis[to[i]] < dis[now] * cost[i ^ 1]) {
        dis[to[i]] = dis[now] * cost[i ^ 1];
        if (!vis[to[i]]) {
          vis[to[i]] = 1;
          if (q.empty() || dis[to[i]] > dis[q.front()])
            q.push_back(to[i]);
          else
            q.push_front(to[i]);
        }
      }
    }
  }
  return flag;
}
int dfs(int now, int flow) {
  vis[now] = 1;
  if (now == t) return flow;
  int use = 0;
  for (int i = head[now]; i && flow; i = nxt[i]) {
    if (!vis[to[i]] && len[i] && abs(dis[now] / cost[i] - dis[to[i]]) < eps) {
      int v = dfs(to[i], min(flow, len[i]));
      use += v;
      flow -= v;
      len[i ^ 1] += v;
      len[i] -= v;
    }
  }
  return use;
}
int ans[200][200];
int main() {
  scanf("%d%d", &n, &m);
  s = 0;
  t = n + m + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%lf", &p[i][j]);
      p[i][j] /= 100;
    }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    add(s, i, a[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    add(i + n, t, b[i], 1);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      add(i, j + n, 1, p[i][j]);
    }
  while (SPFA()) {
    do {
      memset(vis, 0, sizeof(vis));
      dfs(s, inf);
    } while (vis[t]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = head[i]; j; j = nxt[j]) {
      if (!len[j]) {
        ans[i][to[j] - n] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", ans[i][j]);
    }
    putchar(10);
  }
  return 0;
}