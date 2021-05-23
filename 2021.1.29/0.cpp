// Problem: A. K-divisible Sum
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (n > k) {
      if (n % k == 0) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else {
      cout << (k / n) + (k % n != 0) << endl;
    }
  }
  return 0;
}