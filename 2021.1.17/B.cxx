
// Problem: B - 矩阵变换
// Contest: Virtual Judge - 2021校际day13
// URL: https://vjudge.net/contest/418018#problem/B
// Memory Limit: 524 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int n, m, cur[500], a[500][500];
pair<int, int> idx[500];
queue<int> q;
void init() {
  memset(idx, 0, sizeof(idx));
  while (!q.empty()) q.pop();
  memset(cur, 0, sizeof(cur));
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = cur[now] + 1; i <= m; i++) {
      cur[now] = i;
      if (!a[now][i]) continue;
      if (!idx[a[now][i]].first) {
        idx[a[now][i]] = make_pair(now, i);
      } else {
        if (idx[a[now][i]].second < i) {
          q.push(idx[a[now][i]].first);
          idx[a[now][i]] = make_pair(now, i);
        } else {
          q.push(now);
        }
      }
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (idx[j].first == i) {
        printf("%d ", j);
        continue;
      }
    }
  }
  puts("");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}