#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, n, k, p;
struct matrix {
  int v[2][2];
  matrix() { memset(v, 0, sizeof(v)); }
  matrix(int a, int b, int c, int d) {
    v[0][0] = a, v[0][1] = b, v[1][0] = c, v[1][1] = d;
  }
  matrix operator*(const matrix &rhs) const {
    matrix ans;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1; k++) {
          ans.v[i][j] = (ans.v[i][j] + v[i][k] * rhs.v[k][j]) % p;
        }
    return ans;
  }
  // if(resend.OK)
};
signed main() {
  freopen("hakugai.in", "r", stdin);
  freopen("hakugai.out", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> n >> k >> p;
    matrix ans(a, b, 0, 0), bas(0, -1, 1, 3);
    n--;
    while (n) {
      if (n & 1) ans = ans * bas;
      bas = bas * bas;
      n >>= 1;
    }
    cout << ans.v[0][1] << endl;
  }
  return 0;
}