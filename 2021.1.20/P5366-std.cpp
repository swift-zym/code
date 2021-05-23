// ===================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ===================================
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}

const int mod = 1e9 + 7;
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) c = 1ll * c * a % mod;
  return c;
}

int n, G, L, Q;
vector<int> v;
int p[10], c[10], pcnt = 0;
int num[650], sum[650], s[1 << 16], cnt = 0;
int f[650][1 << 16], g[650][1 << 16], h[650][1 << 16], ans[650];

void devide(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    p[++pcnt] = i;
    while (x % i == 0) x /= i, ++c[pcnt];
  }
  if (x > 1) p[++pcnt] = x, c[pcnt] = 1;
}

int calc(int x) {
  int res = 0;
  for (int i = 1; i <= pcnt; ++i) {
    int y = 0;
    while (x % p[i] == 0) x /= p[i], ++y;
    if (y == 0) res |= 1 << (i - 1);
    if (y == c[i]) res |= 1 << (i - 1 + pcnt);
  }
  return res;
}

void FWT_or(int* A, int n, int op) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; ++k) {
        if (op == 1)
          A[i + j + k] = (A[i + j + k] + A[j + k]) % mod;
        else
          A[i + j + k] = (A[i + j + k] - A[j + k] + mod) % mod;
      }
}

int main() {
  n = read(), G = read(), L = read(), Q = read();
  if (L % G) {
    while (Q--) puts("0");
    return 0;
  }
  L /= G, n /= G;
  devide(L);
  for (int i = 1; i <= n && i * i <= L; ++i) {
    if (L % i) continue;
    v.push_back(i);
    if (L / i <= n && i * i != L) v.push_back(L / i);
  }
  for (int i : v) ++s[calc(i)];
  int lim = 1 << (pcnt << 1);
  for (int i = 0; i < lim; ++i)
    if (s[i]) num[++cnt] = i, sum[cnt] = qpow(2, s[i]) - 1;

  f[0][0] = g[cnt + 1][0] = 1;
  for (int i = 0; i < cnt; ++i)
    for (int S = 0; S < lim; ++S) {
      f[i + 1][S] = (f[i + 1][S] + f[i][S]) % mod;
      f[i + 1][S | num[i + 1]] =
          (f[i + 1][S | num[i + 1]] + 1ll * f[i][S] * sum[i + 1]) % mod;
    }
  for (int i = cnt + 1; i > 1; --i)
    for (int S = 0; S < lim; ++S) {
      g[i - 1][S] = (g[i - 1][S] + g[i][S]) % mod;
      g[i - 1][S | num[i - 1]] =
          (g[i - 1][S | num[i - 1]] + 1ll * g[i][S] * sum[i - 1]) % mod;
    }
  cout << (double)clock() / CLOCKS_PER_SEC << endl;
  cout << lim << endl;
  for (int i = 0; i <= cnt; ++i) FWT_or(f[i], lim, 1);
  for (int i = 1; i <= cnt + 1; ++i) FWT_or(g[i], lim, 1);
  for (int i = 1; i <= cnt; ++i)
    for (int S = 0; S < lim; ++S)
      h[i][S] = 1ll * f[i - 1][S] * g[i + 1][S] % mod;
  for (int i = 1; i <= cnt; ++i) FWT_or(h[i], lim, -1);
  for (int i = 1; i <= cnt; ++i) {
    for (int S = 0; S < lim; ++S)
      if ((S | num[i]) == lim - 1) {
        ans[i] = (ans[i] + h[i][S] * qpow(2, s[num[i]] - 1) % mod) % mod;
      }
  }
  while (Q--) {
    int x = read();
    if (x % G) {
      puts("0");
      continue;
    }
    x /= G;
    if (L % x || x > n) {
      puts("0");
      continue;
    }
    int p = lower_bound(num + 1, num + cnt + 1, calc(x)) - num;
    printf("%d\n", ans[p]);
  }
  return 0;
}