#pragma GCC optimize("Ofast")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define N 5000102
#define id(i, j) ((i - 1) * (m - 1) + j)
typedef long long ll;
struct edge {
  int to, nxxt, len;
} e[N << 1];
struct node {
  int to, len;
  friend bool operator<(node a, node b) { return a.len > b.len; }
};
priority_queue<node> q;
int len[N], a[2002][2002], b[2002][2002], S, T, head[N], cnt = 1, n, m;
inline void ins(int u, int v, int w) {
  e[cnt].to = v;
  e[cnt].nxxt = head[u];
  e[cnt].len = w;
  head[u] = cnt++;
}
int main() {
  scanf("%d%d", &n, &m);
  S = (n - 1) * (m - 1) + 1, T = S + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &b[i][j]);
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      int now = id(i, j), to;
      to = id(i, j - 1);
      if (j == 1) {
        to = S;
        ins(to, now, b[i][j]);
      }
      ins(now, to, b[i][j]);
      to = id(i, j + 1);
      if (j == m - 1) {
        to = T;
        ins(to, now, b[i][j + 1]);
      }
      ins(now, to, b[i][j + 1]);
      to = id(i - 1, j);
      if (i == 1) {
        to = T;
        ins(to, now, a[i][j]);
      }
      ins(now, to, a[i][j]);
      to = id(i + 1, j);
      if (i == n - 1) {
        to = S;
        ins(to, now, a[i + 1][j]);
      }
      ins(now, to, a[i + 1][j]);
    }
  for (int i = 1; i <= T; i++) len[i] = 2004032200;
  len[S] = 0;
  node s1;
  s1.to = S, s1.len = 0;
  q.push(s1);
  while (!q.empty()) {
    node a1 = q.top();
    q.pop();
    if (a1.len > len[a1.to]) continue;
    for (int i = head[a1.to]; i; i = e[i].nxxt) {
      node t1;
      t1.to = e[i].to;
      t1.len = a1.len + e[i].len;
      if (t1.len < len[t1.to]) len[t1.to] = t1.len, q.push(t1);
    }
  }
  printf("%d\n", len[T]);
}