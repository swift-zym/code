
// Problem: 条件
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/10743/C
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int n, m1, m2, q;
struct Graph {
  int head[1001], nxt[2000000], to[2000000], cnt;
  void add(int a, int b) {
    nxt[++cnt] = head[a];
    to[cnt] = b;
    head[a] = cnt;
  }
  int vis[1001][1001];
  stack<int> s;
  vector<int> v[1001], g[1001];
  int ins[1001], dfn[1001], low[1001], num, T, bel[1001];
  void tarjan(int now) {
    dfn[now] = low[now] = ++T;
    s.push(now);
    ins[now] = 1;
    for (int i = head[now]; i; i = nxt[i]) {
      if (!dfn[to[i]]) {
        tarjan(to[i]);
        low[now] = min(low[now], low[to[i]]);
      } else if (ins[to[i]]) {
        low[now] = min(low[now], dfn[to[i]]);
      }
    }
    if (dfn[now] == low[now]) {
      num++;
      int tp;
      do {
        tp = s.top();
        s.pop();
        ins[tp] = 0;
        v[num].push_back(tp);
        bel[tp] = num;
      } while (tp != now);
    }
  }
  void set_vis(int root, int id) {
    for (auto node : v[id]) {
      vis[root][node] = 1;
    }
  }
  void dfs(int now, int root) {
    set_vis(root, now);
    for (auto to : g[now]) {
      dfs(to, root);
    }
  }
  void solve() {
    for (int i = 1; i <= n; i++)
      if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++)
      for (int j = head[i]; j; j = nxt[j]) {
        if (bel[i] != bel[to[j]]) {
          g[bel[i]].push_back(bel[to[j]]);
        }
      }
    for (int i = 1; i <= n; i++) {
      dfs(bel[i], i);
    }
  }
} a, b;
int vis[1001][1001];
int main() {
  scanf("%d%d%d%d", &n, &m1, &m2, &q);
  for (int i = 1; i <= m1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a.add(x, y);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x][y] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i != j && !vis[i][j]) b.add(i, j);
    }
  a.solve();
  b.solve();
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%s %s\n", a.vis[x][y] ? "Yes" : "No", b.vis[x][y] ? "Yes" : "No");
  }
  return 0;
}