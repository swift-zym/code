// Problem: SP10707 COT2 - Count on a tree II
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP10707
// Memory Limit: 1.46 MB
// Time Limit: 1210 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define N 1000000
using namespace std;
int n, m, c[N], st[N][20], s[N], e[N], d[N], bel[N], out[N];
vector<int> v[N], euler;
void dfs(int now, int fa) {
  euler.push_back(now);
  s[now] = euler.size() - 1;
  for (int i = 1; i < 20; i++) {
    st[now][i] = st[st[now][i - 1]][i - 1];
  }
  for (auto to : v[now]) {
    if (to == fa) continue;
    d[to] = d[now] + 1;
    st[to][0] = now;
    dfs(to, now);
  }
  euler.push_back(now);
  e[now] = euler.size() - 1;
}
int lca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  for (int i = 19; ~i; i--) {
    if (d[st[a][i]] >= d[b]) a = st[a][i];
  }
  if (a == b) return a;
  for (int i = 19; ~i; i--) {
    if (st[a][i] != st[b][i]) {
      a = st[a][i];
      b = st[b][i];
    }
  }
  return st[a][0];
}
struct query {
  int l, r, id, lca;
  bool operator<(const query &rhs) const {
    if (bel[l] != bel[rhs.l])
      return bel[l] < bel[rhs.l];
    else
      return r < rhs.r;
  }
};
int num[N], vis[N], ans;
void add(int x) {
  // cout << "add " << x << endl;
  if (vis[x] % 2) {
    ans -= ((--num[c[x]]) == 0);
  } else {
    ans += ((num[c[x]]++) == 0);
  }
  vis[x]++;
}
vector<query> q;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  set<int> tmp;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) cin >> c[i], tmp.insert(c[i]);
  int rnk = 0, block = sqrt(2 * n);
  for (auto v : tmp) {
    mp[v] = ++rnk;
  }
  for (int i = 1; i <= n; i++) c[i] = mp[c[i]];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  st[1][0] = 1;
  dfs(1, 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    if (s[a] > s[b]) swap(a, b);
    int v = lca(a, b);
    if (v == a) {
      q.push_back({s[a], s[b], i, 0});
    } else {
      q.push_back({e[a], s[b], i, v});
    }
  }
  for (int i = 0; i < 2 * n; i++) bel[i] = i / block;
  sort(q.begin(), q.end());
  int l = 0, r = -1;
  for (auto que : q) {
    while (l < que.l) add(euler[l++]);
    while (l > que.l) add(euler[--l]);
    while (r < que.r) add(euler[++r]);
    while (r > que.r) add(euler[r--]);
    // cout << "lca:" << que.lca << " " << ans << endl;
    if (que.lca) add(que.lca);
    out[que.id] = ans;
    if (que.lca) add(que.lca);
  }
  for (int i = 1; i <= m; i++) {
    cout << out[i] << endl;
  }
  return 0;
}