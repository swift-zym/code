#include <bits/stdc++.h>
#define N 1000000
using namespace std;
vector<int> g[N];
int n, m, X[N], Y[N], power[N], ans, match[N], vis[N];
struct node {
  int id, x, y, limit, price, r, finished;
  bool operator<(const node &t) const {
    if (price != t.price) return price < t.price;
    return id < t.id;
  }
  bool check(int id) {
    return (x - X[id]) * (x - X[id]) + (y - Y[id]) * (y - Y[id]) <= r * r &&
           limit >= power[id];
  }
};
vector<node> v;
bool dfs(int x) {
  for (auto to : g[x]) {
    if (!vis[to]) {
      vis[to] = 1;
      if (!match[to] || dfs(match[to])) {
        match[to] = x;
        return 1;
      }
    }
  }
  return 0;
}
int exec() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &X[i], &Y[i], &power[i]);
  }
  v.clear();
  memset(match, 0, sizeof(match));
  ans = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    if (f) {
      ans += d;
      d = -d;
    }
    v.push_back({i, a, b, c, d, e, f});
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= m; i++) {
    g[i].clear();
    for (int j = 1; j <= n; j++) {
      if (v[i - 1].check(j)) {
        g[i].push_back(j);
      }
    }
  }
  for (int i = 1, j = n; i <= m && j; i++) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) {
      j--;
      ans += v[i - 1].price;
    }
    if (i == m && j) {
      puts("-1");
      return 0;
    }
  }
  vector<int> out;
  for (int i = 1; i <= n; i++) {
    if (match[i]) {
      out.push_back(v[match[i] - 1].id);
    }
  }
  sort(out.begin(), out.end());
  printf("%d\n", ans);
  for (int i = 0; i < out.size(); i++) {
    if (i) putchar(' ');
    printf("%d", out[i]);
  }
  putchar(10);
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) exec();
  return 0;
}