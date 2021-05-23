#include <bits/stdc++.h>
#define int long long
#define MOD 19940417
using namespace std;
signed main() {
  int n, m;
  cin >> n >> m;
  int ans = n * n % MOD * m % MOD * m % MOD, sum = 0;
  for (int l = 1; l <= m; l = (m / (m / l)) + 1) {
    int r = (m / (m / l));
    sum += (r - l + 1) * (m / l);
  }
  ans -= n * n % MOD * sum % MOD;
  ans = (ans + MOD) % MOD;
  cout << sum << endl;
  sum = 0;
  for (int l = 1; l <= n; l = (n / (n / l)) + 1) {
    int r = (n / (n / l));
    sum += (r - l + 1) * (n / l);
  }
  ans -= m * m % MOD * sum % MOD;
  ans = (ans + MOD) % MOD;
  cout << sum << endl;
  sum = 0;
  for (int l = 1; l <= min(n, m); l = min(n / (n / l), m / (m / l)) + 1) {
    int r = min(n / (n / l), m / (m / l));
    sum += (r - l + 1) * (n / l) * (m / l);
  }
  cout << sum << endl;
  ans += sum;
  ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}