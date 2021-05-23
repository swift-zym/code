#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
namespace flow {
int head[700], nxt[1000000], len[1000000], to[1000000], cnt = -1;
int cur[1000000];
void add(int a, int b, int l, bool _rev = false) {
  nxt[++cnt] = head[a];
  to[cnt] = b;
  len[cnt] = l;
  head[a] = cnt;
  if (!_rev) add(b, a, 0, true);
}
int lev[700];
bool bfs(int s, int t) {
  for (int i = s; i <= t; i++) {
    lev[i] = inf;
    cur[i] = head[i];
  }
  lev[s] = 0;
  queue<int> q;
  q.push(s);
  bool flag = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == t) flag = 1;
    for (int i = head[now]; i != -1; i = nxt[i]) {
      if (lev[to[i]] == inf && len[i]) {
        lev[to[i]] = lev[now] + 1;
        q.push(to[i]);
      }
    }
  }
  return flag;
}
int s, t;
int dfs(int now, int flow) {
  if (now == t) return flow;
  int use = 0;
  for (int i = cur[now]; i != -1 && flow; i = nxt[i]) {
    cur[now] = i;
    if (lev[to[i]] == lev[now] + 1 && len[i]) {
      int val = dfs(to[i], min(flow, len[i]));
      if (!val) lev[to[i]] = inf;
      flow -= val;
      use += val;
      len[i] -= val;
      len[i ^ 1] += val;
    }
  }
  return use;
}
void init() {
  cnt = -1;
  memset(head, -1, sizeof(head));
}
void solve(int mx) {
  s = 0;
  t = mx + 1;
  int ans = 0;
  while (bfs(s, t)) {
    ans += dfs(s, inf);
  }
}
int get(int x) {
  for (int i = head[x]; i != -1; i = nxt[i]) {
    if (to[i] == s) continue;
    if (!len[i]) return to[i];
  }
  return 0;
}
}  // namespace flow
int T, n, m, e, vis_num, num, head[1000000], nxt[1000000], to[1000000], cnt,
    vis[1000000], v[1000000], out[1000000], i;
void add(int a, int b, bool _rev = false) {
  nxt[++cnt] = head[a], to[cnt] = b, head[a] = cnt;
  if (!_rev) add(b, a, 1);
}
void link(int a, int b) {
  vis[vis[a]] = vis[vis[b]] = 0, vis[a] = b, vis[b] = a;
}
int main() {
  srand(time(0));
  cin >> T;
  while (T--) {
    cnt = vis_num = 0;
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    memset(out, 0, sizeof(out));
    cin >> n >> m >> e;
    flow::init();
    for (int i = 1; i <= e; i++) {
      int u, v;
      cin >> u >> v;
      int s = n + (v - 1) * 3;
      add(u, s + 1);
      add(u, s + 2);
      add(u, s + 3);
      flow::add(u, n + v, 1);
    }
    for (int i = 1; i <= m; i++) {
      int s = n + (i - 1) * 3;
      add(s + 1, s + 2);
      add(s + 2, s + 3);
      add(s + 3, s + 1);
    }
    for (int i = 1; i <= n; i++) {
      flow::add(0, i, 1);
    }
    for (int i = n + 1; i <= n + m; i++) {
      flow::add(i, n + m + 1, 1);
    }
    flow::solve(n + m);
    int tot = n + m * 3, ans = 0, _ = 1;
    for (int i = 1; i <= n; i++) {
      int tmp = flow::get(i);
      if (tmp) {
        link((tmp - n - 1) * 3 + n + 1, i);
        vis_num++;
        ans++;
      }
    }
    if (vis_num == n) memcpy(out, vis, sizeof(int) * (tot + 1));
    while (++_ <= 200000 || !out[1]) {
      for (num = 0, i = 1; i <= tot; i++)
        if (!vis[i]) v[++num] = i;
      // cout << ans << " " << num << endl;
      if (!num) break;
      int now = v[1] <= n ? v[1] : v[rand() % num + 1];
      vis_num += now <= n, num = 0;
      for (i = head[now]; i; i = nxt[i]) {
        // cout << now << " " << to[i] << endl;
        if (!vis[to[i]]) {
          ans++;
          link(now, to[i]);
          if (to[i] <= n) vis_num++;
          goto ed;
        } else
          v[++num] = to[i];
      }
      {
        int to = v[rand() % num + 1];
        vis_num -= (vis[to] <= n);
        link(now, to);
      }
    ed:
      if (vis_num == n) memcpy(out, vis, sizeof(int) * (tot + 1));
    }
    cout << ans - n << endl;
    for (i = 1; i <= n; i++) {
      cout << (out[i] - n - 1) / 3 + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}