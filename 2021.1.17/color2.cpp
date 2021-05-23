#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[20][20];
void fwt(int *a, int len, int v) {
  for (int i = 1; i < len; i <<= 1)
    for (int j = 0; j < len; j += (i << 1))
      for (int k = 0; k < i; k++) {
        a[j + i + k] += a[j + k] * v;
      }
}
int a[21][300000], tmp[1000000];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < (1 << n); i++) {
      bool flag = 1;
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) {
          if (s[j][k] == '1' && ((1 << j) & i) && ((1 << k) & i)) {
            flag = 0;
          }
        }
      a[1][i] = flag;
    }
    memcpy(tmp, a[1], sizeof(int) * (1 << n));
    fwt(tmp, (1 << n), 1);
    for (int i = 2; i <= n; i++) {
      memcpy(a[i], a[i - 1], sizeof(int) * (1 << n));
      fwt(a[i], (1 << n), 1);
      for (int j = 0; j < (1 << n); j++) a[i][j] *= tmp[j];
      fwt(a[i], (1 << n), -1);
      for (int j = 0; j < (1 << n); j++) a[i][j] = (bool)a[i][j];
    }
    unsigned int ans = 0, bas = 1;
    for (int i = 1; i < (1 << n); i++) {
      bas *= 233;
      int j = 0;
      for (; !a[j][i]; j++)
        ;
      ans += bas * j;
    }
    printf("%u\n", ans);
  }
  return 0;
}