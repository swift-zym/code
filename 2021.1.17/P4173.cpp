
// Problem: P4173 残缺的字符串
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4173
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef complex<double> cp;
const int N = 1000000;
const double PI = acos(-1), eps = 1e-1;
int idx[N];
db _cos[N], _sin[N];
void FFT(cp *a, int len, int f = 1) {
  for (int i = 0; i < len; i++) {
    if (i > idx[i]) {
      swap(a[i], a[idx[i]]);
    }
  }
  for (int l = 1; l < len; l <<= 1) {
    cp bas(_cos[l], _sin[l] * f);
    for (int s = 0; s < len; s += (l << 1)) {
      cp cur(1, 0);
      for (int k = 0; k < l; k++, cur *= bas) {
        cp x = a[s + k], y = a[s + l + k] * cur;
        a[s + k] = x + y;
        a[s + l + k] = x - y;
      }
    }
  }
  if (f == -1)
    for (int i = 0; i < len; i++) {
      a[i] /= len;
    }
}
int m, n, va[N], vb[N];
string a, b;
cp x[N], y[N], ans[N];
int main() {
  cin >> m >> n >> a >> b;
  reverse(a.begin(), a.end());
  int len = 1, num = 0;
  while (len < n) {
    len <<= 1;
    num++;
  }
  for (int i = 1; i < len; i++) {
    _cos[i] = cos(PI / i);
    _sin[i] = sin(PI / i);
  }
  for (int i = 0; i < len; i++) {
    idx[i] = (idx[i >> 1] >> 1) | ((i & 1) << (num - 1));
  }
  for (int i = 0; i < m; i++) {
    va[i] = (a[i] == '*' ? 0 : a[i] - 'a' + 1);
  }
  for (int i = 0; i < n; i++) {
    vb[i] = (b[i] == '*' ? 0 : b[i] - 'a' + 1);
  }
  for (int i = 0; i < len; i++) {
    x[i] = cp(va[i] * va[i] * va[i], 0);
    y[i] = cp(vb[i], 0);
  }
  FFT(x, len);
  FFT(y, len);
  for (int i = 0; i < len; i++) {
    ans[i] += x[i] * y[i];
  }
  for (int i = 0; i < len; i++) {
    x[i] = cp(va[i] * va[i], 0);
    y[i] = cp(vb[i] * vb[i], 0);
  }
  FFT(x, len);
  FFT(y, len);
  for (int i = 0; i < len; i++) {
    ans[i] -= x[i] * y[i] * cp(2, 0);
  }
  for (int i = 0; i < len; i++) {
    x[i] = cp(va[i], 0);
    y[i] = cp(vb[i] * vb[i] * vb[i], 0);
  }
  FFT(x, len);
  FFT(y, len);
  for (int i = 0; i < len; i++) {
    ans[i] += x[i] * y[i];
  }
  FFT(ans, len, -1);
  vector<int> out;
  for (int i = 0; i < n; i++) {
    if (abs(ans[i].real()) < eps && i + 1 - m + 1 > 0) {
      out.push_back(i + 1 - m + 1);
    }
  }
  cout << out.size() << endl;
  for (auto v : out) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}