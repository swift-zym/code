
// Problem: P4717 【模板】快速莫比乌斯/沃尔什变换 (FMT/FWT)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4717
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
enum type { OR, XOR, AND };
using namespace std;
void fwt(int *a, int len, type tp, int v) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += (i << 1))
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = a[j + i + k];
        if (tp == OR) {
          a[j + i + k] += x * v % MOD;
          a[j + i + k] = (a[j + i + k] + MOD) % MOD;
        } else if (tp == AND) {
          a[j + k] += y * v % MOD;
          a[j + k] = (a[j + k] + MOD) % MOD;
        } else if (tp == XOR) {
          a[j + k] = (x + y) % MOD * v % MOD;
          a[j + k] = (a[j + k] + MOD) % MOD;
          a[j + i + k] = (x - y + MOD) % MOD * v % MOD;
          a[j + i + k] = (a[j + i + k] + MOD) % MOD;
        }
      }
}
int n, a[1000000], b[1000000], c[1000000], d[1000000], e[1000000];
void exec(type tp) {
  memcpy(c, a, sizeof(a));
  memcpy(d, b, sizeof(b));
  fwt(c, 1 << n, tp, 1);
  fwt(d, 1 << n, tp, 1);
  for (int i = 0; i < (1 << n); i++) e[i] = (c[i] * d[i]) % MOD;
  fwt(e, 1 << n, tp, tp == XOR ? (MOD + 1) >> 1 : -1);
  for (int i = 0; i < (1 << n); i++) {
    cout << e[i] << " ";
  }
  cout << endl;
}
signed main() {
  cin >> n;
  for (int i = 0; i < (1 << n); i++) cin >> a[i];
  for (int i = 0; i < (1 << n); i++) cin >> b[i];
  exec(OR);
  exec(AND);
  exec(XOR);
  return 0;
}