#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int T, n, k, f[200000], g[200000], inv[300000], fac[300000], finv[300000];
vector<int> v[200000];
int C(int n, int m) {
  if (n < m) return 0;
  if (m == 0) return 1;
  return fac[n] * finv[m] % MOD * finv[n - m] % MOD;
}
int solve(int a, int b) { return b == 0 ? 1 : C(a + b - 1, b - 1); }
int mp[200000][20];
int dfs(int x, int d) {
  if (mp[x][d]) return mp[x][d];
  int ans = f[x] * solve(k - d, d + 1) % MOD;
  if (d >= k) return mp[x][d] = ans;
  for (auto c : v[x]) {
    ans = (ans + dfs(c, d + 1)) % MOD;
  }
  return mp[x][d] = ans;
}
signed main() {
  // freopen("b.in", "r", stdin);
  // freopen("b.out", "w", stdout);
  inv[0] = fac[0] = finv[0] = inv[1] = fac[1] = finv[1] = 1;
  for (int i = 2; i <= 200000; i++) {
    fac[i] = i * fac[i - 1] % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    finv[i] = inv[i] * finv[i - 1] % MOD;
  }
  for (int i = 2; i <= 100000; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        v[i].push_back(j);
        if (j * j != i && j != 1) {
          v[i].push_back(i / j);
        }
      }
    }
  }
  ios::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    memset(mp, 0, sizeof(mp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
      g[i] = dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) {
      cout << g[i] << " ";
    }
    cout << endl;
  }
  return 0;
}