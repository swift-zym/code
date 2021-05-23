// Problem: D. GCD of an Array
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
int n, q, a[1000000], idx[1000000], x[1000000];
vector<pair<int, int> > tmp[1000000];
map<int, int> mp[1000000], mi;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
vector<int> out;
signed main() {
  for (int i = 2; i <= 200000; i++) {
    int x = i;
    for (int j = 2; j * j <= i && x > 1; j++) {
      int num = 0;
      while (x % j == 0) {
        num++;
        x /= j;
      }
      if (num) tmp[i].push_back(make_pair(num, j));
    }
    if (x != 1) tmp[i].push_back(make_pair(1, x));
  }
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    cin >> idx[i] >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    for (auto pa : tmp[a[i]]) {
      mp[i][pa.second] += pa.first;
    }
  }
  for (int i = 1; i <= q; i++) {
    for (auto pa : tmp[x[i]]) {
      mp[idx[i]][pa.second] += pa.first;
    }
  }
  mi = mp[1];
  for (int i = 2; i <= n; i++) {
    map<int, int> tmp;
    for (auto pa : mp[i]) {
      if (!mi.count(pa.first)) continue;
      tmp[pa.first] = min(pa.second, mi[pa.first]);
    }
    mi.swap(tmp);
  }
  int ans = 1;
  for (auto pa : mi) {
    ans = (ans * qpow(pa.first, pa.second)) % MOD;
  }
  out.push_back(ans);
  for (int i = q; i >= 1; i--) {
    for (auto pa : tmp[x[i]]) {
      int bk = mp[idx[i]][pa.second], ne = bk - pa.first, val = mi[pa.second];
      if (val > ne) {
        ans = ans * qpow(qpow(pa.second, val - ne), MOD - 2) % MOD;
        mi[pa.second] = ne;
      }
      mp[idx[i]][pa.second] = ne;
    }
    if (i != 1) out.push_back(ans);
  }
  reverse(out.begin(), out.end());
  for (auto v : out) {
    cout << v << endl;
  }
  cout << endl;
  return 0;
}