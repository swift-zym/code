// Problem: E - Train
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, x, y, cnt;
int head[100001], nxt[200001], to[200001], len[200001], v[200001], ans[200001];
void add(int a, int b, int l, int x) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  head[a] = cnt;
  len[cnt] = l;
  v[cnt] = x;
}
struct node {
  int x, v;
  bool operator<(const node &t) const { return v > t.v; }
};
priority_queue<node> q;
int fix(int x, int k) { return x % k ? k - (x % k) : 0; }
signed main() {
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    add(a, b, t, k);
    add(b, a, t, k);
  }
  q.push({x, 0});
  for (int i = 1; i <= n; i++) ans[i] = LLONG_MAX;
  ans[x] = 0;
  while (!q.empty()) {
    node now = q.top();
    q.pop();
    if (ans[now.x] != now.v) continue;
    for (int i = head[now.x]; i; i = nxt[i]) {
      int val = fix(ans[now.x], v[i]) + len[i];
      if (ans[to[i]] > ans[now.x] + val) {
        ans[to[i]] = ans[now.x] + val;
        q.push({to[i], ans[to[i]]});
      }
    }
  }
  if (ans[y] == LLONG_MAX)
    puts("-1");
  else
    cout << ans[y] << endl;
  return 0;
}