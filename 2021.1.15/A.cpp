/** **/
#include <bits/stdc++.h>
using namespace std;

struct node {
  double x, y;
  double operator%(const node &t) const { return x * t.y - y * t.x; }
  double operator*(const node &t) const {
    return x == t.x ? 1e8 : (y - t.y) / (x - t.x);
  }
  bool operator<(const node &t) const {
    if (x != t.x) return x < t.x;
    return y < t.y;
  }
  node operator-(const node &t) const { return {x - t.x, y - t.y}; }
} a[2000000], sta[2000000];
double dis(node a, node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void file() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
}
int main() {
  file();
  int n, s = 0;
  double ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s += x;
    a[i] = {(double)s, (double)s / x};
  }
  sort(a + 1, a + n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    sta[++cnt] = a[i];
    while (cnt >= 3 && sta[cnt - 2] * sta[cnt] < sta[cnt - 2] * sta[cnt - 1])
      sta[cnt - 1] = sta[cnt], cnt--;
  }
  vector<node> all;
  for (int i = 1; i <= cnt; i++) {
    all.push_back(sta[i]);
  }
  cnt = 0;
  for (int i = n; i >= 1; i--) {
    sta[++cnt] = a[i];
    while (cnt >= 3 && sta[cnt - 2] * sta[cnt] < sta[cnt - 2] * sta[cnt - 1])
      sta[cnt - 1] = sta[cnt], cnt--;
  }
  for (int i = 2; i < cnt; i++) {
    all.push_back(sta[i]);
  }
  for (int i = 1; i < all.size() - 1; i++) {
    ans += (all[i] - all[0]) % (all[i + 1] - all[0]);
  }
  printf("%0.5lf", ans / 2);
}