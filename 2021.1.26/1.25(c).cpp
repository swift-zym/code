#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;
int n, q, x, ans = 1, m[200000], d[200000], a[200000];
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
signed main() {
  cin >> n >> q >> x;
  a[0] = x;
  for (int i = 1; i <= n; i++) cin >> m[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 1; i <= n; i++)
    a[i] = max(a[i - 1], d[i]), ans *= min(m[i], a[i - 1]), ans %= MOD;
  cout << ans << endl;
  for (int _ = 1; _ <= q; _++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt) {
      int mx = a[x - 1];
      if (y < mx && d[x] < mx) {
        d[x] = y;
        cout << ans << endl;
        continue;
      }
      d[x] = y;
      ans = 1;
      for (int i = 1; i <= n; i++)
        a[i] = max(a[i - 1], d[i]), ans *= min(m[i], a[i - 1]), ans %= MOD;
      cout << ans << endl;
    } else {
      int mx = min(m[x], a[x - 1]);
      m[x] = y;
      int v = min(m[x], a[x - 1]);
      ans = ans * qpow(mx, MOD - 2) % MOD * v % MOD;
      cout << ans << endl;
    }
  }
}
