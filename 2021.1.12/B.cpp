#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n, p[1000000], f[1000000], inv[1000000], finv[1000000];
const int mx = 1000000;
int C(int m, int n) { return m < n ? 0 : f[m] * finv[n] % MOD * finv[m - n]; }
int in[1000000], vis[1000000];
void file() {
  freopen("permutation.in", "r", stdin);
  freopen("permutation.out", "w", stdout);
}
signed main() {
  file();
  f[0] = inv[0] = finv[0] = f[1] = inv[1] = finv[1] = 1;
  for (int i = 2; i < mx; i++) {
    f[i] = f[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &p[i]);
    in[p[i]]++;
  }
  int sa = 0, sb = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i]) continue;
    int x = i, num = 0;
    while (x && !vis[x]) {
      vis[x] = 1;
      num++;
      x = p[x];
    }
    if (num % 2)
      sa++;
    else
      sb++;
    if (x && num % 2) {
      printf("%d\n", 0);
      return 0;
    }
  }
  if (!sa) {
    printf("%lld\n", f[sb]);
    return 0;
  }
  if (sa % 2) {
    printf("0\n");
    return 0;
  }
  int ans = 1, sum = 0;
  for (int i = 1; i <= sa; i += 2) {
    ans *= i;
    ans %= MOD;
  }
  ans *= ans;
  ans %= MOD;
  for (int i = 0; i <= sb; i++) {
    sum += C(sa + i - 1, i);
    sum %= MOD;
  }
  ans *= f[sb] * sum % MOD;
  ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}