// Problem: A. [2021.1.12多校省选模拟1] Function
// Contest: LibreOJ - 2021.112多校省选模拟1
// URL: http://47.92.197.167:5283/contest/54/problem/1
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> p;
int np[1100000];
int n, mx, tot;
void e() {
  p.clear();
  np[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (!np[i]) p.push_back(i);
    for (int j = 0; j < p.size() && i * p[j] <= 1000000; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int g[1000000], v[1000000], id[1000000][2];
int S(int x, int y) {
  if (y && p[y - 1] >= x) return 0;
  int k = x <= mx ? id[x][0] : id[n / x][1];
  int ans = 4 * g[k] - y * 4;
  for (int i = y + 1; i <= p.size() && p[i - 1] * p[i - 1] <= x; i++) {
    int pr = p[i - 1];
    for (int j = 1; pr <= x; j++, pr *= p[i - 1]) {
      int val = S(x / pr, i);
      ans += (3 * j + 1) * (val + (j > 1));
      cout << val << endl;
    }
  }
  return ans;
}
void solve() {
  tot = 0;
  mx = sqrt(n);
  for (int l = 1; l <= n; l = (n / (n / l)) + 1) {
    v[++tot] = n / l;
    g[tot] = v[tot] - 1;
    if (v[tot] <= mx) {
      id[v[tot]][0] = tot;
    } else {
      id[n / v[tot]][1] = tot;
    }
  }
  for (int i = 0; i < p.size(); i++) {
    int pr = p[i];
    for (int j = 1; j <= tot && pr * pr <= v[j]; j++) {
      int k = (v[j] / pr) <= mx ? id[v[j] / pr][0] : id[n / (v[j] / pr)][1];
      g[j] -= (g[k] - i);
    }
  }
  cout << S(n, 0) + 1 << endl;
}
void file() {
  freopen("function.in", "r", stdin);
  freopen("function.out", "w", stdout);
}
signed main() {
  e();
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    solve();
  }
  return 0;
}
