#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[10000];
signed main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  while (cin >> n >> m) {
    for (int i = 0; i <= n; i++) {
      if (i == 0 || i == 1)
        a[i] = 1 % m;
      else if (i == 2 || i == 3)
        a[i] = 0;
      else
        a[i] = ((i + 1) * a[i - 1] % m - (i - 2) * a[i - 2] % m + m -
                (i - 5) * a[i - 3] % m + m + (i - 3) * a[i - 4] % m) %
               m;
    }
    cout << a[n] << endl;
  }
  return 0;
}