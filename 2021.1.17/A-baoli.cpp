#include <bits/stdc++.h>
#define N 1000000
using namespace std;
vector<int> v[N];
int n, f[N][20], d[N], ans;
void dfs(int x, int fa) {
  f[x][0] = fa;
  d[x] = d[fa] + 1;
  for (int i = 1; i < 20; i++) {
    f[x][i] = f[f[x][i - 1]][i - 1];
  }
  for (auto to : v[x]) {
    if (to != fa) dfs(to, x);
  }
}
int dis(int a, int b) {
  int x = a, y = b;
  if (d[x] < d[y]) swap(x, y);
  for (int i = 19; ~i; i--) {
    if (d[f[x][i]] >= d[y]) x = f[x][i];
  }
  if (x == y) return d[a] + d[b] - d[x] * 2;
  for (int i = 19; ~i; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i], y = f[y][i];
    }
  }
  return d[a] + d[b] - d[f[x][0]] * 2;
}
int lca(int a, int b) {
  int x = a, y = b;
  if (d[x] < d[y]) swap(x, y);
  for (int i = 19; ~i; i--) {
    if (d[f[x][i]] >= d[y]) x = f[x][i];
  }
  return x;
  for (int i = 19; ~i; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i], y = f[y][i];
    }
  }
  return f[x][0];
}
int tmp[N];
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        int a = dis(i, j), b = dis(j, k), c = dis(i, k);
        if (a == b && b == c) ans++;
      }
  cout << ans << endl;
  return 0;
}