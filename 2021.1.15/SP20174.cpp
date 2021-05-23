
// Problem: SP20174 DIVCNT3 - Counting Divisors (cube)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP20174
// Memory Limit: 0 MB
// Time Limit: 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> prime;
int np[1000000];
void euler() {
  np[1] = 1;
  for (int i = 2; i < 1000000; i++) {
    if (!np[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && i * prime[j] < 1000000; j++) {
      np[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int g[1000000], val[1000000], idx[1000000][2];
int n, mx, tot;
int S(int x, int y) {
  if (y && prime[y - 1] >= x) return 0;
  int k = x <= mx ? idx[x][0] : idx[n / x][1];
  int ans = 4 * (g[k] - y);
  for (int i = y + 1; i <= prime.size() && prime[i - 1] * prime[i - 1] <= x;
       i++) {
    int pr = prime[i - 1];
    for (int j = 1; pr <= x; j++, pr *= prime[i - 1]) {
      int val = S(x / pr, i);
      ans += (3ll * j + 1) * (val + (j > 1));
    }
  }
  return ans;
}
void solve() {
  tot = 0;
  for (int i = 1; i <= n; i = (n / (n / i)) + 1) {
    val[++tot] = n / i;
    g[tot] = val[tot] - 1;
    if (val[tot] <= mx)
      idx[val[tot]][0] = tot;
    else
      idx[n / val[tot]][1] = tot;
  }
  for (int i = 0; i < prime.size(); i++) {
    int pr = prime[i];
    for (int j = 1; j <= tot && pr * pr <= val[j]; j++) {
      int k =
          val[j] / pr <= mx ? idx[val[j] / pr][0] : idx[n / (val[j] / pr)][1];
      g[j] -= (g[k] - i);
    }
  }
  printf("%lld\n", S(n, 0) + 1);
}
signed main() {
  euler();
  int T;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    mx = sqrt(n);
    solve();
  }
  return 0;
}