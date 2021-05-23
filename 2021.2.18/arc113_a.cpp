// Problem: A - A*B*C
// Contest: AtCoder - AtCoder Regular Contest 113
// URL: https://atcoder.jp/contests/arc113/tasks/arc113_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, ans = 0;
  cin >> x;
  for (int i = 1; i <= x; i++)
    for (int j = 1; i * j <= x; j++)
      for (int k = 1; i * j * k <= x; k++) {
        ans++;
      }
  cout << ans << endl;
  return 0;
}