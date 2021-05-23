// Problem: D. Two chandeliers
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open
// Olympiad in Informatics) URL: https://codeforces.com/contest/1501/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
template <typename T>
void exgcd(const T &a, const T &b, T &g, T &x, T &y) {
  if (b) {
    exgcd(b, a % b, g, y, x);
    y -= x * (a / b);
    return;
  }
  g = a, x = 1, y = 0;
  return;
}
template <typename T>
T Inverse(const T &a, const T &p) {
  T g, x, y;
  exgcd(a, p, g, x, y);
  x %= p;
  if (x < 0) x += p;
  return x;
}
int n, m, k, a[500001], b[500001], pos[1000000];
int check(int t) {
  int g = gcd(n, m);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = pos[a[i]];
    if (!x) continue;
    if ((x - i) % g) continue;
    cout << x - i << endl;
    int tmp = (x - i) / g * Inverse(n / g, m / g);
    cout << i << " " << tmp << endl;
    int cur = t / (m / g);
    if (t % (m / g)) cur--;
    if (t % (m / g) >= tmp) cur++;
    sum += cur;
  }
  cout << sum << endl;
  return sum >= k;
}
signed main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) {
    pos[b[i]] = i;
  }
  int l = 1, r = 1e18;
  while (l != r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}