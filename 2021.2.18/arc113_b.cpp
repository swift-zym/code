// Problem: B - A^B^C
// Contest: AtCoder - AtCoder Regular Contest 113
// URL: https://atcoder.jp/contests/arc113/tasks/arc113_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a, int b) {
  if (b == 0) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % 4 * a % 4 : tmp * tmp % 4;
}
signed main() {
  int a, b, c, v[4];
  cin >> a >> b >> c;
  v[1] = a % 10;
  v[2] = a * v[1] % 10;
  v[3] = a * v[2] % 10;
  v[0] = a * v[3] % 10;
  cout << v[qpow(b, c)] << endl;
  return 0;
}