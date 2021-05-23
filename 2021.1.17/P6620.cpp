
// Problem: P6620 [省选联考 2020 A 卷] 组合数问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6620
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, p, m, a[2000];
int s[1001][1001], b[2000], f[2000];
int qpow(int a, int b) {
  if (b == 0) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % p * a % p : tmp * tmp % p;
}
signed main() {
  cin >> n >> x >> p >> m;
  f[0] = 1;
  for (int i = 1; i <= m; i++) {
    f[i] = f[i - 1] * (n - i + 1) % p;
  }
  s[0][0] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      s[i][j] = s[i - 1][j - 1] + j * s[i - 1][j] % p;
      s[i][j] %= p;
    }
  for (int i = 0; i <= m; i++) cin >> a[i];
  for (int i = 0; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      b[i] += s[j][i] * a[j] % p;
      b[i] %= p;
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans += b[i] * qpow(x, i) % p * qpow(x + 1, n - i) % p * f[i] % p;
    ans %= p;
  }
  cout << ans << endl;
  return 0;
}