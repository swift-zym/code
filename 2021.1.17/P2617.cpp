// Problem: P2617 Dynamic Rankings
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2617
// Memory Limit: 512 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define N 2000000
using namespace std;
int n, m, a[100001], rt[100001], ls[N], rs[N], sum[N], tot;
void ensure(int &x) {
  if (!x) x = ++tot;
}
void pushup(int x) {
  sum[x] = 0;
  if (ls[x]) sum[x] += sum[ls[x]];
  if (rs[x]) sum[x] += sum[rs[x]];
}
void modify(int x, int l, int r, int pos, int v) {
  if (l == r) {
    sum[x] += v;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    ensure(ls[x]);
    modify(ls[x], l, mid, pos, v);
  } else {
    ensure(rs[x]);
    modify(rs[x], mid + 1, r, pos, v);
  }
  pushup(x);
}
void modify(int x, int v) {
  int bk = a[x];
  a[x] = v;
  for (; x <= n; x += x & -x) {
    modify(rt[x], 1, n + m, bk, -1);
    modify(rt[x], 1, n + m, v, 1);
  }
}
vector<int> root[2];
int query(int l, int r, int k) {
  if (l == r) return l;
  int v = 0, mid = (l + r) >> 1;
  for (auto rt : root[0]) v -= sum[ls[rt]];
  for (auto rt : root[1]) v += sum[ls[rt]];
  if (k <= v) {
    for (auto &&rt : root[0]) rt = ls[rt];
    for (auto &&rt : root[1]) rt = ls[rt];
    return query(l, mid, k);
  } else {
    for (auto &&rt : root[0]) rt = rs[rt];
    for (auto &&rt : root[1]) rt = rs[rt];
    return query(mid + 1, r, k - v);
  }
}
int query_list(int l, int r, int k) {
  root[0].clear();
  root[1].clear();
  for (int x = l - 1; x; x -= x & -x) root[0].push_back(x);
  for (int x = r; x; x -= x & -x) root[1].push_back(x);
  return query(1, m + n, k);
}
struct option {
  int opt, x, y, z;
};
vector<option> q;
set<int> st;
map<int, int> mp, re;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) ensure(rt[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    st.insert(a[i]);
  }
  for (int i = 1; i <= m; i++) {
    char c = getchar();
    while (c != 'Q' && c != 'C') c = getchar();
    if (c == 'Q') {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      q.push_back({0, l, r, k});
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      st.insert(y);
      q.push_back({1, x, y, 0});
    }
  }
  int tot = 0;
  for (auto v : st) {
    mp[v] = ++tot;
    re[tot] = v;
  }
  for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
  for (auto &&cur : q) {
    if (cur.opt) {
      cur.y = mp[cur.y];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int x = i; x <= n; x += x & -x) {
      modify(rt[x], 1, n + m, a[i], 1);
    }
  }
  for (auto &&cur : q) {
    if (cur.opt) {
      modify(cur.x, cur.y);
    } else {
      int idx = query_list(cur.x, cur.y, cur.z);
      printf("%d\n", re[idx]);
    }
  }
  return 0;
}