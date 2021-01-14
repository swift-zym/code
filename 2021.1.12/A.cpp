#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define int long long
int n, miu[MAXN << 1], np[MAXN << 1], f[MAXN << 1];
vector<int> prime;
int count(int a, int b) {
  int num = 0;
  while (a % b == 0) a /= b, num++;
  return num;
}
void init() {
  miu[1] = np[1] = f[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (!np[i]) {
      prime.push_back(i);
      miu[i] = -1;
      f[i] = 2;
    }
    for (int j = 0; j < prime.size() && i * prime[j] <= MAXN; j++) {
      np[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        int val = count(i, prime[j]);
        f[i * prime[j]] = f[i] / (val + 1) * (val + 2);
        break;
      }
      miu[i * prime[j]] = -miu[i];
      f[i * prime[j]] = 2 * f[i];
    }
  }
  for (int i = 2; i <= MAXN; i++) {
    miu[i] += miu[i - 1];
  }
  for (int i = 2; i <= MAXN; i++) {
    f[i] *= f[i];
    f[i] += f[i - 1];
  }
}
signed main() {
  freopen("function.in", "r", stdin);
  freopen("function.out", "w", stdout);
  init();
  int T;
  scanf("%lld", &T);
  while (T--) {
    int n;
    scanf("%lld", &n);
    int l, r, ans = 0;
    for (l = 1; l <= n; l = r + 1) {
      r = (n / (n / l));
      ans += (miu[r] - miu[l - 1]) * f[n / l];
    }
    printf("%lld\n", ans);
  }
  return 0;
}