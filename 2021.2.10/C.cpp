// Problem: C. Minimum Ties
// Contest: Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1487/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int T, n;
int vis[101], ans[101][101];
int main() {
  cin >> T;
  while (T--) {
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for (int i = 1; i <= (n % 2 ? n / 2 + 1 : n / 2 - 1); i++) {
      memset(vis, 0, sizeof(vis));
      for (int k = 1; !vis[k]; k++) {
        int nxt;
        for (int j = k; !vis[j]; j = nxt) {
          vis[j] = 1;
          nxt = j + i;
          if (nxt > n) nxt -= n;
          if (nxt > j)
            ans[j][nxt] = 1;
          else
            ans[nxt][j] = -1;
        }
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        cout << ans[i][j] << " ";
      }
    cout << endl;
  }
  return 0;
}
// 1 3 5 2 4
// 2 4 1 3 5