
// Problem: P3380 【模板】二逼平衡树（树套树）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3380
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pushup(x) v[x].siz = v[v[x].ls].siz + v[v[x].rs].siz + 1
#define MIINT -2147483647
#define MXINT 2147483647
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
using namespace std;
struct node {
  int ls, rs, v, siz, rnd;
} v[10000000];
int tot;
inline int new_node(int val) {
  v[++tot] = {0, 0, val, 1, rand()};
  return tot;
}
struct FHQTreap {
  int root;
  void split(int now, int k, int &x, int &y) {
    if (!now) {
      x = y = 0;
      return;
    }
    if (v[now].v <= k) {
      x = now;
      split(v[now].rs, k, v[x].rs, y);
    } else {
      y = now;
      split(v[now].ls, k, x, v[y].ls);
    }
    pushup(now);
  }
  inline int rnk(int x) {
    if (!root) return 0;
    int A, B;
    split(root, x - 1, A, B);
    int ans = v[A].siz;
    root = merge(A, B);
    return ans;
  }
  inline int kth(int k) {
    int now = root;
    while (v[v[now].ls].siz + 1 != k) {
      if (v[v[now].ls].siz + 1 < k) {
        k -= v[v[now].ls].siz + 1;
        now = v[now].rs;
      } else {
        now = v[now].ls;
      }
    }
    return v[now].v;
  }
  int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (v[x].rnd <= v[y].rnd) {
      v[x].rs = merge(v[x].rs, y);
      pushup(x);
      return x;
    } else {
      v[y].ls = merge(x, v[y].ls);
      pushup(y);
      return y;
    }
  }
  inline void insert(int x) {
    int A, B;
    split(root, x, A, B);
    A = merge(A, new_node(x));
    root = merge(A, B);
  }
  inline void remove(int x) {
    int A, B, C;
    split(root, x - 1, A, B);
    split(B, x, B, C);
    B = merge(v[B].ls, v[B].rs);
    A = merge(A, B);
    root = merge(A, C);
  }
  int pre(int x) {
    int A, B;
    split(root, x - 1, A, B);
    int now = A;
    if (!now) return MIINT;
    while (v[now].rs) now = v[now].rs;
    int ans = v[now].v;
    root = merge(A, B);
    return ans;
  }
  int nxt(int x) {
    int A, B;
    split(root, x, A, B);
    int now = B;
    if (!now) return MXINT;
    while (v[now].ls) now = v[now].ls;
    int ans = v[now].v;
    root = merge(A, B);
    return ans;
  }
};
int n, m, arr[300000];
struct segement_tree {
  struct node {
    FHQTreap treap;
    int l, r;
  } a[300000];
  void modify(int now, int pos, int k) {
    a[now].treap.remove(arr[pos]);
    a[now].treap.insert(k);
    // cout << arr[pos] << "->" << k << endl;
    if (a[now].l == a[now].r) return;
    int mid = (a[now].l + a[now].r) >> 1;
    if (pos <= mid)
      modify(now << 1, pos, k);
    else
      modify(now << 1 | 1, pos, k);
  }
  void build(int now, int l, int r) {
    a[now].l = l;
    a[now].r = r;
    for (int i = l; i <= r; i++) a[now].treap.insert(arr[i]);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
  }
  int rnk(int now, int l, int r, int v) {
    if (a[now].l == l && r == a[now].r) {
      // cout << v << " at (" << l << "," << r << ")->" << tmp << endl;
      return a[now].treap.rnk(v);
    }
    int tmp = 0;
    int mid = (a[now].l + a[now].r) >> 1;
    if (r <= mid)
      tmp += rnk(now << 1, l, r, v);
    else if (l > mid)
      tmp += rnk(now << 1 | 1, l, r, v);
    else
      tmp += rnk(now << 1, l, mid, v) + rnk(now << 1 | 1, mid + 1, r, v);
    return tmp;
  }
  int pre(int now, int l, int r, int v) {
    if (a[now].l == l && r == a[now].r) return a[now].treap.pre(v);
    int tmp = MIINT;
    int mid = (a[now].l + a[now].r) >> 1;
    if (r <= mid)
      tmp = max(tmp, pre(now << 1, l, r, v));
    else if (l > mid)
      tmp = max(tmp, pre(now << 1 | 1, l, r, v));
    else
      tmp = max(
          tmp, max(pre(now << 1, l, mid, v), pre(now << 1 | 1, mid + 1, r, v)));
    return tmp;
  }
  int nxt(int now, int l, int r, int v) {
    if (a[now].l == l && r == a[now].r) return a[now].treap.nxt(v);
    int tmp = MXINT;
    int mid = (a[now].l + a[now].r) >> 1;
    if (r <= mid)
      tmp = min(tmp, nxt(now << 1, l, r, v));
    else if (l > mid)
      tmp = min(tmp, nxt(now << 1 | 1, l, r, v));
    else
      tmp = min(
          tmp, min(nxt(now << 1, l, mid, v), nxt(now << 1 | 1, mid + 1, r, v)));
    return tmp;
  }
  inline int kth(int l, int r, int k) {
    int x = 0, y = 100000000, ans;
    while (x <= y) {
      int mid = (x + y) >> 1, val = rnk(1, l, r, mid);
      if (val + 1 <= k) {
        ans = mid;
        x = mid + 1;
      } else {
        y = mid - 1;
      }
    }
    return ans;
  }
} base;
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar()                                                          \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
int main() {
  srand(time(0));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    arr[i] = rd();
  }
  base.build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt = rd(), l, r, pos, k;
    switch (opt) {
      case 1:
        l = rd();
        r = rd();
        k = rd();
        printf("%d\n", base.rnk(1, l, r, k) + 1);
        break;
      case 2:
        l = rd();
        r = rd();
        k = rd();
        printf("%d\n", base.kth(l, r, k));
        break;
      case 3:
        pos = rd();
        k = rd();
        base.modify(1, pos, k);
        arr[pos] = k;
        break;
      case 4:
        l = rd();
        r = rd();
        k = rd();
        printf("%d\n", base.pre(1, l, r, k));
        break;
      default:
        l = rd();
        r = rd();
        k = rd();
        printf("%d\n", base.nxt(1, l, r, k));
        break;
    }
  }
  return 0;
}