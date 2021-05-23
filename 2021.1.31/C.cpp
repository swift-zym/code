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
int T, n, m, e, vis_num, num, head[1000000], nxt[1000000], to[1000000], cnt,
    vis[1000000], v[1000000], out[1000000], i;
void add(int a, int b, bool _rev = false) {
  nxt[++cnt] = head[a], to[cnt] = b, head[a] = cnt;
  if (!_rev) add(b, a, 1);
}
void link(int a, int b) {
  vis[vis[a]] = vis[vis[b]] = 0, vis[a] = b, vis[b] = a;
}
int bel[1000000], vis_bel[1000000];
int du[1000000], idx[1000000];
bool cmp(int a, int b) { return du[a] < du[b]; }
int main() {
  cin >> T;
  while (T--) {
    cnt = vis_num = 0;
    memset(vis, 0, sizeof(vis));
    memset(vis_bel, 0, sizeof(vis_bel));
    memset(head, 0, sizeof(head));
    memset(out, 0, sizeof(out));
    memset(du, 0, sizeof(du));
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
      int u, v;
      cin >> u >> v;
      int s = n + (v - 1) * 3;
      add(u, s + 1);
      add(u, s + 2);
      add(u, s + 3);
      du[u]++;
    }
    int tot = n + m * 3, ans = 0, _ = 1;
    for (int i = 1; i <= m; i++) {
      int s = n + (i - 1) * 3;
      bel[s + 1] = bel[s + 2] = bel[s + 3] = i;
      add(s + 1, s + 2);
      add(s + 2, s + 3);
      add(s + 3, s + 1);
      /*link(s + 1, s + 2);
      ans++;*/
    }
    for (int i = 1; i <= n; i++) idx[i] = i;
    sort(idx + 1, idx + n + 1, cmp);
    for (int _ = 1; _ <= n; _++) {
      int i = idx[_];
      cerr << du[i] << endl;
      for (int j = head[i]; j; j = nxt[j]) {
        if (!vis_bel[bel[to[j]]]) {
          vis_bel[bel[to[j]]] = 1;
          vis_num++;
          ans++;
          link(i, to[j]);
          break;
        }
      }
    }
    cout << vis_num << endl;
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