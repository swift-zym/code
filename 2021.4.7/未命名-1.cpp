#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int n, l, h[101], dp[2][101][3][1001], ans;
signed main() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) cin >> h[i];
  sort(h + 1, h + n + 1);
  int x = 0;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << (h[2] - h[1] <= l) * 2 << endl;
    return 0;
  }
  dp[x][1][0][0] = 1;
  dp[x][1][1][0] = 2;
  for (int _ = 2; _ <= n; _++, x ^= 1) {
    memset(dp[x ^ 1], 0, sizeof(dp[x ^ 1]));
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 2; j++) {
        int nxt = (i * 2 - j) * (h[_] - h[_ - 1]);
        for (int k = 0; k <= l; k++) {
          if (k + nxt > l) continue;
          if (i + 1 <= n) {
            dp[x ^ 1][i + 1][j][k + nxt] += (i - j + 1) * dp[x][i][j][k] % MOD;
            dp[x ^ 1][i + 1][j][k + nxt] %= MOD;
          }
          if (i * 2 - j >= 0) {
            dp[x ^ 1][i][j][k + nxt] += (i * 2 - j) * dp[x][i][j][k] % MOD;
            dp[x ^ 1][i][j][k + nxt] %= MOD;
          }
          if (j < 2 && i + 1 <= n) {
            dp[x ^ 1][i + 1][j + 1][k + nxt] += (2 - j) * dp[x][i][j][k] % MOD;
            dp[x ^ 1][i + 1][j + 1][k + nxt] %= MOD;
          }
          dp[x ^ 1][i - 1][j][k + nxt] += dp[x][i][j][k] * (i - 1) % MOD;
          dp[x ^ 1][i - 1][j][k + nxt] %= MOD;
          if (j < 2) {
            dp[x ^ 1][i][j + 1][k + nxt] += dp[x][i][j][k] * (2 - j) % MOD;
            dp[x ^ 1][i][j + 1][k + nxt] %= MOD;
          }
        }
      }
  }
  for (int i = 0; i <= l; i++) {
    ans = (ans + dp[x][1][2][i]) % MOD;
  }
  cout << ans << endl;
  return 0;
}