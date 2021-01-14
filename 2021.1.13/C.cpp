#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, q, a[1000000], dp[1000000][2], p[1000000], ans = LLONG_MAX;
vector<int> v[1000000];
int dfs(int now) {
  dp[now][0] = LLONG_MIN;
  for (auto to : v[now]) {
    dp[now][0] = max(dp[now][0], dfs(to));
  }
  if (dp[now][0] == LLONG_MIN) dp[now][0] = 0;
  dp[now][1] = dp[now][0] + a[now];
  ans = min(ans, dp[now][1]);
  return dp[now][1];
}
signed main() {
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 2; i <= n; i++) {
    scanf("%lld", &p[i]);
    v[p[i]].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    int x, v;
    scanf("%lld%lld", &x, &v);
    a[x] = v;
    ans = LLONG_MAX;
    dfs(1);
    printf("%lld\n", ans);
  }
  return 0;
}