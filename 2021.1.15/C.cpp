#include <bits/stdc++.h>
#define MAXN 2000000
#define MOD 1000000007
#define int long long
using namespace std;
int n, m, siz;
int inv[MAXN << 1], f[MAXN << 1], finv[MAXN << 1];
int c[MAXN], dp[21][MAXN];
int C(int m, int n) {
  if (m < n) return 0;
  return f[m] * finv[n] % MOD * finv[m - n] % MOD;
}
vector<pair<int, int>> v;
void file() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
}
void build() {
  for (int i = 0; i <= 20; i++)
    for (int j = 1; j <= n; j++) {
      if (!i)
        dp[i][j] = c[j];
      else
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
}
signed main() {
  file();
  scanf("%lld%lld", &n, &m);
  siz = sqrt(10 * m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &c[i]);
  }
  inv[0] = f[0] = finv[0] = inv[1] = f[1] = finv[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    f[i] = f[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  build();
  for (int i = 1; i <= m; i++) {
    int o, x, y;
    scanf("%lld%lld%lld", &o, &x, &y);
    if (o == 1) {
      v.push_back({x, (y - c[x] + MOD) % MOD});
      c[x] = y;
    } else {
      int ans = dp[x][y];
      if (x) {
        if (v.size() <= siz) {
          for (auto c : v) {
            if (c.first > y) continue;
            ans += c.second * C((x - 1) + (y - c.first), x - 1) % MOD;
            ans %= MOD;
          }
        } else {
          build();
          ans = dp[x][y];
          v.clear();
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}