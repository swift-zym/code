#include <bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
int n, db[N << 3], *tf, *tg, *f[N], *g[N], mx[N], s[N], sum[N], ans;
vector<int> v[N];
void dfs1(int x, int f) {
  mx[x] = 1;
  for (auto to : v[x]) {
    if (to == f) continue;
    dfs1(to, x);
    mx[x] = max(mx[x], mx[to] + 1);
    if (mx[to] > mx[s[x]]) s[x] = to;
  }
}
void dfs2(int x, int fa) {
  if (s[x]) {
    f[s[x]] = f[x] + 1;
    g[s[x]] = g[x] - 1;
    dfs2(s[x], x);
  }
  for (auto to : v[x]) {
    if (to == fa || to == s[x]) continue;
    f[to] = tf;
    g[to] = tg + mx[to];
    tf += mx[to];
    tg += (mx[to] << 1);
    dfs2(to, x);
  }
}
void dfs3(int x, int fa) {
  if (s[x]) dfs3(s[x], x);
  f[x][0]++;
  ans += g[x][0];
  for (auto to : v[x]) {
    if (to == fa || to == s[x]) continue;
    dfs3(to, x);
    for (int i = 0; i < mx[to]; i++) {
      if (i) ans += f[x][i - 1] * g[to][i];
      ans += f[to][i] * g[x][i + 1];
    }
    for (int i = 0; i < mx[to]; i++) {
      if (i) g[x][i - 1] += g[to][i];
      g[x][i + 1] += f[to][i] * f[x][i + 1];
      f[x][i + 1] += f[to][i];
    }
  }
}
signed main() {
  freopen("zh.in", "r", stdin);
  freopen("zh.out", "w", stdout);
  tf = db;
  tg = db + (N << 1);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b), v[b].push_back(a);
  }
  dfs1(1, 1);
  f[1] = tf;
  g[1] = tg + mx[1];
  tf += mx[1];
  tg += (mx[1] << 1);
  dfs2(1, 1);
  dfs3(1, 1);
  cout << ans << endl;
  return 0;
}