
// Problem: P5192 Zoj3229 Shoot the Bullet|东方文花帖|【模板】有源汇上下界最大流
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5192
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define N 2000000
#define inf 1000000000
using namespace std;
int n, m, cnt, s, t;
int head[N], nxt[N], to[N], len[N], in[N], out[N];
void add(int a, int b, int l, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
void add(int a, int b, int mi, int mx) {
  in[b] += mi;
  out[a] += mi;
  add(a, b, mx - mi);
}
void clear() {
  cnt = 1;
  memset(head, 0, sizeof(head));
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
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
  int ans = 0;
  while (bfs()) {
    ans += dfs(s, inf);
  }
  return ans;
}
int main() {
  while (cin >> n >> m) {
    clear();
    int s1 = n + m + 1, t1 = n + m + 2, s2 = n + m + 3, t2 = n + m + 4;
    s = s2;
    t = t2;
    for (int i = 1; i <= m; i++) {
      int v;
      cin >> v;
      add(i + n, t1, v, inf);
    }
    for (int i = 1; i <= n; i++) {
      int c, d;
      cin >> c >> d;
      add(s1, i, 0, d);
      for (int j = 1; j <= c; j++) {
        int t, l, r;
        cin >> t >> l >> r;
        t++;
        add(i, t + n, l, r);
      }
    }
    add(t1, s1, 0, inf);
    int sum = 0;
    for (int i = 1; i <= n + m + 2; i++) {
      if (in[i] > out[i]) {
        add(s2, i, in[i] - out[i]);
        sum += in[i] - out[i];
      } else if (out[i] > in[i]) {
        add(i, t2, out[i] - in[i]);
      }
    }
    if (dinic() != sum) {
      puts("-1\n");
    } else {
      s = s1;
      t = t1;
      cout << dinic() << endl << endl;
    }
  }
  return 0;
}