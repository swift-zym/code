#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll p = 998244353, N = 1e6 + 5;
ll fac[N], finv[N], iv[N];
int w[N], sa, sb, n, vv[N], vs[N], rd[N];
ll comb(int n, int m) {
  return n < m ? 0 : fac[n] * finv[m] % p * finv[n - m] % p;
}
int main() {
  freopen("permutation.in", "r", stdin);
  freopen("permutation.out", "w", stdout);
  scanf("%d", &n);
  if (n % 2) return printf("0\n"), 0;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]), rd[w[i]]++;
  fac[0] = fac[1] = iv[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i <= n * 2; i++)
    fac[i] = fac[i - 1] * i % p, iv[i] = (p - p / i) * iv[p % i] % p,
    finv[i] = finv[i - 1] * iv[i] % p;
  for (int i = 1; i <= n; i++)
    if (w[i] && vv[w[i]])
      return printf("0\n"), 0;
    else
      vv[w[i]] = 1;
  for (int i = 1; i <= n; i++) {
    if (rd[i]) continue;
    if (w[i] == 0) {
      sa++;
      continue;
    }
    int x = i, jo = 0;
    while (x != 0 && !vs[x]) vs[x] = 1, x = w[x], jo++;
    if (x) {
      if (jo % 2) return printf("0\n"), 0;
    } else
      jo % 2 ? sa++ : sb++;
  }
  //    cout<<"sd\n";
  if (sa % 2) return printf("0\n"), 0;
  if (sa == 0) return printf("%lld\n", fac[sb]), 0;
  ll ans = 1, sum = 0;
  for (int i = 1; i <= sa; i += 2) ans = ans * i % p;
  ans = ans * ans % p;
  //    cout<<sa<<" "<<sb<<" "<<ans<<endl;
  for (int i = 0; i <= sb; i++) sum = (sum + comb(sa + i - 1, i)) % p;
  ans = sum * fac[sb] % p * ans % p;
  printf("%lld\n", ans);
  return 0;
}
/*
6
2 0 0 0 0 0
*/
