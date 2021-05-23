#ifndef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
#define N 100000
#define M 10
#define MOD 1000000007
#define int long long
using namespace std;
int n, m, tot, a[11][N], c[N], ls[N], rs[N], val[N];
int link(int x, int y, int opt) {
  tot++;
  ls[tot] = x;
  rs[tot] = y;
  c[tot] = opt;
  return tot;
}
namespace expr {
int to[N];
string s;
int build(int l, int r) {
  if (to[r]) {
    if (to[r] == l)
      return build(l + 1, r - 1);
    else {
      int x = build(l, to[r] - 2), y = build(to[r] + 1, r - 1);
      return link(x, y, s[to[r] - 1]);
    }
  }
  tot++;
  c[tot] = (s[r] - '0');
  int x = tot;
  if (l == r) return tot;
  int y = build(l, r - 2);
  return link(x, y, s[r - 1]);
}
void scan(string _s) {
  s = _s;
  stack<int> c;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      c.push(i);
    } else if (s[i] == ')') {
      int tp = c.top();
      c.pop();
      to[tp] = i;
      to[i] = tp;
    }
  }
  build(0, s.length() - 1);
}
}  // namespace expr
namespace dp {
int dp[N][2];
void dfs(int x, int mask) {
  dp[x][0] = dp[x][1] = 0;
  if (!ls[x]) {
    dp[x][!(((1 << c[x]) & mask) >> c[x])] = 1;
    // cout << x << " " << mask << " " << dp[x][mask][0] << " " <<
    // dp[x][mask][1]
    //   << endl;
    return;
  }
  dfs(ls[x], mask);
  dfs(rs[x], mask);
  if (c[x] != '<')
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        dp[x][max(i, j)] += (dp[ls[x]][i] * dp[rs[x]][j]);
      }
    }
  if (c[x] != '>')
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        dp[x][min(i, j)] += (dp[ls[x]][i] * dp[rs[x]][j]);
      }
    }
  dp[x][0] %= MOD;
  dp[x][1] %= MOD;
  // cout << x << " " << mask << " " << dp[x][mask][0] << " " << dp[x][mask][1]
  //    << endl;
}
}  // namespace dp
struct node {
  int x, v;
  bool operator<(const node &t) const { return v < t.v; }
};
vector<node> v;
signed main() {
  int ans = 0;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
  string s;
  char tmp[N];
  scanf("%s", tmp);
  s = tmp;
  expr::scan(s);
  for (int i = 1; i <= tot; i++) {
    // cout << i << " " << ls[i] << " " << rs[i] << " " << c[i] << endl;
  }
  for (int i = 0; i < (1 << m); i++) {
    dp::dfs(tot, i);
    val[i] = dp::dp[tot][1];
  }
  for (int i = 1; i <= n; i++) {
    v.clear();
    for (int j = 1; j <= m; j++) {
      v.push_back({j - 1, a[j][i]});
    }
    sort(v.begin(), v.end());
    int mask = 0;
    ans += val[mask] * v[0].v;
    ans %= MOD;
    // cout << val(mask) << " " << v[0].v << endl;
    for (int j = 1; j < v.size(); j++) {
      mask |= (1 << v[j - 1].x);
      ans += val[mask] * (v[j].v - v[j - 1].v) % MOD;
      // cout << mask << " " << val(mask) << " " << (v[j].v - v[j - 1].v) <<
      // endl;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
  return 0;
}