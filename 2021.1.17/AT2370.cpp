
// Problem: AT2370 [AGC013D] Piling Up
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT2370
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int n, m, ans, dp[4000][4000][2];
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) dp[0][i][0] = 1;
  dp[0][0][1] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= n; j++) {
      dp[i][j][0] %= MOD;
      dp[i][j][1] %= MOD;
      if (j != 0) {
        if (j == 1) {
          dp[i + 1][j][1] += dp[i][j][0];
          dp[i + 1][j - 1][1] += dp[i][j][0];
        } else {
          dp[i + 1][j][0] += dp[i][j][0];
          dp[i + 1][j - 1][0] += dp[i][j][0];
        }
        dp[i + 1][j][1] += dp[i][j][1];
        dp[i + 1][j - 1][1] += dp[i][j][1];
      }
      if (j != n) {
        dp[i + 1][j][0] += dp[i][j][0];
        dp[i + 1][j][1] += dp[i][j][1];
        dp[i + 1][j + 1][0] += dp[i][j][0];
        dp[i + 1][j + 1][1] += dp[i][j][1];
      }
    }
  for (int i = 0; i <= n; i++) {
    ans = (ans + dp[m][i][1]) % MOD;
  }
  cout << ans << endl;
  return 0;
}