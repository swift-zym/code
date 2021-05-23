// Problem: A. Alexey and Train
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open
// Olympiad in Informatics) URL: https://codeforces.com/contest/1501/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, T, a[101], b[101], t[101];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += (a[i] - b[i - 1] + t[i]);
      if (i == n) {
        cout << cur << endl;
        break;
      }
      cur += ceil(1.0 * (b[i] - a[i]) / 2);
      cur = max(cur, b[i]);
    }
  }
  return 0;
}