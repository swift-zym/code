#include <bits/stdc++.h>
#define eps 10
#define int long long
#define f(x) (double)(s[n] - s[n - x] + s[i] - s[i - x - 1]) / (2 * x + 1)
using namespace std;
int n, a[300000], s[300000];
double ans;
signed main() {
  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; i++) {
    int l = 1, r = min(i - 1, n - i);
    while (r - l > eps) {
      int mid = (l + r) / 2, mmid = (mid + r) / 2;
      if (f(mid) < f(mmid)) {
        l = mid;
      } else {
        r = mmid;
      }
    }
    for (int j = l; j <= r; j++) ans = max(ans, f(j) - a[i]);
  }
  cout << fixed << setprecision(5) << ans << endl;
  return 0;
}
