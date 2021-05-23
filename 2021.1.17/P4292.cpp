// Problem: P4292 [WC2010]重建计划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4292
// Memory Limit: 250 MB
// Time Limit: 4000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optmize("Ofast")
#include <bits/stdc++.h>
#define N 1100000
#define eps 1e-9
using namespace std;
int n, l, u, rt, drt, siz[N], mx[N], vis[N], mxdis;
double tmp[N], sum[N], ans;
vector<int> d[N];
vector<pair<int, double>> v[N], vv[N];
void findrt(int x, int tot, int fa = -1) {
  siz[x] = 1;
  for (auto to : vv[x]) {
    if (to.first == fa || vis[to.first]) continue;
    findrt(to.first, tot, x);
    siz[x] += siz[to.first];
  }
  mx[x] = max(siz[x], tot - siz[x]);
  if (mx[x] < mx[rt]) rt = x;
}
void build(int x) {
  vis[x] = 1;
  for (auto to : vv[x]) {
    if (vis[to.first]) continue;
    rt = 0;
    findrt(to.first, siz[to.first]);
    findrt(rt, siz[to.first]);
    d[x].push_back(rt);
    build(rt);
  }
}
void rebuild() {
  findrt(1, n);
  drt = rt;
  findrt(drt, n);
  build(drt);
}
void getdis(int x, int d, double val, int fa) {
  mxdis = max(mxdis, d);
  tmp[d] = max(tmp[d], val);
  for (auto to : v[x]) {
    if (to.first == fa || vis[to.first]) continue;
    getdis(to.first, d + 1, val + to.second, x);
  }
}
void div(int x) {
  int mxidx = 0;
  vis[x] = 1;
  for (auto to : v[x]) {
    if (vis[to.first]) continue;
    int idx = 1;
    mxdis = -1;
    getdis(to.first, 1, to.second, x);
    deque<pair<int, double>> q;
    for (int i = mxdis; i >= 1; i--) {
      while (idx <= u - i && idx <= mxidx) {
        while (!q.empty() && q.back().second < sum[idx]) {
          q.pop_back();
        }
        q.push_back(make_pair(idx, sum[idx]));
        idx++;
      }
      while (!q.empty() && q.front().first < l - i) {
        q.pop_front();
      }
      if (!q.empty()) {
        ans = max(ans, tmp[i] + q.front().second);
      }
    }
    mxidx = max(mxidx, mxdis);
    for (int i = 1; i <= mxdis; i++) {
      if (i >= l && i <= u) ans = max(ans, tmp[i]);
      sum[i] = max(sum[i], tmp[i]);
      tmp[i] = -1e12;
    }
  }
  for (int i = 1; i <= mxidx; i++) sum[i] = -1e12;
  for (auto to : d[x]) {
    div(to);
  }
}
bool dfs(int x, int fa, int d, double val) {
  for (auto to : v[x]) {
    if (to.first == fa) continue;
    if (val + to.second > -eps && d >= l && d <= u) {
      return 1;
    }
    if (dfs(to.first, x, d + 1, val + to.second)) return 1;
  }
  return 0;
}
bool baoli() {
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    flag |= dfs(i, i, 1, 0);
  }
  return flag;
}
bool check(double x) {
  ans = -1e12;
  for (int i = 1; i <= n; i++) sum[i] = tmp[i] = -1e12, vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    v[i] = vv[i];
    for (auto &&to : v[i]) {
      to.second -= x;
    }
  }
  div(drt);
  return ans >= -eps;
}
signed main() {
  scanf("%d%d%d", &n, &l, &u);
  mx[0] = 1000000000;
  for (int i = 1; i < n; i++) {
    int s, t, l;
    scanf("%d%d%d", &s, &t, &l);
    vv[s].push_back(make_pair(t, l));
    vv[t].push_back(make_pair(s, l));
  }
  rebuild();
  double l = 0, r = 1e8;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%0.3lf\n", l);
  return 0;
}
