// Problem: F - Potion
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[101], dp[200][101][101], sum;
set<int, int> st[2];
signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == k) {
    puts("0");
    return 0;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[0][i][0] = 0;
  }
  for (int x = 1; x <= n; x++)
    for (int i = n; i >= 0; i--)
      for (int j = 1; j <= n; j++)
        for (int k = 0; k < j; k++) {
          if (dp[i][j][k] == -1) continue;
          int v = k + a[x];
          dp[i + 1][j][v % j] = max(dp[i + 1][j][v % j], dp[i][j][k] + v / j);
        }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (dp[i][i][k % i] == -1) continue;
    ans = min(ans, k / i - dp[i][i][k % i]);
  }
  cout << ans << endl;
  return 0;
}