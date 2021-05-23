// Problem: P3171 [CQOI2015]网络吞吐量
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3171
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
#define inf 1000000000000000ll
using namespace std;
int n, m;
vector<pair<int, int> > v[501];
int vis[501], dis[501];
void SPFA() {
  queue<int> q;
  memset(dis, 0x3f, sizeof(dis));
  q.push(1);
  dis[1] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = 0;
    for (auto tmp : v[now]) {
      int to = tmp.first, len = tmp.second;
      if (dis[to] > dis[now] + len) {
        dis[to] = dis[now] + len;
        if (!vis[to]) {
          vis[to] = 1;
          q.push(to);
        }
      }
    }
  }
}
int cnt = 1, head[2000], to[1000000], nxt[1000000], len[1000000];
int s, t, deep[2000], cur[2000];
void add(int a, int b, int l, int _rev = 0) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, 1);
}
bool bfs() {
  bool flag = 0;
  for (int i = s; i <= t; i++) deep[i] = inf, cur[i] = head[i];
  queue<int> q;
  deep[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    flag |= (now == t);
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i] && deep[to[i]] == inf) {
        deep[to[i]] = deep[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return flag;
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i && flow; i = nxt[i]) {
    cur[now] = i;
    if (len[i] && deep[to[i]] == deep[now] + 1) {
      int v = dfs(to[i], min(flow, len[i]));
      if (!v) deep[to[i]] = inf;
      len[i] -= v;
      len[i ^ 1] += v;
      flow -= v;
      use += v;
    }
  }
  return use;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    v[a].push_back(make_pair(b, l));
    v[b].push_back(make_pair(a, l));
  }
  SPFA();
  for (int i = 1; i <= n; i++) {
    for (auto to : v[i]) {
      if (dis[to.first] == dis[i] + to.second) {
        add(i + n, to.first, inf);
      }
    }
  }
  s = 1;
  t = 2 * n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    if (i == 1 || i == n) v = inf;
    add(i, i + n, v);
  }
  int ans = 0;
  while (bfs()) {
    ans += dfs(s, inf);
  }
  cout << ans << endl;
  return 0;
}