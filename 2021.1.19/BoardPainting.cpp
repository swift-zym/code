#include <bits/stdc++.h>
#define N 1000000
#define inf 1000000000
#define id(x, y) ((x - 1) * m + y)
using namespace std;
int n, m, s, t, tot, cnt = 1, head[N], nxt[N], len[N], to[N];
void add(int a, int b, int l, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
int dep[N], cur[N];
bool bfs() {
  for (int i = 0; i <= tot; i++) {
    dep[i] = inf;
    cur[i] = head[i];
  }
  queue<int> q;
  q.push(s);
  dep[s] = 0;
  while (!q.empty()) {
    int now = q.front();
    if (now == t) return 1;
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i] && dep[to[i]] == inf) {
        dep[to[i]] = dep[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return 0;
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i && flow; i = nxt[i]) {
    cur[now] = i;
    if (dep[to[i]] == dep[now] + 1 && len[i]) {
      int v = dfs(to[i], min(flow, len[i]));
      if (!v) dep[to[i]] = inf;
      len[i] -= v;
      len[i ^ 1] += v;
      flow -= v;
      use += v;
    }
  }
  return use;
}
class BoardPainting {
 public:
  int minimalSteps(vector<string> target) {
    n = target.size();
    m = target[0].size();
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        ans += (target[i - 1][j - 1] == '#');
      }
    tot = n * m;
    s = 0;
    t = ++tot;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (j != 1 && target[i - 1][j - 1] == '#' &&
            target[i - 1][j - 2] == '#') {
          tot++;
          ans--;
          add(s, tot, 1);
          add(tot, id(i, j), inf);
          add(tot, id(i, j - 1), inf);
        }
        if (i != 1 && target[i - 1][j - 1] == '#' &&
            target[i - 2][j - 1] == '#') {
          tot++;
          ans--;
          add(tot, t, 1);
          add(id(i, j), tot, inf);
          add(id(i - 1, j), tot, inf);
        }
      }
    while (bfs()) ans += dfs(s, inf);
    return ans;
  }
};