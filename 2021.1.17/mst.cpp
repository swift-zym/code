#include <bits/stdc++.h>
#define N 200
using namespace std;
int n, m, r, fa[N], mn[N], bel[N], vis[N], ans;
vector<pair<int, pair<int, int>>> e;
int main() {
  cin >> n >> m >> r;
  while (m--) {
    int a, b, l;
    cin >> a >> b >> l;
    e.push_back(make_pair(a, make_pair(b, l)));
  }
  int T = 0;
  while (1) {
    memset(mn, 0x3f, sizeof(mn));
    memset(bel, 0, sizeof(bel));
    memset(fa, 0, sizeof(bel));
    memset(vis, 0, sizeof(vis));
    mn[r] = 0;
    for (auto pr : e) {
      if (pr.first != pr.second.first &&
          pr.second.second < mn[pr.second.first]) {
        mn[pr.second.first] = pr.second.second;
        fa[pr.second.first] = pr.first;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != r && !fa[i]) {
        puts("-1");
        return 0;
      }
      if (i != r) {
        ans += mn[i];
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (i == r) continue;
      int x = i;
      while (!bel[x] && x != r && vis[x] != i) {
        vis[x] = i;
        x = fa[x];
      }
      if (x != r && !bel[x]) {
        cnt++;
        int y = x;
        do {
          bel[y] = cnt;
          y = fa[y];
        } while (y != x);
      }
    }
    if (!cnt) break;
    for (int i = 1; i <= n; i++) {
      if (!bel[i]) bel[i] = ++cnt;
    }
    for (auto &&pr : e) {
      if (bel[pr.first] != bel[pr.second.first]) {
        pr.second.second -= mn[pr.second.first];
      }
      pr.first = bel[pr.first];
      pr.second.first = bel[pr.second.first];
    }
    n = cnt;
    r = bel[r];
  }
  cout << ans << endl;
  return 0;
}