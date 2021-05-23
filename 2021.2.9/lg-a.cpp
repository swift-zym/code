#include <bits/stdc++.h>
using namespace std;
int n, m, type, t[1000], q[1000], a, b, ans;
int main() {
  cin >> n >> m >> type;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
    if (q[i] & t[i])
      a++;
    else
      b++;
  }
  if (a < m)
    ans += a;
  else
    ans += m;
  ans += b;
  cout << ans << endl;
  return 0;
}