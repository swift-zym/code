#include <bits/stdc++.h>
#define N 1000000
#define int long long
using namespace std;
int n, k, tot, ch[N][2], v[N], rt[N], a[N];
void pp(int x) { v[x] = max(v[ch[x][0]], v[ch[x][1]]); }
int nd(int f) {
  tot++;
  ch[tot][0] = ch[f][0], ch[tot][1] = ch[f][1], v[tot] = v[f];
  return tot;
}
void add(int &x, int f, int l, int r, int L, int R, int c) {
  if (!x) x = nd(f);
  if (l == L && r == R) {
    v[x] += c;
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid) {
    add(ch[x][0], ch[f][0], l, mid, L, R, c);
  } else if (L > mid) {
    add(ch[x][1], ch[f][1], mid + 1, r, L, R, c);
  } else {
    add(ch[x][0], ch[f][0], l, mid, L, mid, c);
    add(ch[x][1], ch[f][1], mid + 1, r, mid + 1, R, c);
  }
  pp(x);
}
void rv(int &x, int f, int l, int r, int c) {
  if (!x) x = nd(f);
  if (l == r) {
    v[x] = LLONG_MIN;
    return;
  }
  int mid = (l + r) >> 1;
  if (v[ch[f][0]] == c)
    rv(ch[x][0], ch[f][0], l, mid, c);
  else
    rv(ch[x][1], ch[f][1], mid + 1, r, c);
}
struct node {
  int x, v;
  node(int _x) {
    x = _x;
    v = ::v[rt[x]];
  }
  bool operator<(const node &t) const { return v < t.v; }
};
priority_queue<node> p;
signed main() {
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(rt[i], rt[i - 1], 1, n, mp[a[i]] + 1, i, a[i]);
    mp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) p.push(node(i));
  return 0;
}