// Problem: B. Replace and Keep Sorted
// Contest: Codeforces - Codeforces Round #701 (Div. 2)
// URL: https://codeforces.com/contest/1485/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, q, k, a[100001], ans[100001];
int main() {
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    ans[i] = max(0, a[i + 1] - a[i - 1] - 2);
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << k - 1 << endl;
    } else
      cout << ans[r - 1] - ans[l] + max(0, k - a[r - 1] - 1) + (a[l + 1] - 2)
           << endl;
  }
  return 0;
}