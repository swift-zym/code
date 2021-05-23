// Problem: C - String Invasion
// Contest: AtCoder - AtCoder Regular Contest 113
// URL: https://atcoder.jp/contests/arc113/tasks/arc113_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
#define int long long
using namespace std;
int sum[1000000][26];
signed main() {
  string s;
  cin >> s;
  for (int i = s.length() - 1; ~i; i--) {
    for (int j = 0; j < 26; j++) {
      sum[i][j] = sum[i + 1][j] + (s[i] - 'a' == j);
    }
  }
  int lst = s.length(), ans = 0, col = -1;
  for (int i = s.length() - 3; ~i; i--) {
    if (s[i] == s[i + 1]) {
      if (col != s[i] - 'a') {
        ans += s.length() - i - 2 -
               (sum[i + 2][s[i] - 'a'] - sum[lst][s[i] - 'a']);
      } else {
        if (lst != i + 1)
          ans += lst - (i + 1) - 1 -
                 (sum[i + 2][s[i] - 'a'] - sum[lst][s[i] - 'a']);
      }
      lst = i;
      col = s[i] - 'a';
    }
  }
  cout << ans << endl;
  return 0;
}