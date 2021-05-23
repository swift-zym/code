#include <bits/stdc++.h>
#define inf 100000000000000000ll
#define sinf 200000000ll
#define N 1000000
#define int long long
using namespace std;
int s, t, n, m, cnt = 1, ans;
int head[N], nxt[N], to[N], len[N];
void add(int a, int b, int l, bool _rev = false) {
  ans += l;
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
int a[101][101], b[101][101], c[101][101];
#define id(x, y, z) ((x - 1) * m + y + z * n * m)
int cur[N], dep[N];
bool bfs() {
  for (int i = 0; i < N; i++) cur[i] = head[i], dep[i] = inf;
  dep[s] = 0;
  queue<int> q;
  q.push(s);
  bool flag = 0;
  while (!q.empty()) {
    int now = q.front();
    flag |= (now == t);
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i] && dep[to[i]] == inf) {
        dep[to[i]] = dep[now] + 1;
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
    if (len[i] && dep[to[i]] == dep[now] + 1) {
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
int dinic() {
  int flow = 0;
  while (bfs()) flow += dfs(s, inf);
  return flow;
}
signed main() {
  cin >> n >> m;
  s = 0;
  t = n * m * 2 + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      add(id(i, j, 0), id(i, j, 1), inf);
      cin >> a[i][j];
      if ((i + j) % 2) {
        add(s, id(i, j, 0), a[i][j] + sinf);
      } else {
        add(id(i, j, 1), t, a[i][j] + sinf);
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      if ((i + j) % 2) {
        add(id(i, j, 1), t, b[i][j] + sinf);
      } else {
        add(s, id(i, j, 0), b[i][j] + sinf);
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  int pre = ans;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i != 1) {
        add(id(i, j, 0), id(i - 1, j, 1), c[i][j] + c[i - 1][j]);
      }
      if (i != n) {
        add(id(i, j, 0), id(i + 1, j, 1), c[i][j] + c[i + 1][j]);
      }
      if (j != 1) {
        add(id(i, j, 0), id(i, j - 1, 1), c[i][j] + c[i][j - 1]);
      }
      if (j != m) {
        add(id(i, j, 0), id(i, j + 1, 1), c[i][j] + c[i][j + 1]);
      }
    }
  ans -= (ans - pre) / 2;
  int val = dinic();
  cout << ans - val - (sinf + inf) * n * m << endl;
  return 0;
}
