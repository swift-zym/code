#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ls c[x][0]
#define rc c[x][1]
int f[N], c[N][2], v[N], s[N], tag[N];
bool notroot(int x) { return c[f[x]][0] == x || c[f[x]][1] == x; }
void pushup(int x) { s[x] = s[ls] ^ s[rc] ^ v[x]; }
void reverse(int x) {
  int t = ls;
  ls = rc;
  rc = t;
  tag[x] ^= 1;
}
void pushdown(int x) {
  if (tag[x]) {
    if (ls) reverse(ls);
    if (rc) reverse(rc);
    tag[x] = 0;
  }
}
void rotate(int x) {
  int y = f[x], z = f[y], k = (c[y][1] == x), w = c[x][!k];
  if (notroot(y)) c[z][c[z][1] == y] = x;
  c[x][!k] = y;
  c[y][k] = w;
  if (w) f[w] = y;
  f[y] = x;
  f[x] = z;
  pushup(y);
}
void pushall(int x) {
  if (notroot(x)) pushall(f[x]);
  pushdown(x);
}
void splay(int x) {
  pushall(x);
  while (notroot(x)) {
    int y = f[x], z = f[y];
    if (notroot(y)) {
      rotate(((c[y][x] == 0) != (c[z][0] == y)) ? x : y);
    }
    rotate(x);
  }
  pushup(x);
}
void access(int x) {
  for (int y = 0; x; y = x, x = f[x]) splay(x), rc = y, pushup(x);
}
void makeroot(int x) {
  access(x);
  splay(x);
  reverse(x);
}
int findroot(int x) {
  access(x);
  splay(x);
  while (ls) pushdown(x), x = ls;
  splay(x);
  return x;
}
void split(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
}
void link(int x, int y) {
  makeroot(x);
  if (findroot(y) != x) f[x] = y;
}
void cut(int x, int y) {
  makeroot(x);
  if (findroot(y) == x && f[y] == x && c[y][0] == 0) {
    f[y] = c[x][1] = 0;
    pushup(x);
  }
}
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 0) {
      split(x, y);
      cout << s[y] << endl;
    } else if (opt == 1) {
      link(x, y);
    } else if (opt == 2) {
      cut(x, y);
    } else {
      splay(x);
      v[x] = y;
    }
  }
  return 0;
}