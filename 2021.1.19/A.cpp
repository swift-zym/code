
// Problem: A. Three swimmers
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/0
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
int solve(int x, int y) { return x % y == 0 ? x : x + (y - (x % y)); }
signed main() {
  cin >> T;
  while (T--) {
    int p, a, b, c;
    cin >> p >> a >> b >> c;
    cout << min(solve(p, a), min(solve(p, b), solve(p, c))) - p << endl;
  }
  return 0;
}