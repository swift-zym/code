
// Problem: P5325 【模板】Min_25筛
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5325
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define MOD 1000000007ll
#define int long long
using namespace std;
int n, mx;
int i2, i3;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
vector<int> prime;
int sum[1000000], ssum[1000000], np[1000000];
void euler() {
  np[1] = 1;
  for (int i = 2; i <= mx; i++) {
    if (!np[i]) {
      prime.push_back(i);
      sum[prime.size()] = sum[prime.size() - 1] + i;
      sum[prime.size()] %= MOD;
      ssum[prime.size()] = ssum[prime.size() - 1] + (i * i) % MOD;
      ssum[prime.size()] %= MOD;
    }
    for (int j = 0; j < prime.size() && i * prime[j] <= mx; j++) {
      np[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int val[1000000], dp[1000000][2], idx[1000000][2], tot;
void init() {
  euler();
  i2 = qpow(2, MOD - 2);
  i3 = qpow(3, MOD - 2);
}
int S(int x, int y) {
  if (y && prime[y - 1] >= x) return 0;
  int k = x <= mx ? idx[x][0] : idx[n / x][1];
  int ans = (((dp[k][1] - ssum[y] + MOD) % MOD) -
             ((dp[k][0] - sum[y] + MOD) % MOD) + MOD) %
            MOD;
  for (int i = y + 1; i <= prime.size() && prime[i - 1] * prime[i - 1] <= x;
       i++) {
    int pr = prime[i - 1];
    for (int j = 1; pr <= x; j++, pr *= prime[i - 1]) {
      ans += ((pr % MOD) * ((pr % MOD) - 1) % MOD * (S(x / pr, i) + (j != 1))) %
             MOD;
      ans %= MOD;
    }
  }
  return ans;
}
void check() {
  for (int i = 0; i < 1000000; i++) {
    assert(sum[i] >= 0);
    assert(ssum[i] >= 0);
    assert(val[i] >= 0);
    assert(dp[i][0] >= 0 && dp[i][1] >= 0);
    assert(idx[i][0] >= 0 && idx[i][1] >= 0);
  }
}
signed main() {
  scanf("%lld", &n);
  mx = sqrt(n);
  init();
  for (int i = 1; i <= n; i = (n / (n / i)) + 1) {
    val[++tot] = (n / i);
    dp[tot][0] =
        ((val[tot] % MOD * (val[tot] % MOD + 1) % MOD * i2) % MOD - 1 + MOD) %
        MOD;
    dp[tot][1] = (val[tot] % MOD * (val[tot] % MOD + 1) % MOD *
                      (2ll * val[tot] % MOD + 1) % MOD * i2 % MOD * i3 % MOD -
                  1 + MOD) %
                 MOD;
    if (val[tot] <= mx) {
      idx[val[tot]][0] = tot;
    } else {
      idx[n / val[tot]][1] = tot;
    }
  }
  for (int i = 1; i <= prime.size(); i++) {
    int pr = prime[i - 1];
    for (int j = 1; pr * pr <= val[j] && j <= tot; j++) {
      int k = (val[j] / pr <= mx) ? (idx[val[j] / pr][0])
                                  : (idx[n / (val[j] / pr)][1]);
      dp[j][0] -= pr * (dp[k][0] - sum[i - 1] + MOD) % MOD;
      dp[j][1] -= (pr * pr) % MOD * (dp[k][1] - ssum[i - 1] + MOD) % MOD;
      dp[j][0] = (dp[j][0] + MOD) % MOD;
      dp[j][1] = (dp[j][1] + MOD) % MOD;
    }
  }
  printf("%lld\n", S(n, 0) + 1);
  return 0;
}