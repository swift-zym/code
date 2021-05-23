#include <bits/stdc++.h>
#define N 2000000
#define ls ch[x][0]
#define rs ch[x][1]
using namespace std;
int v[N], ch[N][2], f[N], s[N][2];
void pushr(int x) {
  if (!x) return;
  swap(ls, rs);
  s[x][0] ^= 1;
}
void pusha(int x, int val) {
  if (!x) return;
  s[x][1] += val;
  v[x] += val;
}
void pushdown(int x) {
  if (s[x][1]) {
    pusha(ls, s[x][1]);
    pusha(rs, s[x][1]);
    s[x][1] = 0;
  }
  if (s[x][0]) {
    pushr(ls);
    pushr(rs);
    s[x][0] = 0;
  }
}
bool isroot(int x) { return ch[f[x]][0] != x && ch[f[x]][1] != x; }
void pushall(int x) {
  if (!isroot(x)) pushall(f[x]);
  pushdown(x);
}
void rotate(int x) {
  int y = f[x], z = f[y], k = (ch[y][1] == x), w = ch[x][k ^ 1];
  ch[x][k ^ 1] = y;
  ch[y][k] = w;
  if (!isroot(y)) {
    ch[z][ch[z][1] == y] = x;
  }
  f[x] = z;
  f[y] = x;
  if (w) f[w] = y;
}
void splay(int x) {
  pushall(x);
  while (!isroot(x)) {
    int y = f[x], z = f[y];
    if (!isroot(y)) {
      rotate((ch[y][1] == x) ^ (ch[z][1] == y) ? x : y);
    }
    rotate(x);
  }
}
void access(int x) {
  for (int y = 0; x; y = x, x = f[x]) {
    splay(x);
    rs = y;
  }
}
void makeroot(int x) {
  access(x);
  splay(x);
  pushr(x);
}
int findroot(int x) {
  access(x);
  splay(x);
  while (ls) {
    pushdown(x);
    x = ls;
  }
  splay(x);
  return x;
}
void split(int x, int y) {
  makeroot(y);
  access(x);
  splay(x);
}
void link(int x, int y) {
  makeroot(x);
  f[x] = y;
}
void cut(int x, int y) {
  split(x, y);
  f[y] = ch[x][0] = 0;
}
int n, m, vis[N];
vector<int> g[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    link(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= m; i++) {
    int opt, x, y, k;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d%d", &x, &y, &k);
      split(x, y);
      pusha(x, k);
    } else if (opt == 2) {
      scanf("%d%d", &x, &y);
      ++n;
      link(n, y);
      v[n] = x;
      g[n].push_back(y);
      g[y].push_back(n);
    } else {
      scanf("%d", &x);
      vis[x] = 1;
      for (auto to : g[x]) {
        if (!vis[to]) cut(x, to);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << i << " " << v[i] << endl;
    }
  }
  return 0;
}