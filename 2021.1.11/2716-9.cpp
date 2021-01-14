
// Problem: SP3734 PERIODNI - Periodni
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP3734
// Memory Limit: 0 MB
// Time Limit: 996 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define MAXN 5000000
#define MOD 1000000007
using namespace std;
int n, k, h[MAXN], son[MAXN][2], fac[MAXN], inv[MAXN], finv[MAXN];
stack<int> s;
int C(int a, int b) {
  if (a < b) return 0;
  return fac[a] * finv[b] % MOD * finv[a - b] % MOD;
}
void init() {
  fac[0] = inv[0] = finv[0] = fac[1] = inv[1] = finv[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
int dp[1000][1000], siz[1000];
void dfs(int now, int fa) {
  dp[now][0] = 1;
  siz[now] = 1;
  if (son[now][0]) {
    dfs(son[now][0], now);
    siz[now] += siz[son[now][0]];
  }
  if (son[now][1]) {
    dfs(son[now][1], now);
    siz[now] += siz[son[now][1]];
  }
  for (int i = min(k, siz[now]); i >= 1; i--) {
    for (int j = 1; j <= min(siz[son[now][0]], i); j++) {
      dp[now][i] += dp[son[now][0]][j] * dp[now][i - j] % MOD;
      dp[now][i] %= MOD;
    }
  }
  for (int i = min(k, siz[now]); i >= 1; i--) {
    for (int j = 1; j <= min(siz[son[now][1]], i); j++) {
      dp[now][i] += dp[son[now][1]][j] * dp[now][i - j] % MOD;
      dp[now][i] %= MOD;
    }
  }
  for (int i = min(k, siz[now]); i >= 1; i--) {
    for (int j = 1; j <= min(i, h[now] - h[fa]); j++) {
      dp[now][i] += fac[j] * C(siz[now] - (i - j), j) % MOD *
                    C(h[now] - h[fa], j) % MOD * dp[now][i - j] % MOD;
      dp[now][i] %= MOD;
    }
  }
  /*for (int i = 0; i <= min(k, siz[now]); i++) {
    cout << now << " " << i << "->" << dp[now][i] << endl;
  }*/
}
signed main() {
  init();
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
  for (int i = 1; i <= n; i++) {
    int lst = -1;
    while (!s.empty() && h[s.top()] > h[i]) {
      lst = s.top();
      s.pop();
    }
    if (!s.empty()) {
      son[s.top()][1] = i;
    }
    if (lst != -1) {
      son[i][0] = lst;
    }
    s.push(i);
  }
  while (s.size() != 1) s.pop();
  dfs(s.top(), 0);
  printf("%lld\n", dp[s.top()][k]);
  return 0;
}