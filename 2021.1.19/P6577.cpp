
// Problem: P6577 【模板】二分图最大权完美匹配
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6577
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define N 1000
int g[1000][1000], match[1000], pre[1000], mp[1000];
void update(int x) {
  if (!i) return;
  int nxt = mp[pre[x]];
  match[x] = pre[x];
  mp[pre[x]] = x;
  update(nxt);
}
void bfs(int s) { queue<int> q; }