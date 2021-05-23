#pragma GCC optimize(3)
#include <bits/stdc++.h>

#include <ext/pb_ds/priority_queue.hpp>
#define N 10000000
#define id(i, j) ((i - 1) * (m - 1) + j)
using namespace std;
int n, m, s, t, cnt, a[1001][1001], b[1001][1001];
int head[N], nxt[N], to[N], len[N], ans[N];
inline void add(int a, int b, int l) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
  len[cnt] = l;
}
struct node {
  int x, v;
  friend bool operator<(node a, node b) { return a.v > b.v; }
};
__gnu_pbds::priority_queue<node> p;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &b[i][j]);
  s = (n - 1) * (m - 1) + 1, t = (n - 1) * (m - 1) + 2;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      int now = id(i, j), to;
      to = id(i, j - 1);
      if (j == 1) {
        to = s;
        add(to, now, b[i][j]);
      }
      add(now, to, b[i][j]);
      to = id(i, j + 1);
      if (j == m - 1) {
        to = t;
        add(to, now, b[i][j + 1]);
      }
      add(now, to, b[i][j + 1]);
      to = id(i - 1, j);
      if (i == 1) {
        to = t;
        add(to, now, a[i][j]);
      }
      add(now, to, a[i][j]);
      to = id(i + 1, j);
      if (i == n - 1) {
        to = s;
        add(to, now, a[i + 1][j]);
      }
      add(now, to, a[i + 1][j]);
    }
  memset(ans, 0x3f, sizeof(ans));
  ans[s] = 0;
  p.push({s, 0});
  while (!p.empty()) {
    node now = p.top();
    p.pop();
    if (ans[now.x] != now.v) continue;
    for (int i = head[now.x]; i; i = nxt[i]) {
      if (ans[to[i]] > ans[now.x] + len[i]) {
        ans[to[i]] = ans[now.x] + len[i];
        p.push({to[i], ans[to[i]]});
      }
    }
  }
  printf("%d\n", ans[t]);
  return 0;
}
