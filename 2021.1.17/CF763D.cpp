
// Problem: CF763D Timofey and a flat tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF763D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int n, head[200000], nxt[300000], to[300000], cnt = 1, ans;
void add(int a, int b) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
}
unordered_map<int, int> mp;
int insert(int v) {
  // cout << "insert " << v << endl;
  return ans = ans + ((mp[v]++) == 0);
}
int remove(int v) {
  // cout << "remove " << v << endl;
  return ans = ans - ((--mp[v]) == 0);
}
int siz[300000], dp[300000];
int mx, pos;
void dfs(int now, int fa, int from) {
  siz[from] = 1;
  for (int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], now, i);
    siz[from] += siz[i];
    dp[from] += dp[i];
    dp[from] %= MOD;
  }
  dp[from] *= siz[from];
  dp[from] %= MOD;
  dp[from] += siz[from] * siz[from] % MOD;
  dp[from] %= MOD;
  insert(dp[from]);
}
void df5(int now, int fa) {
  int sum = 0;
  for (int i = head[now]; i; i = nxt[i]) {
    sum += dp[i];
    sum %= MOD;
  }
  for (int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    siz[i ^ 1] = n - siz[i];
    dp[i ^ 1] = (sum - dp[i] + MOD) % MOD;
    dp[i ^ 1] *= siz[i ^ 1];
    dp[i ^ 1] %= MOD;
    dp[i ^ 1] += siz[i ^ 1] * siz[i ^ 1] % MOD;
    dp[i ^ 1] %= MOD;
    df5(to[i], now);
  }
}
void solve(int now, int fa) {
  for (int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    insert(dp[i ^ 1]);
    remove(dp[i]);
    if (ans > mx) {
      mx = ans;
      pos = to[i];
    }
    solve(to[i], now);
    remove(dp[i ^ 1]);
    insert(dp[i]);
  }
}
signed main() {
  scanf("%lld", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%lld%lld", &a, &b);
    add(a, b);
    add(b, a);
  }
  dfs(1, 0, 0);
  df5(1, 0);
  mx = ans;
  pos = 1;
  solve(1, 0);
  printf("%lld\n", pos);
  return 0;
}