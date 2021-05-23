#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define N 10000000
#define inv2 500000004
using namespace std;
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
int s(int x) { return (x + 1) % MOD * inv2 % MOD * x % MOD; }
int f(int x) { return x % MOD * s(x) % MOD; }
int np[N], v[N];
vector<int> p;
unordered_map<int, int> mp;
inline int get(int n) {
  if (n < N) return v[n];
  int tmp;
  if ((tmp = mp[n])) return tmp;
  int ans = n % MOD;
  for (int l = 2, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans -= (s(r) - s(l - 1)) % MOD * get(n / l) % MOD;
    ans = (ans + MOD) % MOD;
  }
  mp[n] = (ans = (ans + MOD) % MOD);
  return ans;
}
void e() {
  np[1] = v[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!np[i]) {
      p.push_back(i);
      v[i] = (1 - i + MOD) % MOD;
    }
    for (int j = 0; j < p.size() && i * p[j] < N; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0) {
        v[i * p[j]] = v[i];
        break;
      }
      v[i * p[j]] = v[i] * v[p[j]] % MOD;
    }
  }
  for (int i = 2; i < N; i++) {
    v[i] = (v[i] + v[i - 1]) % MOD;
  }
}
void f() {
  freopen("divisor.in", "r", stdin);
  freopen("divisor.out", "w", stdout);
}
signed main() {
  // f();
  int n, ans = 0;
  e();
  cin >> n;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = (n / (n / l));
    ans += f(n / l) * ((get(r) - get(l - 1) + MOD) % MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}