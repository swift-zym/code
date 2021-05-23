#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
struct line {
  int l, r, vis;
  bool operator<(const line &li) const {
    if (r != li.r) return r < li.r;
    return l < li.l;
  }
} a[1000000];
int n, ans;
void file() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
}
int main() {
  file();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i].vis) continue;
    ans++;
    a[i].vis = 1;
    for (int j = i + 1; j <= n; j++) {
      if (a[j].l <= a[i].r) a[j].vis = 1;
    }
  }
  printf("%d %d\n", ans, 0);
  return 0;
}