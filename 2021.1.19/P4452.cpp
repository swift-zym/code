#include <bits/stdc++.h>
#define N 1000000
#define inf 1000000000
using namespace std;
int n, m, k, t, cnt = 1;
int head[N], nxt[N], to[N], le[N], co[N];
void add(int a, int b, int f, int c, bool _rev = false) {
  // cout << a << " " << b << " " << f << " " << c << endl;
  nxt[++cnt] = head[a];
  to[cnt] = b;
  le[cnt] = f;
  co[cnt] = c;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, -c, true);
}
int pre[N], lst[N], flow[N], ans[N], vis[N], tmp[300][300][2];
int A[N], B[N], S[N], T[N], C[N];
void SPFA(int s, int t) {
  queue<int> q;
  memset(flow, 0, sizeof(flow));
  memset(vis, 0, sizeof(vis));
  memset(ans, 0x8f, sizeof(ans));
  flow[s] = inf;
  ans[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    vis[now] = 0;
    q.pop();
    for (int i = head[now]; i; i = nxt[i]) {
      // cout << now << " " << to[i] << endl;
      if (le[i] && ans[to[i]] < ans[now] + co[i]) {
        ans[to[i]] = ans[now] + co[i];
        pre[to[i]] = i;
        lst[to[i]] = now;
        flow[to[i]] = min(flow[now], le[i]);
        if (!vis[to[i]]) {
          vis[to[i]] = 1;
          q.push(to[i]);
        }
      }
    }
  }
  // cout << ">" << ans[t] << endl;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &t);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &tmp[i][j][0]);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &tmp[i][j][1]);
    }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d%d", &A[i], &B[i], &S[i], &T[i], &C[i]);
    A[i]++;
    B[i]++;
    add(i, m + i, 1, C[i]);
    if (tmp[1][A[i]][0] <= S[i]) {
      add(0, i, inf, -tmp[1][A[i]][1]);
    }
    if (T[i] + tmp[B[i]][1][0] <= t) {
      add(i + m, m * 2 + 1, inf, -tmp[B[i]][1][1]);
    }
  }
  add(m * 2 + 2, 0, k, 0);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      if (i == j) continue;
      if (T[i] + tmp[B[i]][A[j]][0] <= S[j]) {
        add(m + i, j, inf, -tmp[B[i]][A[j]][1]);
      }
    }
  int sum = 0, s = m * 2 + 2, t = m * 2 + 1;
  while (1) {
    SPFA(s, t);
    if (!flow[t]) break;
    sum += flow[t] * ans[t];
    int now = t, v = flow[t];
    do {
      le[pre[now]] -= v;
      le[pre[now] ^ 1] += v;
      now = lst[now];
    } while (now != s);
  }
  cout << sum << endl;
  return 0;
}