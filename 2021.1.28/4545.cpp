// Problem: #4545. DQS的trie
// Contest: UOJ
// URL: https://darkbzoj.tk/problem/4545
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define N 500000
#define ls ch[x][0]
#define rs ch[x][1]
using namespace std;
struct lct {
  int ch[N][2], f[N], v[N], tag[N];
  bool isroot(int x) { return ch[f[x]][0] != x && ch[f[x]][1] != x; }
  void add(int x, int val) {
    if (x) {
      v[x] += val;
      tag[x] += val;
    }
  }
  void pushdown(int x) {
    add(ls, tag[x]);
    add(rs, tag[x]);
    tag[x] = 0;
  }
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
      ch[x][1] = y;
    }
  }
  void link(int x, int y) {
    splay(x);
    access(y);
    splay(y);
    f[x] = y;
    add(y, v[x]);
  }
  void cut(int x) {
    access(x);
    splay(x);
    int y = ch[x][0];
    add(y, -v[x]);
    f[y] = ch[x][0] = 0;
  }
} lct;
struct SAM {
  int trans[N][26], f[N], v[N], tot = 1, ans;
  int insert(int c, int p) {
    int np = ++tot;
    v[np] = v[p] + 1;
    lct.v[np] = 1;
    while (p && !trans[p][c]) {
      trans[p][c] = np;
      p = f[p];
    }
    if (!p) {
      lct.link(np, 1);
      f[np] = 1;
      ans += v[np] - v[f[np]];
      return np;
    }
    int q = trans[p][c];
    if (v[q] == v[p] + 1) {
      lct.link(np, q);
      f[np] = q;
      ans += v[np] - v[f[np]];
      return np;
    }
    int nq = ++tot;
    v[nq] = v[p] + 1;
    f[nq] = f[q];
    f[np] = f[q] = nq;
    memcpy(trans[nq], trans[q], sizeof(trans[q]));
    lct.cut(q);
    lct.link(nq, f[nq]);
    lct.link(q, nq);
    lct.link(np, nq);
    while (p && trans[p][c] == q) {
      trans[p][c] = nq;
      p = f[p];
    }
    ans += v[np] - v[f[np]];
    return np;
  }
  int query(string s) {
    int x = 1;
    for (auto c : s) {
      x = trans[x][c - 'a'];
      if (!x) return 0;
    }
    lct.splay(x);
    return lct.v[x];
  }
} sam;
int id, n, m, x[N];
vector<pair<int, int>> g[N];
char tmp[1000000];
void bfs(int s) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto tmp : g[now]) {
      int to = tmp.first, c = tmp.second;
      if (!x[to]) {
        x[to] = sam.insert(c, x[now]);
        q.push(to);
      }
    }
  }
}
signed main() {
  scanf("%lld%lld", &id, &n);
  x[1] = 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    char c;
    scanf("%lld%lld", &u, &v);
    do {
      c = getchar();
    } while (c < 'a' || c > 'z');
    g[u].push_back(make_pair(v, c - 'a'));
    g[v].push_back(make_pair(u, c - 'a'));
  }
  bfs(1);
  scanf("%lld", &m);
  for (int i = 1; i <= m; i++) {
    int opt;
    scanf("%lld", &opt);
    if (opt == 1) {
      printf("%lld\n", sam.ans);
    } else if (opt == 2) {
      int rt, siz;
      cin >> rt >> siz;
      for (int i = 1; i < siz; i++) {
        int u, v;
        char c;
        scanf("%lld%lld", &u, &v);
        do {
          c = getchar();
        } while (c < 'a' || c > 'z');
        g[u].push_back(make_pair(v, c - 'a'));
        g[v].push_back(make_pair(u, c - 'a'));
      }
      bfs(rt);
    } else {
      string s;
      scanf("%s", tmp);
      s = tmp;
      printf("%lld\n", sam.query(s));
    }
  }
  return 0;
}