#include <bits/stdc++.h>
using namespace std;
int T, k, ans, a[1 << 16];
bool judge(int x) {
  int h = 0, bas = 1;
  while (x >= bas) {
    h++;
    x -= bas;
    bas *= 2;
  }
  if (x) h++;
  return h % 2 == k % 2;
}
void file() {
  freopen("stone.in", "r", stdin);
  freopen("stone.out", "w", stdout);
}
int main() {
  file();
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> k;
    for (int i = 1; i < (1 << k); i++) cin >> a[i];
    int sg = 0;
    for (int i = 1; i < (1 << k); i++) {
      if (judge(i)) sg ^= a[i];
    }
    if (!sg) {
      puts("0");
      continue;
    }
    for (int i = 1; i < (1 << k); i++) {
      if (judge(i)) {
        if (a[i] >= (sg ^ a[i])) {
          ans += 1 + (i * 2 < (1 << k));
        } else if ((a[i / 2] + a[i]) >= (sg ^ a[i])) {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}