// Problem: P3746 [六省联考2017]组合数问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3746
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, k, p, r;
struct matrix {
  int length, val[50][50];
  matrix(int _length) {
    length = _length;
    memset(val, 0, sizeof(val));
  }
  matrix operator*(const matrix &rhs) const {
    matrix sol(length);
    for (int i = 0; i < length; i++)
      for (int j = 0; j < length; j++)
        for (int k = 0; k < length; k++) {
          sol.val[i][j] = (1ll * val[i][k] * rhs.val[k][j] + sol.val[i][j]) % p;
        }
    return sol;
  }
};
int main() {
  cin >> n >> p >> k >> r;
  matrix bas(k), ans(k);
  ans.val[0][0] = 1;
  for (int i = 0; i < k; i++) {
    bas.val[i][i]++;
    bas.val[(i + 1) % k][i]++;
  }
  long long tmp = 1ll * n * k;
  while (tmp) {
    if (tmp & 1) {
      ans = ans * bas;
    }
    bas = bas * bas;
    tmp >>= 1;
  }
  cout << ans.val[0][r] << endl;
  return 0;
}