// Problem: AT2675 [AGC018F] Two Trees
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT2675
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define N 3000000
using namespace std;
vector<int> v[N];
int n, cnt = 1, s[N], t[N], le[N], deg[N], ans[N], vis[N], rt1, rt2;
void add(int a, int b, int l) {
  s[++cnt] = a;
  t[cnt] = b;
  le[cnt] = l;
  v[a].push_back(cnt);
  v[b].push_back(cnt);
  deg[a]++;
  deg[b]++;
}
void dfs(int x) {
  while (!v[x].empty()) {
    int id = v[x].back(), to = (s[id] ^ t[id] ^ x), len = le[id];
    v[x].pop_back();
    if (vis[id]) {
      vis[id] = 1;
      if (len) {
        ans[min(x, to)] = (x < to ? 1 : -1);
      }
      dfs(to);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int f;
    cin >> f;
    if (f == -1)
      rt1 = i;
    else
      add(f, i, 0);
  }
  for (int i = 1; i <= n; i++) {
    int f;
    cin >> f;
    if (f == -1)
      rt2 = i;
    else
      add(f + n, i + n, 0);
  }
  add(rt1, rt2 + n, 0);
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 2 != deg[i + n] % 2) {
      cout << "IMPOSSIBLE" << endl;
      goto ed;
    }
    if (deg[i] % 2) {
      add(i, i + n, 1);
    }
  }
  cout << "POSSIBLE" << endl;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
ed:;
  return 0;
}