
// Problem: Hard Nim
// Contest: Virtual Judge - %E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8
// URL: https://vjudge.net/problem/%E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8-4589
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
void fwt(int *a, int len, int v) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += (i << 1))
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = a[j + i + k];
        a[j + k] = (x + y) % MOD * v % MOD;
        a[j + i + k] = (x - y + MOD) % MOD * v % MOD;
      }
}
int n, m, a[2000000], mx;
vector<int> p;
void gp() {
  memset(a, 0, sizeof(int) * mx);
  a[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (!a[i]) {
      p.push_back(i);
    }
    for (int j = 0; j < p.size() && i * p[j] <= m; j++) {
      a[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= m; i++) a[i] ^= 1;
}
int qpow(int a, int b) {
  if (!b) return 1;
  int tmp = qpow(a, b / 2);
  return b % 2 ? tmp * tmp % MOD * a % MOD : tmp * tmp % MOD;
}
void upd() {
  mx = 1 << 3;
  while (mx < m) {
    mx <<= 1;
  }
}
signed main() {
  while (cin >> n >> m) {
    gp();
    upd();
    fwt(a, mx, 1);
    for (int i = 0; i < mx; i++) {
      a[i] = qpow(a[i], n);
    }
    fwt(a, mx, (MOD + 1) >> 1);
    cout << a[0] << endl;
  }
  return 0;
}