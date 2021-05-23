#include <bits/stdc++.h>
#define N 1000000
#define inf 1000000000
using namespace std;
int n, m, s, t, cnt, L, R;
int head[N], nxt[N], len[N], to[N], in[N], out[N];
void add(int a, int b, int l, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
void add(int a, int b, int mi, int mx) {
  out[a] += mi;
  in[b] += mi;
  add(a, b, mx - mi);
}
int dep[N], cur[N];
bool bfs() {
  for (int i = 0; i < N; i++) {
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
void clear() {
  cnt = 1;
  memset(head, 0, sizeof(head));
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
}
int sum_col[300], sum_row[300], a[300][300];
bool check(int x) {
  int s1 = 0, t1 = n + m + 1, s2 = t1 + 1, t2 = s2 + 1;
  clear();
  for (int i = 1; i <= n; i++) {
    add(s1, i, sum_col[i] - x, sum_col[i] + x);
  }
  for (int i = 1; i <= m; i++) {
    add(i + n, t1, sum_row[i] - x, sum_row[i] + x);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      add(i, j + n, L, R);
    }
  add(t1, s1, 0, inf);
  int sum = 0;
  for (int i = 0; i <= n + m + 1; i++) {
    if (in[i] > out[i]) {
      add(s2, i, in[i] - out[i]);
      sum += in[i] - out[i];
    }
    if (out[i] > in[i]) {
      add(i, t2, out[i] - in[i]);
    }
  }
  s = s2;
  t = t2;
  int ans = 0;
  while (bfs()) {
    ans += dfs(s2, inf);
  }
  return ans == sum;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum_col[i] += a[i][j];
      sum_row[j] += a[i][j];
    }
  scanf("%d%d", &L, &R);
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++) r = max(r, sum_col[i]);
  for (int i = 1; i <= m; i++) r = max(r, sum_row[i]);
  while (l != r) {
    int mid = (l + r) >> 1;
    // cout << l << " " << r << " " << mid << " " << check(mid) << endl;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}