// Problem: D. Pythagorean Triples
// Contest: Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1487/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// c=a*a-b
// c=a*a+b*b
#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, n;
signed main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int l = 1, r = 1e9, v;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid / 2 * mid / 2 + 1 <= n) {
        l = mid + 1;
        v = mid;
      } else {
        r = mid - 1;
      }
    }
    while (!v % 2 || (v * v / 2 + 1) > n) v--;
    cout << max((v - 1) / 2, 0ll) << endl;
  }
  return 0;
}