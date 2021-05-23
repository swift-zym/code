
// Problem: C. Maximum width
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int n, m, nxt[300000][26], pre[300000][26], ans[2][300000];
string s, t;
int main() {
  cin >> n >> m >> s >> t;
  s = "$" + s;
  t = "$" + t;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= 25; j++) {
      if (s[i + 1] - 'a' == j) {
        nxt[i][j] = i + 1;
      } else {
        nxt[i][j] = nxt[i + 1][j];
      }
    }
  }
  int now = 0;
  for (int i = 1; i <= m; i++) {
    now = nxt[now][t[i] - 'a'];
    ans[0][i] = now;
  }
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 0; j <= 25; j++) {
      if (s[i - 1] - 'a' == j) {
        pre[i][j] = i - 1;
      } else {
        pre[i][j] = pre[i - 1][j];
      }
    }
  }
  now = n + 1;
  for (int i = m; i >= 1; i--) {
    now = pre[now][t[i] - 'a'];
    ans[1][i] = now;
  }
  int mx = INT_MIN;
  for (int i = 1; i < m; i++) {
    mx = max(mx, ans[1][i + 1] - ans[0][i]);
  }
  cout << mx << endl;
  return 0;
}