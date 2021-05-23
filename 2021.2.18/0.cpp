// Problem: A. Shifting Stacks
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#define int long long
using namespace std;
int T, n, a[1000];
signed main() {
  a[0] = -1;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int s = a[1];
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
      s += a[i];
      if (s <= a[i - 1]) {
        puts("NO");
        goto ed;
      }
      s -= (a[i - 1] + 1);
      a[i] = a[i - 1] + 1;
    }
    puts("YES");
  ed:;
  }
  return 0;
}