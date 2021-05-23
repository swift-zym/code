// Problem: P3810 【模板】三维偏序（陌上花开）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define N 2000000
using namespace std;
struct node {
  int a, b, c, num, ans;
} a[N], b[N];
bool by_a(node a, node b) {
  if (a.a != b.a) return a.a < b.a;
  if (a.b != b.b) return a.b < b.b;
  return a.c < b.c;
}
bool by_b(node a, node b) {
  if (a.b != b.b) return a.b < b.b;
  return a.c < b.c;
}
int t[N];
int n, k, tot, ans[N], f[N];
void add(int x, int v) {
  for (; x <= k; x += x & -x) t[x] += v;
}
int query(int x, int v = 0) {
  for (; x; x -= x & -x) v += t[x];
  return v;
}
void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(a + l, a + mid + 1, by_b);
  sort(a + mid + 1, a + r + 1, by_b);
  int i, j;
  for (i = mid + 1, j = l; i <= r; i++) {
    for (; j <= mid && a[j].b <= a[i].b; j++) add(a[j].c, a[j].num);
    a[i].ans += query(a[i].c);
  }
  for (i = l; i < j; i++) add(a[i].c, -a[i].num);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &b[i].a, &b[i].b, &b[i].c);
  }
  sort(b + 1, b + n + 1, by_a);
  int num = 0;
  for (int i = 1; i <= n; i++) {
    num++;
    if (i == n || b[i].a != b[i + 1].a || b[i].b != b[i + 1].b ||
        b[i].c != b[i + 1].c) {
      a[++tot] = {b[i].a, b[i].b, b[i].c, num, 0};
      num = 0;
    }
  }

  cdq(1, tot);
  for (int i = 1; i <= tot; i++) {
    f[a[i].ans + (a[i].num - 1)] += a[i].num;
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", f[i]);
  }
  return 0;
}