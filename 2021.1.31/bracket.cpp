#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt, ans;
int head[1300000], to[1300000], nxt[1300000], len[1300000], typ[1300000],
    vis[1300000];
void add(int a, int b, int l, int t) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  typ[cnt] = t;
  head[a] = cnt;
}
void file() {
  freopen("bracket.in", "r", stdin);
  freopen("bracket.out", "w", stdout);
}
void dfs(int now, int deep, int v1, int v2) {
  if (v1 < 0 || v2 < 0) return;
  if (v1 == 0 && v2 == 0) vis[now] = 1;
  if (deep == 21) return;
  for (int i = head[now]; i; i = nxt[i]) {
    if (typ[i] == 1) {
      dfs(to[i], deep + 1, v1 + len[i], v2);
    } else {
      dfs(to[i], deep + 1, v1, v2 + len[i]);
    }
  }
}
int main() {
  file();
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, 1, w);
    add(v, u, -1, w);
  }
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    dfs(i, i, 0, 0);
    for (int j = i + 1; j <= n; j++) {
      if (vis[j]) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}