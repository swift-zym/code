#include <bits/stdc++.h>
#define N 1000000
#define inf 1000000000
using namespace std;
int n, s, t, cnt = 1, head[N], nxt[N], to[N], len[N], in[N], out[N], dep[N],
             cur[N];
double a[101][101];
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
bool bfs() {
  for (int i = 0; i < N; i++) {
    dep[i] = inf;
    cur[i] = head[i];
  }
  queue<int> q;
  dep[s] = 0;
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
int dinic(int _s, int _t) {
  s = _s;
  t = _t;
  int ans = 0;
  while (bfs()) ans += dfs(s, inf);
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  int s1 = n * 2 - 1, t1 = s1 + 1, s2 = t1 + 1, t2 = s2 + 1;
  for (int i = 1; i < n; i++) {
    add(s1, i, (int)floor(a[i][n]), (int)ceil(a[i][n]));
  }
  for (int i = 1; i < n; i++) {
    add(n + i - 1, t1, (int)floor(a[n][i]), (int)ceil(a[n][i]));
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      add(i, n + j - 1, (int)floor(a[i][j]), (int)ceil(a[i][j]));
    }
  add(t1, s1, 0, inf);
  int sum = 0;
  for (int i = 1; i <= t1; i++) {
    if (in[i] > out[i]) {
      add(s2, i, in[i] - out[i]);
      sum += in[i] - out[i];
    }
    if (out[i] > in[i]) {
      add(i, t2, out[i] - in[i]);
    }
  }
  if (sum != dinic(s2, t2)) {
    puts("-1");
  } else {
    cout << dinic(s1, t1) * 3 << endl;
  }
  return 0;
}