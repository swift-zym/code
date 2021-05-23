#include <bits/stdc++.h>
#define N 20000000
#define ud unsigned int
using namespace std;
int n, k, tot, pos, ch[N][2], s[N], rt[N], ed[N];
ud a[N];
int nd(int f) {
  tot++;
  ch[tot][0] = ch[f][0], ch[tot][1] = ch[f][1], s[tot] = s[f] + 1;
  return tot;
}
void insert(int &x, int f, int d, ud v, int id) {
  x = nd(f);
  if (!~d) {
    ed[x] = id;
    return;
  }
  int c = (v & (1u << d)) ? 1 : 0;
  insert(ch[x][c], ch[f][c], d - 1, v, id);
}
ud query(int x, int y, int d, ud v) {
  if (!~d) {
    pos = ed[y];
    return 0;
  }
  int c = (v & (1u << d)) ? 1 : 0;
  if (s[ch[y][c ^ 1]] - s[ch[x][c ^ 1]])
    return query(ch[x][c ^ 1], ch[y][c ^ 1], d - 1, v) + (1u << d);
  else if (s[ch[y][c]] - s[ch[x][c]])
    return query(ch[x][c], ch[y][c], d - 1, v);
  else {
    cerr << x << " " << y << " " << d << " " << v << endl;
    exit(1);
  }
}
struct node {
  int l, r, mx, id;
  ud v;
  node(int _l, int _r, int _mx) {
    l = _l, r = _r;
    mx = _mx;
    v = query(rt[l - 1], rt[r], 31, a[mx]);
    id = ::pos + 1;
  }
  bool operator<(const node &rhs) const { return v < rhs.v; }
};
priority_queue<node> p;
unsigned long long ans;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    insert(rt[i + 1], rt[i], 31, a[i], i);
  }
  for (int i = 1; i <= n; i++) p.push(node(1, i, i));
  for (int i = 1; i <= k; i++) {
    node x = p.top();
    p.pop();
    ans += x.v;
    if (x.l < x.id) p.push(node(x.l, x.id - 1, x.mx));
    if (x.id < x.r) p.push(node(x.id + 1, x.r, x.mx));
  }
  cout << ans << endl;
  return 0;
}