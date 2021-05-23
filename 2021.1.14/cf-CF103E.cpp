
// Problem: CF103E Buying Sets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF103E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define inf 2000000000
#define sinf 500000000
using namespace std;
int n, s, t, head[700], nxt[1000000], len[1000000], to[1000000], cnt = -1;
int cur[1000000];
void add(int a, int b, int l, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
int lev[700];
bool bfs() {
  for (int i = s; i <= t; i++) {
    lev[i] = inf;
    cur[i] = head[i];
  }
  lev[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == t) return true;
    for (int i = head[now]; i != -1; i = nxt[i]) {
      if (lev[to[i]] == inf && len[i]) {
        lev[to[i]] = lev[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return false;
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i != -1 && flow; i = nxt[i]) {
    cur[now] = i;
    if (lev[to[i]] == lev[now] + 1 && len[i]) {
      int val = dfs(to[i], min(flow, len[i]));
      if (!val) lev[to[i]] = inf;
      flow -= val;
      use += val;
      len[i] -= val;
      len[i ^ 1] += val;
    }
  }
  return use;
}
signed main() {
  memset(head, -1, sizeof(head));
  scanf("%lld", &n);
  s = 0;
  t = 2 * n + 1;
  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%lld", &num);
    for (int j = 1; j <= num; j++) {
      int x;
      scanf("%lld", &x);
      add(i, n + x, inf);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%lld", &x);
    add(s, i, sinf - x);
    ans += sinf - x;
  }
  for (int i = 1; i <= n; i++) {
    add(n + i, t, sinf);
  }
  while (bfs()) {
    ans -= dfs(s, inf);
  }
  printf("%lld\n", min(-ans, 0ll));
  return 0;
}