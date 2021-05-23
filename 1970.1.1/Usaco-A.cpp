#include <bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
/*segement tree*/
int tot, rt[N], s[N], num[N], ls[N], rs[N];
int gls(int x) { return ls[x] ? ls[x] : ls[x] = ++tot; }
int grs(int x) { return rs[x] ? rs[x] : rs[x] = ++tot; }
void add(int x, int l, int r, int pos) {
  s[x] += pos;
  num[x]++;
  int mid = (l + r) >> 1;
  if (pos <= mid)
    add(gls(x), l, mid, pos);
  else
    add(grs(x), mid + 1, r, pos);
}
int qs(int x, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (l == L && r == R) return s[x];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return ls[x] ? qs(ls[x], l, mid, L, R) : 0;
  else if (L > mid)
    return rs[x] ? qs(rs[x], mid + 1, r, L, R) : 0;
  else
    return (ls[x] ? qs(ls[x], l, mid, L, mid) : 0) +
           (rs[x] ? qs(rs[x], mid + 1, r, mid + 1, R) : 0);
}
int qn(int x, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (l == L && r == R) return num[x];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return ls[x] ? qs(ls[x], l, mid, L, R) : 0;
  else if (L > mid)
    return rs[x] ? qs(rs[x], mid + 1, r, L, R) : 0;
  else
    return (ls[x] ? qs(ls[x], l, mid, L, mid) : 0) +
           (rs[x] ? qs(rs[x], mid + 1, r, mid + 1, R) : 0);
}
/*main function*/
int n, a[N], l[N], r[N], lst[N];
int lqs(int x, int v) {
  int ans = 0;
  for (; x; x -= x & -x) {
    ans += qs(rt[x], 1, N, v + 1, N);
  }
  return ans;
}
int lqn(int x, int v) {
  int ans = 0;
  for (; x; x -= x & -x) {
    ans += qn(rt[x], 1, N, v + 1, N);
  }
  return ans;
}
int query(int l, int r, int v) {
  return lqs(r, v) - lqs(l - 1, v) - (lqn(r, v) - lqn(l - 1, v)) * v;
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    l[i] = lst[a[i]] + 1;
    lst[a[i]] = i;
    rt[i] = i;
  }
  tot = n;
  fill(lst + 1, lst + N, n + 1);
  for (int i = n; i >= 1; i--) {
    r[i] = lst[a[i]] - 1;
    lst[a[i]] = i;
    for (int j = i; j <= n; j += j & -j) {
      add(rt[j], 1, N, a[i]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (l[i] > i - 1) continue;
    ans += query(l[i], i - 1, a[i]);
  }
  cout << ans << endl;
  return 0;
}