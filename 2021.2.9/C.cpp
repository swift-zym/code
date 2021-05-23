//
// Created by swift on 2020/7/21.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
char s[2000000];
struct SAM {
  struct node {
    unordered_map<int, int> go;
    int fail, val, ans;
  } a[2000000];
  int cnt = 1, last = 1;
  int tmp[2000000];
  int id[2000000];
  int solve() {
    for (int i = 1; i <= cnt; i++) tmp[a[i].val]++;
    for (int i = 1; i <= cnt; i++) tmp[i] += tmp[i - 1];
    for (int i = 1; i <= cnt; i++) id[tmp[a[i].val]--] = i;
    int mx = -1;
    for (int i = cnt; i >= 1; i--) {
      int now = id[i];
      if (a[now].ans != 1) mx = max(mx, a[now].val * a[now].ans);
      a[a[now].fail].ans += a[now].ans;
    }
    return mx;
  }
  void add(int x) {
    int p = last;
    int np = ++cnt;
    a[np].val = a[p].val + 1;
    a[np].ans = 1;
    last = np;
    while (p && a[p].go[x] == 0) {
      a[p].go[x] = np;
      p = a[p].fail;
    }
    if (!p) {
      a[np].fail = 1;
      return;
    }
    int q = a[p].go[x];
    if (a[q].val == a[p].val + 1) {
      a[np].fail = q;
      return;
    }
    int nq = ++cnt;
    a[nq].val = a[p].val + 1;
    a[nq].go = a[q].go;
    a[nq].fail = a[q].fail;
    a[q].fail = nq;
    a[np].fail = nq;
    while (p && a[p].go[x] == q) {
      a[p].go[x] = nq;
      p = a[p].fail;
    }
  }
} sam;
signed main() {
  freopen("sub.in", "r", stdin);
  freopen("sub.out", "w", stdout);
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    sam.add(s[i] - 'a');
  }
  printf("%lld\n", sam.solve());
  return 0;
}