// Problem: #2882. 「JOISC 2014 Day4」两个人的星座
// Contest: LibreOJ
// URL: https://loj.ac/p/2882
// Memory Limit: 256 MB
// Time Limit: 9000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, type;
  double val;
  bool operator<(const node &t) const {
    if (val != t.val) return val < t.val;
    return x < t.x;
  }
} v[10000];
int cnt, n, x[3001], y[3001], c[3001], col[6], vis[3001], use[3001];
long long ans;
inline void add(int ca, int cb) {
  long long tmp = 1;

  if (ca != 0) tmp *= col[0];

  if (ca != 1) tmp *= col[1];

  if (ca != 2) tmp *= col[2];

  if (cb != 0) tmp *= col[3];

  if (cb != 1) tmp *= col[4];

  if (cb != 2) tmp *= col[5];

  ans += tmp;
}
signed main() {
  ios::sync_with_stdio(0);
  cin >> n;

  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> c[i];

  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    memset(use, 0, sizeof(use));
    memset(col, 0, sizeof(col));
    cnt = -1;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        v[++cnt] = {x[i] - x[j], y[i] - y[j], j,
                    atan2(y[i] - y[j], x[i] - x[j])};
        v[++cnt] = {x[j] - x[i], y[j] - y[i], -j,
                    atan2(y[j] - y[i], x[j] - x[i])};
      }
    }

    sort(v, v + cnt + 1);
    int num = n - 1;

    for (int _ = 1; _ <= 2; _++) {
      for (int j = 0; j <= cnt; j++) {
        if (v[j].type > 0) {
          int id = v[j].type;

          if (!vis[id])
            num--;
          else
            col[c[id] + 3]--;

          col[c[id]]++;
          vis[id] = 1;

          if (!num && !use[id]) {
            use[id] = 1;
            col[c[id]]--;
            add(c[id], c[i]);
            col[c[id]]++;
          }
        } else {
          int id = -v[j].type;

          if (!vis[id])
            num--;
          else
            col[c[id]]--;

          col[c[id] + 3]++;
          vis[id] = 1;
        }
      }
    }
  }

  cout << ans / 2 << endl;
  return 0;
}