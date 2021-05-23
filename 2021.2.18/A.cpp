// Problem: A. Anti-knapsack
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = k + 1; i <= n; i++) {
      ans.push_back(i);
    }
    for (int i = k - 1; i >= k / 2 + (k % 2); i--) {
      ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}