
// Problem: E. Intergalaxy Trips
// Contest: Codeforces - Codeforces Round #335 (Div. 1)
// URL: https://codeforces.com/problemset/problem/605/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
int n, vis[1001];
double p[1001][1001];
double e[1001], g[1001];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%lf", &p[i][j]);
      p[i][j] /= 100;
    }
  if (n == 1) {
    puts("0");
    exit(0);
  }
  vis[n] = 1;
  for (int i = 1; i < n; i++) {
    e[i] = 1;
    g[i] = 1.0 - p[i][n];
  }
  for (int i = 1; i <= n; i++) {
    double mi = 1e18;
    int pos;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && e[j] / (1 - g[j]) < mi) {
        mi = e[j] / (1 - g[j]);
        pos = j;
      }
    }
    vis[pos] = 1;
    if (pos == 1) {
      printf("%0.10lf\n", e[pos] / (1 - g[pos]));
      exit(0);
    }
    for (int j = 1; j <= n; j++) {
      e[j] += e[pos] / (1 - g[pos]) * p[j][pos] * g[j];
      g[j] *= (1 - p[j][pos]);
    }
  }
  return 0;
}