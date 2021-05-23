#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
int n, m, ans = 1;
vector<int> tmp;
void fwt(int f) {
  for (int i = 1; i < tmp.size(); i <<= 1)
    for (int j = 0; j < tmp.size(); j += (i << 1)) {
      for (int k = 0; k < i; k++) {
        tmp[i + j + k] = (tmp[i + j + k] + tmp[j + k] * f) % MOD;
      }
    }
}
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
signed main() {
  freopen("lg.in", "r", stdin);
  freopen("lg.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    for (int j = 1; i * j <= m * 100; j++) {
      vector<pair<int, int>> pr;
      vector<int> v;
      for (int k = 1; k <= sqrt(j) && k <= m / i; k++) {
        if (j % k == 0) {
          v.push_back(k);
          if (k * k != j && j / k <= m / i) v.push_back(j / k);
        }
      }
      int x = j;
      for (int k = 2; k <= sqrt(j); k++) {
        if (x % k == 0) {
          int cnt = 0;
          while (x % k == 0) {
            cnt++;
            x /= k;
          }
          pr.push_back(make_pair(k, cnt));
        }
      }
      if (x != 1) pr.push_back(make_pair(x, 1));
      int limit = (1 << (pr.size() << 1));
      tmp.assign(limit, 0);
      for (auto x : v) {
        int mask = 0;
        for (int k = 0; k < pr.size(); k++) {
          auto y = pr[k];
          int cnt = 0;
          while (x % y.first == 0) {
            cnt++;
            x /= y.first;
          }
          if (!cnt) mask |= (1 << k);
          if (cnt == y.second) mask |= (1 << (k + pr.size()));
        }
        tmp[mask]++;
      }
      fwt(1);
      for (auto &&x : tmp) {
        x = qpow(x, n);
      }
      fwt(-1);
      if (tmp.back()) {
        ans *= qpow(qpow(i * j, i), tmp.back()) % MOD;
        ans %= MOD;
      }
    }
  cout << ans << endl;
  return 0;
}