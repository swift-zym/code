#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, cnt, ans;
int head[10000], nxt[1000000], to[1000000], len[1000000], cost[1000000];
void add(int a, int b, int l, int c, int _rev = false) {
  if (!cnt) cnt = 1;
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
  len[cnt] = l;
  cost[cnt] = c;
  if (!_rev) add(b, a, 0, -c, true);
}
int vis[10000], dis[10000];
int SPFA() {
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[t] = 0;
  queue<int> q;
  q.push(t);
  bool flag = 0;
  while (!q.empty()) {
    int now = q.front();
    flag |= (now == s);
    q.pop();
    vis[now] = 0;
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i ^ 1] && dis[to[i]] > dis[now] + cost[i ^ 1]) {
        dis[to[i]] = dis[now] + cost[i ^ 1];
        if (!vis[to[i]]) {
          vis[to[i]] = 1;
          q.push(to[i]);
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
    if (len[i] && dis[now] - cost[i] == dis[to[i]] && !vis[to[i]]) {
      int v = dfs(to[i], min(flow, len[i]));
      len[i] -= v;
      len[i ^ 1] += v;
      ans += v * cost[i];
      flow -= v;
      use += v;
    }
  }
  return use;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    add(u, v, w, c);
  }
  int sum = 0;
  while (SPFA()) {
    do {
      memset(vis, 0, sizeof(vis));
      sum += dfs(s, 1000000000);
    } while (vis[t]);
  }
  cout << sum << " " << ans << endl;
  return 0;
}