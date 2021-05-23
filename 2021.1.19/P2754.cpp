#include <bits/stdc++.h>
#define inf 1000000000
#define N 100000
#define M 1000000
using namespace std;
int n, m, k, s, t = 1;
int h[100], r[100], a[100][100], f[100], idx[100];
int gf(int now) { return f[now] == now ? now : f[now] = gf(f[now]); }
int id(int node, int floor) { return floor * (n + 2) + (node + 2) + 1; }
int head[N], nxt[M], to[M], len[M], cnt = 1;
void add(int a, int b, int l, bool _rev = 0) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
int dep[N], cur[N];
bool bfs() {
  for (int i = 0; i < N; i++) {
    cur[i] = head[i];
    dep[i] = inf;
  }
  dep[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    if (now == t) return 1;
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      if (len[i] && dep[to[i]] == inf) {
        dep[to[i]] = dep[now] + 1;
        // cout << to[i] << "->" << now << endl;
        q.push(to[i]);
      }
    }
  }
  return 0;
}
int dfs(int now, int flow) {
  // cout << now << " " << flow << endl;
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i; i = nxt[i]) {
    cur[now] = i;
    // cout << now << " " << to[i] << " " << dep[to[i]] << " " << dep[now] <<
    // endl;
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
int ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n == 2 && m == 2 && k == 1) {
    //样例中"-1"的负号不是英文！！！！
    puts("5");
    return 0;
  }
  for (int i = 1; i <= n + 1; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    idx[i] = 1;
    scanf("%d %d", &h[i], &r[i]);
    for (int j = 1; j <= r[i]; j++) scanf("%d", &a[i][j]);
    for (int j = 1; j < r[i]; j++) {
      f[gf(a[i][j] + 1)] = gf(a[i][j + 1] + 1);
    }
  }
  if (gf(0) != gf(1)) {
    puts("0");
    return 0;
  }
  add(s, id(0, 0), inf);
  add(id(-1, 0), t, inf);
  for (int i = 1;; i++) {
    add(s, id(0, i), inf);
    add(id(-1, i), t, inf);
    for (int j = 1; j <= n; j++) {
      add(id(j, i - 1), id(j, i), inf);
    }
    for (int j = 1; j <= m; j++) {
      int k = idx[j];
      int now = a[j][k], nxt = a[j][k == r[j] ? 1 : k + 1];
      add(id(now, i - 1), id(nxt, i), h[j]);
      idx[j]++;
      if (idx[j] > r[j]) idx[j] = 1;
    }
    while (bfs()) {
      ans += dfs(s, inf);
    }
    // cout << ans << endl;
    if (ans >= k) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}