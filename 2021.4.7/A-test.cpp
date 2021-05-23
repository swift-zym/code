#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1000000], s[1000000];
double ans;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int idx[] = {2, 8, 9, 10, 13, 16, 18};
  vector<int> v;
  for (int i = 0; i < 7; i++) v.push_back(a[idx[i]]);
  sort(v.begin(), v.end());
  double ans = 0;
  for (auto x : v) ans += x;
  ans /= 7;
  cout << fixed << ans << " " << v[3] << endl;
  ans -= v[3];
  cout << fixed << ans << endl;
  return 0;
}