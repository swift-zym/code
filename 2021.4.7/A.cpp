#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1000000], s[1000000];
double ans;
signed main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; i++) {
    int l = 0, r = min(i - 1, n - i);
    while (r - l > 5) {
      int mid = (l + r) / 2, mmid = (mid + r) / 2;
      if (1.0 * (s[i] - s[i - mid - 1] + s[n] - s[n - mid]) / (mid * 2 + 1) -
              a[i] >
          1.0 * (s[i] - s[i - mmid - 1] + s[n] - s[n - mmid]) / (mmid * 2 + 1) -
              a[i]) {
        r = mmid;
      } else {
        l = mid;
      }
    }
    for (int j = l; j <= r; j++) {
      ans =
          max(ans, 1.0 * (s[i] - s[i - j - 1] + s[n] - s[n - j]) / (j * 2 + 1) -
                       a[i]);
    }
  }
  cout << fixed << setprecision(4) << ans << endl;
  return 0;
}