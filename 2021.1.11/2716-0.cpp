#include <bits/stdc++.h>
#define int long long
using namespace std;
struct area {
  int x, y, xx, yy;
};
struct line {
  int y, yy, x, type;
  bool operator<(const line &l) const { return x < l.x; }
};
vector<area> v;
vector<line> l;
int tag[1000000], val[1000000];
void pushup(int now, int l, int r) {
  if (!tag[now])
    val[now] = val[now * 2] + val[now * 2 + 1];
  else
    val[now] = r - l + 1;
}
int query(int now, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return val[now];
  }
  int mid = (l + r) / 2;
  if (R <= mid)
    return query(now * 2, l, mid, L, R);
  else if (L > mid)
    return query(now * 2 + 1, mid + 1, r, L, R);
  else
    return query(now * 2, l, mid, L, mid) +
           query(now * 2 + 1, mid + 1, r, mid + 1, R);
}
void modify(int now, int l, int r, int L, int R, int v) {
  if (l == L && r == R) {
    tag[now] += v;
    pushup(now, l, r);
    return;
  }
  int mid = (l + r) / 2;
  if (R <= mid)
    modify(now * 2, l, mid, L, R, v);
  else if (L > mid)
    modify(now * 2 + 1, mid + 1, r, L, R, v);
  else {
    modify(now * 2, l, mid, L, mid, v);
    modify(now * 2 + 1, mid + 1, r, mid + 1, R, v);
  }
  pushup(now, l, r);
}
void solve() {
  for (auto a : v) {
    l.push_back({a.y, a.yy, a.x, 1});
    l.push_back({a.y, a.yy, a.xx + 1, -1});
  }
  sort(l.begin(), l.end());
  int lst = -1, val = -1, ans = 0;
  vector<line> tmp;
  for (auto s : l) {
    if (s.x == val) {
      tmp.push_back(s);
      continue;
    }
    if (tmp.size()) {
      ans += query(1, 0, 100000, 0, 100000) * (val - lst);
      for (auto i : tmp) {
        modify(1, 0, 100000, i.y, i.yy, i.type);
      }
      tmp.clear();
    }
    lst = val;
    val = s.x;
    tmp.push_back(s);
  }
  if (tmp.size()) {
    ans += query(1, 0, 100000, 0, 100000) * (val - lst);
    for (auto i : tmp) {
      modify(1, 0, 100000, i.y, i.yy, i.type);
    }
    tmp.clear();
  }
  printf("%lld\n", ans);
}
void init() {
  v.clear();
  l.clear();
  memset(tag, 0, sizeof(tag));
}
signed main() {
  int x, y, xx, yy;
  while (scanf("%lld%lld%lld%lld", &x, &y, &xx, &yy) != EOF) {
    if (x == -1 && y == -1 && xx == -1 && yy == -1) {
      if (!v.size()) break;
      solve();
      init();
    } else
      v.push_back({x, y, xx - 1, yy - 1});
  }
  return 0;
}