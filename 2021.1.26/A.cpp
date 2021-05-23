#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
#define getchar()                                                          \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
struct node {
  int deep[64], val[64];
  void insert(int v, int d) {
    for (int i = 63;; i--) {
      if (v & (1ull << i)) {
        if (!val[i]) {
          val[i] = v;
          deep[i] = d;
          break;
        }
        if (d > deep[i]) {
          swap(d, deep[i]);
          swap(v, val[i]);
        }
        v ^= val[i];
      }
      if (!i) break;
    }
  }
  int query(int d) {
    int ans = 0;
    for (int i = 63;; i--) {
      if (deep[i] >= d) {
        if ((ans ^ val[i]) > ans) {
          ans ^= val[i];
        }
      }
      if (!i) break;
    }
    return ans;
  }
  void copy(node from) {
    memcpy(deep, from.deep, sizeof(from.deep));
    memcpy(val, from.val, sizeof(from.val));
  }
} a[2000000];
int n, m, deep[2000000], cnt;
void file() {
  freopen("squirrel.in", "r", stdin);
  freopen("squirrel.out", "w", stdout);
}
signed main() {
  file();
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    int f = read(), v = read();
    deep[i] = deep[f] + 1;
    a[i].copy(a[f]);
    a[i].insert(v, deep[i]);
  }
  cnt = n;
  for (int i = 1; i <= m; i++) {
    int opt = read();
    if (opt) {
      int f = read(), v = read();
      deep[++cnt] = deep[f] + 1;
      a[cnt].copy(a[f]);
      a[cnt].insert(v, deep[cnt]);
    } else {
      int u = read(), d = read();
      cout << a[u].query(deep[u] - d) << endl;
    }
  }
  return 0;
}