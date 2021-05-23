#include <bits/stdc++.h>
#define N 1000000
#define pr pair<int, pair<int, int>>
#define fi first
#define se second.first
#define th second.second
#define mp(a, b, c) make_pair(a, make_pair(b, c))
using namespace std;
int T, n, m, mx[N], tag[N], a[N];
void pushdown(int x) {
  mx[x << 1] += tag[x];
  mx[x << 1 | 1] += tag[x];
  tag[x << 1] += tag[x];
  tag[x << 1 | 1] += tag[x];
  tag[x] = 0;
}
void pushup(int x) { mx[x] = max(mx[x << 1], mx[x << 1 | 1]); }
void add(int x, int l, int r, int L, int R, int v) {
  if (l == L && r == R) {
    mx[x] += v;
    tag[x] += v;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (R <= mid)
    add(x << 1, l, mid, L, R, v);
  else if (L > mid)
    add(x << 1 | 1, mid + 1, r, L, R, v);
  else {
    add(x << 1, l, mid, L, mid, v);
    add(x << 1 | 1, mid + 1, r, mid + 1, R, v);
  }
  pushup(x);
}
void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pushup(x);
}
int query(int x, int l, int r, int L, int R) {
  if (l == L && r == R) return mx[x];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(x << 1, l, mid, L, R);
  else if (L > mid)
    return query(x << 1 | 1, mid + 1, r, L, R);
  else
    return max(query(x << 1, l, mid, L, mid),
               query(x << 1 | 1, mid + 1, r, mid + 1, R));
}
int main() {
  scanf("%d", &T);
  while (T--) {
    memset(mx, 0, sizeof(mx));
    memset(a, 0, sizeof(a));
    memset(tag, 0, sizeof(tag));
    scanf("%d%d", &n, &m);
    vector<pr> v;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int l, r, a;
      scanf("%d%d%d", &l, &r, &a);
      if (l <= r) {
        v.push_back(mp(l, r, a));
        v.push_back(mp(l + m, r + m, a));
      } else {
        v.push_back(mp(l, r + m, a));
      }
      sum += a;
    }
    if (sum > m) {
      puts("No");
      continue;
    }
    sort(v.begin(), v.end(), [](pr a, pr b) { return a.se < b.se; });
    set<int> st;
    map<int, int> mp, re;
    for (auto x : v) {
      st.insert(x.fi);
    }
    int cnt = 0;
    for (auto x : st) {
      cnt++;
      mp[x] = cnt;
      re[cnt] = x;
    }
    for (auto &&x : v) {
      a[mp[x.fi]] = x.fi;
      x.fi = mp[x.fi];
    }
    build(1, 1, cnt);
    bool flag = 1;
    for (auto x : v) {
      add(1, 1, cnt, 1, x.fi, x.th);
      if (x.se + 1 < query(1, 1, cnt, 1, x.fi)) flag = 0;
    }
    if (!flag) {
      puts("No");
    } else {
      puts("Yes");
    }
  }
  return 0;
}