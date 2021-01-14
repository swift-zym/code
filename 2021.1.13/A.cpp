#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[100][100];
int l(list<int> s) {
  int r = 0;
  for (auto x : s) {
    r = max(r, x);
  }
  return r;
}
int vis[100][100], use[100][100];
pair<int, int> s(int v) {
  int x = 1;
  while (v > x) {
    v -= x;
    x++;
  }
  return make_pair(x, v);
}
int count(int x, int y, int w = -1, int t = 0) {
  int ans = a[x][y];
  use[x][y] = 1;
  if (vis[x + 1][y + 1] && (w == -1 || w == 0 || t + 1 < k) &&
      !use[x + 1][y + 1])
    ans += count(x + 1, y + 1, 0, (w == -1 || w == 0) ? t : t + 1);
  if (vis[x + 1][y] && (w == -1 || w == 1 || t + 1 < k) && !use[x + 1][y])
    ans += count(x + 1, y, 1, (w == -1 || w == 1) ? t : t + 1);
  return ans;
}
int dfs(int deep) {
  int ans = 0;
  if (deep == n * (n + 1) / 2 + 1) {
    memset(use, 0, sizeof(use));
    return count(1, 1);
  }
  auto pos = s(deep);
  vis[pos.first][pos.second] = 1;
  ans = max(ans, dfs(deep + 1));
  vis[pos.first][pos.second] = 0;
  ans = max(ans, dfs(deep + 1));
  return ans;
}
signed main() {
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int T;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld", &n, &k);
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        scanf("%lld", &a[i][j]);
      }
    }
    if (k == 1) {
      int sum = 0, mx = 0, x = 1, y = 1;
      for (int i = 2; i <= n; i++) {
        x++;
        sum += a[x][y];
        mx = max(mx, sum);
      }
      int ans = mx;
      sum = 0, mx = 0, x = 1, y = 1;
      for (int i = 2; i <= n; i++) {
        x++;
        y++;
        sum += a[x][y];
        mx = max(mx, sum);
      }
      printf("%lld\n", ans + mx);
    } else {
      vis[1][1] = 1;
      printf("%lld\n", dfs(2));
    }
  }
  return 0;
}