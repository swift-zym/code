#include <bits/stdc++.h>
long long n, k, f[3000];
int main() {
  std::cin >> n >> k;
  f[0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = i; ~j; j--) {
      f[j] = (f[j + 1] + (j ? f[j - 1] : 0)) % 1000000007;
    }
  for (int i = 1; i <= n - k - 1; i++) f[n - k] = (f[n - k] * 2) % 1000000007;
  std::cout << f[n - k] << std::endl;
  return 0;
}