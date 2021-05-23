#define LUOGU
#include <bits/stdc++.h>
#define int long long
#define N 10000000
#ifndef LUOGU
#define MOD 100000009
#define inv2 50000005
#else
#define MOD 20101009
#define inv2 10050505
#endif
using namespace std;
int s(int n) { return n * (n + 1) % MOD * inv2 % MOD; }
int f(int n, int m) { return s(n) * s(m) % MOD; }
int np[N + 1], g[N + 1];
vector<int> p;
void e() {
  np[1] = g[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!np[i]) {
      p.push_back(i);
      g[i] = i * (1ll - i + MOD) % MOD;
    }
    for (int j = 0; j < p.size() && i * p[j] <= N; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0) {
        g[i * p[j]] = g[i] * p[j] % MOD;
        break;
      } else {
        g[i * p[j]] = g[i] * g[p[j]] % MOD;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    g[i] += g[i - 1];
    g[i] %= MOD;
  }
}
signed main() {
  e();
  int T = 1, n, m;
#ifndef LUOGU
  scanf("%lld", &T);
#endif
  while (T--) {
    scanf("%lld%lld", &n, &m);
    if (n > m) swap(n, m);
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
      r = min((n / (n / l)), (m / (m / l)));
      ans += f(n / l, m / l) * ((g[r] - g[l - 1]) % MOD + MOD) % MOD;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}