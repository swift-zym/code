// Problem: F. Copy or Prefix Sum
// Contest: Codeforces - Codeforces Round #701 (Div. 2)
// URL: https://codeforces.com/contest/1485/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// v v v s s s v
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int T, n, a[1000000], sum[1000000], dp[1000000];
map<int, int> mp;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      sum[i] = sum[i + 1] + a[i];
    }
    for (int i = 2; i <= n; i++) {
      for (auto x : mp) {
        if (x.first - sum[i]) {
          mp[x.first] = x.second * 2;
        }
      }
      mp[sum[i]] = mp[sum[i]] + 1;
    }

    for (auto x : mp) {
      cout << x.first << " " << x.second << endl;
      dp[0] += x.second;
    }
    cout << dp[0] << endl;
  }
  return 0;
}
// 2 -1 1
// 2 -1 -2
// 2 -3 1
// 2 -3 2