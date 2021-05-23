#include <bits/stdc++.h>
#define N 10000
using namespace std;
int n, m, d, ans = INT_MAX, cur, f[N + 1];
struct edge {
  int u, v, w, vis;
  bool operator<(const edge &e) const { return w < e.w; }
} e[N + 1];
int gf(int x) { return f[x] == x ? x : f[x] = gf(f[x]); }
bool check() {
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    if (e[i].vis) {
      f[gf(e[i].u)] = gf(e[i].v);
    }
  }
  for (int i = 1; i <= d; i++) {
    if (gf(i) != gf(n - i + 1)) return 0;
  }
  return 1;
}
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  while ((double)clock() / CLOCKS_PER_SEC < 1.9) {
    random_shuffle(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++) e[i].vis = 0;
    cur = 0;
    for (int i = 1; i <= m; i++) {
      0 e[i].vis = 1;
      cur += e[i].w;
      if (check()) {
        ans = min(ans, cur);
      }
    }
    // test
  }
  cout << (ans == INT_MAX ? -1 : ans) << endl;
  return 0;
}